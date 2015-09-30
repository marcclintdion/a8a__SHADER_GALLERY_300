#define VK_OEM_PLUS	0xBB
#define VK_OEM_COMMA	0xBC
#define VK_OEM_MINUS	0xBD
#define VK_OEM_PERIOD	0xBE    
      
        bool TAB_KEY_RESET                      = true;
        bool KEY_V_IS_RESET                     = true;
        bool KEY_C_IS_RESET                     = true;

        bool VK_PRIOR_KeyIsReset                = true;
        bool VK_NEXT_KeyIsReset                 = true;

        bool aKeyIsReset                        = true;            
        bool bKeyIsReset                        = true;         
        bool cKeyIsReset                        = true;    
        bool dKeyIsReset                        = true;            
        bool eKeyIsReset                        = true;         
        bool fKeyIsReset                        = true;           
        bool gKeyIsReset                        = true;         
        bool hKeyIsReset                        = true;         
        bool iKeyIsReset                        = true;  
        bool jKeyIsReset                        = true; 
        bool kKeyIsReset                        = true;        
        bool lKeyIsReset                        = true;         
        bool mKeyIsReset                        = true;         
        bool nKeyIsReset                        = true;        
        bool oKeyIsReset                        = true;          
        bool pKeyIsReset                        = true;        
        bool qKeyIsReset                        = true;        
        bool rKeyIsReset                        = true;        
        bool sKeyIsReset                        = true;        
        bool tKeyIsReset                        = true;        
        bool uKeyIsReset                        = true;          
        bool vKeyIsReset                        = true;       
        bool wKeyIsReset                        = true;         
        bool xKeyIsReset                        = true;                
        bool yKeyIsReset                        = true;         
        bool zKeyIsReset                        = true;          
        
        bool homeKeyIsReset                     = true;            
        bool endKeyIsReset                      = true;
        
        bool VK_OEM_COMMA_KeyIsReset            = true;            
        bool VK_OEM_PERIOD_KeyIsReset           = true;    
        
        
        bool numpad_1_isReset                   = true;                                 
        
        bool spaceBarIsPressed                  = false;
        
        //======================================================================
 
        static bool  leftMouseButton;
        static bool  rightMouseButton;
        static bool  middleMouseButton;

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
//
// This header file contains the new OpenGL symbols and functions required to
// support multisample anti-aliasing (MSAA) and coverage sample anti-aliasing
// (CSAA) on the Windows platform.
//
// NVIDIA GeForce 8 series and higher GPUs support a new anti-aliasing method
// called coverage sample anti-aliasing (CSAA). CSAA is usually used with 
// framebuffer objects (FBOs) for offscreen rendering. However CSAA can also be
// used in an application window.
//
// The following extensions are used for MSAA:
//  GL_ARB_multisample
//  WGL_ARB_multisample
//  WGL_ARB_pixel_format
//
// The following NVIDIA extensions are used for CSAA:
//  GL_NV_multisample_coverage
//  WGL_NV_multisample_coverage
//
// Each function is loaded on first use. Ensure the extensions are supported
// via the OpenGL extension string and then start calling them.
//
// Three custom functions are provided to simplify (multisample and coverage
// sample) anti-aliasing setup under Windows:
//  ChooseBestAntiAliasingPixelFormat()
//  ChooseAntiAliasingPixelFormat()
//  GetAntiAliasingPixelFormatString()
//
// Use these functions in place of ChoosePixelFormat() to return a pixel format
// that supports MSAA.
//
// Example usage:
//  1. Get the highest quality MSAA pixel format.
//      int pf;
//
//      ChooseBestAntiAliasingPixelFormat(pf);
//
//      PIXELFORMATDESCRIPTOR pfd = { fill in as per normal };
//      HDC hDC = GetDC( your app's HWND );
//      HGLRC hRC;
//
//      SetPixelFormat(hDC, pf, &pfd);
//      hRC = wglCreateContext(hDC);
//      wglMakeCurrent(hDC, hRC);
//
//  2. Get a pixel format supporting 4x anti-aliasing.
//      int pf;
//
//      ChooseAntiAliasingPixelFormat(pf, 4);
//
//      PIXELFORMATDESCRIPTOR pfd = { fill in as per normal };
//      HDC hDC = GetDC( your app's HWND );
//      HGLRC hRC;
//
//      SetPixelFormat(hDC, pf, &pfd);
//      hRC = wglCreateContext(hDC);
//      wglMakeCurrent(hDC, hRC);
//
//-----------------------------------------------------------------------------
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif


