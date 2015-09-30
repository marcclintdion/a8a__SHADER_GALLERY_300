
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"sphere_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &sphere_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, sphere_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"sphere" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &sphere_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, sphere_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/sphere/sphere_DOT3.bmp",          sphere_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/sphere/sphere.png",               sphere_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "sphere.cpp"                                                                                                                
      glGenBuffers(1,              &sphere_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, sphere_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------//___LOAD_INDEX_VBO          
      #include    "sphere_INDEX.cpp"       
      glGenBuffers(1, &sphere_INDEX_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphere_INDEX_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sphere_INDEX), sphere_INDEX, GL_STATIC_DRAW);
    
      //=================================================================================================================================   
