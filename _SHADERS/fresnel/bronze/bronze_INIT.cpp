     #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      bronze_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_bronze =                                                                                                        

"    #define highp                                                                                                                                              \n"                           

"    uniform highp      vec4    light_POSITION_01;                                                                                                              \n"                           
 
"    uniform            mat4    mvpMatrix;                                                                                                                      \n"          
"    uniform            mat4    modelView;                                                                                                                      \n"                              

"    uniform            mat4    lightMatrix;                                                                                                                    \n"                           

"    attribute          vec4    position;                                                                                                                       \n"                           
"    attribute          vec2    texture;                                                                                                                        \n"                           

"    varying    highp   vec4    lightPosition_PASS_01;                                                                                                          \n"                           

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

"        varTexcoord            = texture;                                                                                                                      \n"                           

"        gl_Position            = mvpMatrix * position;                                                                                                         \n"                           
			
"    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      bronze_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(bronze_SHADER_VERTEX, 1, &vertexSource_bronze, NULL);                                                                        
      glCompileShader(bronze_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_bronze =                                                                                                            

" #ifdef GL_ES                                                                                                                                                  \n"                       
" #else                                                                                                                                                         \n"                       
" #define highp                                                                                                                                                 \n"                       
" #endif                                                                                                                                                        \n"                       

"     uniform   sampler2D    Texture1;                                                                                                                          \n"                       
"     uniform   sampler2D    NormalMap;                                                                                                                         \n"                       
"     uniform   sampler2D    FresnelMap;                                                                                                                        \n"             

"     uniform   highp float  shininess_01;                                                                                                                      \n"           

"     uniform   highp float  attenuation_01;                                                                                                                    \n"                       

"     varying   highp vec4   lightPosition_PASS_01;                                                                                                             \n"                       

"     varying   highp vec2   varTexcoord;                                                                                                                       \n"                       
                                                                                                                      
"               highp vec3   normal;                                                                                                                            \n"                       
"               highp vec3   NormalTex;                                                                                                                         \n"      

"               highp vec3   wsR;                                                                                                                               \n"        
"               highp vec3   envColor;                                                                                                                          \n"   

"               highp float  NdotL1;                                                                                                                            \n"                       

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

"         color                 =  texture2D(Texture1, varTexcoord.st, 0.0) * pow(NdotL1,  200.0);                                                              \n"//vec4(0.9, 0.6, 0.6, 1.0) 

"         Reflect               =  reflect(invertView, normal);                                                                                                 \n"

"         RH                    =  normalize(Reflect + invertView);                                                                                             \n"

"         fresnel               =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(dot(invertView, RH), 500.0) * NdotL1;                                  \n" 

"         fresnelTexture        =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + vec3(0.0, 0.0, 1.0)).xy) * 4.0;                                        \n" 

"         color_A               =  mix(color, fresnelTexture, fresnel);                                                               \n"

"         color_B               =  texture2D(Texture1, varTexcoord.st) * pow(NdotL1, shininess_01) * vec4(2.0, 1.0, 0.1, 1.0)*.5;                                  \n"   

"         gl_FragColor          =   (color_A * 0.2+ color_A *color_B + pow(NdotL1, shininess_01 ) * pow(NdotL1,  700.0)) * attenuation_01* NdotL1;                                                   \n"

"    }\n"; 
      //---------------------------------------------------------------------                                                                         
      bronze_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(bronze_SHADER_FRAGMENT, 1, &fragmentSource_bronze, NULL);                                                                          
      glCompileShader(bronze_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(bronze_SHADER, bronze_SHADER_VERTEX);                                                                                              
      glAttachShader(bronze_SHADER, bronze_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(bronze_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(bronze_SHADER,    1, "normal");       
      glBindAttribLocation(bronze_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(bronze_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(bronze_SHADER, bronze_SHADER_VERTEX);                                                                                              
      glDetachShader(bronze_SHADER, bronze_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(bronze_SHADER_VERTEX);                                                                                                            
      glDeleteShader(bronze_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_bronze                   = glGetUniformLocation(bronze_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_bronze                       = glGetUniformLocation(bronze_SHADER,   "modelView");      
      UNIFORM_LIGHT_MATRIX_bronze                    = glGetUniformLocation(bronze_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_bronze               = glGetUniformLocation(bronze_SHADER,   "light_POSITION_01");
                                        
      UNIFORM_SHININESS_01_bronze                    = glGetUniformLocation(bronze_SHADER,   "shininess_01");                                              
    
      UNIFORM_ATTENUATION_01_bronze                  = glGetUniformLocation(bronze_SHADER,   "attenuation_01");     
                                                
      UNIFORM_TEXTURE_DOT3_bronze                    = glGetUniformLocation(bronze_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_bronze                         = glGetUniformLocation(bronze_SHADER,   "Texture1"); 
      UNIFORM_FRESNELMAP_bronze                      = glGetUniformLocation(bronze_SHADER,   "FresnelMap");   
//==============================================================================================================================
#ifdef __APPLE__                                                                                                                          
filePathName = [[NSBundle mainBundle] pathForResource:@"cornerStone_bronze" ofType:@"png"];                                                  
image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
glGenTextures(1, &bronze_FRESNELMAP);                                                                                                     
glBindTexture(GL_TEXTURE_2D, bronze_FRESNELMAP);                                                                                          
ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
imgDestroyImage(image);                                                                                                                   
#endif
//----------------------------------------------------------------------------------------------------------------------------                                                                   
      #ifdef WIN32  
      loadTexture("_SHADERS/fresnel/bronze/cornerStone_bronze.png",                bronze_FRESNELMAP);       
      #endif 








