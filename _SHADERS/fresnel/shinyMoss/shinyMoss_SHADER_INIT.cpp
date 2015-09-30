    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      shinyMoss_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_shinyMoss =                                                                                                        

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
           //---------------------------
      "    varying highp vec3   column0;                                                                       \n"   
      "    varying highp vec3   column1;                                                                       \n"   
      "    varying highp vec3   column2;                                                                       \n"        
           //---------------------------
      "    uniform highp float  generic;                                                                                            \n"       
      
      "    varying highp vec4   lightPosition_PASS;                                                                                 \n" 
      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                     \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0); \n"
      //-------------------------------------------- 
      "    varying highp vec2   varTexcoord;                                                                                        \n"
      //-------------------------------------------- 
      "    varying highp vec4   Vertex;			                                                                                    \n"
      "    varying highp vec4   inverseEye;                                                                                         \n"
 
      //=======================================================================================================================
      "    void main()                                                                                                              \n" 
      "    {                                                                                                                        \n"
      "            column0               =  highp vec3(mvpMatrix[0].xyz);                                                                 \n"   
      "            column1               =  highp vec3(mvpMatrix[1].xyz);                                                                 \n"   
      "            column2               =  highp vec3(mvpMatrix[2].xyz);                                                                 \n"
                   //---------------------------------------------
      "            Vertex                =  mvMatrix * position;                                                                    \n"
      "            inverseEye            =  highp vec4(0.0, 0.0, -1.0, 0.0);                                                        \n"
 
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
      shinyMoss_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(shinyMoss_SHADER_VERTEX, 1, &vertexSource_shinyMoss, NULL);                                                                        
      glCompileShader(shinyMoss_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_shinyMoss =                                                                                                            

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
      "    varying highp vec4  reverseLightRotation;                                                                                \n"  
      "    varying highp vec2  varTexcoord;                                                                                         \n"                       
           //---------------------------
      "    varying highp vec3   column0;                                                                                            \n"   
      "    varying highp vec3   column1;                                                                                            \n"   
      "    varying highp vec3   column2;                                                                                            \n"        
           //---------------------------
      "            highp float  NdotL1;                                                                                             \n"                       
      "            highp vec3   normal_FRAG;                                                                                        \n"                       
      "            highp vec3   NormalTex;                                                                                          \n"                       
      //--------------------------------------------                            
      "    varying highp vec3   normal_PASS;                                                                                        \n"       
      //-------------------------------------------- 
      "    varying highp vec4   Vertex;			                                                                                      \n"
      "    varying highp vec4   inverseEye;                                                                                           \n"
      //--------------------------------------------  
      "    highp   vec4 finalcolor;                                                                                                   \n"
      "    highp   vec4 diffuse =  highp vec4(2.0, 2.0, 2.0, 1.0);                                                                    \n"
      "    highp   vec4 hotSpot;                                                                                                      \n"
      "    highp   vec4 ambient;                                                                                                      \n"

      "    highp   vec3  newNormal;	                                                                                                  \n"
      "    highp   vec3  invertView;                                                                                                   \n"
      "    highp   vec3  Hn;                                                                                                           \n"
      "    highp   vec3  Reflect;                                                                                                      \n"
      "    highp   vec3  RH;                                                                                                           \n"
      "    highp   vec3  Ln = highp vec3(-0.913, 0.365, 0.183);                                                                        \n"
      "    highp   vec4  tempColor;                                                                                                    \n"
      "    highp   vec4  col;                                                                                                          \n"
      "    highp   vec4  textureMap;                                                                                                   \n"
      "    highp   float fresnelReflectance = 0.1;	                                                                                  \n"
      "    highp   float diffuseFresnel;                                                                                              \n"
      "    highp   float specularFresnel;                                                                                             \n"
      "    highp   float fresnel;                                                                                                     \n"

      //=======================================================================================================================
      "     void main()                                                                                                               \n"                       
      "     {                                                                                                                         \n"                       
      "         mat3 n                    =  mat3(column0, column1, column2);                                                         \n"         
      //----------------------------------------------------------------------------------------- 
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                         \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                          \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                       \n" 
      //-----------------------------------------------------------------------------------------
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                                  \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                        \n"                       
      "         normal_FRAG               =  normalize(NormalTex);                                                                    \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                                      \n"                       
      //-----------------------------------------------------------------------------------------
      "         finalcolor        =  texture2D(Texture1, varTexcoord);                                                                \n"     
      "         finalcolor        =  highp vec4(1.0, 1.0, 1.0, 1.0) * pow(NdotL1, 10.0) * 0.4;                                              \n"                                  
      //------------------------------------------------------------------------------------------------------------------- 
      "         newNormal         =  normal_FRAG;	                                                                                  \n"     
      "         invertView        =  normalize(Vertex.xyz * inverseEye.w - inverseEye.xyz * Vertex.w);                                \n"     
      "         Hn                =  normalize(Ln - invertView);                                                                      \n"     

      "         col               =  finalcolor;                                                                                      \n"     
    
      "         Reflect           =  reflect(invertView, n * newNormal);                                                                  \n"     
      "         RH                =  normalize(Reflect - invertView);                                                                 \n"     
  
  
      "         fresnel           =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(1.0 + dot(invertView, RH), 2.0) * 2.0;     \n"     
      "         textureMap        =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + highp vec3(0.0, 0.0, 1.0)).xy);                  \n"     

      "         tempColor         =  mix(col, textureMap, fresnel-0.2);                                                               \n"     

      //-----------------------------------------------------------------------------------------        
      "         gl_FragColor              =  tempColor * NdotL1 * NdotL1;                                                                      \n" 

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      shinyMoss_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(shinyMoss_SHADER_FRAGMENT, 1, &fragmentSource_shinyMoss, NULL);                                                                          
      glCompileShader(shinyMoss_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(shinyMoss_SHADER, shinyMoss_SHADER_VERTEX);                                                                                              
      glAttachShader(shinyMoss_SHADER, shinyMoss_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(shinyMoss_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(shinyMoss_SHADER,    1, "normal");       
      glBindAttribLocation(shinyMoss_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(shinyMoss_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(shinyMoss_SHADER, shinyMoss_SHADER_VERTEX);                                                                                              
      glDetachShader(shinyMoss_SHADER, shinyMoss_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(shinyMoss_SHADER_VERTEX);                                                                                                            
      glDeleteShader(shinyMoss_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_shinyMoss                   = glGetUniformLocation(shinyMoss_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_shinyMoss                       = glGetUniformLocation(shinyMoss_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_shinyMoss                   = glGetUniformLocation(shinyMoss_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_shinyMoss                      = glGetUniformLocation(shinyMoss_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_shinyMoss                     = glGetUniformLocation(shinyMoss_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_shinyMoss                 = glGetUniformLocation(shinyMoss_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_shinyMoss                    = glGetUniformLocation(shinyMoss_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_shinyMoss                   = glGetUniformLocation(shinyMoss_SHADER,      "textureMatrix"); 
      UNIFORM_reverseModelView_shinyMoss                = glGetUniformLocation(shinyMoss_SHADER,      "reverseModelViewMatrix");   
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_shinyMoss                     = glGetUniformLocation(shinyMoss_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_shinyMoss                 = glGetUniformLocation(shinyMoss_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_shinyMoss               = glGetUniformLocation(shinyMoss_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_shinyMoss                       = glGetUniformLocation(shinyMoss_SHADER,      "shininess");
      UNIFORM_GENERIC_shinyMoss                         = glGetUniformLocation(shinyMoss_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_SHADOW_shinyMoss                  = glGetUniformLocation(shinyMoss_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_FRESNEL_shinyMoss                 = glGetUniformLocation(shinyMoss_SHADER,      "FresnelMap");       
      UNIFORM_TEXTURE_DOT3_shinyMoss                    = glGetUniformLocation(shinyMoss_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_shinyMoss                         = glGetUniformLocation(shinyMoss_SHADER,      "Texture1");                                   

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
        glGenTextures(1, &shinyMoss_FRESNELMAP);
        glBindTexture(GL_TEXTURE_2D, shinyMoss_FRESNELMAP);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        } 
      #endif
      //----------------------------------------------------------------------------------------------------------------------------                                                                   
      #ifdef WIN32  
      loadTexture("_SHADERS/fresnel/shinyMoss/shinyMoss.png",                shinyMoss_FRESNELMAP);       
      #endif // -> Terrain_posz_1 __ looks awesome contrasted against the sheild texture
                   

