    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      minnaert_A_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_minnaert_A =                                                                                                        

      "    #define highp                                                                                                                         \n"        

      "    uniform highp vec4   light_POSITION_01;                                                                                               \n"        
      "    uniform       mat4   mvpMatrix;                                                                                                       \n"      
      "    uniform       mat4   mvMatrix;                                                                                                        \n"  
           //-----
      "    uniform       mat4   viewMatrix;                                                                                                      \n"                   
           //-----
      "    uniform       mat4   projectionShadow;                                                                                                \n"        
      "    uniform       mat4   modelViewShadow;                                                                                                 \n"        
           //-----   
      "    uniform       mat4   lightMatrix;                                                                                                     \n"     
      "    uniform       mat4   textureMatrix;                                                                                                   \n"  
           //-----
      "    attribute     vec4   position;                                                                                                        \n"      
      "    attribute     vec2   texture;                                                                                                         \n"       

      "    uniform highp float  generic;                                                                                                         \n"       
      
      "    varying highp vec4   lightPosition_PASS;                                                                                              \n" 
      "    varying highp vec4   position_PASS;                                                                                                   \n"        
 
      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                                  \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);              \n"
      //-------------------------------------------- 
      "    varying highp vec2  varTexcoord;                                                                                                      \n"
      
    
      
      //=========================================================================================================================================
      "    void main()                                                                                                                           \n" 
      "    {                                                                                                                                     \n"
     
   
      "            shadowTexcoord        =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;                \n" 
      "            shadowTexcoord        =   shadowTexcoord / shadowTexcoord.w;                                                                  \n"      
                   //---------------------------------------------------------------------------------------------------------

      "            position_PASS         =   normalize(lightMatrix * position);                                             \n"       
      
                   //---------------------------------------------------------------------------------------------------------      
      "            lightPosition_PASS    =   normalize(lightMatrix * light_POSITION_01);                                                          \n"        

      "            varTexcoord           =   texture;                                                                                             \n"          
      "            gl_Position           =   mvpMatrix * position;                                                                                \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      minnaert_A_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(minnaert_A_SHADER_VERTEX, 1, &vertexSource_minnaert_A, NULL);                                                                        
      glCompileShader(minnaert_A_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_minnaert_A =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"   
  
      "    uniform sampler2D    Texture1;                                                                                                         \n"                       
      "    uniform sampler2D    NormalMap;                                                                                                        \n"                       
      //--------------------------------------------
      "    uniform sampler2D    ShadowTexture;                                                                                                    \n"     
      "    varying highp vec4   shadowTexcoord;                                                                                                   \n"  
      //--------------------------------------------         
      "    uniform highp float  generic;                                                                                                         \n"       
       
 
      "    uniform highp float  shininess;                                                                                                        \n"                       

      "    varying highp vec4   lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec4   position_PASS;                                                                                               \n"        
      "    varying highp vec2   varTexcoord;                                                                                                      \n"                       

      "            highp float  NdotL1;                                                                                                           \n"                       
      "            highp vec3   normal_FRAG;                                                                                                      \n"                       
      "            highp vec3   NormalTex;                                                                                                        \n"                       
      //--------------------------------------------    
      "            highp vec4   Color;                                                                                                            \n"                       



      //===================================================================================================================
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
 
      //------------------------------------------------------------------------------------------------------------  
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                            \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                             \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                          \n" 
      //------------------------------------------------------------------------------------------------------------   
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                     \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                           \n"                       
      "         normal_FRAG               =  normalize(NormalTex);                                                       \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                         \n"                       
      //------------------------------------------------------------------------------------------------------------  
      //PDF:Advanced Lighting and Materials with Shaders ~Kelly Dempski and Emmanuel Viale
      //-----------------------------------------------
      "         highp vec3 PixelToEye     =  normalize(position_PASS.xyz);                                               \n"  

      "         highp float NdotV         =  max(dot(normal_FRAG, PixelToEye), 0.0);                                     \n"  

      "         highp float Irradiance    =  max(0.0, NdotL1);                                                           \n"  
      "         highp vec4 DiffuseColor   =  texture2D(Texture1,  varTexcoord) * highp vec4(.99, .5, .1, 1.0) ;	                                         \n"  
      "         highp float Power         =  generic;                                                                    \n"  
      "         Color                     =  DiffuseColor * pow(NdotV * NdotL1, Power) * Irradiance;                     \n"  
      

      //-------------------------------------------------------------------------------------------------------------   


     "         gl_FragColor              = texture2D(Texture1,  varTexcoord) * NdotL1 * NdotL1 * 0.5 + Color * 0.5;             \n"                       


      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      minnaert_A_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(minnaert_A_SHADER_FRAGMENT, 1, &fragmentSource_minnaert_A, NULL);                                                                          
      glCompileShader(minnaert_A_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(minnaert_A_SHADER, minnaert_A_SHADER_VERTEX);                                                                                              
      glAttachShader(minnaert_A_SHADER, minnaert_A_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(minnaert_A_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(minnaert_A_SHADER,    1, "normal");       
      glBindAttribLocation(minnaert_A_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(minnaert_A_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(minnaert_A_SHADER, minnaert_A_SHADER_VERTEX);                                                                                              
      glDetachShader(minnaert_A_SHADER, minnaert_A_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(minnaert_A_SHADER_VERTEX);                                                                                                            
      glDeleteShader(minnaert_A_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_minnaert_A                   = glGetUniformLocation(minnaert_A_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_minnaert_A                       = glGetUniformLocation(minnaert_A_SHADER,      "mvMatrix");       
      //-------------------------------      
      UNIFORM_viewMatrix_minnaert_A                      = glGetUniformLocation(minnaert_A_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_minnaert_A                     = glGetUniformLocation(minnaert_A_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_minnaert_A                 = glGetUniformLocation(minnaert_A_SHADER,      "modelViewShadow");            
      //-------------------------------                                              
      UNIFORM_LIGHT_MATRIX_minnaert_A                    = glGetUniformLocation(minnaert_A_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_minnaert_A                   = glGetUniformLocation(minnaert_A_SHADER,      "textureMatrix"); 
      //-------------------------------  
      UNIFORM_SHADOW_PROJ_minnaert_A                     = glGetUniformLocation(minnaert_A_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_minnaert_A                 = glGetUniformLocation(minnaert_A_SHADER,      "modelViewShadow");            
      //-------------------------------  
      UNIFORM_LIGHT_POSITION_01_minnaert_A               = glGetUniformLocation(minnaert_A_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_minnaert_A                       = glGetUniformLocation(minnaert_A_SHADER,      "shininess");
      UNIFORM_GENERIC_minnaert_A                         = glGetUniformLocation(minnaert_A_SHADER,      "generic");      
                                                    
      UNIFORM_TEXTURE_SHADOW_minnaert_A                  = glGetUniformLocation(minnaert_A_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_DOT3_minnaert_A                    = glGetUniformLocation(minnaert_A_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_minnaert_A                         = glGetUniformLocation(minnaert_A_SHADER,      "Texture1");                                   

      


