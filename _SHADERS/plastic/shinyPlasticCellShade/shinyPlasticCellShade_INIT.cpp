    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      shinyPlasticCellShade_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_shinyPlasticCellShade =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           
      "    uniform highp vec4    secondSpecular;                                                                         \n"   
      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    varying highp vec4  diffuse;                                                                        \n"
      "    varying highp vec4  ambient;                                                                        \n"      
      "    varying highp vec4  ambientGlobal;                                                                  \n"
   

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "     diffuse                 = vec4( 0.00,   48.6,  1.0, 1.0);                                          \n"
      "     ambient                 = secondSpecular;                                         \n"
      "     ambientGlobal           = vec4(-1.0,   -1.00, 0.0, 1.0);                                          \n"
    
  
      "     lightPosition_PASS      =  normalize(lightMatrix *light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      shinyPlasticCellShade_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(shinyPlasticCellShade_SHADER_VERTEX, 1, &vertexSource_shinyPlasticCellShade, NULL);                                                                        
      glCompileShader(shinyPlasticCellShade_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_shinyPlasticCellShade =                                                                                                            

     
     
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
      "         NdotL1                =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                  \n"                       

      "         att                   =  1.0 / attenuation;                                                              \n"
      
      "         color                 =  (ambientGlobal + ((diffuse * NdotL1 + ambient))) * NdotL1 ;                     \n"
    
      "         color               +=  vec4(-9.60, 1.0, 9.60, 1.0) * pow(NdotL1,shininess)*2.0;                        \n"

     
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st)  * color * att;                             \n"                

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      shinyPlasticCellShade_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(shinyPlasticCellShade_SHADER_FRAGMENT, 1, &fragmentSource_shinyPlasticCellShade, NULL);                                                                          
      glCompileShader(shinyPlasticCellShade_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(shinyPlasticCellShade_SHADER, shinyPlasticCellShade_SHADER_VERTEX);                                                                                              
      glAttachShader(shinyPlasticCellShade_SHADER, shinyPlasticCellShade_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(shinyPlasticCellShade_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(shinyPlasticCellShade_SHADER,    1, "normal");       
      glBindAttribLocation(shinyPlasticCellShade_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(shinyPlasticCellShade_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(shinyPlasticCellShade_SHADER, shinyPlasticCellShade_SHADER_VERTEX);                                                                                              
      glDetachShader(shinyPlasticCellShade_SHADER, shinyPlasticCellShade_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(shinyPlasticCellShade_SHADER_VERTEX);                                                                                                            
      glDeleteShader(shinyPlasticCellShade_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_shinyPlasticCellShade                   = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_shinyPlasticCellShade                    = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_shinyPlasticCellShade               = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SECOND_SPECULAR_shinyPlasticCellShade                 = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "secondSpecular");      
      UNIFORM_SHININESS_shinyPlasticCellShade                       = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_shinyPlasticCellShade                     = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_shinyPlasticCellShade                    = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_shinyPlasticCellShade                         = glGetUniformLocation(shinyPlasticCellShade_SHADER,   "Texture1");                                   
