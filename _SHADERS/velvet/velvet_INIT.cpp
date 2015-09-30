    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      velvet_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_velvet =                                                                                                        

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

      "     diffuse                 = vec4( 1.00,  1.0,  1.00, 1.0) * vec4(1.0, 48.6, 1.0, 1.0);               \n"
      "     ambient                 = vec4(-1.75, -1.75, 0.0,  1.0) * vec4(1.1, 26.1, 1.1, 1.0);               \n"
      "     ambientGlobal           = vec4(-1.75, -1.75, 0.0, 1.0);                                            \n"
    
  
      "     lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      velvet_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(velvet_SHADER_VERTEX, 1, &vertexSource_velvet, NULL);                                                                        
      glCompileShader(velvet_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_velvet =                                                                                                            

     
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

      "            highp float   att;                                                                                    \n"
      "            highp vec4    color;                                                                                  \n"
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  max(dot(normal, lightPosition_PASS.xyz),  0.0);                                            \n"                       

      "         att                   =  1.0 / attenuation;                                                              \n"
      
      "         color                 =  ambientGlobal + (att * (diffuse  + ambient));                           \n"
      "         color                +=   vec4(-0.60, -11.0, 0.60, 1.0) * pow(NdotL1,  13.84);                           \n"
     
      "         color                -=   vec4(1.0, 1.0,1.0, 1.0) * pow(NdotL1,  shininess);                             \n"      
      
      "         gl_FragColor          =   texture2D(Texture1, varTexcoord.st) *color * NdotL1 * 2.0;                                                                          \n"                    

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      velvet_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(velvet_SHADER_FRAGMENT, 1, &fragmentSource_velvet, NULL);                                                                          
      glCompileShader(velvet_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(velvet_SHADER, velvet_SHADER_VERTEX);                                                                                              
      glAttachShader(velvet_SHADER, velvet_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(velvet_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(velvet_SHADER,    1, "normal");       
      glBindAttribLocation(velvet_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(velvet_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(velvet_SHADER, velvet_SHADER_VERTEX);                                                                                              
      glDetachShader(velvet_SHADER, velvet_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(velvet_SHADER_VERTEX);                                                                                                            
      glDeleteShader(velvet_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_velvet                   = glGetUniformLocation(velvet_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_velvet                    = glGetUniformLocation(velvet_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_velvet               = glGetUniformLocation(velvet_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_velvet                       = glGetUniformLocation(velvet_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_velvet                     = glGetUniformLocation(velvet_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_velvet                    = glGetUniformLocation(velvet_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_velvet                         = glGetUniformLocation(velvet_SHADER,   "Texture1");                                   
