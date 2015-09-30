    glUseProgram(shinyPlasticCellShade_SHADER);      
    //-----------------------------------------------
    MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //--------------------------------------------------------------------------         
    LoadIdentity(lightMatrix1);                                                                                                                                                
    InvertMatrix(lightMatrix1, modelView);    
    //--------------------------------------------------------------------------  
    //--------------------------------------------------------------------------------------------------------  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                             
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_shinyPlasticCellShade, shinyPlasticCellShade_LIGHT_POSITION_01[0], 
                                                                 shinyPlasticCellShade_LIGHT_POSITION_01[1], 
                                                                 shinyPlasticCellShade_LIGHT_POSITION_01[2], 
                                                                 shinyPlasticCellShade_LIGHT_POSITION_01[3]);        
    
    glUniform4f(UNIFORM_SECOND_SPECULAR_shinyPlasticCellShade,   shinyPlasticCellShade_SECOND_SPECULAR[0], 
                                                                 shinyPlasticCellShade_SECOND_SPECULAR[1], 
                                                                 shinyPlasticCellShade_SECOND_SPECULAR[2], 
                                                                 shinyPlasticCellShade_SECOND_SPECULAR[3]);
                                                               
    glUniform1f(UNIFORM_SHININESS_shinyPlasticCellShade,         shinyPlasticCellShade_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_shinyPlasticCellShade,       shinyPlasticCellShade_ATTENUATION);                                                                                                                  
    
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_shinyPlasticCellShade,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_shinyPlasticCellShade,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_shinyPlasticCellShade, 1);      
    glUniform1i (UNIFORM_TEXTURE_shinyPlasticCellShade, 0 );   
