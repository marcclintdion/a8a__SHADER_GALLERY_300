    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      dullPlastic_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_dullPlastic =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix1;                                                                   \n"                           

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

      "     ecPos                   = mvpMatrix * position;                                                    \n"
      "     aux                     = vec3(light_POSITION_01 - ecPos);                                         \n"
      "     dist                    = length(aux);                                                             \n"

      "     diffuse                 = vec4(  -1.925, 2.925 , 1.0, 1.0);                                      \n"
      "     ambientGlobal           =  vec4(-1.75, -1.75, 0.0, 1.0);                                           \n"      
     
      "     lightPosition_PASS      = normalize(lightMatrix1 * light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      dullPlastic_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(dullPlastic_SHADER_VERTEX, 1, &vertexSource_dullPlastic, NULL);                                                                        
      glCompileShader(dullPlastic_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_dullPlastic =                                                                                                            

     
     
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
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         att                   =  1.0 / attenuation;                                                              \n"
      "         color                 =  (ambientGlobal + (att * diffuse))* NdotL1;                                                \n"
      "         color                +=  vec4(1.0, 1.0, 1.0, 1.0) * (att + pow(NdotL1, 500.2* NdotL1));                                                      \n"

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st) * att * color* NdotL1;                      \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      dullPlastic_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(dullPlastic_SHADER_FRAGMENT, 1, &fragmentSource_dullPlastic, NULL);                                                                          
      glCompileShader(dullPlastic_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(dullPlastic_SHADER, dullPlastic_SHADER_VERTEX);                                                                                              
      glAttachShader(dullPlastic_SHADER, dullPlastic_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(dullPlastic_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(dullPlastic_SHADER,    1, "normal");       
      glBindAttribLocation(dullPlastic_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(dullPlastic_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(dullPlastic_SHADER, dullPlastic_SHADER_VERTEX);                                                                                              
      glDetachShader(dullPlastic_SHADER, dullPlastic_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(dullPlastic_SHADER_VERTEX);                                                                                                            
      glDeleteShader(dullPlastic_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_dullPlastic                   = glGetUniformLocation(dullPlastic_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_dullPlastic                    = glGetUniformLocation(dullPlastic_SHADER,   "lightMatrix1");                                            
      UNIFORM_LIGHT_POSITION_01_dullPlastic               = glGetUniformLocation(dullPlastic_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_dullPlastic                       = glGetUniformLocation(dullPlastic_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_dullPlastic                     = glGetUniformLocation(dullPlastic_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_dullPlastic                    = glGetUniformLocation(dullPlastic_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_dullPlastic                         = glGetUniformLocation(dullPlastic_SHADER,   "Texture1");                                   
