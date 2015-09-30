glUseProgram(greenPlasma_SHADER);      
//================================================================================== 
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //-------------------------------------------------------------------------------------------------------
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);                                                                                                                                     
    //-------------------------------------------------------------------------------------------------------
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    //Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   
    //=======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    //====================================================================================               
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_greenPlasma,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_greenPlasma,       1,0,  modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_MODELVIEW_greenPlasma,       1,0,  modelRotation);    
    //---------------     
    glUniformMatrix4fv(UNIFORM_viewMatrix_greenPlasma,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_greenPlasma,     1,0,  ProjectionShadow);   
    glUniformMatrix4fv(UNIFORM_modelViewShadow_greenPlasma, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_greenPlasma,    1,0,  lightMatrix1);
    glUniformMatrix4fv(UNIFORM_textureMatrix_greenPlasma,   1,0,  textureMatrix);  
    glUniformMatrix4fv(UNIFORM_reverseModelView_greenPlasma,1,0,  reverseModelView);     
    
    
    //-------------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_greenPlasma, greenPlasma_LIGHT_POSITION_01[0], 
                                                        greenPlasma_LIGHT_POSITION_01[1], 
                                                        greenPlasma_LIGHT_POSITION_01[2], 
                                                        greenPlasma_LIGHT_POSITION_01[3]);      
    //-------------------------------------------------------------------------------------     
    glUniform1f(UNIFORM_SHININESS_greenPlasma, greenPlasma_SHININESS);  
    
    //------------------------------------------------------------------      
    glUniform1i(UNIFORM_TEXTURE_SHADOW_greenPlasma, 3);      
    glUniform1i(UNIFORM_TEXTURE_FRESNEL_greenPlasma, 2);     
    glUniform1i(UNIFORM_TEXTURE_DOT3_greenPlasma, 1);                                                                                                                             
    glUniform1i(UNIFORM_TEXTURE_greenPlasma, 0 );                                                                                                                                 
    //===================================================================================                                                                

    
    glActiveTexture(GL_TEXTURE3);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---     
    glActiveTexture(GL_TEXTURE2);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, greenPlasma_FRESNELMAP);





