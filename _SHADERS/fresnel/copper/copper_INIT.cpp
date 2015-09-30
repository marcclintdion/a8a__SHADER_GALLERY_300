      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      copper_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_copper =                                                                                                        

"    #define highp                                                                                                                                              \n"                           

"    uniform highp      vec4    light_POSITION_01;                                                                                                              \n"                           
"    uniform highp      vec4    light_POSITION_02;                                                                                                              \n"                                
       
"    uniform            mat4    mvpMatrix;                                                                                                                      \n"          
"    uniform            mat4    modelView;                                                                                                                      \n"                              

"    uniform            mat4    lightMatrix;                                                                                                                    \n"                           

"    attribute          vec4    position;                                                                                                                       \n"                           
"    attribute          vec2    texture;                                                                                                                        \n"                           

"    varying    highp   vec4    lightPosition_PASS_01;                                                                                                          \n"                           
"    varying    highp   vec4    lightPosition_PASS_02;                                                                                                          \n"                            
       
"    varying    highp   vec2    varTexcoord;                                                                                                                    \n"                           

"    varying    highp   vec4    Vertex;                                                                                                                         \n"                                                          
"    varying    highp   vec4    inverseEye;                                                                                                                     \n"   
"    varying    highp   vec3    invertView;                                                                                                                     \n" 

"    void main()                                                                                                                                                \n"                           
"    {                                                                                                                                                          \n"                           
"        Vertex                 = modelView * position;                                                                                                         \n"  

"        inverseEye             = normalize(lightMatrix * vec4(0.0, 0.0, -1.0, 0.0));                                                                           \n"          
"        invertView             = normalize(Vertex.xyz * inverseEye.w - inverseEye.xyz * Vertex.w);                                                             \n"  

"        lightPosition_PASS_01  = normalize(lightMatrix * light_POSITION_01 - Vertex);                                                                          \n"//!!!!!!__VERIFY USING MOST RECENT iOS_WIN                     
"        lightPosition_PASS_02  = normalize(lightMatrix * light_POSITION_02 - Vertex);                                                                          \n"   

"        varTexcoord            = texture;                                                                                                                      \n"                           

"        gl_Position            = mvpMatrix * position;                                                                                                         \n"                           
			
"    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      copper_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(copper_SHADER_VERTEX, 1, &vertexSource_copper, NULL);                                                                        
      glCompileShader(copper_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_copper =                                                                                                            

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

"     varying   highp vec4   Vertex;                                                                                                                            \n"                                                          
"     varying   highp vec4   inverseEye;                                                                                                                        \n" 
"     varying   highp vec3   invertView;                                                                                                                        \n"  

"               highp float  fresnelReflectance = 0.1;                                                                                                          \n" 	                                                      

"               highp vec4   ka;                                                                                                                                \n"                                                    
"               highp vec4   color;                                                                                                                             \n" 
"               highp vec4   fresnelTexture;                                                                                                                    \n" 
"               highp vec4   specular;                                                                                                                          \n" 
"               highp vec4   color_A;                                                                                                                           \n" 
"               highp vec4   color_B;                                                                                                                           \n" 

                                                                  
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

"         color                 =  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1,  200.0)*.5;                                                              \n"//vec4(0.9, 0.6, 0.6, 1.0) 

"         Reflect               =  reflect(invertView, normal);                                                                                                 \n"

"         RH                    =  normalize(Reflect + invertView);                                                                                             \n"

"         fresnel               =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(dot(invertView, RH), 500.0) * NdotL2;                                  \n" 

"         fresnelTexture        =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + vec3(0.0, 0.0, 1.0)).xy) * 4.0;                                        \n" 

"         color_A               =  mix(color, fresnelTexture, fresnel) * NdotL1 * attenuation_01;                                                               \n"

"         color_B               =  texture2D(Texture1, varTexcoord.st) * pow(NdotL2, shininess_01) * vec4(2.0, 1.0, 0.1, 1.0)*.5;                                  \n"   

"         gl_FragColor          =   (color_A + color_B + pow(NdotL2, shininess_01 * 2.0)*.5 + pow(NdotL1,  700.0))*.5;                                                   \n"

"    }\n"; 
      //---------------------------------------------------------------------                                                                         
      copper_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(copper_SHADER_FRAGMENT, 1, &fragmentSource_copper, NULL);                                                                          
      glCompileShader(copper_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(copper_SHADER, copper_SHADER_VERTEX);                                                                                              
      glAttachShader(copper_SHADER, copper_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(copper_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(copper_SHADER,    1, "normal");       
      glBindAttribLocation(copper_SHADER,    2, "texture");                                                                                                 
      //------------------------------------------------                                                                                              
      glLinkProgram(copper_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(copper_SHADER, copper_SHADER_VERTEX);                                                                                              
      glDetachShader(copper_SHADER, copper_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(copper_SHADER_VERTEX);                                                                                                            
      glDeleteShader(copper_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_copper                   = glGetUniformLocation(copper_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_copper                       = glGetUniformLocation(copper_SHADER,   "modelView");      
      UNIFORM_LIGHT_MATRIX_copper                    = glGetUniformLocation(copper_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_copper               = glGetUniformLocation(copper_SHADER,   "light_POSITION_01");
      UNIFORM_LIGHT_POSITION_02_copper               = glGetUniformLocation(copper_SHADER,   "light_POSITION_02");                                            
      UNIFORM_SHININESS_01_copper                    = glGetUniformLocation(copper_SHADER,   "shininess_01");                                              
      UNIFORM_SHININESS_02_copper                    = glGetUniformLocation(copper_SHADER,   "shininess_02");       
      UNIFORM_ATTENUATION_01_copper                  = glGetUniformLocation(copper_SHADER,   "attenuation_01");     
      UNIFORM_ATTENUATION_02_copper                  = glGetUniformLocation(copper_SHADER,   "attenuation_02");                                                    
      UNIFORM_TEXTURE_DOT3_copper                    = glGetUniformLocation(copper_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_copper                         = glGetUniformLocation(copper_SHADER,   "Texture1"); 
      UNIFORM_FRESNELMAP_copper                      = glGetUniformLocation(copper_SHADER,   "FresnelMap");  


//==============================================================================================================================
#ifdef __APPLE__                                                                                                                          
filePathName = [[NSBundle mainBundle] pathForResource:@"cornerStone_copper" ofType:@"png"];                                                  
image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
glGenTextures(1, &copper_FRESNELMAP);                                                                                                     
glBindTexture(GL_TEXTURE_2D, copper_FRESNELMAP);                                                                                          
ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
imgDestroyImage(image);                                                                                                                   
#endif
//----------------------------------------------------------------------------------------------------------------------------

      #ifdef WIN32  
      loadTexture("_SHADERS/cornerStone_FRa.png",                copper_FRESNELMAP);       
      #endif 





