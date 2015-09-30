glUseProgram(colorRamp_SHADER);      
//================================================================================== 
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelRotation);                                                                                                                                     
    
    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    //Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    //======================================================================================================                
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_colorRamp,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_colorRamp,       1,0,  modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_MODELVIEW_colorRamp,       1,0,  modelRotation);    
    //---------------     
    glUniformMatrix4fv(UNIFORM_viewMatrix_colorRamp,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_colorRamp,     1,0,  ProjectionShadow);   
    glUniformMatrix4fv(UNIFORM_modelViewShadow_colorRamp, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_colorRamp,    1,0,  lightMatrix1);
    glUniformMatrix4fv(UNIFORM_textureMatrix_colorRamp,   1,0,  textureMatrix);  
    
    //---------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_colorRamp, colorRamp_LIGHT_POSITION_01[0], 
                                                     colorRamp_LIGHT_POSITION_01[1], 
                                                     colorRamp_LIGHT_POSITION_01[2], 
                                                     colorRamp_LIGHT_POSITION_01[3]);      
    //---------------------------------------------------------------------------------     
    glUniform2f(UNIFORM_RAMP_XY_COORDS_colorRamp, colorRamp_RAMP_VALUE_XY[0], 
                                                  colorRamp_RAMP_VALUE_XY[1]);    
    //---------------------------------------------------------------------------------      
    glUniform1f(UNIFORM_SHININESS_colorRamp, colorRamp_SHININESS);  
    //---------------------------------------------------------------------------------       
    glUniform1i (UNIFORM_TEXTURE_SHADOW_colorRamp, 3);      
    glUniform1i (UNIFORM_TEXTURE_RAMP_colorRamp,   2);    
    glUniform1i (UNIFORM_TEXTURE_DOT3_colorRamp,   1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_colorRamp,        0);                                                                                                                                 
    //======================================================================================================                                                                  

    glActiveTexture (GL_TEXTURE3);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---         
    glActiveTexture (GL_TEXTURE2);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, RampTexture);                                                                                                                          
    //---     




