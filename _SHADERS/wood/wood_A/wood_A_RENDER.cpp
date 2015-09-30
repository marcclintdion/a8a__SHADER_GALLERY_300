    glUseProgram(wood_A_SHADER);      
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
    LightPerspectiveMatrix(lightProjection, adjustLightProjectionMatrix, 10, 0.1, 1000);
    MultiplyMatrix(lightMatrix1, lightProjection, modelView);    
    //-------------------------------------
    LoadIdentity(lightMatrix2); 
    InvertMatrix(lightMatrix2, modelView);      
   
    
    //-------------------------------------------------------------------------------------------------------------------------------------------
    glUniform4f(UNIFORM_LIGHT_POSITION_01_wood_A, wood_A_LIGHT_POSITION_01[0], wood_A_LIGHT_POSITION_01[1], wood_A_LIGHT_POSITION_01[2], wood_A_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_wood_A, wood_A_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_wood_A, wood_A_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_wood_A,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_MODELVIEW_wood_A,       1,0,  modelView);     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_1_wood_A,    1,0,  lightMatrix1);                                                                                                    
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_2_wood_A,    1,0,  lightMatrix2);     
    
    UNIFORM_rainbow_FRESNELMAP = glGetUniformLocation(wood_A_SHADER, "RainbowTex"); 
    glUniform1i(UNIFORM_rainbow_FRESNELMAP, 3);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D,  rainbow_FRESNELMAP); 
    
    CUBE_MAPPING_textureID = glGetUniformLocation(wood_A_SHADER, "EnvMap"); 
    glUniform1i(CUBE_MAPPING_textureID, 2);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D,  cubemapTexture[0]); 
    
    glUniform1i (UNIFORM_TEXTURE_DOT3_wood_A, 1);      
    glUniform1i (UNIFORM_TEXTURE_wood_A, 0 ); 
