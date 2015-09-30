    glUseProgram(aluminum_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //----------------------------------------------------------------------------------------------    
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    LoadIdentity(lightMatrix1); 
    LoadIdentity(lightProjection);                                                                                                                                                
    PerspectiveMatrix(lightProjection, adjustLightProjectionMatrix, 10, 0.1, 1000);
    //RotateZ(lightProjection, 45);    
    MultiplyMatrix(lightMatrix1, lightProjection, modelView);    
    InvertMatrix(lightMatrix1, lightMatrix1); 
    //-------------------------------------
    LoadIdentity(lightMatrix2); 
    InvertMatrix(lightMatrix2, modelView);      
    //-------------------------------------------------------------------------------------------------------------------------------------------
    glUniform4f(UNIFORM_LIGHT_POSITION_01_aluminum, aluminum_LIGHT_POSITION_01[0], 
                                                    aluminum_LIGHT_POSITION_01[1], 
                                                    aluminum_LIGHT_POSITION_01[2], 
                                                    aluminum_LIGHT_POSITION_01[3]);        
    
    glUniform1f(UNIFORM_SHININESS_aluminum,              aluminum_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_aluminum,            aluminum_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_aluminum,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_MODELVIEW_aluminum,       1,0,  modelView);     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_1_aluminum,  1,0,  lightMatrix1);                                                                                                    
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_2_aluminum,  1,0,  lightMatrix2);     
    

    glUniform1i (UNIFORM_TEXTURE_aluminum_FRESNEL, 2); 
    glUniform1i (UNIFORM_TEXTURE_DOT3_aluminum, 1);      
    glUniform1i (UNIFORM_TEXTURE_aluminum, 0 ); 
    //--- ---------------------------------------------------------------------------------
          
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_FRESNELMAP);
