    glUseProgram(wood_C_SHADER);      
    //----------------------------------------------------------------------------------------------    
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_wood_C, wood_C_LIGHT_POSITION_01[0], wood_C_LIGHT_POSITION_01[1], wood_C_LIGHT_POSITION_01[2], wood_C_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_wood_C, wood_C_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_wood_C, wood_C_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_wood_C,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_wood_C,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_wood_C, 1);      
    glUniform1i (UNIFORM_TEXTURE_wood_C, 0 );   
