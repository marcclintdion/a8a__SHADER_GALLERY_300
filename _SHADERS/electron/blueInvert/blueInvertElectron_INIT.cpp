      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      blueElectron_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_blueElectron =                                                                                                        

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
      blueElectron_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(blueElectron_SHADER_VERTEX, 1, &vertexSource_blueElectron, NULL);                                                                        
      glCompileShader(blueElectron_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_blueElectron =                                                                                                            

      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                     \n"                       
      " #define highp                                                                                                  \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform sampler2D       Texture1;                                                                             \n"                       
      "    uniform sampler2D       NormalMap;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                            \n"                       
      "    uniform highp float   attenuation;                                                                          \n"                       

      "    varying highp vec4    lightPosition_PASS;                                                                   \n"                       
      "    varying highp vec2    varTexcoord;                                                                          \n"                       

      "     highp  float         NdotL1;                                                                               \n"                       
      "     highp  vec3          normal;                                                                               \n"                       
      "     highp vec3           NormalTex;                                                                            \n"                       

      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex   =  texture2D(NormalMap,  varTexcoord).xyz;                                                   \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       
/*
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0)  * 1.0                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.5, 1.0, .1, 1.0)*attenuation ;    \n"                       
*/
     "         vec4 colorInvert       =  texture2D(Texture1, varTexcoord.st, 0.0)  * 1.0                                  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1* NdotL1*attenuation  \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess) * vec4(2.5, 1.0, .1, 1.0)*attenuation ;   \n"                       
      
      //"         gl_FragColor          =  vec4(1.0 - colorInvert.r, 1.0 - colorInvert.g, 1.0 - colorInvert.b, colorInvert.a );                       \n"    
      
      //"         gl_FragColor          =  vec4((colorInvert.r*-1.0)+1.0, (colorInvert.g*-1.0)+1.0, (colorInvert.b*-1.0)+1.0, colorInvert.a );         \n"    
    
      "         gl_FragColor          =  colorInvert;                                                                       \n"    
    
      
      
      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      blueElectron_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(blueElectron_SHADER_FRAGMENT, 1, &fragmentSource_blueElectron, NULL);                                                                          
      glCompileShader(blueElectron_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(blueElectron_SHADER, blueElectron_SHADER_VERTEX);                                                                                              
      glAttachShader(blueElectron_SHADER, blueElectron_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(blueElectron_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(blueElectron_SHADER,    1, "normal");       
      glBindAttribLocation(blueElectron_SHADER,    2, "texture");                                                                                                
      //------------------------------------------------                                                                                              
      glLinkProgram(blueElectron_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(blueElectron_SHADER, blueElectron_SHADER_VERTEX);                                                                                              
      glDetachShader(blueElectron_SHADER, blueElectron_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(blueElectron_SHADER_VERTEX);                                                                                                            
      glDeleteShader(blueElectron_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_blueElectron                   = glGetUniformLocation(blueElectron_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_blueElectron                    = glGetUniformLocation(blueElectron_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_blueElectron               = glGetUniformLocation(blueElectron_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_blueElectron                       = glGetUniformLocation(blueElectron_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_blueElectron                     = glGetUniformLocation(blueElectron_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_blueElectron                    = glGetUniformLocation(blueElectron_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_blueElectron                         = glGetUniformLocation(blueElectron_SHADER,   "Texture1");                                               
      //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
      
