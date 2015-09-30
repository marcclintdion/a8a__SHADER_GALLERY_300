    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      shinyPlastic_05_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_shinyPlastic_05 =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    varying highp vec4  diffuse;                                                                        \n"
      "    varying highp vec4  ambientGlobal;                                                                  \n"
      "    varying highp float dist;                                                                           \n"
      "            highp vec4  ecPos;                                                                          \n"
      "            highp vec3  aux;                                                                            \n"

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "        ecPos                 = mvpMatrix * position;                                                   \n"
      "        aux                   = vec3(light_POSITION_01 - ecPos);                                        \n"
      "        dist                  = length(aux);                                                            \n"

      "        diffuse               = highp  vec4(  -1.925, 2.925 , 2.925, 1.0);                              \n"
      "        ambientGlobal         = highp  vec4(-1.75, -1.75, 0.0, 1.0);                                    \n"      
     
      "        lightPosition_PASS    = normalize(lightMatrix * light_POSITION_01);                             \n"                           
      "        varTexcoord           = texture;                                                                \n"                           
      "        gl_Position           = mvpMatrix * position;                                                   \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      shinyPlastic_05_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(shinyPlastic_05_SHADER_VERTEX, 1, &vertexSource_shinyPlastic_05, NULL);                                                                        
      glCompileShader(shinyPlastic_05_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_shinyPlastic_05 =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"   
    
      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec2    varTexcoord;                                                                            \n"                       

      "            highp float   NdotL1;                                                                                 \n"                       
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    NormalTex;                                                                              \n"                       

      "    varying highp vec4    diffuse;                                                                                \n"
      "    varying highp vec4    ambientGlobal;                                                                          \n"
      "    varying highp float   dist;                                                                                   \n"

      "            highp float   att;                                                                                    \n"
      "            highp vec4    color;                                                                                  \n"
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                  \n"                       

      "         att                   =  1.0 / attenuation;                                                              \n"
      "         color                 =  ambientGlobal + (att * diffuse);                                                \n"
      "         color                +=  highp vec4(1.0, 1.0, 1.0, 1.0) * pow(NdotL1, 100.2);                            \n"

      "         gl_FragColor          = texture2D(Texture1, varTexcoord.st) * att * color * NdotL1;                      \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      shinyPlastic_05_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(shinyPlastic_05_SHADER_FRAGMENT, 1, &fragmentSource_shinyPlastic_05, NULL);                                                                          
      glCompileShader(shinyPlastic_05_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(shinyPlastic_05_SHADER, shinyPlastic_05_SHADER_VERTEX);                                                                                              
      glAttachShader(shinyPlastic_05_SHADER, shinyPlastic_05_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(shinyPlastic_05_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(shinyPlastic_05_SHADER,    1, "normal");       
      glBindAttribLocation(shinyPlastic_05_SHADER,    2, "texture");                                                                                          
      //------------------------------------------------                                                                                              
      glLinkProgram(shinyPlastic_05_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(shinyPlastic_05_SHADER, shinyPlastic_05_SHADER_VERTEX);                                                                                              
      glDetachShader(shinyPlastic_05_SHADER, shinyPlastic_05_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(shinyPlastic_05_SHADER_VERTEX);                                                                                                            
      glDeleteShader(shinyPlastic_05_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_shinyPlastic_05                   = glGetUniformLocation(shinyPlastic_05_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_shinyPlastic_05                    = glGetUniformLocation(shinyPlastic_05_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_shinyPlastic_05               = glGetUniformLocation(shinyPlastic_05_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_shinyPlastic_05                       = glGetUniformLocation(shinyPlastic_05_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_shinyPlastic_05                     = glGetUniformLocation(shinyPlastic_05_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_shinyPlastic_05                    = glGetUniformLocation(shinyPlastic_05_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_shinyPlastic_05                         = glGetUniformLocation(shinyPlastic_05_SHADER,   "Texture1");                                   
