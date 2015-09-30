    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      liquidShiny_01_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_liquidShiny_01 =                                                                                                        

      "    #define highp                                                                                       \n"                           
      
      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform highp vec4   light_POSITION_02;                                                             \n"      
     
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   lightMatrix;                                                                   \n"                           

      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
      "    varying highp vec4   lightPosition_PASS_2;                                                          \n"       
      
      "    varying highp vec2   varTexcoord;                                                                   \n" 



      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           

                         
      "        lightPosition_PASS    = normalize(lightMatrix * light_POSITION_01);                             \n"                           
      "        lightPosition_PASS_2    = normalize(lightMatrix * light_POSITION_02);                             \n"        
      "        varTexcoord           = texture;                                                                \n"                           
      "        gl_Position           = mvpMatrix * position;                                                   \n" 
     
     "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      liquidShiny_01_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(liquidShiny_01_SHADER_VERTEX, 1, &vertexSource_liquidShiny_01, NULL);                                                                        
      glCompileShader(liquidShiny_01_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_liquidShiny_01 =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                     
     
      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                     \n"   
      "    varying highp vec4    lightPosition_PASS_2;                                                                   \n"                              
      "    varying highp vec2    varTexcoord;                                                                            \n"                       

      "            highp float   NdotL1;                                                                                 \n"                       
      "            highp float   NdotL2;                                                                                 \n"        
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    NormalTex;                                                                              \n"  
      
      "            highp float   shiny;                                                                                  \n"  
      "            highp float   shiny_2;                                                                                  \n"       
      "            highp vec4    ka      = highp vec4(0.9, 0.6, 0.7, 1.0);                                               \n"  
      "            highp vec4    color;                                                                                  \n"  
      
      
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                  \n"              
      "         NdotL2                =  max(dot(normal, lightPosition_PASS_2.xyz), 0.0);                                \n"  

      "         shiny                 = pow(NdotL1, 199.733 * 0.1);                                                      \n" 
      "         shiny                += pow(NdotL1, 199.733 * 4.1) * 15.0;                                               \n" 
      //"         shiny                 = max(pow(NdotL1, 199.733 * 0.1), 0.0);                                          \n" 
      //"         shiny                += max(pow(NdotL1, 199.733 * 4.1), 0.0) * 15.0;                                   \n" 
      //"         shiny                 = pow(max(NdotL1, 0.0), 199.733 * 0.1);                                          \n" 
      //"         shiny                += pow(max(NdotL1, 0.0), 199.733 * 4.1) * 15.0;                                   \n"         
      
      "         color                = ka * pow(NdotL2, shininess * 0.1);                                                \n"            
      "         color               += ka * pow(NdotL2, shininess      ) * 10.0;                                         \n"        
     
     
      "         color                 += ka * shiny;                                                                     \n" 
            
      "         gl_FragColor          = ((texture2D(Texture1, varTexcoord.st) * (color * NdotL1))                        \n"  
      "                               + (1.0 - NdotL1) * 0.10);                                                          \n" 

      "}\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      liquidShiny_01_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(liquidShiny_01_SHADER_FRAGMENT, 1, &fragmentSource_liquidShiny_01, NULL);                                                                          
      glCompileShader(liquidShiny_01_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(liquidShiny_01_SHADER, liquidShiny_01_SHADER_VERTEX);                                                                                              
      glAttachShader(liquidShiny_01_SHADER, liquidShiny_01_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(liquidShiny_01_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(liquidShiny_01_SHADER,    1, "normal");       
      glBindAttribLocation(liquidShiny_01_SHADER,    2, "texture");                                                                                          
      //------------------------------------------------                                                                                              
      glLinkProgram(liquidShiny_01_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(liquidShiny_01_SHADER, liquidShiny_01_SHADER_VERTEX);                                                                                              
      glDetachShader(liquidShiny_01_SHADER, liquidShiny_01_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(liquidShiny_01_SHADER_VERTEX);                                                                                                            
      glDeleteShader(liquidShiny_01_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_liquidShiny_01                   = glGetUniformLocation(liquidShiny_01_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_liquidShiny_01                    = glGetUniformLocation(liquidShiny_01_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_liquidShiny_01               = glGetUniformLocation(liquidShiny_01_SHADER,   "light_POSITION_01"); 
      UNIFORM_LIGHT_POSITION_02_liquidShiny_01               = glGetUniformLocation(liquidShiny_01_SHADER,   "light_POSITION_02");                                           
      UNIFORM_SHININESS_liquidShiny_01                       = glGetUniformLocation(liquidShiny_01_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_liquidShiny_01                     = glGetUniformLocation(liquidShiny_01_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_liquidShiny_01                    = glGetUniformLocation(liquidShiny_01_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_liquidShiny_01                         = glGetUniformLocation(liquidShiny_01_SHADER,   "Texture1");                                   
