 
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      #ifdef __APPLE__                                                                                                                          
     
      filePathName = [[NSBundle mainBundle] pathForResource:@"sculptris_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &sculptris_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, sculptris_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"sculptris" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &sculptris_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, sculptris_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/sculptris/sculptris_DOT3.bmp",          sculptris_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/sculptris/sculptris.png",               sculptris_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "sculptris.cpp"                                                                                                                
      glGenBuffers(1,              &sculptris_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, sculptris_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(sculptris), sculptris, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------//___LOAD_INDEX_VBO          
      #include    "sculptris_INDEX.cpp" 
      glGenBuffers(1, &sculptris_INDEX_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sculptris_INDEX_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sculptris_INDEX), sculptris_INDEX, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
      //=================================================================================================================================       
