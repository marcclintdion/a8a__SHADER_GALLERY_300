    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      original_Aniso_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_original_Aniso =                                                                                                        

      "    #define highp                                                                                                                         \n"        

      "    uniform highp vec4   light_POSITION_01;                                                                                               \n"        
      "    uniform       mat4   mvpMatrix;                                                                                                       \n"      
      "    uniform       mat4   mvMatrix;                                                                                                        \n"  
      "    uniform       mat4   modelRotationMatrix;                                                                                                        \n"  
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
      "    attribute     vec3   normal;                                                                                                        \n"      
      "    attribute     vec2   texture;                                                                                                         \n"       

      "    uniform      float   generic;                                                                                                         \n"       
      
      "    varying highp vec4   lightPosition_PASS;                                                                                              \n" 
      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                                  \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);              \n"
      //-------------------------------------------- 
      "    varying highp vec2  varTexcoord;                                                                                                      \n"
      //-------------------------------------------- 
      "    varying highp vec2  anisoTexCoords;                                                                                                      \n"
      "    varying highp vec4  color;                                                                                                      \n"
       
     //=========================================================================================================================================
      "    void main()                                                                                                                           \n" 
      "    {                                                                                                                                     \n"
                  
                   //---------------------------------------------------------------------------------------------------------     
     
      "            shadowTexcoord        =   ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;                \n" 
      "            shadowTexcoord        =   shadowTexcoord / shadowTexcoord.w;                                                                  \n"      
                   //---------------------------------------------------------------------------------------------------------
      "            lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                                                          \n"        
                   //---------------------------------------------------------------------------------------------------------
      "            highp vec3 tmpNorm = (mvMatrix * highp vec4(normal, 1.0)).xyz;                                                     \n" 
      "            highp vec4 worldNormal;                                                                     \n" 
      "            worldNormal.x = tmpNorm.x;                                                                  \n" 
      "            worldNormal.y = tmpNorm.y;                                                                  \n" 
      "            worldNormal.z = tmpNorm.z;                                                                  \n" 
      "            worldNormal.w = 0.0;                                                                        \n" 

      "            highp vec4 worldSpacePos = mvMatrix * position;                                             \n" 

      "            highp vec4 vertToEye = normalize( highp vec4(0.0, 0.0, 1.0, 0.0) - worldSpacePos );         \n" 

      "            highp vec4 halfAngle = vertToEye - light_POSITION_01;                                      \n" 

      "            anisoTexCoords = texture;                                                                   \n" 
      "            anisoTexCoords.x = max( dot(light_POSITION_01, worldNormal), 0.0)*1.6;                         \n" 
      "            anisoTexCoords.y = max( dot(halfAngle, worldNormal), 0.5);                                  \n" 
/**/

