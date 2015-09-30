    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      HEMI_MIX_1_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_HEMI_MIX_1 =                                                                                                        

      "    #define highp                                                                                                                         \n"        

      "    uniform highp vec4   light_POSITION_01;                                                                                  \n"        
      "    uniform       mat4   mvpMatrix;                                                                                          \n"      
      "    uniform       mat4   mvMatrix;                                                                                           \n"  
      "    uniform       mat4   modelRotationMatrix;                                                                                \n"  
           //-----
      "    uniform       mat4   viewMatrix;                                                                                         \n"                   
           //-----
      "    uniform       mat4   projectionShadow;                                                                                   \n"        
      "    uniform       mat4   modelViewShadow;                                                                                    \n"        
           //-----   
      "    uniform       mat4   lightMatrix;                                                                                        \n"     
      "    uniform       mat4   textureMatrix;                                                                                      \n"  
           //-----
      "    attribute     vec4   position;                                                                                           \n"      
      "    attribute     vec3   normal;                                                                                             \n"      
      "    attribute     vec2   texture;                                                                                            \n"       

      "    uniform      float   generic;                                                                                            \n"       
      
      "    varying highp vec4   lightPosition_PASS;                                                                                 \n" 
      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                     \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0); \n"
      //-------------------------------------------- 
      "    varying highp vec2  varTexcoord;                                                                                         \n"
      //-------------------------------------------- 

     //=========================================================================================================================================
      "    void main()                                                                                                                           \n" 
      "    {                                                                                                                                     \n"
                  
                   //---------------------------------------------------------------------------------------------------------     
     
      "            shadowTexcoord        =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;   \n" 
      "            shadowTexcoord        =   shadowTexcoord / shadowTexcoord.w;                                                     \n"      
                   //---------------------------------------------------------------------------------------------------------
      "            lightPosition_PASS    =   normalize(lightMatrix * light_POSITION_01);                                            \n"        
                   //---------------------------------------------------------------------------------------------------------
      
                   //---------------------------------------------------------------------------------------------------------     
      "            varTexcoord           =   texture;                                                                               \n"          
      "            gl_Position           =   mvpMatrix * position;                                                            \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      HEMI_MIX_1_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(HEMI_MIX_1_SHADER_VERTEX, 1, &vertexSource_HEMI_MIX_1, NULL);                                                                        
      glCompileShader(HEMI_MIX_1_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_HEMI_MIX_1 =                                                                                                            

      " #ifdef GL_ES                                                                                                                \n"                       
      " #else                                                                                                                       \n"                       
      " #define highp                                                                                                               \n"                       
      " #endif                                                                                                                      \n"   
    
      //--------------------------------------------      
      "    uniform sampler2D   Texture1;                                                                                            \n"                       
      "    uniform sampler2D   NormalMap;                                                                                           \n"                       
      //--------------------------------------------
      "    uniform sampler2D   ShadowTexture;                                                                                       \n"     
      "    varying highp vec4  shadowTexcoord;                                                                                      \n"  
      //--------------------------------------------         
      "    uniform highp float shininess;                                                                                           \n"                       
      "            highp vec4  specular_1;                                                                                          \n"           
      //--------------------------------------------      
      "    uniform highp float attenuation;                                                                                         \n"                       

      "    varying highp vec4  lightPosition_PASS;                                                                                  \n"                       
      "    varying highp vec2  varTexcoord;                                                                                         \n"                       

      "            highp float NdotL1;                                                                                              \n"                       
      "            highp vec3  normal_FRAG;                                                                                              \n"                       
      "            highp vec3  NormalTex;                                                                                           \n"                       
     //--------------------------------------------                            
      "            highp vec4  SkyColor    = highp vec4(1.0, 0.0, 0.0, 1.0);                                                        \n"
      "            highp vec4  GroundColor = highp vec4(0.0, 0.0, 1.0, 1.0);                                                        \n"   
      "            highp float mixFactor;                                                                                           \n"
      //------------------------------------------------------------------------    
 

      //=======================================================================================================================
      "     void main()                                                                                                             \n"                       
      "     {                                                                                                                       \n"                       
   
      //---------------------------------------------------------------------------------------- 
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                       \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                        \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                     \n" 
      //-----------------------------
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                                \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                      \n"                       
      "         normal_FRAG               =  normalize(NormalTex);                                                                  \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                                    \n"                       
      //------------------
      "         mixFactor                 =  -0.05 + 0.7 * NdotL1;                                                                    \n"      
      //------------------         
      "         specular_1                =  highp vec4(1.0, 0.6, 0.8, 1.0) * pow(max(NdotL1, 0.0), 30.0);                           \n"
      //----------------------------------------------------------------------------------------        
      "         gl_FragColor              =  (mix(GroundColor, SkyColor, mixFactor) + specular_1)* NdotL1;                         \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      HEMI_MIX_1_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(HEMI_MIX_1_SHADER_FRAGMENT, 1, &fragmentSource_HEMI_MIX_1, NULL);                                                                          
      glCompileShader(HEMI_MIX_1_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(HEMI_MIX_1_SHADER, HEMI_MIX_1_SHADER_VERTEX);                                                                                              
      glAttachShader(HEMI_MIX_1_SHADER, HEMI_MIX_1_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(HEMI_MIX_1_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(HEMI_MIX_1_SHADER,    1, "normal");       
      glBindAttribLocation(HEMI_MIX_1_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(HEMI_MIX_1_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(HEMI_MIX_1_SHADER, HEMI_MIX_1_SHADER_VERTEX);                                                                                              
      glDetachShader(HEMI_MIX_1_SHADER, HEMI_MIX_1_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(HEMI_MIX_1_SHADER_VERTEX);                                                                                                            
      glDeleteShader(HEMI_MIX_1_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_HEMI_MIX_1                   = glGetUniformLocation(HEMI_MIX_1_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_HEMI_MIX_1                       = glGetUniformLocation(HEMI_MIX_1_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_HEMI_MIX_1                   = glGetUniformLocation(HEMI_MIX_1_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_HEMI_MIX_1                      = glGetUniformLocation(HEMI_MIX_1_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_HEMI_MIX_1                     = glGetUniformLocation(HEMI_MIX_1_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_HEMI_MIX_1                 = glGetUniformLocation(HEMI_MIX_1_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_HEMI_MIX_1                    = glGetUniformLocation(HEMI_MIX_1_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_HEMI_MIX_1                   = glGetUniformLocation(HEMI_MIX_1_SHADER,      "textureMatrix"); 
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_HEMI_MIX_1                     = glGetUniformLocation(HEMI_MIX_1_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_HEMI_MIX_1                 = glGetUniformLocation(HEMI_MIX_1_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_HEMI_MIX_1               = glGetUniformLocation(HEMI_MIX_1_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_HEMI_MIX_1                       = glGetUniformLocation(HEMI_MIX_1_SHADER,      "shininess");
      UNIFORM_GENERIC_HEMI_MIX_1                         = glGetUniformLocation(HEMI_MIX_1_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_SHADOW_HEMI_MIX_1                  = glGetUniformLocation(HEMI_MIX_1_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_DOT3_HEMI_MIX_1                    = glGetUniformLocation(HEMI_MIX_1_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_HEMI_MIX_1                         = glGetUniformLocation(HEMI_MIX_1_SHADER,      "Texture1");                                   

      //=========================================================================================================================
                      

