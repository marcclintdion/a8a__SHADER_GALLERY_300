                    if(flowerShield_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &flowerShield_NORMALMAP);                                                                  
                            flowerShield_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(flowerShield_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &flowerShield_TEXTUREMAP);                                                                 
                            flowerShield_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(flowerShield_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &flowerShield_VBO);                                                                         
                            flowerShield_VBO  = 0;                                                                                         
                    }                                                                                                              
