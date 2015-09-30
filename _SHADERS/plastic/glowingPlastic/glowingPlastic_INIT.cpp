    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      glowingPlastic_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_glowingPlastic =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "            highp vec3  aux;                                                                            \n"

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
 
      "     lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                              \n"                           
      "     varTexcoord             = texture;                                                                 \n"                           
      "     gl_Position             = mvpMatrix * position;                                                    \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      glowingPlastic_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(glowingPlastic_SHADER_VERTEX, 1, &vertexSource_glowingPlastic, NULL);                                                                        
      glCompileShader(glowingPlastic_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_glowingPlastic =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D     Texture1;                                                                                       \n"                       
      "    uniform sampler2D     NormalMap;                                                                                      \n"                       
      "    uniform highp float   shininess;                                                                                      \n"                       
      "    uniform highp float   attenuation;                                                                                    \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                             \n"                       
      "    varying highp vec2    varTexcoord;                                                                                    \n"                       

      "            highp float   NdotL1;                                                                                         \n"                       
      "            highp vec3    normal;                                                                                         \n"                       
      "            highp vec3    NormalTex;                                                                                      \n"                       

      "            highp vec4    ambient_2 = vec4(-14.275, 1.25, 14.60, 1.0);                                                    \n"
    
      "            highp float   att;                                                                                            \n"
      "            highp vec4    color;                                                                                          \n"
      
      "     void main()                                                                                                          \n"                       
      "     {                                                                                                                    \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                                 \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                                       \n"                       
      "         normal                =  normalize(NormalTex);                                                                   \n"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                                    \n"                       

      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st) * attenuation                                       \n" 
      "                               *  ambient_2 * NdotL1 * NdotL1                                                             \n"
      "                               +  pow(NdotL1 * NdotL1, 700.2) * NdotL1 * NdotL1;                                              \n"                    

     
     
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      glowingPlastic_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(glowingPlastic_SHADER_FRAGMENT, 1, &fragmentSource_glowingPlastic, NULL);                                                                          
      glCompileShader(glowingPlastic_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(glowingPlastic_SHADER, glowingPlastic_SHADER_VERTEX);                                                                                              
      glAttachShader(glowingPlastic_SHADER, glowingPlastic_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(glowingPlastic_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(glowingPlastic_SHADER,    1, "normal");       
      glBindAttribLocation(glowingPlastic_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(glowingPlastic_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(glowingPlastic_SHADER, glowingPlastic_SHADER_VERTEX);                                                                                              
      glDetachShader(glowingPlastic_SHADER, glowingPlastic_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(glowingPlastic_SHADER_VERTEX);                                                                                                            
      glDeleteShader(glowingPlastic_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_glowingPlastic                   = glGetUniformLocation(glowingPlastic_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_glowingPlastic                    = glGetUniformLocation(glowingPlastic_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_glowingPlastic               = glGetUniformLocation(glowingPlastic_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_glowingPlastic                       = glGetUniformLocation(glowingPlastic_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_glowingPlastic                     = glGetUniformLocation(glowingPlastic_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_glowingPlastic                    = glGetUniformLocation(glowingPlastic_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_glowingPlastic                         = glGetUniformLocation(glowingPlastic_SHADER,   "Texture1");                                   
