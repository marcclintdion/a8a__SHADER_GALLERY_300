    glUseProgram(renderMonkeyish_J_SHADER);
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_renderMonkeyish_J, renderMonkeyish_J_LIGHT_POSITION_01[0], renderMonkeyish_J_LIGHT_POSITION_01[1], renderMonkeyish_J_LIGHT_POSITION_01[2], renderMonkeyish_J_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_renderMonkeyish_J, renderMonkeyish_J_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_renderMonkeyish_J, renderMonkeyish_J_ATTENUATION); 
    glUniform1f(UNIFORM_NOISE_SCALE_renderMonkeyish_J, renderMonkeyish_J_NOISE_SCALE);     
                                                                                                                     
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_renderMonkeyish_J,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_renderMonkeyish_J,    1,0,  lightMatrix1);                                                                                                    
    
    glUniform1i (UNIFORM_ANISO_renderMonkeyish_J, 2 );     
    glUniform1i (UNIFORM_TEXTURE_DOT3_renderMonkeyish_J, 1);      
    glUniform1i (UNIFORM_TEXTURE_renderMonkeyish_J, 0 );   



    //---       
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, renderMonkeyish_J_ANISOMAP);
