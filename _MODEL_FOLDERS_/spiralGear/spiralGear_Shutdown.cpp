                    if(spiralGear_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &spiralGear_NORMALMAP);                                                                  
                            spiralGear_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(spiralGear_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &spiralGear_TEXTUREMAP);                                                                 
                            spiralGear_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(spiralGear_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &spiralGear_VBO);                                                                         
                            spiralGear_VBO  = 0;                                                                                         
                    }                                                                                                              
