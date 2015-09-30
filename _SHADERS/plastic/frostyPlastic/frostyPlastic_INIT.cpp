    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      frostyPlastic_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_frostyPlastic =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    varying highp vec4  diffuse;                                                                        \n"
      "    varying highp vec4  ambient;                                                                        \n"      
      "    varying highp vec4  ambientGlobal;                                                                  \n"
      "    varying highp float dist;                                                                           \n"
      "            highp vec4  ecPos;                                                                          \n"
      "            highp vec3  aux;                                                                            \n"

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "     ecPos                   = mvpMatrix * position;                                                    \n"
      "     aux                     = vec3(light_POSITION_01 - ecPos);                                         \n"
      "     dist                    = length(aux);                                                             \n"

      "     diffuse                 = vec4( 0.00,  1.0,  1.00, 1.0)  * vec4(1.0, 48.6, 1.0, 1.0);              \n"
      "     ambient                 = vec4(-1.75, -1.75, 0.0,  1.0)  * vec4(1.1, 26.1, 1.1, 1.0);              \n"
      "     ambientGlobal           =  vec4(-1.75, -1.75, 0.0, 1.0);                                           \n"
    
      "     lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      frostyPlastic_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(frostyPlastic_SHADER_VERTEX, 1, &vertexSource_frostyPlastic, NULL);                                                                        
      glCompileShader(frostyPlastic_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_frostyPlastic =                                                                                                            

     
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
      "    varying highp vec4    ambient;                                                                                \n"        
      "    varying highp vec4    ambientGlobal;                                                                          \n"
      "    varying highp float   dist;                                                                                   \n"

      "            highp vec4    color;                                                                                  \n"
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

     
      "         color                 =  ambientGlobal + (0.7 * (diffuse * NdotL1 + ambient* NdotL1));                   \n"
      "         color                +=  vec4(1.0, 1.0, 1.0, 1.0) * pow(NdotL1, 45.2) * 0.8;                             \n"
    
      "         color                +=  vec4(1.0, 1.0, 1.0, 1.0) * pow(NdotL1, shininess) * 0.8;                        \n"    
      
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st)  *color * attenuation                       \n"   
      "                               +(1.0 - NdotL1) * 0.1;                                                             \n"                    

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      frostyPlastic_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(frostyPlastic_SHADER_FRAGMENT, 1, &fragmentSource_frostyPlastic, NULL);                                                                          
      glCompileShader(frostyPlastic_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(frostyPlastic_SHADER, frostyPlastic_SHADER_VERTEX);                                                                                              
      glAttachShader(frostyPlastic_SHADER, frostyPlastic_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(frostyPlastic_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(frostyPlastic_SHADER,    1, "normal");       
      glBindAttribLocation(frostyPlastic_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(frostyPlastic_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(frostyPlastic_SHADER, frostyPlastic_SHADER_VERTEX);                                                                                              
      glDetachShader(frostyPlastic_SHADER, frostyPlastic_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(frostyPlastic_SHADER_VERTEX);                                                                                                            
      glDeleteShader(frostyPlastic_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_frostyPlastic                   = glGetUniformLocation(frostyPlastic_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_frostyPlastic                    = glGetUniformLocation(frostyPlastic_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_frostyPlastic               = glGetUniformLocation(frostyPlastic_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_frostyPlastic                       = glGetUniformLocation(frostyPlastic_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_frostyPlastic                     = glGetUniformLocation(frostyPlastic_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_frostyPlastic                    = glGetUniformLocation(frostyPlastic_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_frostyPlastic                         = glGetUniformLocation(frostyPlastic_SHADER,   "Texture1");                                   
