                                  //GLfloat     wood_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_wood                  =   0.175;
                               
                                  //--------------------------------------------------
                                  GLfloat     offset_wood[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_wood[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      wood_SHADER_VERTEX;                                                                                 
                                  GLuint      wood_SHADER_FRAGMENT;                                                                               
                                  GLuint      wood_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_wood;                                                                     
                                  GLuint      UNIFORM_ambient_wood;
                                  GLuint      UNIFORM_attenuation_SHINY_wood;                                  
                                  GLuint      UNIFORM_shininess_wood;
                                  GLuint      UNIFORM_counter_wood;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_wood;                                                                                
                                  GLuint      UNIFORM_tileJump_wood;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_wood;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_wood;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_wood;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_wood;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_wood;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_wood;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_wood;                                                                          
                                  GLuint      UNIFORM_TEXTURE_wood; 
