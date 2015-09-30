      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      knight_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_knight =                                                                                                        

      "    #define highp                                                                                     \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                           \n"                           
      "    uniform         mat4   mvpMatrix;                                                                   \n"                           
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                          \n"                           
      "    varying highp vec2   varTexcoord;                                                                 \n"                           


      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        lightPosition_PASS = normalize(lightMatrix * light_POSITION_01);                                \n"                           

      "        varTexcoord        = texture;                                                                   \n"                           

      "        gl_Position        = mvpMatrix * position;                                                      \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      knight_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(knight_SHADER_VERTEX, 1, &vertexSource_knight, NULL);                                                                        
      glCompileShader(knight_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_knight =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  float         NdotL1;                                                                               \n"                       
      "     highp  vec3          normal;                                                                               \n"                       
      "     highp vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * .2                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      knight_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(knight_SHADER_FRAGMENT, 1, &fragmentSource_knight, NULL);                                                                          
      glCompileShader(knight_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(knight_SHADER, knight_SHADER_VERTEX);                                                                                              
      glAttachShader(knight_SHADER, knight_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(knight_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(knight_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(knight _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(knight_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(knight_SHADER, knight_SHADER_VERTEX);                                                                                              
      glDetachShader(knight_SHADER, knight_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(knight_SHADER_VERTEX);                                                                                                            
      glDeleteShader(knight_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_knight                   = glGetUniformLocation(knight_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_knight                    = glGetUniformLocation(knight_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_knight               = glGetUniformLocation(knight_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_knight                       = glGetUniformLocation(knight_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_knight                     = glGetUniformLocation(knight_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_knight                    = glGetUniformLocation(knight_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_knight                         = glGetUniformLocation(knight_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"knight_DOT3" ofType:@"png"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &knight_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, knight_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"knight" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &knight_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, knight_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/knight/knight_DOT3.png",          knight_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/knight/knight.png",               knight_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "knight.cpp"                                                                                                                
      glGenBuffers(1,              &knight_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, knight_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(knight), knight, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------//___LOAD_INDEX_VBO          
      #include    "knight_INDICES.cpp"       
      glGenBuffers(1, &knight_INDICES_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, knight_INDICES_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(knight_INDICES), knight_INDICES, GL_STATIC_DRAW);
      //=================================================================================================================================   



