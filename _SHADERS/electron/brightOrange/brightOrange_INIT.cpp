      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      brightOrange_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_brightOrange =                                                                                                        

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
      brightOrange_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(brightOrange_SHADER_VERTEX, 1, &vertexSource_brightOrange, NULL);                                                                        
      glCompileShader(brightOrange_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_brightOrange =                                                                                                            

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

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * 0.0                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.5, 1.0, .1, 1.0)*attenuation ;              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      brightOrange_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(brightOrange_SHADER_FRAGMENT, 1, &fragmentSource_brightOrange, NULL);                                                                          
      glCompileShader(brightOrange_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(brightOrange_SHADER, brightOrange_SHADER_VERTEX);                                                                                              
      glAttachShader(brightOrange_SHADER, brightOrange_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(brightOrange_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(brightOrange_SHADER,    1, "normal");       
      glBindAttribLocation(brightOrange_SHADER,    2, "texture");                                                                                          
      //------------------------------------------------                                                                                              
      glLinkProgram(brightOrange_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(brightOrange_SHADER, brightOrange_SHADER_VERTEX);                                                                                              
      glDetachShader(brightOrange_SHADER, brightOrange_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(brightOrange_SHADER_VERTEX);                                                                                                            
      glDeleteShader(brightOrange_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_brightOrange                   = glGetUniformLocation(brightOrange_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_brightOrange                    = glGetUniformLocation(brightOrange_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_brightOrange               = glGetUniformLocation(brightOrange_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_brightOrange                       = glGetUniformLocation(brightOrange_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_brightOrange                     = glGetUniformLocation(brightOrange_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_brightOrange                    = glGetUniformLocation(brightOrange_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_brightOrange                         = glGetUniformLocation(brightOrange_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
