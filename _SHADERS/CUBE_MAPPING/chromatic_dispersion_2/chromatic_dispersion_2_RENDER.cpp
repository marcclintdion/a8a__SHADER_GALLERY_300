    glUseProgram(chromatic_dispersion_2_SHADER);      
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_chromatic_dispersion_2, chromatic_dispersion_2_LIGHT_POSITION_01[0], chromatic_dispersion_2_LIGHT_POSITION_01[1], chromatic_dispersion_2_LIGHT_POSITION_01[2], chromatic_dispersion_2_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_chromatic_dispersion_2, chromatic_dispersion_2_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_chromatic_dispersion_2, chromatic_dispersion_2_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_chromatic_dispersion_2,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_chromatic_dispersion_2,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_chromatic_dispersion_2, 1);      
    glUniform1i (UNIFORM_TEXTURE_chromatic_dispersion_2, 0 );  
    
    CUBE_MAPPING_textureID = glGetUniformLocation(chromatic_dispersion_2_SHADER, "EnvMap"); 
    glUniform1i(CUBE_MAPPING_textureID, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]); 
