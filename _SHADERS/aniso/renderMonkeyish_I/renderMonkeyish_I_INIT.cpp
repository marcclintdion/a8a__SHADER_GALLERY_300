 
    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      renderMonkeyish_I_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_renderMonkeyish_I =                                                                                                        

      "    #define highp                                                                                                 \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                                       \n"                           
      "    uniform       mat4   mvpMatrix;                                                                               \n"                           
      "    uniform       mat4   lightMatrix;                                                                             \n"                           

      "    attribute     vec4   position;                                                                                \n"                           
      "    attribute     vec3   normal;                                                                                  \n"       
      "    attribute     vec2   texture;                                                                                 \n"                           

      "    varying highp vec4   lightPosition_PASS;                                                                      \n"                           
      "    varying highp vec4   normal_PASS;                                                                             \n"        
      "    varying highp vec3   vViewVec;                                                                                \n"   
     
  
      "    varying highp vec2   varTexcoord;                                                                             \n"                           


      "    void main()                                                                                                   \n"                           
      "    {                                                                                                             \n"                           
     
      "        normal_PASS             = -normalize(mvpMatrix * vec4(normal, 0.0));                                        \n"  
 
      "        vViewVec.xyz            = highp vec3(  mvpMatrix * position );                                                    \n"  
      "        vViewVec.z              = -vViewVec.z;                                                                      \n"  
     
      "        lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                                       \n"        
     
      "        varTexcoord             = texture;                                                                          \n"                           
      "        gl_Position             = mvpMatrix * position;                                                             \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      renderMonkeyish_I_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(renderMonkeyish_I_SHADER_VERTEX, 1, &vertexSource_renderMonkeyish_I, NULL);                                                                        
      glCompileShader(renderMonkeyish_I_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_renderMonkeyish_I =                                                                                                            

     
      " #ifdef GL_ES                                                                                                                  \n"                       
      " #else                                                                                                                         \n"                       
      " #define highp                                                                                                                 \n"                       
      " #endif                                                                                                                        \n"                        

      "    uniform sampler2D     Texture1;                                                                                            \n"                       
      "    uniform sampler2D     NormalMap;                                                                                           \n"                       
      "    uniform highp vec4    light_POSITION_01;                                                                                   \n" 
      "    varying highp vec4    lightPosition_PASS;                                                                                  \n"                       
      "    varying highp vec4    normal_PASS;                                                                                         \n"        
      "    varying highp vec3    vViewVec;                                                                                            \n"      
  
      "    varying highp vec2    varTexcoord;                                                                                         \n"                       
      "    uniform highp float   shininess;                                                                                           \n"                       
      "    uniform highp float   attenuation;                                                                                         \n"        
      "    uniform highp float   noiseScale;                                                                                          \n"       
      
      "            highp vec4    color      = highp vec4(0.6, 0.0, 0.0, 1.0);                                                               \n"          
      "            highp vec4    gloss      = highp vec4(0.8, 0.0, 0.0, 1.0);                                                               \n" 


      "            highp vec3    normalFrag;                                                                                          \n"         
      "            highp vec3    NormalTex;                                                                                           \n"                       
      "            highp vec3    ColorTex;                                                                                            \n"         
      "            highp float   NdotL1;                                                                                              \n"  
      "            highp float cosA, sinA, tanA;                                                                                      \n"     
      
      "     void main()                                                                                                               \n"                       
      "     {                                                                                                                         \n"                       

      "         NormalTex                  =  texture2D(NormalMap,  varTexcoord).xyz;                                                 \n"                       
      "         NormalTex                  = (NormalTex - 0.5);                                                                       \n"                       
      "         normalFrag                 =  normalize(NormalTex);                                                               \n"                       
      "         NdotL1                     =  dot(normalFrag, lightPosition_PASS.xyz);                                          \n"                       
      "         normalFrag                 =  normalize(normal_PASS.xyz);                                                     \n"                       
 
//=======================================================================================================
      "         highp vec3 viewVec         = normalize(vViewVec);                                                                     \n"  
      "         highp vec3 oglLightDir     = highp vec3(light_POSITION_01.x, light_POSITION_01.y, -light_POSITION_01.z);                    \n"  
    
      "         ColorTex                   =  texture2D(Texture1,  varTexcoord).xyz;                                                  \n"        
      
      "         highp float angle          = noiseScale * ColorTex.x * NdotL1;                                                        \n"  
  
      "         sinA = sin(angle);                                                                                                    \n" 
      "         cosA = cos(angle);                                                                                                    \n" 
      "         tanA = tan(angle);                                                                                                    \n" 
//========================================================================================================
      "         highp vec3 tang                  =  tanA * highp vec3(normalFrag.z, normalFrag.y*10.0, normalFrag.x*10.0) + sinA * highp vec3(normalFrag.x, normalFrag.y, normalFrag.z) ; \n" 

//========================================================================================================
      "         highp float cs                   = -dot(viewVec, tang);                                                                     \n" 
      "         highp float sn                   =  sqrt(1.0 - cs * cs) ;                                                                   \n" 
      "         highp float cl                   =  dot(oglLightDir.xyz, tang)* ColorTex.x ;                                                \n" 
      "         highp float sl                   =  sqrt(1.0 - cl * cl);                                                                    \n" 
      "         highp float specular             =  pow( (cs * cl + sn * sl), 143.484)* NdotL1;                                           \n" 
//=======================================================================================================      
      "         gl_FragColor               =   texture2D(Texture1, varTexcoord.xy) * color   * NdotL1 * 1.0                    \n" 
      "                                    +   gloss * specular  ;                                                                    \n"                    
      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      renderMonkeyish_I_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(renderMonkeyish_I_SHADER_FRAGMENT, 1, &fragmentSource_renderMonkeyish_I, NULL);                                                                          
      glCompileShader(renderMonkeyish_I_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(renderMonkeyish_I_SHADER, renderMonkeyish_I_SHADER_VERTEX);                                                                                              
      glAttachShader(renderMonkeyish_I_SHADER, renderMonkeyish_I_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(renderMonkeyish_I_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(renderMonkeyish_I_SHADER,    1, "normal");       
      glBindAttribLocation(renderMonkeyish_I_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(renderMonkeyish_I_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(renderMonkeyish_I_SHADER, renderMonkeyish_I_SHADER_VERTEX);                                                                                              
      glDetachShader(renderMonkeyish_I_SHADER, renderMonkeyish_I_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(renderMonkeyish_I_SHADER_VERTEX);                                                                                                            
      glDeleteShader(renderMonkeyish_I_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_renderMonkeyish_I                   = glGetUniformLocation(renderMonkeyish_I_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_renderMonkeyish_I                    = glGetUniformLocation(renderMonkeyish_I_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_renderMonkeyish_I               = glGetUniformLocation(renderMonkeyish_I_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_renderMonkeyish_I                       = glGetUniformLocation(renderMonkeyish_I_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_renderMonkeyish_I                     = glGetUniformLocation(renderMonkeyish_I_SHADER,   "attenuation");
      UNIFORM_NOISE_SCALE_renderMonkeyish_I                     = glGetUniformLocation(renderMonkeyish_I_SHADER,   "noiseScale");                                                    
      UNIFORM_TEXTURE_DOT3_renderMonkeyish_I                    = glGetUniformLocation(renderMonkeyish_I_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_renderMonkeyish_I                         = glGetUniformLocation(renderMonkeyish_I_SHADER,   "Texture1");                                   
      UNIFORM_ANISO_renderMonkeyish_I                           = glGetUniformLocation(renderMonkeyish_I_SHADER,   "TextureAniso"); 

      #ifdef WIN32  
      loadTexture("_SHADERS/aniso/renderMonkeyish_I/ogl_aniso.tga",                renderMonkeyish_I_ANISOMAP);       
      #endif 




