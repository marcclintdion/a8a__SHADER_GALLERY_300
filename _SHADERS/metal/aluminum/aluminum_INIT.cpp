    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      aluminum_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_aluminum =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   mvMatrix;                                                                      \n"        
     
      "    uniform       mat4   lightMatrix1;                                                                   \n"                           
      "    uniform       mat4   lightMatrix2;                                                                   \n"   
      
      "    varying highp   vec4    lightPosition_PASS_01;                                                    \n" 
      "    varying highp   vec4    lightPosition_PASS_02;                                                    \n"             


      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec3   normal;                                                                        \n"      
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying highp vec3   vViewVec;                                                                      \n"        
      "    varying highp vec3   vNormal;                                                                       \n"       
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

        "    varying    highp   vec4    inverseEye;                                                                                     \n"   

      "    void main()                                                                                                          \n"                           
      "    {                                                                                                                    \n"                           

      "        inverseEye             = normalize(lightMatrix2 * highp vec4(0.0, 0.0, 1.0, 0.0));                                     \n"          
 
      //---------------------------------------------------------------------------------------------------------------------

      //---------------------------------------------------------------------------------------------------------------------

      "        lightPosition_PASS_01  = normalize(lightMatrix1 * light_POSITION_01);                                                    \n"      
      "        lightPosition_PASS_02  = normalize(lightMatrix2 * light_POSITION_01);                                                    \n"
      
      "        varTexcoord             = texture;                                                                               \n"                           
      "        gl_Position             = mvpMatrix * position;                                                                  \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      aluminum_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(aluminum_SHADER_VERTEX, 1, &vertexSource_aluminum, NULL);                                                                        
      glCompileShader(aluminum_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_aluminum =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform highp vec4   light_POSITION_01;                                                                       \n"          
      "    uniform sampler2D    FresnelMap;                                                                              \n"         
      "    uniform sampler2D    Texture1;                                                                                \n"                       
      "    uniform sampler2D    NormalMap;                                                                               \n"                       
      "    uniform highp float  shininess;                                                                               \n"                       
      "    uniform highp float  attenuation;                                                                             \n"                       
      
      "    varying highp vec4   lightPosition_PASS_01;                                                                   \n"        
      "    varying highp vec4   lightPosition_PASS_02;                                                                   \n"     

      "    varying highp vec2   varTexcoord;                                                                             \n"                       

      "    varying    highp   vec4    inverseEye;                                                                        \n"   
      "               highp   vec3    invertView;                                                                        \n" 
      
      "            highp vec4   fresnelTexture;                                                                          \n"
      "            highp vec4   diffuseTexture;                                                                          \n"      
      "            highp vec3   reflection;                                                                              \n"                      
      "            highp vec3   normal_1;                                                                                \n"                       
      "            highp vec3   normal_2;                                                                                \n"       
      "            highp vec3   NormalTex;                                                                               \n"                       
      "            highp float  NdotL1;                                                                                  \n"       
      "            highp float  NdotL2;                                                                                  \n"                       

      "            highp float  fresnelReflectance = 0.1;                                                                \n" 	                                                      
      "            highp vec3   Reflect;                                                                                 \n"                                                                  
      "            highp vec3   RH;                                                                                      \n"                                                               
      "            highp float  fresnel;                                                                                 \n" 
     
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
     

//===================================================================================================================================      
  
      "         diffuseTexture        =  texture2D(Texture1,  varTexcoord);                                              \n"      
      "         fresnelTexture        =  texture2D(FresnelMap,  varTexcoord);                                            \n"            
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
      //------------------------------------------------------------------------------------
      "         normal_1              =  normalize(NormalTex)/texture2D(Texture1,  varTexcoord).w;                       \n"      
      "         NdotL1                =  max(dot(normal_1, lightPosition_PASS_01.xyz), 0.0);                             \n"                       
      //------------------------------------------------------------------------------------     
      "         normal_2              =  normalize(NormalTex)/texture2D(Texture1,  varTexcoord).w;                       \n"      
      "         NdotL2                =  max(dot(normal_2, lightPosition_PASS_02.xyz), 0.0);                             \n"                       
      //------------------------------------------------------------------------------------     
      "         invertView            =  normalize(inverseEye.xyz);                                                      \n"  
     
      "         Reflect               =  reflect(invertView, normal_2);                                                        \n"
      "         RH                    =  normalize(Reflect + invertView);                                                                                             \n"
      "         fresnel               =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(dot(invertView, RH), 500.0);    \n" 
      "         fresnelTexture        =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + highp vec3(0.0, 0.0, 1.0)).xy); \n" 
       //------------------------------------------------------------------------------------        
      "         highp vec4 color_1    =  highp vec4(1.0, 1.0, 1.0, 1.0) *  NdotL1 * NdotL1;                                    \n"      
      "         highp vec4 color_2    =  highp vec4(1.0, 1.0, 1.0, 1.0) *  NdotL2 * NdotL2;                                    \n"       
      
      "         highp float shiny     =  max(pow(NdotL2, 40.0), 0.0);                                                    \n"  
      
      "         gl_FragColor          =  (diffuseTexture * color_1 * 0.4)                                                \n"   
      "                               +  (diffuseTexture * color_2 * 0.2)                                                \n"   
      "                               +  (fresnelTexture * 0.4 *  NdotL2)                                                \n"   
      "                               +   highp vec4(1.0, 0.7, 0.2, 1.0) * shiny * 1.0;                                  \n"                       
  
     
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      aluminum_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(aluminum_SHADER_FRAGMENT, 1, &fragmentSource_aluminum, NULL);                                                                          
      glCompileShader(aluminum_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(aluminum_SHADER, aluminum_SHADER_VERTEX);                                                                                              
      glAttachShader(aluminum_SHADER, aluminum_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(aluminum_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(aluminum_SHADER,    1, "normal");       
      glBindAttribLocation(aluminum_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(aluminum_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(aluminum_SHADER, aluminum_SHADER_VERTEX);                                                                                              
      glDetachShader(aluminum_SHADER, aluminum_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(aluminum_SHADER_VERTEX);                                                                                                            
      glDeleteShader(aluminum_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_aluminum                   = glGetUniformLocation(aluminum_SHADER,   "mvpMatrix"); 
      UNIFORM_MODELVIEW_aluminum                       = glGetUniformLocation(aluminum_SHADER,   "mvMatrix");                                                    
      UNIFORM_LIGHT_MATRIX_1_aluminum                  = glGetUniformLocation(aluminum_SHADER,   "lightMatrix1");
      UNIFORM_LIGHT_MATRIX_2_aluminum                  = glGetUniformLocation(aluminum_SHADER,   "lightMatrix2");                                                 
      UNIFORM_LIGHT_POSITION_01_aluminum               = glGetUniformLocation(aluminum_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_aluminum                       = glGetUniformLocation(aluminum_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_aluminum                     = glGetUniformLocation(aluminum_SHADER,   "attenuation"); 
      UNIFORM_TEXTURE_aluminum_FRESNEL                 = glGetUniformLocation(aluminum_SHADER,   "FresnelMap");                                                    
      UNIFORM_TEXTURE_DOT3_aluminum                    = glGetUniformLocation(aluminum_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_aluminum                         = glGetUniformLocation(aluminum_SHADER,   "Texture1");   
      
      
 //------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES                
#ifdef __APPLE__                                                                                                                          
filePathName = [[NSBundle mainBundle] pathForResource:@"cornerStone" ofType:@"png"];                                                  
image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
glGenTextures(1, &aluminum_FRESNELMAP);                                                                                                     
glBindTexture(GL_TEXTURE_2D, aluminum_FRESNELMAP);                                                                                          
ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
imgDestroyImage(image);                                                                                                                   
#endif                                                                                                                                    
//------------------------------------------------------------------------------------------ 
      #ifdef WIN32  
      loadTexture("_SHADERS/metal/aluminum/cornerStone.png",                aluminum_FRESNELMAP);       
      #endif 

//##########################################################################################################################################
     
      
      
      
      
                                  
