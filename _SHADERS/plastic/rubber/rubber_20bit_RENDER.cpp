    glUseProgram(rubber_20bit_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //--------------------------------------------------------------------------         
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);    
    //--------------------------------------------------------------------------      
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   2, GL_FLOAT, GL_FALSE, 20, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_rubber_20bit, rubber_20bit_LIGHT_POSITION_01[0], rubber_20bit_LIGHT_POSITION_01[1], rubber_20bit_LIGHT_POSITION_01[2], rubber_20bit_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_rubber_20bit, rubber_20bit_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_rubber_20bit, rubber_20bit_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_rubber_20bit,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_rubber_20bit,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_rubber_20bit, 1);      
    glUniform1i (UNIFORM_TEXTURE_rubber_20bit, 0 );   