#include <windows.h>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

#if defined(_DEBUG)
#include <crtdbg.h>
#endif




#if !defined(WGL_ARB_MULTISAMPLE_H)
#define WGL_ARB_MULTISAMPLE_H

#include <windows.h>
#include <GL/gl.h>

extern "C" {

// GL_ARB_multisample

#define GL_MULTISAMPLE_ARB                 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB         0x809F
#define GL_SAMPLE_COVERAGE_ARB             0x80A0
#define GL_SAMPLE_BUFFERS_ARB              0x80A8
#define GL_SAMPLES_ARB                     0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB       0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB      0x80AB
#define GL_MULTISAMPLE_BIT_ARB             0x20000000

extern void glSampleCoverageARB(GLclampf value, GLboolean invert);

// GL_NV_multisample_coverage

#define GL_COVERAGE_SAMPLES_NV             0x80A9
#define GL_COLOR_SAMPLES_NV                0x8E20

// WGL_ARB_multisample

#define WGL_SAMPLE_BUFFERS_ARB             0x2041
#define WGL_SAMPLES_ARB                    0x2042

// WGL_ARB_pixel_format

#define WGL_NUMBER_PIXEL_FORMATS_ARB       0x2000
#define WGL_DRAW_TO_WINDOW_ARB             0x2001
#define WGL_DRAW_TO_BITMAP_ARB             0x2002
#define WGL_ACCELERATION_ARB               0x2003
#define WGL_NEED_PALETTE_ARB               0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB        0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB         0x2006
#define WGL_SWAP_METHOD_ARB                0x2007
#define WGL_NUMBER_OVERLAYS_ARB            0x2008
#define WGL_NUMBER_UNDERLAYS_ARB           0x2009
#define WGL_TRANSPARENT_ARB                0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB      0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB    0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB     0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB    0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB    0x203B
#define WGL_SHARE_DEPTH_ARB                0x200C
#define WGL_SHARE_STENCIL_ARB              0x200D
#define WGL_SHARE_ACCUM_ARB                0x200E
#define WGL_SUPPORT_GDI_ARB                0x200F
#define WGL_SUPPORT_OPENGL_ARB             0x2010
#define WGL_DOUBLE_BUFFER_ARB              0x2011
#define WGL_STEREO_ARB                     0x2012
#define WGL_PIXEL_TYPE_ARB                 0x2013
#define WGL_COLOR_BITS_ARB                 0x2014
#define WGL_RED_BITS_ARB                   0x2015
#define WGL_RED_SHIFT_ARB                  0x2016
#define WGL_GREEN_BITS_ARB                 0x2017
#define WGL_GREEN_SHIFT_ARB                0x2018
#define WGL_BLUE_BITS_ARB                  0x2019
#define WGL_BLUE_SHIFT_ARB                 0x201A
#define WGL_ALPHA_BITS_ARB                 0x201B
#define WGL_ALPHA_SHIFT_ARB                0x201C
#define WGL_ACCUM_BITS_ARB                 0x201D
#define WGL_ACCUM_RED_BITS_ARB             0x201E
#define WGL_ACCUM_GREEN_BITS_ARB           0x201F
#define WGL_ACCUM_BLUE_BITS_ARB            0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB           0x2021
#define WGL_DEPTH_BITS_ARB                 0x2022
#define WGL_STENCIL_BITS_ARB               0x2023
#define WGL_AUX_BUFFERS_ARB                0x2024
#define WGL_NO_ACCELERATION_ARB            0x2025
#define WGL_GENERIC_ACCELERATION_ARB       0x2026
#define WGL_FULL_ACCELERATION_ARB          0x2027
#define WGL_SWAP_EXCHANGE_ARB              0x2028
#define WGL_SWAP_COPY_ARB                  0x2029
#define WGL_SWAP_UNDEFINED_ARB             0x202A
#define WGL_TYPE_RGBA_ARB                  0x202B
#define WGL_TYPE_COLORINDEX_ARB            0x202C

extern BOOL wglGetPixelFormatAttribivARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
extern BOOL wglGetPixelFormatAttribfvARB(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
extern BOOL wglChoosePixelFormatARB(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

// WGL_NV_multisample_coverage

#define WGL_COVERAGE_SAMPLES_NV            0x2042
#define WGL_COLOR_SAMPLES_NV               0x20B9

// Returns the highest quality hardware accelerated anti-aliasing pixel format.
// If a suitable MSAA or CSAA pixel format was found it will be returned in the
// 'pf' integer reference argument. Otherwise '0' will be returned.
extern void ChooseBestAntiAliasingPixelFormat(int &pf);

// Returns a hardware accelerated anti-aliasing (MSAA or CSAA) pixel format
// that supports the specified samples per pixel. If a matching MSAA or CSAA
// pixel format was found it will be returned in the 'pf' integer reference
// argument. Otherwise '0' will be returned.
extern void ChooseAntiAliasingPixelFormat(int &pf, int samples);

// Returns a string containing a description of the anti-aliasing pixel format
// selected by the most recent call to ChooseBestAntiAliasingPixelFormat() or
// ChooseAntiAliasingPixelFormat().
extern const char *GetAntiAliasingPixelFormatString();

} // extern "C"
#endif

//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//

//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//

#if !defined(PFD_SUPPORT_COMPOSITION)
#define PFD_SUPPORT_COMPOSITION 0x00008000
#endif

// GL_EXT_texture_filter_anisotropic
#define GL_TEXTURE_MAX_ANISOTROPY_EXT       0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT   0x84FF

// GL_SGIS_generate_mipmap
#define GL_GENERATE_MIPMAP_SGIS             0x8191

#define CAMERA_FOVY  45.0f
#define CAMERA_ZFAR  10.0f
#define CAMERA_ZNEAR 0.1f

#define MOUSE_ORBIT_SPEED 0.30f     // 0 = SLOWEST, 1 = FASTEST
#define MOUSE_DOLLY_SPEED 0.02f     // same as above...but much more sensitive
#define MOUSE_TRACK_SPEED 0.005f    // same as above...but much more sensitive









HWND                g_hWnd;
HDC                 g_hDC;
HGLRC               g_hRC;
HINSTANCE           g_hInstance;
int                 g_framesPerSecond;
int                 g_windowWidth;
int                 g_windowHeight;
int                 g_maxAnisotrophy;
float               g_heading;
float               g_pitch;
float               g_cameraPos[3] = {0.0f, 0.0f, 4.0f};
float               g_targetPos[3];
bool                g_isFullScreen;
bool                g_hasFocus;
bool                g_enableVerticalSync;
bool				g_enableGL_MULTISAMPLE_ARB = true;
bool                g_displayHelp;
GLuint              g_decalMap;


//-----------------------------------------------------------------------------
// Functions Prototypes.
//-----------------------------------------------------------------------------

void    Cleanup();
void    CleanupApp();
HWND    CreateAppWindow(const WNDCLASSEX &wcl, const char *pszTitle);
void    DrawFrame();

void    EnableVerticalSync(bool enableVerticalSync);

float   GetElapsedTimeInSeconds();
void    Init();

void    InitGL();

void    Log(const char *pszMessage);
void    ProcessMouseInput(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void    SetProcessorAffinity();
void    ToggleFullScreen();
void    UpdateFrame(float elapsedTimeSec);
void    UpdateFrameRate(float elapsedTimeSec);
LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);









int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
#if defined _DEBUG
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif

    MSG msg = {0};
    WNDCLASSEX wcl = {0};

    wcl.cbSize = sizeof(wcl);
    wcl.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wcl.lpfnWndProc = WindowProc;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hInstance = g_hInstance = hInstance;
    wcl.hIcon = LoadIcon(0, IDI_APPLICATION);
    wcl.hCursor = LoadCursor(0, IDC_ARROW);
    wcl.hbrBackground = 0;
    wcl.lpszMenuName = 0;
    wcl.lpszClassName = "GLWindowClass";
    wcl.hIconSm = 0;

    if (!RegisterClassEx(&wcl))
        return 0;

    g_hWnd = CreateAppWindow(wcl, 0);

    if (g_hWnd)
    {
        SetProcessorAffinity();
		InitGL();
		ToggleFullScreen();

            ShowWindow(g_hWnd, nShowCmd);
            UpdateWindow(g_hWnd);

            while (true)
            {
                while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                        break;

                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                if (msg.message == WM_QUIT)
                    break;


                if (keys[VK_ESCAPE])
		        { 
                     msg.message = WM_QUIT ;
                }                                   
               
                if (g_hasFocus)
                {
                    UpdateFrame(GetElapsedTimeInSeconds());
                    RenderGL();
                    SwapBuffers(g_hDC);
                    ProcessKeyboard();
                }
                else
                {
                    WaitMessage();
                }
            }


        Cleanup();
        UnregisterClass(wcl.lpszClassName, hInstance);
    }

    return static_cast<int>(msg.wParam);
}






LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        //======================================================================================
        case WM_KEYDOWN:
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
            return 0;								// Jump Back
		}
        break;
        case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}
		break;    
       //======================================================================================
    
    case WM_ACTIVATE:
        switch (wParam)
        {
        default:
            break;

        case WA_ACTIVE:
        case WA_CLICKACTIVE:
            g_hasFocus = true;
            break;

        case WA_INACTIVE:
            if (g_isFullScreen)
                ShowWindow(hWnd, SW_MINIMIZE);
            g_hasFocus = false;
            break;
        }
        break;

    case WM_CHAR:
        switch (static_cast<int>(wParam))
        {
        case VK_ESCAPE:
                PostMessage(hWnd, WM_CLOSE, 0, 0);
            break;

        case VK_SPACE:
            if (g_enableGL_MULTISAMPLE_ARB = !g_enableGL_MULTISAMPLE_ARB)
                glEnable(GL_MULTISAMPLE_ARB);
            else
                glDisable(GL_MULTISAMPLE_ARB);
          
            break;
        
   
       

        default:
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        g_windowWidth = static_cast<int>(LOWORD(lParam));
        g_windowHeight = static_cast<int>(HIWORD(lParam));
        break;

    case WM_SYSKEYDOWN:
        if (wParam == VK_RETURN)
            ToggleFullScreen();
        break;

    default:
        ProcessMouseInput(hWnd, msg, wParam, lParam);
        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void Cleanup()
{
    CleanupApp();

    if (g_hDC)
    {
        if (g_hRC)
        {
            wglMakeCurrent(g_hDC, 0);
            wglDeleteContext(g_hRC);
            g_hRC = 0;
        }

        ReleaseDC(g_hWnd, g_hDC);
        g_hDC = 0;
    }
}

void CleanupApp()
{



}

HWND CreateAppWindow(const WNDCLASSEX &wcl, const char *pszTitle)
{
    // Create a window that is centered on the desktop. It's exactly 1/4 the
    // size of the desktop. Don't allow it to be resized.

    DWORD wndExStyle = WS_EX_OVERLAPPEDWINDOW;
    DWORD wndStyle   = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    HWND hWnd = CreateWindowEx(wndExStyle, wcl.lpszClassName, pszTitle, wndStyle, 0, 0, 0, 0, 0, 0, wcl.hInstance, 0);

    if (hWnd)
    {
        viewWidth = GetSystemMetrics(SM_CXSCREEN);
        viewHeight = GetSystemMetrics(SM_CYSCREEN);
        
        
        int halfScreenWidth = (int)viewWidth / 2;
        int halfScreenHeight = (int)viewHeight / 2;
        int left = ((int)viewWidth - halfScreenWidth) / 2;
        int top = ((int)viewHeight - halfScreenHeight) / 2;
        RECT rc = {0};

        SetRect(&rc, 0, 0, (int)viewWidth, (int)viewHeight);
        AdjustWindowRectEx(&rc, wndStyle, FALSE, wndExStyle);
        MoveWindow(hWnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);

        GetClientRect(hWnd, &rc);
        g_windowWidth = rc.right - rc.left;
        g_windowHeight = rc.bottom - rc.top;
    }

    return hWnd;
}



void EnableVerticalSync(bool enableVerticalSync)
{
    // WGL_EXT_swap_control.

    typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC)(GLint);

    static PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT =
        reinterpret_cast<PFNWGLSWAPINTERVALEXTPROC>(
        wglGetProcAddress("wglSwapIntervalEXT"));

    if (wglSwapIntervalEXT)
    {
        wglSwapIntervalEXT(enableVerticalSync ? 1 : 0);
        g_enableVerticalSync = enableVerticalSync;
    }
}


