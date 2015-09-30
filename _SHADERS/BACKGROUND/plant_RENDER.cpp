 glUseProgram(plant_SHADER);          
          //------------------------------------------------------------------------------|__BUFFERS          
          glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                  
          glEnableVertexAttribArray(0);	                                                                                              
                                                                                                                                               //glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
                                                                                                                                               //glEnableVertexAttribArray(0);	                                                                                          
          glVertexAttribPointer(1,     2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                 
          glEnableVertexAttribArray(1);                                                                                               
          //------------------------------------------------------------------------------|__UNIFORMS                                 
          
          glUniform4f(UNIFORM_LIGHT_POSITION_01_plant,                 plant_LIGHT_POSITION_01[0],                       
                                                                       plant_LIGHT_POSITION_01[1],                       
                                                                       plant_LIGHT_POSITION_01[2],                       
                                                                       plant_LIGHT_POSITION_01[3]);                      

          glUniform4f(UNIFORM_offset_plant,                            offset[0], 
                                                                       offset[1], 
                                                                       offset[2], 
                                                                       offset[3]);                               
                                                                                                       
          
          glUniform4f(UNIFORM_tileJump_plant,                          tileJump_plant[0],                                
                                                                       tileJump_plant[1],                                
                                                                       tileJump_plant[2],                                
                                                                       tileJump_plant[3]);                               
         
          glUniform1f(UNIFORM_ambient_plant,                           ambient_plant);          
          //------------------------------------------------------------------------------|__MATRICES
          glUniformMatrix4fv(UNIFORM_MODELVIEW_plant,     1, 0,         modelView);                                             
          glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_plant, 1, 0,         mvpMatrix);                                   
                                                                                                                                              //glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_plant, 1, 0, ModelViewProjectionInverse);                            
          glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_plant,  1, 0,         lightMatrix);                                           
          glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_plant,  1, 0,       textureMatrix);                                       
          //------------------------------------------------------------------------------|__TEXTURES                                 
          glUniform1i(UNIFORM_TEXTURE_SHADOW_plant, 2);                                                                      
          glUniform1i(UNIFORM_TEXTURE_DOT3_plant,   1);                                                                        
          glUniform1i(UNIFORM_TEXTURE_plant,        0);                                                        
