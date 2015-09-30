      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      spiralGear_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_spiralGear =                                                                                                        

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
      spiralGear_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(spiralGear_SHADER_VERTEX, 1, &vertexSource_spiralGear, NULL);                                                                        
      glCompileShader(spiralGear_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_spiralGear =                                                                                                            

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
      spiralGear_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(spiralGear_SHADER_FRAGMENT, 1, &fragmentSource_spiralGear, NULL);                                                                          
      glCompileShader(spiralGear_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(spiralGear_SHADER, spiralGear_SHADER_VERTEX);                                                                                              
      glAttachShader(spiralGear_SHADER, spiralGear_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(spiralGear_SHADER, 0, "position");                                                                                            
      glBindAttribLocation(spiralGear_SHADER, 1, "texture");                                                                                             
      //glBindAttribLocation(spiralGear _SHADER, 2, "normal");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(spiralGear_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(spiralGear_SHADER, spiralGear_SHADER_VERTEX);                                                                                              
      glDetachShader(spiralGear_SHADER, spiralGear_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(spiralGear_SHADER_VERTEX);                                                                                                            
      glDeleteShader(spiralGear_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_spiralGear                   = glGetUniformLocation(spiralGear_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_spiralGear                    = glGetUniformLocation(spiralGear_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_spiralGear               = glGetUniformLocation(spiralGear_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_spiralGear                       = glGetUniformLocation(spiralGear_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_spiralGear                     = glGetUniformLocation(spiralGear_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_spiralGear                    = glGetUniformLocation(spiralGear_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_spiralGear                         = glGetUniformLocation(spiralGear_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"spiralGear_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &spiralGear_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, spiralGear_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"spiralGear" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &spiralGear_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, spiralGear_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/spiralGear/spiralGear_DOT3.bmp",          spiralGear_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/spiralGear/spiralGear.png",               spiralGear_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "spiralGear.cpp"                                                                                                                
      glGenBuffers(1,              &spiralGear_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, spiralGear_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(spiralGear), spiralGear, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------//___LOAD_INDEX_VBO          
      #include    "spiralGear_INDEX.cpp"       
      glGenBuffers(1, &spiralGear_INDEX_VBO);                       
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, spiralGear_INDEX_VBO);                   
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(spiralGear_INDEX), spiralGear_INDEX, GL_STATIC_DRAW);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);      
      //=================================================================================================================================   


