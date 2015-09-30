glUseProgram(sancho_qshaderedit_minnaertWard_SHADER);      
//================================================================================== 
 

    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);                                                                                                                                     
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    InvertMatrix(textureMatrix, mvpMatrix);     
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    //======================================================================================================                
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_sancho_qshaderedit_minnaertWard,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_sancho_qshaderedit_minnaertWard,       1,0,  modelView);                                                                                                          
    //---------------     
    //glUniformMatrix4fv(UNIFORM_viewMatrix_sancho_qshaderedit_minnaertWard,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_sancho_qshaderedit_minnaertWard,     1,0,  ProjectionShadow);   
    //glUniformMatrix4fv(UNIFORM_modelViewShadow_sancho_qshaderedit_minnaertWard, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_sancho_qshaderedit_minnaertWard,    1,0,  lightMatrix1);
    glUniformMatrix4fv(UNIFORM_textureMatrix_sancho_qshaderedit_minnaertWard,   1,0,  textureMatrix);  
    
    //---------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_sancho_qshaderedit_minnaertWard, sancho_qshaderedit_minnaertWard_LIGHT_POSITION_01[0], 
                                                      sancho_qshaderedit_minnaertWard_LIGHT_POSITION_01[1], 
                                                      sancho_qshaderedit_minnaertWard_LIGHT_POSITION_01[2], 
                                                      sancho_qshaderedit_minnaertWard_LIGHT_POSITION_01[3]);      
    //---------------------------------------------------------------------------------     
    
    glUniform1f(UNIFORM_SHININESS_sancho_qshaderedit_minnaertWard, sancho_qshaderedit_minnaertWard_SHININESS);  
    glUniform1f(UNIFORM_GENERIC_sancho_qshaderedit_minnaertWard, sancho_qshaderedit_minnaertWard_GENERIC);      
    
    //---------------------------------------------------------------------------------       
     
    glUniform1i (UNIFORM_TEXTURE_SHADOW_sancho_qshaderedit_minnaertWard, 3);      
    glUniform1i (UNIFORM_TEXTURE_sancho_qshaderedit_minnaertWard_FRESNEL, 2);    
    glUniform1i (UNIFORM_TEXTURE_DOT3_sancho_qshaderedit_minnaertWard, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_sancho_qshaderedit_minnaertWard, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
          
       
    glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---     
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, flowerShield_FRESNELMAP);
    //---     
