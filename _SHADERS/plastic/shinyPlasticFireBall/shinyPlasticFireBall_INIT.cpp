    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      shinyPlasticFireBall_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_shinyPlasticFireBall =                                                                                                        

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
   

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "     diffuse                 = vec4( 0.00,  1.0,   1.00, 1.0)  * vec4(1.0, 48.6, 1.0, 1.0);              \n"
      "     ambient                 = vec4(-2.75, -2.75, -2.75,  1.0)  * vec4(1.1, 26.1, 1.1, 1.0);              \n"
      "     ambientGlobal           = vec4(-1.75, -1.75, -1.75, 1.0);                                            \n"
    
  
      "     lightPosition_PASS      = lightMatrix * normalize(light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      shinyPlasticFireBall_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(shinyPlasticFireBall_SHADER_VERTEX, 1, &vertexSource_shinyPlasticFireBall, NULL);                                                                        
      glCompileShader(shinyPlasticFireBall_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_shinyPlasticFireBall =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                        

      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp vec4    secondSpecular;                                                                         \n"      
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

      "            highp float   att;                                                                                    \n"
      "            highp vec4    color;                                                                                  \n"
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       

      "         att                   =  1.0 / attenuation;                                                              \n"
      
      "         color                 =  ambientGlobal / ((diffuse * NdotL1 + ambient)) ;                                \n"
      "         color                +=  secondSpecular * pow(NdotL1, 16.26)*.15 ;                                           \n"
 
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st)  * color * NdotL1* att;                                                                   \n"                

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      shinyPlasticFireBall_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(shinyPlasticFireBall_SHADER_FRAGMENT, 1, &fragmentSource_shinyPlasticFireBall, NULL);                                                                          
      glCompileShader(shinyPlasticFireBall_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(shinyPlasticFireBall_SHADER, shinyPlasticFireBall_SHADER_VERTEX);                                                                                              
      glAttachShader(shinyPlasticFireBall_SHADER, shinyPlasticFireBall_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(shinyPlasticFireBall_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(shinyPlasticFireBall_SHADER,    1, "normal");       
      glBindAttribLocation(shinyPlasticFireBall_SHADER,    2, "texture");                                                                                             
      //------------------------------------------------                                                                                              
      glLinkProgram(shinyPlasticFireBall_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(shinyPlasticFireBall_SHADER, shinyPlasticFireBall_SHADER_VERTEX);                                                                                              
      glDetachShader(shinyPlasticFireBall_SHADER, shinyPlasticFireBall_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(shinyPlasticFireBall_SHADER_VERTEX);                                                                                                            
      glDeleteShader(shinyPlasticFireBall_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_shinyPlasticFireBall                   = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_shinyPlasticFireBall                    = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_shinyPlasticFireBall               = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SECOND_SPECULAR_shinyPlasticFireBall                 = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "secondSpecular");        
      UNIFORM_SHININESS_shinyPlasticFireBall                       = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_shinyPlasticFireBall                     = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_shinyPlasticFireBall                    = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_shinyPlasticFireBall                         = glGetUniformLocation(shinyPlasticFireBall_SHADER,   "Texture1");                                   
