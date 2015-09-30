                                  //GLfloat     plant_LIGHT_POSITION_01[]      =  {0, 2.39002, 0, 1.0};//----------------QUADRATRIC_ATTENUATION
                                  //GLfloat     ambient_plant                  =   0.175;
                              
                                  
                                  //--------------------------------------------------
                                  GLfloat     offset_plant[]                 = { 0.0,  0.0,  0.0,  1.0};                                           
                                  GLfloat     tileJump_plant[]               = { 0.0,  0.0,  0.0,  1.0};                                           
                                  //=====================================================================================|_SHADER
                                  GLuint      plant_SHADER_VERTEX;                                                                                 
                                  GLuint      plant_SHADER_FRAGMENT;                                                                               
                                  GLuint      plant_SHADER;     
                                  //-------------------------------------------------------------------------------------|_CONFIGURABLE_UNIFORMS
                                  GLuint      UNIFORM_LIGHT_POSITION_01_plant;                                                                     
                                  GLuint      UNIFORM_ambient_plant;
                                  GLuint      UNIFORM_counter_plant;                                                                               
                                  //-------------------------------------------------------------------------------------|_CORRECTION_UNIFORMS
                                  GLuint      UNIFORM_offset_plant;                                                                                
                                  GLuint      UNIFORM_tileJump_plant;                                                                              
                                  //-------------------------------------------------------------------------------------|_MATRIX_UNIFORMS
                                  GLuint      UNIFORM_MODELVIEW_plant;                                                                             
                                  GLuint      UNIFORM_MODELVIEWPROJ_plant;                                                                         
                                  //GLuint    UNIFORM_MODELVIEWPROJ_INVERSE_plant;                                                                 
                                  GLuint      UNIFORM_LIGHT_MATRIX_plant;                                                                          
                                  GLuint      UNIFORM_TEXTURE_MATRIX_plant;                                                                        
                                  //-------------------------------------------------------------------------------------|_TEXTURE_UNIFORMS
                                  GLuint      UNIFORM_TEXTURE_SHADOW_plant;                                                                        
                                  GLuint      UNIFORM_TEXTURE_DOT3_plant;                                                                          
                                  GLuint      UNIFORM_TEXTURE_plant; 
