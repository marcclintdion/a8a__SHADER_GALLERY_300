                    if(sculptris_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &sculptris_NORMALMAP);                                                                  
                            sculptris_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(sculptris_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &sculptris_TEXTUREMAP);                                                                 
                            sculptris_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(sculptris_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &sculptris_VBO);                                                                         
                            sculptris_VBO  = 0;                                                                                         
                    }                                                                                                              
