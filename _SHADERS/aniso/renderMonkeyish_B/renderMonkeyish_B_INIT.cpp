 
    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      renderMonkeyish_B_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_renderMonkeyish_B =                                                                                                        

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
      
      "      normal_PASS             =  normalize(mvpMatrix * vec4(normal, 0.0));                                        \n"
 

      "      vViewVec.xyz            =  highp vec3( mvpMatrix * position );                                              \n"

      "      lightPosition_PASS      =  normalize(lightMatrix * light_POSITION_01);                                      \n"
     
                     
      "      varTexcoord             =  texture;                                                                         \n"
      "      gl_Position             =  mvpMatrix * position;                                                            \n"

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      renderMonkeyish_B_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(renderMonkeyish_B_SHADER_VERTEX, 1, &vertexSource_renderMonkeyish_B, NULL);                                                                        
      glCompileShader(renderMonkeyish_B_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_renderMonkeyish_B =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                        

      "    uniform highp sampler2D     Texture1;                                                                         \n"
      "    uniform highp sampler2D     NormalMap;                                                                        \n"
      "    uniform highp vec4    light_POSITION_01;                                                                      \n" 
      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec4    normal_PASS;                                                                            \n"        
      "    varying highp vec3    vViewVec;                                                                               \n"      
      "    varying highp vec2    varTexcoord;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"        
      "    uniform highp float   noiseScale;                                                                             \n"
      
      
      "            highp vec4    color      = highp vec4(1.0, 0.5, 0.01, 1.0);                                           \n"
      "            highp vec4    gloss      = highp vec4(0.772549, 0.588109, 0.401132, 1.0);                             \n"
      
      "            highp vec3    normalFrag;                                                                             \n"         
      "            highp vec3    NormalTex;                                                                              \n"                       
      "            highp vec3    ColorTex;                                                                               \n"
      "            highp float   NdotL1;                                                                                 \n"  
    
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normalFrag            =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  dot(normalFrag, lightPosition_PASS.xyz);                                        \n"
      "         normalFrag            =  normalize(normal_PASS.xyz);                                                     \n"                       
 
//=======================================================================================================
      "    highp vec3 viewVec         =  normalize(vViewVec);                                                            \n"
      "    highp vec3 oglLightDir     =  highp vec3(light_POSITION_01.x, light_POSITION_01.y, -light_POSITION_01.z);     \n"
    
      "    ColorTex                   =  texture2D(Texture1,  varTexcoord).xyz;                                          \n"
      
      "    highp float angle          =  noiseScale * ColorTex.x * NdotL1* NdotL1;                                       \n"
  
      "    highp float cosA, sinA, tanA;                                                                                 \n" 
      "    sinA = sin(angle);                                                                                            \n" 
      "    cosA = cos(angle);                                                                                            \n" 
      "    tanA = tan(angle);                                                                                            \n" 

//========================================================================================================


      "   highp vec3 tang =  tanA * highp vec3(normalFrag.z, normalFrag.y, normalFrag.x) + sinA * vec3(normalFrag.x, normalFrag.y, normalFrag.z) ;  \n"


//========================================================================================================
      "    highp float cs       = -dot(viewVec, tang);                                                                                              \n"
      "    highp float sn       = sqrt(1.0 - cs * cs) ;                            // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo \n"
      "    highp float cl       =  dot(oglLightDir.xyz, tang)* ColorTex.x ;                                                                         \n"
      "    highp float sl       = sqrt(1.0 - cl * cl);                             // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo \n"
      "    highp float specular = pow( (cs * cl + sn * sl), shininess)* NdotL1;                                                                     \n"


//=======================================================================================================      
     
     
      "    gl_FragColor         =   texture2D(Texture1, varTexcoord.xy) * color  * NdotL1 *NdotL1 * attenuation + gloss * specular  ;           \n"




      "    }\n";

      //---------------------------------------------------------------------                                                                         
      renderMonkeyish_B_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(renderMonkeyish_B_SHADER_FRAGMENT, 1, &fragmentSource_renderMonkeyish_B, NULL);                                                                          
      glCompileShader(renderMonkeyish_B_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(renderMonkeyish_B_SHADER, renderMonkeyish_B_SHADER_VERTEX);                                                                                              
      glAttachShader(renderMonkeyish_B_SHADER, renderMonkeyish_B_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(renderMonkeyish_B_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(renderMonkeyish_B_SHADER,    1, "normal");       
      glBindAttribLocation(renderMonkeyish_B_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(renderMonkeyish_B_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(renderMonkeyish_B_SHADER, renderMonkeyish_B_SHADER_VERTEX);                                                                                              
      glDetachShader(renderMonkeyish_B_SHADER, renderMonkeyish_B_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(renderMonkeyish_B_SHADER_VERTEX);                                                                                                            
      glDeleteShader(renderMonkeyish_B_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_renderMonkeyish_B                   = glGetUniformLocation(renderMonkeyish_B_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_renderMonkeyish_B                    = glGetUniformLocation(renderMonkeyish_B_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_renderMonkeyish_B               = glGetUniformLocation(renderMonkeyish_B_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_renderMonkeyish_B                       = glGetUniformLocation(renderMonkeyish_B_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_renderMonkeyish_B                     = glGetUniformLocation(renderMonkeyish_B_SHADER,   "attenuation");
      UNIFORM_NOISE_SCALE_renderMonkeyish_B                     = glGetUniformLocation(renderMonkeyish_B_SHADER,   "noiseScale");                                                    
      UNIFORM_TEXTURE_DOT3_renderMonkeyish_B                    = glGetUniformLocation(renderMonkeyish_B_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_renderMonkeyish_B                         = glGetUniformLocation(renderMonkeyish_B_SHADER,   "Texture1");                                   
      UNIFORM_ANISO_renderMonkeyish_B                           = glGetUniformLocation(renderMonkeyish_B_SHADER,   "TextureAniso"); 

      #ifdef WIN32  
      //loadTexture("_SHADERS/aniso/renderMonkeyish_B/ogl_aniso.tga",                renderMonkeyish_B_ANISOMAP);       
      #endif 