float GetElapsedTimeInSeconds()
{
    // Returns the elapsed time (in seconds) since the last time this function
    // was called. This elaborate setup is to guard against large spikes in
    // the time returned by QueryPerformanceCounter().

    static const int MAX_SAMPLE_COUNT = 50;

    static float frameTimes[MAX_SAMPLE_COUNT];
    static float timeScale = 0.0f;
    static float actualElapsedTimeSec = 0.0f;
    static INT64 freq = 0;
    static INT64 lastTime = 0;
    static int sampleCount = 0;
    static bool initialized = false;

    INT64 time = 0;
    float elapsedTimeSec = 0.0f;

    if (!initialized)
    {
        initialized = true;
        QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&freq));
        QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&lastTime));
        timeScale = 1.0f / freq;
    }

    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&time));
    elapsedTimeSec = (time - lastTime) * timeScale;
    lastTime = time;

    if (fabsf(elapsedTimeSec - actualElapsedTimeSec) < 1.0f)
    {
        memmove(&frameTimes[1], frameTimes, sizeof(frameTimes) - sizeof(frameTimes[0]));
        frameTimes[0] = elapsedTimeSec;

        if (sampleCount < MAX_SAMPLE_COUNT)
            ++sampleCount;
    }

    actualElapsedTimeSec = 0.0f;

    for (int i = 0; i < sampleCount; ++i)
        actualElapsedTimeSec += frameTimes[i];

    if (sampleCount > 0)
        actualElapsedTimeSec /= sampleCount;

    return actualElapsedTimeSec;
}


