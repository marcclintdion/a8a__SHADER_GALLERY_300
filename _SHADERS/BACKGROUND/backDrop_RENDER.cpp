 glUseProgram(backDrop_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
                                                                                                                                               //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
                                                                                                                                               //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          
          glUniform4f(UNIFORM_LIGHT_POSITION_01_backDrop,          backDrop_LIGHT_POSITION_01[0],                       
                                                                       backDrop_LIGHT_POSITION_01[1],                       
                                                                       backDrop_LIGHT_POSITION_01[2],                       
                                                                       backDrop_LIGHT_POSITION_01[3]);                      

          glUniform4f(UNIFORM_offset_backDrop,                     offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          
          glUniform4f(UNIFORM_tileJump_backDrop,                   tileJump_backDrop[0],                                
                                                                       tileJump_backDrop[1],                                
                                                                       tileJump_backDrop[2],                                
                                                                       tileJump_backDrop[3]);                               
         
          glUniform1f(UNIFORM_ambient_backDrop,                    ambient_backDrop);    
          glUniform1f(UNIFORM_shininess_backDrop,                    shininess_backDrop);                  
          //------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_backDrop,     1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_backDrop, 1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_backDrop, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_backDrop,  1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_backDrop,  1, 0,     textureMatrix);                                       
          //------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_backDrop, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_backDrop,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_backDrop,        0);                                                        
