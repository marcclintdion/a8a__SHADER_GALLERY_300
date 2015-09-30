      #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      squishy_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_squishy =                                                                                                        

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
      squishy_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(squishy_SHADER_VERTEX, 1, &vertexSource_squishy, NULL);                                                                        
      glCompileShader(squishy_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_squishy =                                                                                                            

//" #ifdef GL_ES                                                                                                                                                  \n"                       
//" #else                                                                                                                                                         \n"                       
//" #define highp                                                                                                                                                 \n"                       
//" #endif                                                                                                                                                        \n"                       
     
" #ifdef GL_ES                                                                                                                                                  \n"                       
" #else                                                                                                                                                         \n"                       
" #define highp                                                                                                                                                 \n"                       
" #endif                                                                                                                                                        \n"                       
               
      //=====================================================================================================================

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
//"         NdotL2                =  dot(normal, lightPosition_PASS_02.xyz);                                                                                      \n"   

"         color                 =  texture2D(Texture1, varTexcoord.st, 0.0) * attenuation_01;                                                              \n"//vec4(0.9, 0.6, 0.6, 1.0) 

"         Reflect               =  reflect(invertView, normal);                                                                                                 \n"

"         RH                    =  normalize(Reflect + invertView);                                                                                             \n"

"         color_B               =  texture2D(Texture1, varTexcoord.st) * pow(NdotL1, shininess_01) * vec4(2.0, 1.0, 0.1, 1.0)*.5;                                  \n"   

"         gl_FragColor          =   (color + color_B + pow(NdotL1, shininess_01 * 2.0)*NdotL1 + pow(NdotL1,  700.0))*.5;                                                   \n"

"    }\n"; 
      //---------------------------------------------------------------------                                                                         
      squishy_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(squishy_SHADER_FRAGMENT, 1, &fragmentSource_squishy, NULL);                                                                          
      glCompileShader(squishy_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(squishy_SHADER, squishy_SHADER_VERTEX);                                                                                              
      glAttachShader(squishy_SHADER, squishy_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(squishy_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(squishy_SHADER,    1, "normal");       
      glBindAttribLocation(squishy_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(squishy_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(squishy_SHADER, squishy_SHADER_VERTEX);                                                                                              
      glDetachShader(squishy_SHADER, squishy_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(squishy_SHADER_VERTEX);                                                                                                            
      glDeleteShader(squishy_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_squishy                   = glGetUniformLocation(squishy_SHADER,   "mvpMatrix");                                              
      UNIFORM_MODELVIEW_squishy                       = glGetUniformLocation(squishy_SHADER,   "modelView");      
      UNIFORM_LIGHT_MATRIX_squishy                    = glGetUniformLocation(squishy_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_squishy               = glGetUniformLocation(squishy_SHADER,   "light_POSITION_01");
      UNIFORM_LIGHT_POSITION_02_squishy               = glGetUniformLocation(squishy_SHADER,   "light_POSITION_02");                                            
      UNIFORM_SHININESS_01_squishy                    = glGetUniformLocation(squishy_SHADER,   "shininess_01");                                              
      UNIFORM_SHININESS_02_squishy                    = glGetUniformLocation(squishy_SHADER,   "shininess_02");       
      UNIFORM_ATTENUATION_01_squishy                  = glGetUniformLocation(squishy_SHADER,   "attenuation_01");     
      UNIFORM_ATTENUATION_02_squishy                  = glGetUniformLocation(squishy_SHADER,   "attenuation_02");                                                    
      UNIFORM_TEXTURE_DOT3_squishy                    = glGetUniformLocation(squishy_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_squishy                         = glGetUniformLocation(squishy_SHADER,   "Texture1"); 
      UNIFORM_FRESNELMAP_squishy                      = glGetUniformLocation(squishy_SHADER,   "FresnelMap");   