/*
void InitGL()
{
    if (!(g_hDC = GetDC(g_hWnd)))
        throw std::runtime_error("GetDC() failed.");

    int pf = 0;
    PIXELFORMATDESCRIPTOR pfd = {0};
    OSVERSIONINFO osvi = {0};

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (!GetVersionEx(&osvi))
        throw std::runtime_error("GetVersionEx() failed.");

    // When running under Windows Vista or later support desktop composition.
    if (osvi.dwMajorVersion > 6 || (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion >= 0))
        pfd.dwFlags |=  PFD_SUPPORT_COMPOSITION;



    ChooseBestAntiAliasingPixelFormat(pf);



    // It's always a good idea to fall back to a standard pixel format in case
    // MSAA is not supported. Most modern video cards should support some form
    // of MSAA - one exception is older embedded video cards.
    if (!pf)
    {
        pf = ChoosePixelFormat(g_hDC, &pfd);

    }

    if (!SetPixelFormat(g_hDC, pf, &pfd))
        throw std::runtime_error("SetPixelFormat() failed.");

    if (!(g_hRC = wglCreateContext(g_hDC)))
        throw std::runtime_error("wglCreateContext() failed.");

    if (!wglMakeCurrent(g_hDC, g_hRC))
        throw std::runtime_error("wglMakeCurrent() failed.");


}
*/