//      "        gl_FrontColor = gl_Color;                                  \n" 
           
                   //---------------------------------------------------------------------------------------------------------     
                       



      "            varTexcoord           =  texture;                                                                                             \n"          
      "            gl_Position           =  mvpMatrix * position;                                                                                 \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      original_Aniso_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(original_Aniso_SHADER_VERTEX, 1, &vertexSource_original_Aniso, NULL);                                                                        
      glCompileShader(original_Aniso_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_original_Aniso =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"   
    
      "    uniform sampler2D   AnisoMap;                                                                                                         \n"                       
      //--------------------------------------------      
      "    uniform sampler2D   Texture1;                                                                                                         \n"                       
      "    uniform sampler2D   NormalMap;                                                                                                        \n"                       
      //--------------------------------------------
      "    uniform sampler2D   ShadowTexture;                                                                                                    \n"     
      "    varying highp vec4  shadowTexcoord;                                                                                                   \n"  
      //--------------------------------------------         
      "    uniform highp float shininess;                                                                                                        \n"                       
      "    uniform highp float attenuation;                                                                                                      \n"                       

      "    varying highp vec4  lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec2  varTexcoord;                                                                                                      \n"                       

      "            highp float NdotL1;                                                                                                           \n"                       
      "            highp vec3  normal;                                                                                                           \n"                       
      "            highp vec3  NormalTex;                                                                                                        \n"                       
      //-------------------------------------------- 
      "    varying highp vec2  anisoTexCoords;                                                                                                      \n"
      "    varying highp vec4  color;                                                                                                      \n"
       
      //=========================================================================================================================================
      "     void main()                                                                                                                          \n"                       
      "     {                                                                                                                                    \n"                       
   
      //-----------------------------------------------------------------------------------------------------------------------------    
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                                    \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                                     \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                                  \n" 
      //-----------------------------------------------------------------------------------------------------------------------------     
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                                             \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                                   \n"                       
      "         normal                    =  normalize(NormalTex);                                                                               \n"                       
      "         NdotL1                    =  max(dot(normal, lightPosition_PASS.xyz), 0.0);                                                      \n"                       

    
      "         gl_FragColor              =  texture2D(AnisoMap, anisoTexCoords.st) * NdotL1;                     \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      original_Aniso_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(original_Aniso_SHADER_FRAGMENT, 1, &fragmentSource_original_Aniso, NULL);                                                                          
      glCompileShader(original_Aniso_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(original_Aniso_SHADER, original_Aniso_SHADER_VERTEX);                                                                                              
      glAttachShader(original_Aniso_SHADER, original_Aniso_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(original_Aniso_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(original_Aniso_SHADER,    1, "normal");       
      glBindAttribLocation(original_Aniso_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(original_Aniso_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(original_Aniso_SHADER, original_Aniso_SHADER_VERTEX);                                                                                              
      glDetachShader(original_Aniso_SHADER, original_Aniso_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(original_Aniso_SHADER_VERTEX);                                                                                                            
      glDeleteShader(original_Aniso_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_original_Aniso                   = glGetUniformLocation(original_Aniso_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_original_Aniso                       = glGetUniformLocation(original_Aniso_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_original_Aniso                   = glGetUniformLocation(original_Aniso_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_original_Aniso                      = glGetUniformLocation(original_Aniso_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_original_Aniso                     = glGetUniformLocation(original_Aniso_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_original_Aniso                 = glGetUniformLocation(original_Aniso_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_original_Aniso                    = glGetUniformLocation(original_Aniso_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_original_Aniso                   = glGetUniformLocation(original_Aniso_SHADER,      "textureMatrix"); 
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_original_Aniso                     = glGetUniformLocation(original_Aniso_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_original_Aniso                 = glGetUniformLocation(original_Aniso_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_original_Aniso               = glGetUniformLocation(original_Aniso_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_original_Aniso                       = glGetUniformLocation(original_Aniso_SHADER,      "shininess");
      UNIFORM_GENERIC_original_Aniso                         = glGetUniformLocation(original_Aniso_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_COORDINATES_ADJUST_original_Aniso      = glGetUniformLocation(original_Aniso_SHADER,      "AnisoMap");                                                    
      UNIFORM_TEXTURE_SHADOW_original_Aniso                  = glGetUniformLocation(original_Aniso_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_DOT3_original_Aniso                    = glGetUniformLocation(original_Aniso_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_original_Aniso                         = glGetUniformLocation(original_Aniso_SHADER,      "Texture1");                                   

      //=========================================================================================================================
                      
      #ifdef __APPLE__                                                                                                                          
      /*  filePathName = nil;
        //-----------------
        filePathName = [[NSBundle mainBundle] pathForResource:@"ogl_aniso_original" ofType:@"png"];                                                       
        //---------------------
        if(filePathName != nil)                                                                                                                                
        {
                image        = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
                glGenTextures(1, &aniso_TEXTUREMAP);                                                                                                       
                glBindTexture(GL_TEXTURE_2D, aniso_TEXTUREMAP);                                                                                            
                ConfigureAndLoadTexture(image->data,  image->width, image->height);                                                                      
                imgDestroyImage(image);                                                                                                                   
                                                                                                                               
        }else                                                                                                                                              
        {                                                                                                                                              
             //add error file output here                                                                                                                
       } */
       //-----------------------------------------------------------------------------------------------------
       
        spriteImage             = [UIImage imageNamed:@"anisoRepaired.png"].CGImage;
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
        glGenTextures(1, &aniso_TEXTUREMAP);
        glBindTexture(GL_TEXTURE_2D, aniso_TEXTUREMAP);
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        }  
      #endif
      //============================================================================================================================                                         
      #ifdef WIN32  
      loadTexture("_SHADERS/aniso/original_Aniso/anisoRepaired.png",                   aniso_TEXTUREMAP);                                                        
      #endif 

