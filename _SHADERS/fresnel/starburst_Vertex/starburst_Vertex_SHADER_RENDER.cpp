glUseProgram(starburst_Vertex_SHADER);      
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
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_starburst_Vertex,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_starburst_Vertex,       1,0,  modelView);                                                                                                          
    glUniformMatrix4fv(UNIFORM_MODELVIEW_starburst_Vertex,       1,0,  modelRotation);    
    //---------------     
    glUniformMatrix4fv(UNIFORM_viewMatrix_starburst_Vertex,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_starburst_Vertex,     1,0,  ProjectionShadow);   
    glUniformMatrix4fv(UNIFORM_modelViewShadow_starburst_Vertex, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_starburst_Vertex,    1,0,  lightMatrix1);
    glUniformMatrix4fv(UNIFORM_textureMatrix_starburst_Vertex,   1,0,  textureMatrix);  
    glUniformMatrix4fv(UNIFORM_reverseModelView_starburst_Vertex,1,0,  reverseModelView);     
    
    
    //-------------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_starburst_Vertex, starburst_Vertex_LIGHT_POSITION_01[0], 
                                                        starburst_Vertex_LIGHT_POSITION_01[1], 
                                                        starburst_Vertex_LIGHT_POSITION_01[2], 
                                                        starburst_Vertex_LIGHT_POSITION_01[3]);      
    //-------------------------------------------------------------------------------------     
    glUniform1f(UNIFORM_SHININESS_starburst_Vertex, starburst_Vertex_SHININESS);  
    
    //------------------------------------------------------------------      
    glUniform1i(UNIFORM_TEXTURE_SHADOW_starburst_Vertex, 3);      
    glUniform1i(UNIFORM_TEXTURE_FRESNEL_starburst_Vertex, 2);     
    glUniform1i(UNIFORM_TEXTURE_DOT3_starburst_Vertex, 1);                                                                                                                             
    glUniform1i(UNIFORM_TEXTURE_starburst_Vertex, 0 );                                                                                                                                 
    //===================================================================================                                                                

    
    glActiveTexture(GL_TEXTURE3);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---     
    glActiveTexture(GL_TEXTURE2);                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, starburst_Vertex_FRESNELMAP);