void Log(const char *pszMessage)
{
    MessageBox(0, pszMessage, "Error", MB_ICONSTOP);
}

void ProcessMouseInput(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Use the left mouse button to track the camera.
    // Use the middle mouse button to dolly the camera.
    // Use the right mouse button to orbit the camera.

    enum CameraMode {CAMERA_NONE, CAMERA_TRACK, CAMERA_DOLLY, CAMERA_ORBIT};

    static CameraMode cameraMode = CAMERA_NONE;
    static POINT ptMousePrev = {0};
    static POINT ptMouseCurrent = {0};
    static int mouseButtonsDown = 0;
    static float dx = 0.0f;
    static float dy = 0.0f;

    switch (msg)
    {
    case WM_LBUTTONDOWN:
        
        leftMouseButton     = true;

        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_RBUTTONDOWN:

        rightMouseButton    = true;

        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_MBUTTONDOWN:
        
        middleMouseButton   = true;
        
        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_MOUSEMOVE:
        ptMouseCurrent.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMouseCurrent.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMouseCurrent);
        //=====================================================================================            
            ptMouseCurrent.x = LOWORD (lParam);
			ptMouseCurrent.y = HIWORD (lParam);
        //=====================================================================================
			
            if( rightMouseButton )
			{
            
            }
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && !keys[VK_CONTROL]  && !keys[VK_SHIFT])
			{
                  Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x)   * .3;
                  Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y)   * .3;
            }
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && keys[VK_CONTROL])
			{
                  Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y)   * .05;
            }                   
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && keys[VK_SHIFT])
			{
                  Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x)   * .01;
                  Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }
            //-------------------------------------------------------------------------------------        
        
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && !keys[VK_CONTROL]  && !keys[VK_SHIFT])
			{
                  Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x)   * .3;
                  Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y)   * .3;
            }
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && keys[VK_CONTROL])
			{
                  Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }                   
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && keys[VK_SHIFT])
			{
                  Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x)   * .01;
                  Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }
            //-------------------------------------------------------------------------------------          
        
        
        
        //=====================================================================================        
            ptMousePrev.x = ptMouseCurrent.x;
            ptMousePrev.y = ptMouseCurrent.y;          
        //=====================================================================================
        break;


    case WM_LBUTTONUP:
        
        leftMouseButton     = false;
        break;
    
    case WM_RBUTTONUP:
        rightMouseButton     = false;
        break;
    
    case WM_MBUTTONUP:
        middleMouseButton     = false;
        break;

    default:
        break;
    }
}

