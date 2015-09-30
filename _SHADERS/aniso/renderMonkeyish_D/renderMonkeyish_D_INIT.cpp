 
    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      renderMonkeyish_D_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_renderMonkeyish_D =                                                                                                        

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
 

      "      vViewVec.xyz            = vec3(  mvpMatrix * position );                                                    \n"  
      "      vViewVec.z              = -vViewVec.z;                                                                      \n"  
     
      "      lightPosition_PASS      = normalize(lightMatrix * light_POSITION_01);                                       \n"        
     
                     
      "      varTexcoord             = texture;                                                                          \n"                           
      "      gl_Position             = mvpMatrix * position;                                                             \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      renderMonkeyish_D_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(renderMonkeyish_D_SHADER_VERTEX, 1, &vertexSource_renderMonkeyish_D, NULL);                                                                        
      glCompileShader(renderMonkeyish_D_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_renderMonkeyish_D =                                                                                                            

     
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
      
      "            highp vec4    color      = highp vec4(0.6, 0.0, 0.0, 1.0);                                                 \n"          
      "            highp vec4    gloss      = highp vec4(0.8, 0.0, 0.0, 1.0);                                                 \n" 


      "            highp vec3    normal;                                                                                 \n"                       
      "            highp vec3    normalFrag;                                                                             \n"         
      "            highp vec3    NormalTex;                                                                              \n"                       
      "            highp vec3    ColorTex;                                                                              \n"         
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
    
      "    ColorTex             =  texture2D(Texture1,  varTexcoord).xyz;                                                \n"        
      
      "    highp float angle = noiseScale * ColorTex.x * NdotL1;                                                             \n"  
  
      "    highp float cosA, sinA, tanA;                                                                                 \n" 
      "    sinA = sin(angle);                                                                                            \n" 
      "    cosA = cos(angle);                                                                                            \n" 
      "    tanA = tan(angle);                                                                                            \n" 

//========================================================================================================
      // "    vec3 tang =  tanA * vec3(normalFrag.y, normalFrag.z, normalFrag.y);                                                         \n" 

    //"   vec3 tang =  tanA * vec3(normalFrag.x, normalFrag.z, normalFrag.y) + sinA * vec3(normalFrag.x, normalFrag.y, normalFrag.z) ;         \n" //!var         renderMonkeyish_D_LIGHT_POSITION_01[]    =  {0, 92.3999, 139.5, 1.0};var         renderMonkeyish_D_ATTENUATION    =  0.847001;var         renderMonkeyish_D_SHININESS    =  174.998;var         renderMonkeyish_D_NOISE_SCALE      =  -0.0105;


    "   highp vec3 tang =  tanA * highp vec3(normalFrag.z, normalFrag.y, normalFrag.x) + sinA * highp vec3(normalFrag.x, normalFrag.y, normalFrag.z) ;         \n"  //!var         renderMonkeyish_D_ATTENUATION    =  1.057;var         renderMonkeyish_D_SHININESS    =  205.001;var         renderMonkeyish_D_NOISE_SCALE      =  -0.0034;

    //"   vec3 tang =  sinA * vec3(normalFrag.x, normalFrag.x, normalFrag.x) ;                                                                \n" //!var         renderMonkeyish_D_ATTENUATION    =  0.847001;var         renderMonkeyish_D_SHININESS    =  174.998;var         renderMonkeyish_D_NOISE_SCALE      =  -0.0034;

   //"   vec3 tang =  tanA * vec3(normalFrag.x, normalFrag.x, normalFrag.x) ;                                                            \n"    //!
   //     "   vec3 tang =  tanA * vec3(normalFrag.x, normalFrag.y, normalFrag.y) ;                                                            \n" //
   //      "   vec3 tang =  tanA * vec3(normalFrag.y, normalFrag.y, normalFrag.y) ;                                                            \n" //
   //   "   vec3 tang =  tanA * vec3(normalFrag.y, normalFrag.z, normalFrag.x) ;                                                            \n" //!
    //    "   vec3 tang =  cosA * vec3(normalFrag.y, normalFrag.z, normalFrag.x) ;                                                            \n" //?
    //   "   vec3 tang =  sinA * vec3(normalFrag.y, normalFrag.z, normalFrag.x) ;                                                            \n" //!
   //      "   vec3 tang =  cosA * vec3(normalFrag.y, normalFrag.z, normalFrag.x) ;                                                            \n" //?
   //      "   vec3 tang =  cosA * vec3(normalFrag.x, normalFrag.z, normalFrag.y) ;                                                            \n" //?
   //     "   vec3 tang =  sinA * vec3(normalFrag.x, normalFrag.z, normalFrag.y) ;                                                            \n" //
   //   "   vec3 tang =  cosA * vec3(normalFrag.x, normalFrag.z, normalFrag.y) + sinA * vec3(normalFrag.z , normalFrag.y, normalFrag.x);    \n" //?
   //      "   vec3 tang =  sinA * vec3(normalFrag.x, normalFrag.z, normalFrag.y) + cosA * vec3(normalFrag.z , normalFrag.y, normalFrag.x);    \n" //?
   //--------------------------------------------------------------------------------------------------------------
   //    "   vec3 tang =  sinA * vec3(normalFrag.z, normalFrag.y, normalFrag.z) ;                                                            \n" //!
    //   "   vec3 tang =  cosA * vec3(normalFrag.x, normalFrag.y, normalFrag.z) ;                       \n" //?
    //"   vec3 tang =  sinA * vec3(normalFrag.x , normalFrag.y, normalFrag.z) ;                       \n" //!





//========================================================================================================
      "    highp float cs = -dot(viewVec, tang);                                                                                                      \n" 
      "    highp float sn = sqrt(1.0 - cs * cs) ;                                 // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo     \n" 
      "    highp float cl =  dot(oglLightDir.xyz, tang)* ColorTex.x ;                                                                                 \n" 
      "    highp float sl = sqrt(1.0 - cl * cl);                                 // sqrt(1.0 - cs * cs) * NdotL1<-shiny with second specular halo     \n" 
      "    highp float specular = pow( (cs * cl + sn * sl), shininess)* NdotL1;                                                                               \n" 


//=======================================================================================================      
     
     
      "         gl_FragColor          =   texture2D(Texture1, varTexcoord.xy) * color  * NdotL1 *NdotL1 * attenuation + gloss * specular  ;       \n"                    

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      renderMonkeyish_D_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(renderMonkeyish_D_SHADER_FRAGMENT, 1, &fragmentSource_renderMonkeyish_D, NULL);                                                                          
      glCompileShader(renderMonkeyish_D_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(renderMonkeyish_D_SHADER, renderMonkeyish_D_SHADER_VERTEX);                                                                                              
      glAttachShader(renderMonkeyish_D_SHADER, renderMonkeyish_D_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(renderMonkeyish_D_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(renderMonkeyish_D_SHADER,    1, "normal");       
      glBindAttribLocation(renderMonkeyish_D_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(renderMonkeyish_D_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(renderMonkeyish_D_SHADER, renderMonkeyish_D_SHADER_VERTEX);                                                                                              
      glDetachShader(renderMonkeyish_D_SHADER, renderMonkeyish_D_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(renderMonkeyish_D_SHADER_VERTEX);                                                                                                            
      glDeleteShader(renderMonkeyish_D_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_renderMonkeyish_D                   = glGetUniformLocation(renderMonkeyish_D_SHADER,   "mvpMatrix");                                              
      UNIFORM_LIGHT_MATRIX_renderMonkeyish_D                    = glGetUniformLocation(renderMonkeyish_D_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_renderMonkeyish_D               = glGetUniformLocation(renderMonkeyish_D_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_renderMonkeyish_D                       = glGetUniformLocation(renderMonkeyish_D_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_renderMonkeyish_D                     = glGetUniformLocation(renderMonkeyish_D_SHADER,   "attenuation");
      UNIFORM_NOISE_SCALE_renderMonkeyish_D                     = glGetUniformLocation(renderMonkeyish_D_SHADER,   "noiseScale");                                                    
      UNIFORM_TEXTURE_DOT3_renderMonkeyish_D                    = glGetUniformLocation(renderMonkeyish_D_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_renderMonkeyish_D                         = glGetUniformLocation(renderMonkeyish_D_SHADER,   "Texture1");                                   
      UNIFORM_ANISO_renderMonkeyish_D                           = glGetUniformLocation(renderMonkeyish_D_SHADER,   "TextureAniso"); 

      #ifdef WIN32  
      loadTexture("_SHADERS/aniso/renderMonkeyish_D/ogl_aniso.tga",                renderMonkeyish_D_ANISOMAP);       
      #endif 




