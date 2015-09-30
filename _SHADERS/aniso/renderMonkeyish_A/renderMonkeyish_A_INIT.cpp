 
    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      renderMonkeyish_A_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_renderMonkeyish_A =                                                                                                        

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
      
      "      normal_PASS             = -normalize(mvpMatrix * vec4(normal, 0.0));                                        \n"  
 

      "      vViewVec.xyz            = highp vec3(  mvpMatrix * position );                                                    \n"  
      "      vViewVec.z              = -vViewVec.z;                                                                      \n"  
     
      "      lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                                       \n"        
     
                     
      "      varTexcoord             = texture;                                                                          \n"                           
      "      gl_Position             = mvpMatrix * position;                                                             \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      renderMonkeyish_A_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(renderMonkeyish_A_SHADER_VERTEX, 1, &vertexSource_renderMonkeyish_A, NULL);                                                                        
      glCompileShader(renderMonkeyish_A_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_renderMonkeyish_A =                                                                                                            

     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                        

      "    uniform sampler2D     Texture1;                                                                               \n"                       
      "    uniform sampler2D     NormalMap;                                                                              \n"                       
      "    uniform highp vec4    light_POSITION_01;                                                                      \n" 
      "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       
      "    varying highp vec4    normal_PASS;                                                                            \n"        
      "    varying highp vec3    vViewVec;                                                                               \n"      
      
      "    varying highp vec2    varTexcoord;                                                                            \n"                       
      "    uniform highp float   shininess;                                                                              \n"                       
      "    uniform highp float   attenuation;                                                                            \n"        
      "    uniform highp float   noiseScale;                                                                            \n"       
      
      
      "            highp vec4    color      = highp vec4(1.0, 0.5, 0.01, 1.0);                                                 \n"          
      "            highp vec4    gloss      = highp vec4(0.772549*2.0, 0.588109*2.0, 0.401132*2.0, 1.0);                                   \n"     
      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    normalFrag;                                                                             \n"         
      "            highp vec3    NormalTex;                                                                              \n"                       
      "            highp float   NdotL1;                                                                                 \n"  
    
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      "         normal                =  normalize(NormalTex);                                                           \n"                       
      "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                       
      "         normalFrag            =  normalize(normal_PASS.xyz);                                                     \n"                       
 
//=======================================================================================================
      "    highp vec3 viewVec = normalize(vViewVec);                                                                     \n"  
      "    highp vec3 oglLightDir = highp vec3(light_POSITION_01.x, light_POSITION_01.y, -light_POSITION_01.z);                \n"  

      "    highp float angle = noiseScale *  NdotL1;                                                                     \n"  
  
      "    highp float cosA, sinA, tanA;                                                                                 \n" 
      "    sinA = sin(angle);                                                                                            \n" 
      "    cosA = cos(angle);                                                                                            \n" 
      "    tanA = tan(angle);                                                                                            \n" 

      "   highp vec3 tang1 =  sinA * highp vec3(normalFrag.x, normalFrag.x, normalFrag.x) ;                                          \n" //!var         renderMonkeyish_B_ATTENUATION    =  0.847001;var         renderMonkeyish_B_SHININESS    =  174.998;var         renderMonkeyish_B_NOISE_SCALE      =  -0.0034;
      "   highp vec3 tang2 =  sinA * highp vec3(normalFrag.z, normalFrag.y, normalFrag.z) ;                                          \n"    //!


      "    highp float cs  = -dot(viewVec, tang1);                                                                             \n" 
      "    highp float cs2 = -dot(viewVec, tang2);                                                                             \n"       
     
      "    highp float sn  = sqrt(1.0 - cs * cs)* NdotL1  ;                                                                   \n" 
      
      "    highp float cl  =  dot(oglLightDir.xyz, tang1);                                                                     \n" 
      "    highp float cl2 =  dot(oglLightDir.xyz, tang2);                                                                     \n"       
      
      "    highp float sl  = sqrt(1.0 - cl * cl)* NdotL1  ;                                                                   \n" 
      
      "    highp float specular = pow( clamp( ( cs *cl + sn * sl), 0.0, 1.0 ), shininess);                           \n" 


//=======================================================================================================      
     "       color.a = 0.3;                                                                                                                    \n"  
   
     "       gl_FragColor          =   (texture2D(Texture1, varTexcoord.xy) * color  * NdotL1 * NdotL1* attenuation + gloss * specular);       \n"                    

     
     
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      renderMonkeyish_A_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(renderMonkeyish_A_SHADER_FRAGMENT, 1, &fragmentSource_renderMonkeyish_A, NULL);                                                                          
      glCompileShader(renderMonkeyish_A_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(renderMonkeyish_A_SHADER, renderMonkeyish_A_SHADER_VERTEX);                                                                                              
      glAttachShader(renderMonkeyish_A_SHADER, renderMonkeyish_A_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(renderMonkeyish_A_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(renderMonkeyish_A_SHADER,    1, "normal");       
      glBindAttribLocation(renderMonkeyish_A_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(renderMonkeyish_A_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(renderMonkeyish_A_SHADER, renderMonkeyish_A_SHADER_VERTEX);                                                                                              
      glDetachShader(renderMonkeyish_A_SHADER, renderMonkeyish_A_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(renderMonkeyish_A_SHADER_VERTEX);                                                                                                            
      glDeleteShader(renderMonkeyish_A_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_renderMonkeyish_A                   = glGetUniformLocation(renderMonkeyish_A_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_renderMonkeyish_A                    = glGetUniformLocation(renderMonkeyish_A_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_renderMonkeyish_A               = glGetUniformLocation(renderMonkeyish_A_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_renderMonkeyish_A                       = glGetUniformLocation(renderMonkeyish_A_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_renderMonkeyish_A                     = glGetUniformLocation(renderMonkeyish_A_SHADER,   "attenuation");
      UNIFORM_NOISE_SCALE_renderMonkeyish_A                     = glGetUniformLocation(renderMonkeyish_A_SHADER,   "noiseScale");                                                    
      UNIFORM_TEXTURE_DOT3_renderMonkeyish_A                    = glGetUniformLocation(renderMonkeyish_A_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_renderMonkeyish_A                         = glGetUniformLocation(renderMonkeyish_A_SHADER,   "Texture1");                                   
      UNIFORM_ANISO_renderMonkeyish_A                           = glGetUniformLocation(renderMonkeyish_A_SHADER,   "TextureAniso"); 

      #ifdef WIN32  
      loadTexture("_SHADERS/aniso/renderMonkeyish_A/ogl_aniso.tga",                renderMonkeyish_A_ANISOMAP);       
      #endif 




