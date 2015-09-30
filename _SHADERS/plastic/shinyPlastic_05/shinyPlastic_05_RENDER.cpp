    glUseProgram(shinyPlastic_05_SHADER);      
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_shinyPlastic_05, shinyPlastic_05_LIGHT_POSITION_01[0], shinyPlastic_05_LIGHT_POSITION_01[1], shinyPlastic_05_LIGHT_POSITION_01[2], shinyPlastic_05_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_shinyPlastic_05, shinyPlastic_05_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_shinyPlastic_05, shinyPlastic_05_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_shinyPlastic_05,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_shinyPlastic_05,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_shinyPlastic_05, 1);      
    glUniform1i (UNIFORM_TEXTURE_shinyPlastic_05, 0 );   
