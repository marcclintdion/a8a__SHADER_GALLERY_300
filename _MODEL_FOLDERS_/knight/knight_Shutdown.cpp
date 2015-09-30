                    if(knight_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &knight_NORMALMAP);                                                                  
                            knight_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(knight_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &knight_TEXTUREMAP);                                                                 
                            knight_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(knight_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &knight_VBO);                                                                         
                            knight_VBO  = 0;                                                                                         
                    }                                                                                                              
