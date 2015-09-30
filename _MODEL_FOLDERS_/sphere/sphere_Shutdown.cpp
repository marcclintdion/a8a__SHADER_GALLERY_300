                    if(sphere_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &sphere_NORMALMAP);                                                                  
                            sphere_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(sphere_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &sphere_TEXTUREMAP);                                                                 
                            sphere_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(sphere_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &sphere_VBO);                                                                         
                            sphere_VBO  = 0;                                                                                         
                    }                                                                                                              
