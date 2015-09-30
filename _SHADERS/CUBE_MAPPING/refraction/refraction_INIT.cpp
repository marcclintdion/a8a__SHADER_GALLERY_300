    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      refraction_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_refraction =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           
      "    uniform highp float  shininess;                                                                     \n"                       
      
      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec3   normal;                                                                        \n"         
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec3   column0;                                                                       \n"   
      "    varying highp vec3   column1;                                                                       \n"   
      "    varying highp vec3   column2;                                                                       \n"        
     
      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec3   normal_PASS;                                                                   \n"          
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

      "        normal_PASS           = -normalize(mvpMatrix * vec4(normal, 0.0)).xyz;                          \n"        
     

     
      "        column0               =  vec3(mvpMatrix[0].xyz);                                                \n"   
      "        column1               =  vec3(mvpMatrix[1].xyz);                                                \n"   
      "        column2               =  vec3(mvpMatrix[2].xyz);                                                \n"     
           
      "        lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                            \n"                           
      "        varTexcoord           =  texture;                                                               \n"                           
      "        gl_Position           =  mvpMatrix * position;                                                  \n"                           

        "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      refraction_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(refraction_SHADER_VERTEX, 1, &vertexSource_refraction, NULL);                                                                        
      glCompileShader(refraction_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_refraction =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"   
    
      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform samplerCube   EnvMap;                                                                                 \n"    
      "    uniform highp vec4    light_POSITION_01;                                                                      \n"        
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec3    normal_PASS;                                                                            \n"          
      "            highp vec3    T;                                                                                      \n"       
      "    varying highp vec2    varTexcoord;                                                                            \n"                       
      
      "    varying highp vec3    column0;                                                                                \n"   
      "    varying highp vec3    column1;                                                                                \n"   
      "    varying highp vec3    column2;                                                                                \n"        

      "            highp float   NdotL1;                                                                                 \n"                       
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    NormalTex;                                                                              \n"                       

      "            highp vec4    color;                                                                                  \n"
     
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       

      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      
      "         NdotL1                =  dot(normal, normalize(lightPosition_PASS.xyz));                                  \n"                       

      "         T                     =  refract(normalize(lightPosition_PASS.xyz), normal, shininess);                                             \n" 

      "         color                 =  textureCube(EnvMap, T);                                                         \n"  
     
      "         gl_FragColor          =  mix(vec4(1.0, 1.0, 1.0, 1.0), color, attenuation) * NdotL1 * NdotL1;                     \n"                       

      "    }\n";                                                                                                                                       

      //---------------------------------------------------------------------                                                                         
      refraction_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(refraction_SHADER_FRAGMENT, 1, &fragmentSource_refraction, NULL);                                                                          
      glCompileShader(refraction_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(refraction_SHADER, refraction_SHADER_VERTEX);                                                                                              
      glAttachShader(refraction_SHADER, refraction_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(refraction_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(refraction_SHADER,    1, "normal");       
      glBindAttribLocation(refraction_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(refraction_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(refraction_SHADER, refraction_SHADER_VERTEX);                                                                                              
      glDetachShader(refraction_SHADER, refraction_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(refraction_SHADER_VERTEX);                                                                                                            
      glDeleteShader(refraction_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_refraction                   = glGetUniformLocation(refraction_SHADER,   "mvpMatrix");
      UNIFORM_MODELVIEW_refraction                       = glGetUniformLocation(refraction_SHADER,   "mvMatrix");                                                    
      UNIFORM_LIGHT_MATRIX_refraction                    = glGetUniformLocation(refraction_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_refraction               = glGetUniformLocation(refraction_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_refraction                       = glGetUniformLocation(refraction_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_refraction                     = glGetUniformLocation(refraction_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_refraction                    = glGetUniformLocation(refraction_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_refraction                         = glGetUniformLocation(refraction_SHADER,   "Texture1");                                   
