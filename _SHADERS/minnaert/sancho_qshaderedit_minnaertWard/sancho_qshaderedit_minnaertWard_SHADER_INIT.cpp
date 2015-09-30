    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      sancho_qshaderedit_minnaertWard_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_sancho_qshaderedit_minnaertWard =                                                                                                        

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

      "    uniform      float   generic;                                                                                                         \n"       
      
      "    varying highp vec4   lightPosition_PASS;                                                                                              \n" 
      "    varying highp vec4   position_PASS;                                                                                                   \n"        
      "    varying highp vec3   v_V;                                                                                                   \n"        

      //--------------------------------------------      
      "    varying highp vec4   shadowTexcoord;                                                                                                  \n"
      "            const mat4   ScaleMatrix = mat4(0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.5, 0.5, 0.5, 1.0);              \n"
      //-------------------------------------------- 
      "    varying highp vec2   varTexcoord;                                                                                                      \n"
      //--------------------------------------------       
        "    varying    highp   vec4    Vertex;                                                                                         \n"                                                          
        "    varying    highp   vec4    inverseEye;                                                                                     \n"   
      
      
      //=========================================================================================================================================
      "    void main()                                                                                                                           \n" 
      "    {                                                                                                                                     \n"
      "            Vertex                 =  mvpMatrix * position;                                                                   \n"  

      "            inverseEye             =  normalize(lightMatrix * highp vec4(0.0, 0.0, -1.0, 0.0));                                     \n"          
   
     //---------------------------------------------------------------------------------------------------------
     
      "            shadowTexcoord         =  ScaleMatrix * projectionShadow * modelViewShadow * viewMatrix * mvMatrix * position;                \n" 
      "            shadowTexcoord         =  shadowTexcoord / shadowTexcoord.w;                                                                  \n"      
                   //---------------------------------------------------------------------------------------------------------
     
      "	           v_V                    =  highp vec3(lightMatrix * position).xyz;                                  \n"

                   //---------------------------------------------------------------------------------------------------------      
      "            lightPosition_PASS     =  normalize(lightMatrix * light_POSITION_01);                                                          \n"        

      "            varTexcoord            =  texture;                                                                                             \n"          
      "            gl_Position            =  mvpMatrix * position;                                                                                \n"           

      "    }\n";                                                                                                                             
      
      
      //---------------------------------------------------------------------                                                                   
      sancho_qshaderedit_minnaertWard_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(sancho_qshaderedit_minnaertWard_SHADER_VERTEX, 1, &vertexSource_sancho_qshaderedit_minnaertWard, NULL);                                                                        
      glCompileShader(sancho_qshaderedit_minnaertWard_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_sancho_qshaderedit_minnaertWard =                                                                                                            

      " #ifdef GL_ES                                                                                                                             \n"                       
      " #else                                                                                                                                    \n"                       
      " #define highp                                                                                                                            \n"                       
      " #endif                                                                                                                                   \n"   
         

      "    uniform sampler2D   Texture1;                                                                                                         \n"                       
      "    uniform sampler2D   NormalMap;                                                                                                        \n"                       
      //--------------------------------------------
      "    uniform sampler2D   ShadowTexture;                                                                                                    \n"     
      "    varying highp vec4  shadowTexcoord;                                                                                                   \n"  
      //--------------------------------------------         
      "    uniform highp float   generic;                                                                                                         \n"       
       
 
      "    uniform highp float shininess;                                                                                                        \n"                       

      "    varying highp vec4  lightPosition_PASS;                                                                                               \n"                       
      "    varying highp vec2  varTexcoord;                                                                                                      \n"                       
      
      "    varying highp vec3   v_V;                                                                                                   \n"        
      
      "            highp float NdotL1;                                                                                                           \n"                       
      "            highp vec3  normal_FRAG;                                                                                                      \n"                       
      "            highp vec3  NormalTex;                                                                                                        \n"                       
      //--------------------------------------------    
      "            highp vec4  Color;                                                                                                            \n"                       
      //-------------------------------------------- 
//      "            uniform highp float k;                                                                                     \n"// minnaert roughness  1.5                           \n" 
//      "            uniform highp float roughness;                                                                             \n"// Ward isotropic specular roughness 0.2                           \n" 
//      "            uniform highp float ior;                                                                                   \n"// Schlick's fresnel approximation index of refraction 1.5                           \n" 
      //-------------------------------------------- 
      "    varying    highp   vec4    Vertex;                                                                                         \n"                                                          
      "    varying    highp   vec4    inverseEye;                                                                                     \n"   
      "               highp   vec3    invertView;                                                                                     \n" 
//--------------------------------------------                                                                                                                           // Minnaert limb darkening diffuse term
      "    uniform sampler2D   FresnelMap;                                                                              \n"   
      "            highp vec4   fresnelTexture;                                                                          \n"      
      
      "            highp float  fresnelReflectance = 0.1;                                                                \n" 	                                                      
      "            highp vec3   Reflect;                                                                                 \n"                                                                  
      "            highp vec3   RH;                                                                                      \n"                                                               
      "            highp float  fresnel;                                                                                 \n" 
           
      //--------------------------------------------------------------------------------           
      
      "            highp vec3 minnaert( highp vec3 L, highp vec3 Nf, highp float k)                                                             \n" 
      "            {                                                                                                    \n" 
      "            	    highp float ndotl = max( 0.0, dot(L, Nf));                                                            \n" 
      "            	    return texture2D(Texture1,  varTexcoord).xyz * pow( ndotl, k);                                  \n" 
      "            }                                                                                                    \n" 

                                                                                                                           // Ward isotropic specular term
      "            highp vec3 wardiso( highp vec3 Nf, highp vec3 Ln, highp vec3 Hn, highp float roughness, highp float ndotv )                              \n" 
      "            {                                                                                                    \n" 
      "            	highp float ndoth      = dot( Nf, Hn);                                                                    \n" 
      "            	highp float ndotl      = dot( Nf, Ln);                                                                    \n" 
      "            	highp float tandelta   = tan( acos(ndoth));                                                               \n" 
      
      "            	return     texture2D(Texture1,  varTexcoord).xyz                                                    \n" 
      "            		     * exp( -( pow( tandelta, 1.7) / pow( roughness, 1.7)))                                     \n" 
      "            		     * (1.0 / sqrt( ndotl * ndotv ))                                                            \n" 
      "            		     * (1.0 / (4.0 * pow( roughness, 1.7)));                                                    \n" 
      "            	}                                                                                                   \n" 
	
      "             highp float schlick( highp vec3 Nf, highp vec3 Vf, highp float ior, highp float ndotv )                                           \n" 
      "             {                                                                                                   \n" 
      "            	highp float kr    = (ior-1.0)/(ior+1.0);                                                            \n" 
      "            	kr         *= kr;                                                                                   \n" 
      "            	return kr + (1.0-kr)*pow( 1.0 - ndotv, 5.0);                                                        \n" 
      "            }                                                                                                    \n" 


      //===================================================================================================================
      "     void main()                                                                                                  \n"                       
      "     {                                                                                                            \n"                       
   
      //------------------------------------------------------------------------------------------------------------  
      "         highp float comp          = (shadowTexcoord.z / shadowTexcoord.w) - 8.4e-005;                            \n" 
      "         highp float depth_PowerVR =  texture2DProj(ShadowTexture, shadowTexcoord).r;                             \n" 
      "         highp float shadowVal     =  comp <= depth_PowerVR ? 1.0 : 0.4;                                          \n" 
      //------------------------------------------------------------------------------------------------------------   
 
      "         NormalTex                 =  texture2D(NormalMap,  varTexcoord).xyz;                                     \n"                       
      "         normal_FRAG               =  normalize(NormalTex - 0.5);                                                 \n"                       
      "         NdotL1                    =  max(dot(normal_FRAG, lightPosition_PASS.xyz), 0.0);                         \n"                       
      //------------------------------------------------------------------------------------------------------------        
      "         invertView                = -normalize(inverseEye.xyz);                                                         \n"      
      
      "         fresnelTexture            =  texture2D(FresnelMap,  varTexcoord);                                               \n"        
     
      "         Reflect                   =  reflect(invertView, normal_FRAG);                                                  \n"
      "         RH                        =  normalize(Reflect - invertView);                                                                                             \n"
      "         fresnel                   =  fresnelReflectance + (1.0 - fresnelReflectance) * pow(dot(invertView, RH), 1.0);   \n" 
      "         fresnelTexture            =  texture2D(FresnelMap, 0.5 + 0.5 * normalize(Reflect + vec3(0.0, 0.0, 1.0)).xy);    \n" 
     
            //Reflect         = reflect(invertView, normal) ;
            
            //RH              = normalize(Reflect - invertView);
            
            //fresnel         = fresnelReflectance + (1.0 - fresnelReflectance) * pow(1.0 + dot(invertView, RH),7.0);///ADJUSTMENT FOR TEXTURE MAP BRIGHTNESS
            
            //texture         = texture2D(Texture1, 0.5 + 0.5 * normalize(Reflect + vec3(0.0, 0.0, 1.0)).xy)*NdotL;
     
      //------------------------------------------------------------------------------------------------------------  
      // Copyright 2007 Sancho Pereira
     
      "         highp vec3  V              =  normalize(v_V);                                                                          \n" 
      "         highp vec3  L              =  normalize(highp vec3(lightPosition_PASS));                                                     \n" 
      "         highp vec3  Vf             =  V;                                                                                      \n" 
      "         highp float ndotv          =  dot(normal_FRAG, Vf);                                                                    \n" 
      "         highp vec3  H              =  normalize(L+Vf);                                                                         \n" 

      "         highp vec3  ambient        =  texture2D(Texture1,  varTexcoord).xyz;                                                              \n" 
      "         highp vec3  diffuse        =  texture2D(Texture1,  varTexcoord).xyz * minnaert( L, normal_FRAG, 1.5);                                \n" 
      "         highp float fresnel        =  schlick( normal_FRAG, V, .1, ndotv);                                                    \n" 
      " 	highp vec3  specular       =  highp vec3(.99, .5, .1) * wardiso( normal_FRAG, L, H, 0.2, ndotv) * fresnel; \n"

      //-------------------------------------------------------------------------------------------------------------   

      "         gl_FragColor         =  highp vec4( diffuse + specular, 1.0) *  NdotL1 * 0.5 + fresnelTexture * 0.5 *  NdotL1;              \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT, 1, &fragmentSource_sancho_qshaderedit_minnaertWard, NULL);                                                                          
      glCompileShader(sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(sancho_qshaderedit_minnaertWard_SHADER, sancho_qshaderedit_minnaertWard_SHADER_VERTEX);                                                                                              
      glAttachShader(sancho_qshaderedit_minnaertWard_SHADER, sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(sancho_qshaderedit_minnaertWard_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(sancho_qshaderedit_minnaertWard_SHADER,    1, "normal");       
      glBindAttribLocation(sancho_qshaderedit_minnaertWard_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(sancho_qshaderedit_minnaertWard_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(sancho_qshaderedit_minnaertWard_SHADER, sancho_qshaderedit_minnaertWard_SHADER_VERTEX);                                                                                              
      glDetachShader(sancho_qshaderedit_minnaertWard_SHADER, sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(sancho_qshaderedit_minnaertWard_SHADER_VERTEX);                                                                                                            
      glDeleteShader(sancho_qshaderedit_minnaertWard_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_sancho_qshaderedit_minnaertWard                   = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "mvpMatrix"); 
      UNIFORM_MODELVIEW_sancho_qshaderedit_minnaertWard                       = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "mvMatrix");       
      //-------------------------------      
      UNIFORM_viewMatrix_sancho_qshaderedit_minnaertWard                      = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "viewMatrix");              
      //-------------------------------
      UNIFORM_SHADOW_PROJ_sancho_qshaderedit_minnaertWard                     = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_sancho_qshaderedit_minnaertWard                 = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "modelViewShadow");            
      //-------------------------------                                              
      UNIFORM_LIGHT_MATRIX_sancho_qshaderedit_minnaertWard                    = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "lightMatrix");                                            
      UNIFORM_textureMatrix_sancho_qshaderedit_minnaertWard                   = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "textureMatrix"); 
      //-------------------------------  
      UNIFORM_SHADOW_PROJ_sancho_qshaderedit_minnaertWard                     = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "projectionShadow");                                                  
      UNIFORM_modelViewShadow_sancho_qshaderedit_minnaertWard                 = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "modelViewShadow");            
      //-------------------------------  
      UNIFORM_LIGHT_POSITION_01_sancho_qshaderedit_minnaertWard               = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "light_POSITION_01");                                      
      UNIFORM_SHININESS_sancho_qshaderedit_minnaertWard                       = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "shininess");
      UNIFORM_GENERIC_sancho_qshaderedit_minnaertWard                         = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "generic");      
      
      UNIFORM_TEXTURE_SHADOW_sancho_qshaderedit_minnaertWard                  = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "ShadowTexture");       
      UNIFORM_TEXTURE_sancho_qshaderedit_minnaertWard_FRESNEL                 = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "FresnelMap");   
      
      UNIFORM_TEXTURE_DOT3_sancho_qshaderedit_minnaertWard                    = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "NormalMap");                                              
      UNIFORM_TEXTURE_sancho_qshaderedit_minnaertWard                         = glGetUniformLocation(sancho_qshaderedit_minnaertWard_SHADER,      "Texture1");                                   

      


