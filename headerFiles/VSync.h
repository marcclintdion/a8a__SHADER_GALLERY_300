/* File: VSync.h; Mode: C++; Tab-width: 3; Author: Simon Flannery;           */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <GL/gl.h>

typedef void (APIENTRY *PFNWGLEXTSWAPCONTROLPROC) (int);
typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);
 
PFNWGLEXTSWAPCONTROLPROC     wglSwapIntervalEXT    = NULL;
PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = NULL;

void SetVSyncState(bool enable)
{
   static bool first = true;

   if (first != false)
   {
      wglSwapIntervalEXT = (PFNWGLEXTSWAPCONTROLPROC) wglGetProcAddress("wglSwapIntervalEXT");
      first = false;
   }

   if (wglSwapIntervalEXT != NULL)
   {
      if (enable == false)
      {
         wglSwapIntervalEXT(0);
      }
      else
      {
         wglSwapIntervalEXT(1);
      }
   }

   return;
}

bool GetVSyncState()
{
   static bool first = true;

   if (first != false)
   {
      wglGetSwapIntervalEXT = (PFNWGLEXTGETSWAPINTERVALPROC) wglGetProcAddress("wglGetSwapIntervalEXT");
      first = false;
   }

   if (wglSwapIntervalEXT != NULL)
   {
      return wglGetSwapIntervalEXT() > 0;
   }

   return true; /* ...else VSync is on! */
}
