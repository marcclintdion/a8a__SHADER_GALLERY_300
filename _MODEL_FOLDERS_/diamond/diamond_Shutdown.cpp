                    if(capsule_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &capsule_NORMALMAP);                                                                  
                            capsule_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(capsule_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &capsule_TEXTUREMAP);                                                                 
                            capsule_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(capsule_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &capsule_VBO);                                                                         
                            capsule_VBO  = 0;                                                                                         
                    }                                                                                                              
