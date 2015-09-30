    glUseProgram(reflection_SHADER);      
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_reflection, reflection_LIGHT_POSITION_01[0], reflection_LIGHT_POSITION_01[1], reflection_LIGHT_POSITION_01[2], reflection_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_reflection, reflection_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_reflection, reflection_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_reflection,   1,0,  mvpMatrix);
    glUniformMatrix4fv(UNIFORM_MODELVIEW_reflection,       1,0,  modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_reflection,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_reflection, 1);      
    glUniform1i (UNIFORM_TEXTURE_reflection, 0 );  
    
    CUBE_MAPPING_textureID = glGetUniformLocation(reflection_SHADER, "EnvMap"); 
    glUniform1i(CUBE_MAPPING_textureID, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]); 
