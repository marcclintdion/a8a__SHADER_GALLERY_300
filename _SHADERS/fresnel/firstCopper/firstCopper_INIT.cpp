    
/*
      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      firstCopper_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_firstCopper =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp   vec4   light_POSITION_01;                                                           \n"                           
      "    uniform highp   vec4   light_POSITION_02;                                                           \n"        
     
      "    uniform         mat4   mvpMatrix;                                                                   \n"          
      "    uniform         mat4   modelView;                                                                   \n"                           
    
      "    uniform         mat4   lightMatrix;                                                                 \n"                           

      "    attribute       vec4   position;                                                                    \n"                           
      "    attribute       vec2   texture;                                                                     \n"                           
 
      "    varying highp   vec4   lightPosition_PASS_01;                                                       \n"                           
      "    varying highp   vec4   lightPosition_PASS_02;                                                       \n"        
      
      "    varying highp   vec2   varTexcoord;                                                                 \n"                           

      "    varying highp   vec4   Vertex;                                                                      \n" 
      "    varying highp   vec3   wsI;                                                                         \n" 
      
      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
      "        Vertex                = mvpMatrix * position;                                                   \n"  
      "        wsI                   = Vertex.xyz;                                                             \n" 
      
      "        lightPosition_PASS_01 = normalize(lightMatrix * light_POSITION_01);                             \n"                           
      "        lightPosition_PASS_02 = normalize(lightMatrix * light_POSITION_02);                             \n"  
      
      "        varTexcoord           = texture;                                                                \n"                           

      "        gl_Position           = mvpMatrix * position;                                                   \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      firstCopper_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(firstCopper_SHADER_VERTEX, 1, &vertexSource_firstCopper, NULL);                                                                        
      glCompileShader(firstCopper_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_firstCopper =                                                                                                            

      " #ifdef GL_ES                                                                                                                                            \n"                       
      " #else                                                                                                                                                   \n"                       
      " #define highp                                                                                                                                           \n"                       
      " #endif                                                                                                                                                  \n"                       

      "     uniform sampler2D     Texture1;                                                                                                                     \n"                       
      "     uniform sampler2D     NormalMap;                                                                                                                    \n"                       
      "     uniform samplerCube   EnvMap;                                                                                                                       \n"   
      
      "     uniform highp float   shininess_01;                                                                                                                 \n"           
      "     uniform highp float   shininess_02;                                                                                                                 \n"                       
      
      "     uniform highp float   attenuation_01;                                                                                                               \n"                       
      "     uniform highp float   attenuation_02;                                                                                                               \n"    
      
      "     varying highp vec4    lightPosition_PASS_01;                                                                                                        \n"                       
      "     varying highp vec4    lightPosition_PASS_02;                                                                                                        \n"           
      
      "     varying highp vec2    varTexcoord;                                                                                                                  \n"                       

      "     varying highp vec4    Vertex;//------------ <--                                                                                                     \n" 
      "     varying highp vec3    wsI;                                                                                                                          \n" 
      
      
      "     highp  vec4           reflectVec_01;                                                                                                                \n"           
      "     highp  vec4           adjustLight_01;                                                                                                                \n"            
      
      "     highp  vec3           normal;                                                                                                                       \n"                       
      "     highp  vec3           NormalTex;                                                                                                                    \n"      
      
      "     highp  float          NdotL1;                                                                                                                       \n"                       
      "     highp  float          NdotL2;                                                                                                                       \n"     
      "     highp  float          NdotL3;                                                                                                                       \n"           
      
                      

     
      "     void main()                                                                                                                                         \n"                       
      "     {                                                                                                                                                   \n"                       
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                                                                \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                                                                      \n"                       
      "         normal                =  normalize(NormalTex);                                                                                                  \n"                       

      "         NdotL1                =  dot(normal, lightPosition_PASS_01.xyz);                                                                                \n"                       
      "         NdotL2                =  dot(normal, lightPosition_PASS_02.xyz);                                                                                \n" 
     
      "         vec3 wsR              =  reflect(wsI, normal);  //------------ <--                                                                              \n"        
      "         vec3 envColor         =  vec3(textureCube(EnvMap, wsR));                                                                                        \n"        
    
      "         adjustLight_01        = lightPosition_PASS_01;                                                                                                  \n"  
      "         adjustLight_01.z      *= -1.0;                                                                                                                  \n"         
 
      "         reflectVec_01         =  vec4(reflect(normal, adjustLight_01.xyz), 1.0);                                                                        \n"  
      
      "         float spec4           =  max(dot(adjustLight_01.xyz, reflectVec_01.xyz), 0.0);                                                                  \n"
      "               spec4           =  pow(spec4, 300.0);                                                                                                     \n"
    
      "         gl_FragColor          =  texture2D(Texture1, varTexcoord.st, 0.0) * 0.5 * vec4(envColor, 1.0)                                                   \n"                       

      "                               +  vec4(1.0, 0.8, 0.0, 1.0) * spec4 * vec4(envColor, 1.0) * 3.0 * NdotL2                                                  \n"      
      
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * NdotL1 * NdotL1 * NdotL1 * attenuation_01                                   \n"                       

      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1, shininess_01) * vec4(1.0, 1.0, 0.1, 1.0)                        \n"                       
     
      "                               +  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL2, shininess_02) * vec4(1.0, 0.4, 0.2, 1.0)* attenuation_02;       \n"                 
      
      
     // "         gl_FragColor          =  vec4(envColor, 1.0);                                                     \n"   
      
      "    }\n";                                                                                                                                   

// vec4(envColor, 1.0) 

*/ 
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#ifdef __APPLE__                                                                                                                          
#import <OpenGLES/ES2/gl.h>                                                                                                               
#import <OpenGLES/ES2/glext.h>                                                                                                            
#endif                                                                                                                                    
//===============================================================================================                                         
firstCopper_SHADER = glCreateProgram();                                                                                                         
//---------------------------------------------------------------------                                                                   
const GLchar *vertexSource_firstCopper =                                                                                                        

