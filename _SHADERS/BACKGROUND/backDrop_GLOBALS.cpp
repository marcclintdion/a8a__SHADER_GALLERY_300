                                  //GLfloat     backDrop_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_backDrop                  =   0.175;
                               
                                  //--------------------------------------------------
                                  GLfloat     offset_backDrop[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_backDrop[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      backDrop_SHADER_VERTEX;                                                                                 
                                  GLuint      backDrop_SHADER_FRAGMENT;                                                                               
                                  GLuint      backDrop_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_backDrop;                                                                     
                                  GLuint      UNIFORM_ambient_backDrop;
                                  GLuint      UNIFORM_shininess_backDrop;
                                  GLuint      UNIFORM_counter_backDrop;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_backDrop;                                                                                
                                  GLuint      UNIFORM_tileJump_backDrop;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_backDrop;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_backDrop;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_backDrop;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_backDrop;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_backDrop;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_backDrop;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_backDrop;                                                                          
                                  GLuint      UNIFORM_TEXTURE_backDrop; 