void SetProcessorAffinity()
{
    // Assign the current thread to one processor. This ensures that timing
    // code runs on only one processor, and will not suffer any ill effects
    // from power management.
    //
    // Based on DXUTSetProcessorAffinity() function from the DXUT framework.

    DWORD_PTR dwProcessAffinityMask = 0;
    DWORD_PTR dwSystemAffinityMask = 0;
    HANDLE hCurrentProcess = GetCurrentProcess();

    if (!GetProcessAffinityMask(hCurrentProcess, &dwProcessAffinityMask, &dwSystemAffinityMask))
        return;

    if (dwProcessAffinityMask)
    {
        // Find the lowest processor that our process is allowed to run against.

        DWORD_PTR dwAffinityMask = (dwProcessAffinityMask & ((~dwProcessAffinityMask) + 1));

        // Set this as the processor that our thread must always run against.
        // This must be a subset of the process affinity mask.

        HANDLE hCurrentThread = GetCurrentThread();

        if (hCurrentThread != INVALID_HANDLE_VALUE)
        {
            SetThreadAffinityMask(hCurrentThread, dwAffinityMask);
            CloseHandle(hCurrentThread);
        }
    }

    CloseHandle(hCurrentProcess);
}

void ToggleFullScreen()
{
    static DWORD savedExStyle;
    static DWORD savedStyle;
    static RECT rcSaved;

    g_isFullScreen = !g_isFullScreen;

    if (g_isFullScreen)
    {
        // Moving to full screen mode.

        savedExStyle = GetWindowLong(g_hWnd, GWL_EXSTYLE);
        savedStyle = GetWindowLong(g_hWnd, GWL_STYLE);
        GetWindowRect(g_hWnd, &rcSaved);

        SetWindowLong(g_hWnd, GWL_EXSTYLE, 0);
        SetWindowLong(g_hWnd, GWL_STYLE, WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
        SetWindowPos(g_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED | SWP_SHOWWINDOW);

        g_windowWidth = GetSystemMetrics(SM_CXSCREEN);
        g_windowHeight = GetSystemMetrics(SM_CYSCREEN);

        SetWindowPos(g_hWnd, HWND_TOPMOST, 0, 0,
            g_windowWidth, g_windowHeight, SWP_SHOWWINDOW);
    }
    else
    {
        // Moving back to windowed mode.

        SetWindowLong(g_hWnd, GWL_EXSTYLE, savedExStyle);
        SetWindowLong(g_hWnd, GWL_STYLE, savedStyle);
        SetWindowPos(g_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED | SWP_SHOWWINDOW);

        g_windowWidth = rcSaved.right - rcSaved.left;
        g_windowHeight = rcSaved.bottom - rcSaved.top;

        SetWindowPos(g_hWnd, HWND_NOTOPMOST, rcSaved.left, rcSaved.top, g_windowWidth, g_windowHeight, SWP_SHOWWINDOW);
    }
}

void UpdateFrame(float elapsedTimeSec)
{
    UpdateFrameRate(elapsedTimeSec);
}

void UpdateFrameRate(float elapsedTimeSec)
{
    static float accumTimeSec = 0.0f;
    static int frames = 0;

    accumTimeSec += elapsedTimeSec;

    if (accumTimeSec > 1.0f)
    {
        g_framesPerSecond = frames;

        frames = 0;
        accumTimeSec = 0.0f;
    }
    else
    {
        ++frames;
    }
}