"    #define highp                                                                                                                                              \n"                           

"    uniform highp      vec4    light_POSITION_01;                                                                             \n"                           
"    uniform highp      vec4    light_POSITION_02;                                                                             \n"                                
       
"    uniform            mat4    mvpMatrix;                                                                                     \n"          
"    uniform            mat4    modelView;                                                                                     \n"                              

"    uniform            mat4    lightMatrix;                                                                                   \n"                           

"    attribute          vec4    position;                                                                                      \n"                           
"    attribute          vec3    normal;                                                                                        \n"  
"    attribute          vec2    texture;                                                                                       \n"                           

"    varying    highp   vec4    lightPosition_PASS_01;                                                                         \n"                           
"    varying    highp   vec4    lightPosition_PASS_02;                                                                         \n"                            
       
"    varying    highp   vec2    varTexcoord;                                                                                   \n"                           

"    varying    highp   vec4    Vertex;                                                                                        \n"                                                          
"    varying    highp   vec4    inverseEye;                                                                                    \n"   
"    varying    highp   vec3    invertView;                                                                                    \n" 

"    void main()                                                                                                               \n"                           
"    {                                                                                                                         \n"                           
"        Vertex                 = modelView * position;                                                                        \n"  

"        inverseEye             = normalize(lightMatrix * vec4(0.0, 0.0, -1.0, 0.0));                                          \n"          
"        invertView             = normalize(Vertex.xyz * inverseEye.w - inverseEye.xyz * Vertex.w);                            \n"  

"        lightPosition_PASS_01  = normalize(lightMatrix * light_POSITION_01 - Vertex);                                         \n"                     
"        lightPosition_PASS_02  = normalize(lightMatrix * light_POSITION_02 - Vertex);                                         \n"   

"        varTexcoord            = texture;                                                                                     \n"                           

"        gl_Position            = mvpMatrix * position;                                                                        \n"                           
			
"    }\n";                                                                                                                             
//---------------------------------------------------------------------                                                                   
firstCopper_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
glShaderSource(firstCopper_SHADER_VERTEX, 1, &vertexSource_firstCopper, NULL);                                                                        
glCompileShader(firstCopper_SHADER_VERTEX);                                                                                                     
//---------------------------------------------------------------------                                                                   
const GLchar *fragmentSource_firstCopper =                                                                                                            

" #ifdef GL_ES                                                                                                                                                  \n"                       
" #else                                                                                                                                                         \n"                       
" #define highp                                                                                                                                                 \n"                       
" #endif                                                                                                                                                        \n"                       

"     uniform   sampler2D    Texture1;                                                                                                                          \n"                       
"     uniform   sampler2D    NormalMap;                                                                                                                         \n"                       
"     uniform   sampler2D    FresnelMap;                                                                                                                        \n"             

"     uniform   highp float  shininess_01;                                                                                                                      \n"           
"     uniform   highp float  shininess_02;                                                                                                                      \n"                       

"     uniform   highp float  attenuation_01;                                                                                                                    \n"                       
"     uniform   highp float  attenuation_02;                                                                                                                    \n"    

"     varying   highp vec4   lightPosition_PASS_01;                                                                                                             \n"                       
"     varying   highp vec4   lightPosition_PASS_02;                                                                                                             \n"                     
                
"     varying   highp vec2   varTexcoord;                                                                                                                       \n"                       
                                                                                                                      
"               highp vec3   normal;                                                                                                                            \n"                       
"               highp vec3   NormalTex;                                                                                                                         \n"      

"               highp vec3   wsR;                                                                                                                               \n"        
"               highp vec3   envColor;                                                                                                                          \n"   

"               highp float  NdotL1;                                                                                                                            \n"                       
"               highp float  NdotL2;                                                                                                                            \n"            



"               highp vec4   ka;                                                                                                                                \n"                                                    
"               highp vec4   color;                                                                                                                             \n" 
"               highp vec4   specular;                                                                                                                          \n" 
"               highp vec4   color_A;                                                                                                                           \n" 
"               highp vec4   color_B;                                                                                                                           \n" 

