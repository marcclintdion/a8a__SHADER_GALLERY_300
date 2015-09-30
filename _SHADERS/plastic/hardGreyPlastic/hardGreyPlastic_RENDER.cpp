    glUseProgram(hardGreyPlastic_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //--------------------------------------------------------------------------         
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);    
    //--------------------------------------------------------------------------  
    //------------------------------------------------------------------------------
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_hardGreyPlastic, hardGreyPlastic_LIGHT_POSITION_01[0], hardGreyPlastic_LIGHT_POSITION_01[1], hardGreyPlastic_LIGHT_POSITION_01[2], hardGreyPlastic_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_hardGreyPlastic, hardGreyPlastic_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_hardGreyPlastic, hardGreyPlastic_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_hardGreyPlastic,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_hardGreyPlastic,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_hardGreyPlastic, 1);      
    glUniform1i (UNIFORM_TEXTURE_hardGreyPlastic, 0 );   
