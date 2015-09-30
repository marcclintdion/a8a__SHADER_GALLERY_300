    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      starburst_Vertex_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_starburst_Vertex =                                                                                                        

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
      "    uniform       mat4   reverseModelViewMatrix;                                                                                   \n"             
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
      "    varying highp vec2   varTexcoord;                                                                                        \n"
      //-------------------------------------------- 
      "    varying highp vec4   modelViewPos;                                                                                       \n"
      "    varying highp vec4   inverseEye;                                                                                         \n"     
      "    varying highp vec3   normal_PASS;                                                                                        \n"        
      "    varying highp vec4   reverseLightRotation;                                                                               \n"        
     
      //=======================================================================================================================
      "    void main()                                                                                                              \n" 
      "    {                                                                                                                        \n"

      "            inverseEye            =   normalize(lightMatrix * highp vec4(0.0, 0.0, -1.0, 0.0));                              \n"          
      "            modelViewPos          =   mvMatrix  * position - highp vec4(0.0, 0.0, 10.0, 0.0);                                                                  \n"
      "            normal_PASS           =   (mvMatrix  * vec4(normal, 1.0)).xyz;                                                   \n"         
      "            reverseLightRotation  =   normalize(reverseModelViewMatrix  * light_POSITION_01);                                                   \n"          
         
                   //---------------------------------------------------------------------------------------------------------     
      "            shadowTexcoord        =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;   \n" 
      "            shadowTexcoord        =   shadowTexcoord / shadowTexcoord.w;                                                     \n"      
                   //-------------------------------------------------------------------
      "            lightPosition_PASS    =   normalize(lightMatrix * light_POSITION_01);                                            \n"        
                   //-------------------------------------------------------------------
      "            varTexcoord           =   texture;                                                                               \n"          
      "            gl_Position           =   mvpMatrix * position;                                                                  \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      starburst_Vertex_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(starburst_Vertex_SHADER_VERTEX, 1, &vertexSource_starburst_Vertex, NULL);                                                                        
      glCompileShader(starburst_Vertex_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_starburst_Vertex =                                                                                                            

      " #ifdef GL_ES                                                                                                                \n"                       
      " #else                                                                                                                       \n"                       
      " #define highp                                                                                                               \n"                       
      " #endif                                                                                                                      \n"   
    
      //--------------------------------------------      
      "    uniform sampler2D   FresnelMap;                                                                                          \n"                       
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
      "    varying highp vec4  reverseLightRotation;                                                                               \n"  
      "    varying highp vec2  varTexcoord;                                                                                         \n"                       

      "            highp float NdotL1;                                                                                              \n"                       
      "            highp vec3  normal_FRAG;                                                                                         \n"                       
      "            highp vec3  NormalTex;                                                                                           \n"                       
      //--------------------------------------------                            
      "    varying highp vec4  modelViewPos;                                                                                        \n"
      "    varying highp vec4  inverseEye;                                                                                          \n"  
      "            highp vec3  invertView;                                                                        \n" 
      "            highp vec3  Reflect;                                                                        \n" 
      "            highp vec3  RH;                                                                        \n" 
      "            highp float fresnel;                                                                        \n"    
      "            highp vec4  fresnelTexture;                                                                        \n"       
      //--------------------------------------------   
      "    varying highp vec3   normal_PASS;                                                                                         \n"       

      "    highp float fresnelReflectance = 0.11;                         //ORIGINAL_COMMENT???_//Fresnel reflectance at zero angle	                                          \n"

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
      "         invertView                =  normalize(modelViewPos.xyz);                                                                      \n"  

      "         Reflect                   =  reflect(-invertView, normalize(normal_PASS));                                                                                                 \n"
      "         RH                        =  normalize(Reflect - invertView);                                                                                             \n"
      "         fresnel                   =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(1.0 + dot(invertView, RH), 5.0);                                  \n" 
      "         fresnelTexture            =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + highp vec3(0.0, 0.0, 1.0)).xy) * 2.0 * NdotL1;                                        \n" 

      "         gl_FragColor              =  mix(texture2D(Texture1,  varTexcoord)* 0.4, fresnelTexture, fresnel) * NdotL1;                                              \n"  

      //-----------------------------------------------------------------------------------------        
//      "         gl_FragColor              =  highp vec4(0.0, 0.3, 1.0, 1.0);          \n" 


      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      starburst_Vertex_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(starburst_Vertex_SHADER_FRAGMENT, 1, &fragmentSource_starburst_Vertex, NULL);                                                                          
      glCompileShader(starburst_Vertex_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(starburst_Vertex_SHADER, starburst_Vertex_SHADER_VERTEX);                                                                                              
      glAttachShader(starburst_Vertex_SHADER, starburst_Vertex_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(starburst_Vertex_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(starburst_Vertex_SHADER,    1, "normal");       
      glBindAttribLocation(starburst_Vertex_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(starburst_Vertex_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(starburst_Vertex_SHADER, starburst_Vertex_SHADER_VERTEX);                                                                                              
      glDetachShader(starburst_Vertex_SHADER, starburst_Vertex_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(starburst_Vertex_SHADER_VERTEX);                                                                                                            
      glDeleteShader(starburst_Vertex_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_starburst_Vertex                   = glGetUniformLocation(starburst_Vertex_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_starburst_Vertex                       = glGetUniformLocation(starburst_Vertex_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_starburst_Vertex                   = glGetUniformLocation(starburst_Vertex_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_starburst_Vertex                      = glGetUniformLocation(starburst_Vertex_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_starburst_Vertex                     = glGetUniformLocation(starburst_Vertex_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_starburst_Vertex                 = glGetUniformLocation(starburst_Vertex_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_starburst_Vertex                    = glGetUniformLocation(starburst_Vertex_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_starburst_Vertex                   = glGetUniformLocation(starburst_Vertex_SHADER,      "textureMatrix"); 
      UNIFORM_reverseModelView_starburst_Vertex                = glGetUniformLocation(starburst_Vertex_SHADER,      "reverseModelViewMatrix");   
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_starburst_Vertex                     = glGetUniformLocation(starburst_Vertex_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_starburst_Vertex                 = glGetUniformLocation(starburst_Vertex_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_starburst_Vertex               = glGetUniformLocation(starburst_Vertex_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_starburst_Vertex                       = glGetUniformLocation(starburst_Vertex_SHADER,      "shininess");
      UNIFORM_GENERIC_starburst_Vertex                         = glGetUniformLocation(starburst_Vertex_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_SHADOW_starburst_Vertex                  = glGetUniformLocation(starburst_Vertex_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_FRESNEL_starburst_Vertex                 = glGetUniformLocation(starburst_Vertex_SHADER,      "FresnelMap");       
      UNIFORM_TEXTURE_DOT3_starburst_Vertex                    = glGetUniformLocation(starburst_Vertex_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_starburst_Vertex                         = glGetUniformLocation(starburst_Vertex_SHADER,      "Texture1");                                   

      //==============================================================================================================================
      #ifdef __APPLE__                                                                                                                          
        spriteImage             = [UIImage imageNamed:@"light_brownMarble.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glGenTextures(1, &starburst_Vertex_FRESNELMAP);
        glBindTexture(GL_TEXTURE_2D, starburst_Vertex_FRESNELMAP);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        } 
      #endif
      //----------------------------------------------------------------------------------------------------------------------------                                                                   
      #ifdef WIN32  
      loadTexture("_SHADERS/fresnel/starburst_Vertex/light_brownMarble.png",                starburst_Vertex_FRESNELMAP);       
      #endif // -> Terrain_posz_1 __ looks awesome contrasted against the sheild texture
                   

