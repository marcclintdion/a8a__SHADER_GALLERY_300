    char *ext = (char*)glGetString( GL_EXTENSIONS );

    if( strstr( ext, "GL_ARB_shading_language_100" ) == NULL )
    {
        // This extension string indicates that the OpenGL Shading Language,
        // version 1.00, is supported.
        MessageBox(NULL,"GL_ARB_shading_language_100 extension was not found",
            "ERROR",MB_OK|MB_ICONEXCLAMATION);
       
    }

      
            
              
       glCreateProgramObjectARB                      = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
       glCreateProgram                               = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");       
       glDeleteProgram                               = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
       glDetachShader                                = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader"); 
       glDeleteShader                                = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");     
          
       glUseProgramObjectARB                         = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
       glUseProgram                                  = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
       glCreateShaderObjectARB                       = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
       glCreateShader                                = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");       
       glShaderSource                                = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
       glBindAttribLocation                          = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
       glCompileShader                               = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
       glGetObjectParameterivARB                     = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
       glAttachObjectARB                             = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
       glAttachShader                                = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");      
       glGetInfoLogARB                               = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
       glLinkProgram                                 = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
       glGetUniformLocation                          = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
       glGetAttribLocation                           = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
       glUniform1i			                         = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");      
       glUniform1iARB			                     = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
       glUniform3fARB			                     = (PFNGLUNIFORM3FARBPROC)wglGetProcAddress("glUniform3fARB");       
       //----------------------------------------------------------------------------------------------------------------------
       glUniform1f			                         = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
       glUniform2f			                         = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");        
       glUniform3f			                         = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");        
       glUniform4f			                         = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
       //----------------------------------------------------------------------------------------------------------------------       
       glActiveTextureARB                            = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
       glActiveTexture                            = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");       
       glUniform1fARB                                = (PFNGLUNIFORM1FARBPROC)wglGetProcAddress("glUniform1fARB");       
       glUniform3fvARB                               = (PFNGLUNIFORM3FVARBPROC)wglGetProcAddress("glUniform3fvARB");       
       glUniform4fv                                  = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
       glUniformMatrix4fvARB                         = (PFNGLUNIFORMMATRIX4FVARBPROC)wglGetProcAddress("glUniformMatrix4fvARB");
	   glMultiTexCoord2fARB                          = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
	   glMultiTexCoord3fARB                          = (PFNGLMULTITEXCOORD3FARBPROC)wglGetProcAddress("glMultiTexCoord3fARB");
	   glMultiTexCoord2fvARB                         = (PFNGLMULTITEXCOORD2FVARBPROC)wglGetProcAddress("glMultiTexCoord2fvARB");
	   glMultiTexCoord3fvARB                         = (PFNGLMULTITEXCOORD3FVARBPROC)wglGetProcAddress("glMultiTexCoord3fvARB");                     	   
       glClientActiveTextureARB                      = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");       
       glUniformMatrix4fv	                         = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

       glGenBuffersARB                               = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffersARB");
       glBindBufferARB                               = (PFNGLBINDBUFFERARBPROC)wglGetProcAddress("glBindBufferARB");
       glBufferDataARB                               = (PFNGLBUFFERDATAARBPROC)wglGetProcAddress("glBufferDataARB");
       glBufferSubDataARB                            = (PFNGLBUFFERSUBDATAARBPROC)wglGetProcAddress("glBufferSubDataARB");
       glDeleteBuffersARB                            = (PFNGLDELETEBUFFERSARBPROC)wglGetProcAddress("glDeleteBuffersARB");
       
       glGenBuffers                               = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
       glBindBuffer                               = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
       glBufferData                               = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
       glBufferSubData                            = (PFNGLBUFFERSUBDATAPROC)wglGetProcAddress("glBufferSubData");
       glDeleteBuffers                            = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
              
       //glGenVertexArrays                           = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
       //glBindVertexArray                           =  (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
       glVertexAttribPointer                         = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
       glEnableVertexAttribArray                     = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");

       glGenFramebuffersEXT                          = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffersEXT");
       glDeleteFramebuffersEXT                       = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffersEXT");
       glBindFramebufferEXT                          = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
       glCheckFramebufferStatusEXT                   = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
       glGetFramebufferAttachmentParameterivEXT      = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
       glGenerateMipmapEXT                           = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmapEXT");
       glFramebufferTexture2DEXT                     = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2DEXT");
       glFramebufferRenderbufferEXT                  = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbufferEXT");
       glGenRenderbuffersEXT                         = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffersEXT");
       glDeleteRenderbuffersEXT                      = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffersEXT");
       glBindRenderbufferEXT                         = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbufferEXT");
       glRenderbufferStorageEXT                      = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorageEXT");    

