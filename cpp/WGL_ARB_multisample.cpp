//-----------------------------------------------------------------------------
// Copyright (c) 2006-2008 dhpoware. All Rights Reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include <cassert>
#include <cstdio>
#include <cstring>
#include "../headerFiles/WGL_ARB_multisample.h"

namespace
{
    WNDCLASSEX g_wcl;
    HWND g_hWnd;
    HDC g_hDC;
    HGLRC g_hRC;
    char g_szAAPixelFormat[32];

LRESULT CALLBACK DummyGLWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
        switch (msg)
        {
        case WM_CREATE:
            if (!(g_hDC = GetDC(hWnd)))
                return -1;
            break;

        case WM_DESTROY:
            if (g_hDC)
            {
                if (g_hRC)
                {
                    wglMakeCurrent(g_hDC, 0);
                    wglDeleteContext(g_hRC);
                    g_hRC = 0;
                }

                ReleaseDC(hWnd, g_hDC);
                g_hDC = 0;
            }

            PostQuitMessage(0);
            return 0;

        default:
            break;
        }

        return DefWindowProc(hWnd, msg, wParam, lParam);
}

bool CreateDummyGLWindow()
{
        g_wcl.cbSize = sizeof(g_wcl);
        g_wcl.style = CS_OWNDC;
        g_wcl.lpfnWndProc = DummyGLWndProc;
        g_wcl.hInstance = reinterpret_cast<HINSTANCE>(GetModuleHandle(0));
        g_wcl.lpszClassName = "DummyGLWindowClass";

        if (!RegisterClassEx(&g_wcl))
            return false;

        g_hWnd = CreateWindow(g_wcl.lpszClassName, "", WS_OVERLAPPEDWINDOW, 0, 0, 0, 0, 0, 0, g_wcl.hInstance, 0);

        if (!g_hWnd)
            return false;

        PIXELFORMATDESCRIPTOR pfd = {0};

        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 32;
        pfd.cDepthBits = 24;
        pfd.iLayerType = PFD_MAIN_PLANE;

        int pf = ChoosePixelFormat(g_hDC, &pfd);

        if (!SetPixelFormat(g_hDC, pf, &pfd))
            return false;

        if (!(g_hRC = wglCreateContext(g_hDC)))
            return false;

        if (!wglMakeCurrent(g_hDC, g_hRC))
            return false;

        return true;
}


void ChooseBestMSAAPixelFormat(int &pf)
{
        int attributes[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
            WGL_COLOR_BITS_ARB,     24,
            WGL_ALPHA_BITS_ARB,     8,
            WGL_DEPTH_BITS_ARB,     24,
            WGL_STENCIL_BITS_ARB,   8,
            WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
            WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
            WGL_SAMPLES_ARB,        0,
            0, 0
        };

        int returnedPixelFormat = 0;
        UINT numFormats = 0;
        BOOL bStatus = FALSE;

        for (int samples = 4; samples > 0; samples /= 2)
        {
            attributes[17] = samples;

            bStatus = wglChoosePixelFormatARB(g_hDC, attributes, 0, 1,
                        &returnedPixelFormat, &numFormats);

            if (bStatus == TRUE && numFormats)
            {
                pf = returnedPixelFormat;
                sprintf(g_szAAPixelFormat, "%dx MSAA", samples);
                break;
            }
        }

        if (bStatus == FALSE)
            g_szAAPixelFormat[0] = '\0';
}

void ChooseMSAAPixelFormat(int &pf, int samples)
{
        int attributes[] =
        {
            WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
            WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB,
            WGL_COLOR_BITS_ARB,     24,
            WGL_ALPHA_BITS_ARB,     8,
            WGL_DEPTH_BITS_ARB,     24,
            WGL_STENCIL_BITS_ARB,   8,
            WGL_DOUBLE_BUFFER_ARB,  GL_TRUE,
            WGL_SAMPLE_BUFFERS_ARB, GL_TRUE,
            WGL_SAMPLES_ARB,        samples,
            0, 0
        };

        int  returnedPixelFormat = 0;
        UINT numFormats = 0;
        BOOL bStatus = wglChoosePixelFormatARB(g_hDC, attributes, 0, 1, &returnedPixelFormat, &numFormats);

        if (bStatus == TRUE && numFormats)
        {
            pf = returnedPixelFormat;
            sprintf(g_szAAPixelFormat, "%dx MSAA", samples);
        }
        else
        {
            g_szAAPixelFormat[0] = '\0';
        }
}

void DestroyDummyGLWindow()
{
        if (g_hWnd)
        {
            PostMessage(g_hWnd, WM_CLOSE, 0, 0);

            BOOL bRet;
            MSG msg;

            while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        UnregisterClass(g_wcl.lpszClassName, g_wcl.hInstance);
}


}//--END_NAMESPACE

void ChooseBestAntiAliasingPixelFormat(int &pf)
{
    pf = 0;

    if (!CreateDummyGLWindow())
    {
        DestroyDummyGLWindow();
        return;
    }

        ChooseBestMSAAPixelFormat(pf);


    DestroyDummyGLWindow();
}



BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats)
{
    typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
    static PFNWGLCHOOSEPIXELFORMATARBPROC pfnChoosePixelFormatARB = 0;

    if (!pfnChoosePixelFormatARB)
    {
        pfnChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
        assert(pfnChoosePixelFormatARB != 0);
    }

    return pfnChoosePixelFormatARB(hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats);
}




