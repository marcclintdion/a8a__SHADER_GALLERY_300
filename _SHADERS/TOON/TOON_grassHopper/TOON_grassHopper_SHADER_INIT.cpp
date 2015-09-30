    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      TOON_grassHopper_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_TOON_grassHopper =                                                                                                        

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
      TOON_grassHopper_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(TOON_grassHopper_SHADER_VERTEX, 1, &vertexSource_TOON_grassHopper, NULL);                                                                        
      glCompileShader(TOON_grassHopper_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_TOON_grassHopper =                                                                                                            

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
      "            highp vec3  normal_FRAG;                                                                                         \n"                       
      "            highp vec3  NormalTex;                                                                                           \n"                       
      //--------------------------------------------                            
      "            highp float kValue;                                                                                              \n"
      "            highp float specular;                                                                                            \n"
      "            highp float diffuse;                                                                                             \n"
      
      //=======================================================================================================================
      "     void main()                                                                                                             \n"                       
      "     {                                                                                                                       \n"                       
   
      //----------------------------------------------------------------------------------------- 
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                       \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                        \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                     \n" 
      //-----------------------------------------------------------------------------------------
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                                \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                      \n"                       
      "         normal_FRAG               =  normalize(NormalTex);                                                                  \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                                    \n"                       
      //-----------------------------------------------------------------------------------------
      "	        diffuse                   =  NdotL1;                                                                                \n" 
      "         kValue                    =  0.15;                                                                                  \n" 
      "         diffuse                   =  smoothstep(0.4 - kValue, 0.4 + kValue, diffuse);                                       \n" 
      //----------------
      "   	specular                  =  NdotL1;                                                                                \n" 
      "		specular                  =  max(pow(specular, 30.0), 0.0);                                                         \n" 
      "	        kValue                    =  0.2;                                                                                   \n" 
      "	        specular                  =  smoothstep(0.5 - kValue, 0.5 + kValue, specular);                                      \n" 
      //-----------------------------------------------------------------------------------------        
      "         gl_FragColor              =  highp vec4(0.0, 0.3, 1.0, 1.0) * texture2D(Texture1,  varTexcoord) * diffuse           \n" 
      "                                   +  highp vec4(0.7, 0.7, 1.0, 1.0) * texture2D(Texture1,  varTexcoord) * specular;         \n"                       



      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      TOON_grassHopper_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(TOON_grassHopper_SHADER_FRAGMENT, 1, &fragmentSource_TOON_grassHopper, NULL);                                                                          
      glCompileShader(TOON_grassHopper_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(TOON_grassHopper_SHADER, TOON_grassHopper_SHADER_VERTEX);                                                                                              
      glAttachShader(TOON_grassHopper_SHADER, TOON_grassHopper_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(TOON_grassHopper_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(TOON_grassHopper_SHADER,    1, "normal");       
      glBindAttribLocation(TOON_grassHopper_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(TOON_grassHopper_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(TOON_grassHopper_SHADER, TOON_grassHopper_SHADER_VERTEX);                                                                                              
      glDetachShader(TOON_grassHopper_SHADER, TOON_grassHopper_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(TOON_grassHopper_SHADER_VERTEX);                                                                                                            
      glDeleteShader(TOON_grassHopper_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_TOON_grassHopper                   = glGetUniformLocation(TOON_grassHopper_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_TOON_grassHopper                       = glGetUniformLocation(TOON_grassHopper_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_TOON_grassHopper                   = glGetUniformLocation(TOON_grassHopper_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_TOON_grassHopper                      = glGetUniformLocation(TOON_grassHopper_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_TOON_grassHopper                     = glGetUniformLocation(TOON_grassHopper_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_TOON_grassHopper                 = glGetUniformLocation(TOON_grassHopper_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_TOON_grassHopper                    = glGetUniformLocation(TOON_grassHopper_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_TOON_grassHopper                   = glGetUniformLocation(TOON_grassHopper_SHADER,      "textureMatrix"); 
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_TOON_grassHopper                     = glGetUniformLocation(TOON_grassHopper_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_TOON_grassHopper                 = glGetUniformLocation(TOON_grassHopper_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_TOON_grassHopper               = glGetUniformLocation(TOON_grassHopper_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_TOON_grassHopper                       = glGetUniformLocation(TOON_grassHopper_SHADER,      "shininess");
      UNIFORM_GENERIC_TOON_grassHopper                         = glGetUniformLocation(TOON_grassHopper_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_SHADOW_TOON_grassHopper                  = glGetUniformLocation(TOON_grassHopper_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_DOT3_TOON_grassHopper                    = glGetUniformLocation(TOON_grassHopper_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_TOON_grassHopper                         = glGetUniformLocation(TOON_grassHopper_SHADER,      "Texture1");                                   

      //=========================================================================================================================
                      

