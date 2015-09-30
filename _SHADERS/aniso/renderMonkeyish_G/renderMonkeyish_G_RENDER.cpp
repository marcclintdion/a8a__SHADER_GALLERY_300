    glUseProgram(renderMonkeyish_G_SHADER);      
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
    glUniform4f(UNIFORM_LIGHT_POSITION_01_renderMonkeyish_G, renderMonkeyish_G_LIGHT_POSITION_01[0], renderMonkeyish_G_LIGHT_POSITION_01[1], renderMonkeyish_G_LIGHT_POSITION_01[2], renderMonkeyish_G_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_renderMonkeyish_G, renderMonkeyish_G_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_renderMonkeyish_G, renderMonkeyish_G_ATTENUATION); 
    glUniform1f(UNIFORM_NOISE_SCALE_renderMonkeyish_G, renderMonkeyish_G_NOISE_SCALE);     
                                                                                                                     
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_renderMonkeyish_G,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_renderMonkeyish_G,    1,0,  lightMatrix1);                                                                                                    
    
    glUniform1i (UNIFORM_ANISO_renderMonkeyish_G, 2 );     
    glUniform1i (UNIFORM_TEXTURE_DOT3_renderMonkeyish_G, 1);      
    glUniform1i (UNIFORM_TEXTURE_renderMonkeyish_G, 0 );   



    //---       
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, renderMonkeyish_G_ANISOMAP);
