    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      colorRamp_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_colorRamp =                                                                                                        

      "    #define highp                                                                                                                         \n"        

      "    uniform highp vec4   light_POSITION_01;                                                                                  \n"        
      "    uniform       mat4   mvpMatrix;                                                                                          \n"      
      "    uniform       mat4   mvMatrix;                                                                                           \n"  
      "    uniform       mat4   modelRotationMatrix;                                                                                \n"  
      //-------------------------------------------- 
      "    uniform       mat4   viewMatrix;                                                                                         \n"                   
      //-------------------------------------------- 
      "    uniform       mat4   projectionShadow;                                                                                   \n"        
      "    uniform       mat4   modelViewShadow;                                                                                    \n"        
      //--------------------------------------------  
      "    uniform       mat4   lightMatrix;                                                                                        \n"     
      "    uniform       mat4   textureMatrix;                                                                                      \n"  
      //-------------------------------------------- 
      "    uniform highp float  generic;                                                                                            \n"       
      //-------------------------------------------- 
      "    uniform highp vec2   ramp_XY_coords;                                                                                     \n"       
      //-------------------------------------------- 
      "    attribute     vec4   position;                                                                                           \n"      
      "    attribute     vec3   normal;                                                                                             \n"      
      "    attribute     vec2   texture;                                                                                            \n"       
      //-------------------------------------------- 
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
      "            lightPosition_PASS    =   normalize(lightMatrix * light_POSITION_01 );                                            \n"        
                //_NOTES_::BY CHANGING THE LIGHT POSITION, THE SPECUALAR HIGHLIGHTS CAN BE SOFTENED WITHOUT CHANING THE SIZE PF THE HIGHLIGHT    
 
                   //---------------------------------------------------------------------------------------------------------
      
                   //---------------------------------------------------------------------------------------------------------     
      "            varTexcoord           =   texture;                                                                               \n"          
      "            gl_Position           =   mvpMatrix * position;                                                            \n"           

      "    }\n";                                                                                                                             
      
     
      
      //---------------------------------------------------------------------                                                                   
      colorRamp_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(colorRamp_SHADER_VERTEX, 1, &vertexSource_colorRamp, NULL);                                                                        
      glCompileShader(colorRamp_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_colorRamp =                                                                                                            

      " #ifdef GL_ES                                                                                                                \n"                       
      " #else                                                                                                                       \n"                       
      " #define highp                                                                                                               \n"                       
      " #endif                                                                                                                      \n"   
    
      //--------------------------------------------      
      "    uniform sampler2D   Texture1;                                                                                            \n"                       
      "    uniform sampler2D   NormalMap;                                                                                           \n"                       
      //--------------------------------------------   
      "    uniform highp float  generic;                                                                                            \n"       
      //--------------------------------------------           
      "    uniform sampler2D   RampTexture;                                                                                         \n"                       
      "    uniform highp vec2  ramp_XY_coords;                                                                                      \n"       
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

  
      //=======================================================================================================================
      "     void main()                                                                                                             \n"                       
      "     {                                                                                                                       \n"                       
   
      //----------------------------------------------------------------------------------------- 
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                                       \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                        \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                     \n" 
      //-----------------------------------------------------------------------------------------
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                            \n"                       
      "         NormalTex                 = (NormalTex - 0.5);                                                                      \n"                       
      "         normal_FRAG               =  normalize(NormalTex);                                                                  \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                                    \n"                       
      //-----------------------------------------------------------------------------------------


      //-----------------------------------------------------------------------------------------        
      "         gl_FragColor   =  texture2D(Texture1,  varTexcoord) * texture2D(RampTexture,  highp vec2(NdotL1, ramp_XY_coords[1]))       \n"    
      
      "                  +   max(pow(NdotL1, 1500.00), 0.0)  ;                     \n" 
                        //_NOTES_::BY CHANGING THE LIGHT POSITION, THE SPECUALAR HIGHLIGHTS CAN BE SOFTENED WITHOUT CHANING THE SIZE PF THE HIGHLIGHT    
 

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      colorRamp_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(colorRamp_SHADER_FRAGMENT, 1, &fragmentSource_colorRamp, NULL);                                                                          
      glCompileShader(colorRamp_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(colorRamp_SHADER, colorRamp_SHADER_VERTEX);                                                                                              
      glAttachShader(colorRamp_SHADER, colorRamp_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(colorRamp_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(colorRamp_SHADER,    1, "normal");       
      glBindAttribLocation(colorRamp_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(colorRamp_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(colorRamp_SHADER, colorRamp_SHADER_VERTEX);                                                                                              
      glDetachShader(colorRamp_SHADER, colorRamp_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(colorRamp_SHADER_VERTEX);                                                                                                            
      glDeleteShader(colorRamp_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_colorRamp                   = glGetUniformLocation(colorRamp_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_colorRamp                       = glGetUniformLocation(colorRamp_SHADER,      "mvMatrix");       
      UNIFORM_MODELROTATION_colorRamp                   = glGetUniformLocation(colorRamp_SHADER,      "modelRotationMatrix");            
      //-------------------------------      
      UNIFORM_viewMatrix_colorRamp                      = glGetUniformLocation(colorRamp_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_colorRamp                     = glGetUniformLocation(colorRamp_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_colorRamp                 = glGetUniformLocation(colorRamp_SHADER,      "modelViewShadow");            
      //------------------------------------                                              
      UNIFORM_LIGHT_MATRIX_colorRamp                    = glGetUniformLocation(colorRamp_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_colorRamp                   = glGetUniformLocation(colorRamp_SHADER,      "textureMatrix"); 
      //------------------------------------  
      UNIFORM_SHADOW_PROJ_colorRamp                     = glGetUniformLocation(colorRamp_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_colorRamp                 = glGetUniformLocation(colorRamp_SHADER,      "modelViewShadow");            
      //--------------------------------------  
      UNIFORM_LIGHT_POSITION_01_colorRamp               = glGetUniformLocation(colorRamp_SHADER,      "light_POSITION_01");                                      
      UNIFORM_RAMP_XY_COORDS_colorRamp                  = glGetUniformLocation(colorRamp_SHADER,      "ramp_XY_coords");        
      UNIFORM_SHININESS_colorRamp                       = glGetUniformLocation(colorRamp_SHADER,      "shininess");
      UNIFORM_GENERIC_colorRamp                         = glGetUniformLocation(colorRamp_SHADER,      "generic");      
      //-----------------------------------------------                               
      UNIFORM_TEXTURE_SHADOW_colorRamp                  = glGetUniformLocation(colorRamp_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_RAMP_colorRamp                    = glGetUniformLocation(colorRamp_SHADER,      "RampTexture");       
      UNIFORM_TEXTURE_DOT3_colorRamp                    = glGetUniformLocation(colorRamp_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_colorRamp                         = glGetUniformLocation(colorRamp_SHADER,      "Texture1");                                   

      //=========================================================================================================================
      #ifdef __APPLE__                                                                                                                          
        spriteImage             = [UIImage imageNamed:@"ramp.png"].CGImage;
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
        glGenTextures(1, &RampTexture);//_____________________!!!!!!!!!__TEXTURE_ASSIGNMENTS
        glBindTexture(GL_TEXTURE_2D, RampTexture);//__________!!!!!!!!!__TEXTURE_ASSIGNMENTS
        ConfigureAndLoadTexture(spriteData,  width, height); 
        if(spriteData != NULL)
        {
                free(spriteData);    
        } 
      #endif
      //----------------------------------------------------------------------------------------------------------------------------                                                                   
      #ifdef WIN32  
      loadTexture("_SHADERS/colorRamp/ramp.png",                RampTexture);//_______!!!!!!!!!__TEXTURE_ASSIGNMENTS
      #endif 
      
