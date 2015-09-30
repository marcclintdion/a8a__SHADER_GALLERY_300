 glUseProgram(wood_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
                                                                                                                                               //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
                                                                                                                                               //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          
          glUniform4f(UNIFORM_LIGHT_POSITION_01_wood,          wood_LIGHT_POSITION_01[0],                       
                                                                       wood_LIGHT_POSITION_01[1],                       
                                                                       wood_LIGHT_POSITION_01[2],                       
                                                                       wood_LIGHT_POSITION_01[3]);                      

          glUniform4f(UNIFORM_offset_wood,                     offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          
          glUniform4f(UNIFORM_tileJump_wood,                   tileJump_wood[0],                                
                                                                       tileJump_wood[1],                                
                                                                       tileJump_wood[2],                                
                                                                       tileJump_wood[3]);                               
         
          glUniform1f(UNIFORM_ambient_wood,                    ambient_wood);    
          glUniform1f(UNIFORM_shininess_wood,                    shininess_wood);  
          glUniform1f(UNIFORM_attenuation_SHINY_wood,                    attenuation_SHINY_wood);           
          glUniform1f(UNIFORM_counter_wood,                    globalLinearAttenuation);                            
          //------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_wood,     1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_wood, 1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_wood, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_wood,  1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_wood,  1, 0,     textureMatrix);                                       
          //------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_wood, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_wood,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_wood,        0);                                                        
