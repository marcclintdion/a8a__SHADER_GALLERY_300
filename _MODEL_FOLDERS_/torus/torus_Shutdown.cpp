                    if(torus_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &torus_NORMALMAP);                                                                  
                            torus_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(torus_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &torus_TEXTUREMAP);                                                                 
                            torus_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(torus_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &torus_VBO);                                                                         
                            torus_VBO  = 0;                                                                                         
                    }                                                                                                              
