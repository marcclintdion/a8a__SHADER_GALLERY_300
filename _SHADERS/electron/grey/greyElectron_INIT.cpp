      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      greyElectron_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_greyElectron =                                                                                                        

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
      greyElectron_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(greyElectron_SHADER_VERTEX, 1, &vertexSource_greyElectron, NULL);                                                                        
      glCompileShader(greyElectron_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_greyElectron =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec2    varTexcoord;                                                                            \n"                       

      "     highp  float         NdotL1;                                                                                 \n"                       
      "     highp  vec3          normal;                                                                                 \n"                       
      "     highp vec3           NormalTex;                                                                              \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      //__THIS SHADER_IS_NEGATIVE_LIGHT
      "         gl_FragColor          =  attenuation - (texture2D(Texture1, varTexcoord.st, 0.0) + texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess)) * NdotL1* NdotL1 * attenuation; \n"       
       
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0) * 0.2  \n"      
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* attenuation  \n"      
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.0, 1.0, .1, 1.0);  \n"                       
    
      "         gl_FragColor          =  attenuation - (texture2D(Texture1, varTexcoord.st, 0.0) + texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess)) * NdotL1* NdotL1 * attenuation; \n"       
                 

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      greyElectron_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(greyElectron_SHADER_FRAGMENT, 1, &fragmentSource_greyElectron, NULL);                                                                          
      glCompileShader(greyElectron_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(greyElectron_SHADER, greyElectron_SHADER_VERTEX);                                                                                              
      glAttachShader(greyElectron_SHADER, greyElectron_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(greyElectron_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(greyElectron_SHADER,    1, "normal");       
      glBindAttribLocation(greyElectron_SHADER,    2, "texture");   
      //------------------------------------------------                                                                                              
      glLinkProgram(greyElectron_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(greyElectron_SHADER, greyElectron_SHADER_VERTEX);                                                                                              
      glDetachShader(greyElectron_SHADER, greyElectron_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(greyElectron_SHADER_VERTEX);                                                                                                            
      glDeleteShader(greyElectron_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_greyElectron                   = glGetUniformLocation(greyElectron_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_greyElectron                    = glGetUniformLocation(greyElectron_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_greyElectron               = glGetUniformLocation(greyElectron_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_greyElectron                       = glGetUniformLocation(greyElectron_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_greyElectron                     = glGetUniformLocation(greyElectron_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_greyElectron                    = glGetUniformLocation(greyElectron_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_greyElectron                         = glGetUniformLocation(greyElectron_SHADER,   "Texture1");                    
