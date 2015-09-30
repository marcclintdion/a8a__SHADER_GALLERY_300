    glUseProgram(shinyPlasticInverse_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //--------------------------------------------------------------------------         
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);    
    //--------------------------------------------------------------------------  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_shinyPlasticInverse, shinyPlasticInverse_LIGHT_POSITION_01[0], 
                                                               shinyPlasticInverse_LIGHT_POSITION_01[1], 
                                                               shinyPlasticInverse_LIGHT_POSITION_01[2], 
                                                               shinyPlasticInverse_LIGHT_POSITION_01[3]);        
    
    glUniform4f(UNIFORM_SECOND_SPECULAR_shinyPlasticInverse,   shinyPlasticInverse_SECOND_SPECULAR[0], 
                                                               shinyPlasticInverse_SECOND_SPECULAR[1], 
                                                               shinyPlasticInverse_SECOND_SPECULAR[2], 
                                                               shinyPlasticInverse_SECOND_SPECULAR[3]);
                                                                       
    glUniform1f(UNIFORM_SHININESS_shinyPlasticInverse,         shinyPlasticInverse_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_shinyPlasticInverse,       shinyPlasticInverse_ATTENUATION);                                                                                                                  
    
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_shinyPlasticInverse,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_shinyPlasticInverse,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_shinyPlasticInverse, 1);      
    glUniform1i (UNIFORM_TEXTURE_shinyPlasticInverse, 0 );   