"     varying   highp vec4   Vertex;                                                                                                                            \n"                                                          
"     varying   highp vec4   inverseEye;                                                                                                                        \n" 
"     varying   highp vec3   invertView;                                                                                                                        \n"  
"               highp vec4   fresnelTexture;                                                                                                                    \n" 
"               highp float  fresnelReflectance = 0.1;                                                                                                          \n" 	                                                      
"               highp vec3   Reflect;                                                                                                                           \n"                                                                  
"               highp vec3   RH;                                                                                                                                \n"                                                               
"               highp float  fresnel;                                                                                                                           \n" 

"     void main()                                                                                                                                               \n"                       
"     {                                                                                                                                                         \n"                       
"         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                                                                      \n"                       
"         NormalTex             = (NormalTex - 0.5);                                                                                                            \n"                       
"         normal                =  normalize(NormalTex);                                                                                                        \n"                       

"         NdotL1                =  dot(normal, lightPosition_PASS_01.xyz);                                                                                      \n"                       
"         NdotL2                =  dot(normal, lightPosition_PASS_02.xyz);                                                                                      \n"   

"         color                 =  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1,  200.0);                                                              \n"//vec4(0.9, 0.6, 0.6, 1.0) 

"         Reflect               =  reflect(invertView, normal);                                                                                                 \n"
"         RH                    =  normalize(Reflect + invertView);                                                                                             \n"
"         fresnel               =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(dot(invertView, RH), 500.0) * NdotL2;                                  \n" 
"         fresnelTexture        =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + vec3(0.0, 0.0, 1.0)).xy) * 4.0;                                        \n" 

"         color_A               =  mix(color, fresnelTexture, fresnel) * NdotL1 * attenuation_01;                                                               \n"

"         color_B               =  texture2D(Texture1, varTexcoord.st) * pow(NdotL2, shininess_01) * vec4(1.0, 1.0, 0.1, 1.0);                                  \n"   


"         gl_FragColor          =  color_A + color_B + pow(NdotL2, shininess_01 * 2.0) + pow(NdotL1,  700.0);                                                   \n"

"    }\n"; 
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      //---------------------------------------------------------------------                                                                         
      firstCopper_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(firstCopper_SHADER_FRAGMENT, 1, &fragmentSource_firstCopper, NULL);                                                                          
      glCompileShader(firstCopper_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(firstCopper_SHADER, firstCopper_SHADER_VERTEX);                                                                                              
      glAttachShader(firstCopper_SHADER, firstCopper_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(firstCopper_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(firstCopper_SHADER,    1, "normal");       
      glBindAttribLocation(firstCopper_SHADER,    2, "texture");                                                                                             
                                                                                          
      //------------------------------------------------                                                                                              
      glLinkProgram(firstCopper_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(firstCopper_SHADER, firstCopper_SHADER_VERTEX);                                                                                              
      glDetachShader(firstCopper_SHADER, firstCopper_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(firstCopper_SHADER_VERTEX);                                                                                                            
      glDeleteShader(firstCopper_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_firstCopper                   = glGetUniformLocation(firstCopper_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_firstCopper                       = glGetUniformLocation(firstCopper_SHADER,   "modelView");      
      UNIFORM_LIGHT_MATRIX_firstCopper                    = glGetUniformLocation(firstCopper_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_firstCopper               = glGetUniformLocation(firstCopper_SHADER,   "light_POSITION_01");
      UNIFORM_LIGHT_POSITION_02_firstCopper               = glGetUniformLocation(firstCopper_SHADER,   "light_POSITION_02");                                            
      UNIFORM_SHININESS_01_firstCopper                    = glGetUniformLocation(firstCopper_SHADER,   "shininess_01");                                              
      UNIFORM_SHININESS_02_firstCopper                    = glGetUniformLocation(firstCopper_SHADER,   "shininess_02");       
      UNIFORM_ATTENUATION_01_firstCopper                  = glGetUniformLocation(firstCopper_SHADER,   "attenuation_01");     
      UNIFORM_ATTENUATION_02_firstCopper                  = glGetUniformLocation(firstCopper_SHADER,   "attenuation_02");                                                    
      UNIFORM_TEXTURE_DOT3_firstCopper                    = glGetUniformLocation(firstCopper_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_firstCopper                         = glGetUniformLocation(firstCopper_SHADER,   "Texture1"); 
      UNIFORM_FRESNELMAP_firstCopper                      = glGetUniformLocation(firstCopper_SHADER,   "FresnelMap");   

//------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
#ifdef __APPLE__                                                                                                                          
filePathName = [[NSBundle mainBundle] pathForResource:@"cornerStone_firstCopper" ofType:@"png"];                                                  
image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
glGenTextures(1, &firstCopper_FRESNELMAP);                                                                                                     
glBindTexture(GL_TEXTURE_2D, firstCopper_FRESNELMAP);                                                                                          
ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
imgDestroyImage(image);                                                                                                                   
#endif                                                                                                                                    
//------------------------------------------------------------------------------------------ 
      #ifdef WIN32  
      loadTexture("_SHADERS/fresnel/firstCopper/cornerStone_firstCopper.png",                firstCopper_FRESNELMAP);       
      #endif 

//##########################################################################################################################################








