    wood_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_wood =                                                                                    

    " #define highp                                                                                                        \n" 
    "     attribute vec4 vertex_01;                                                                                       \n" 
    "     attribute vec2 texture;                                                                                         \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform   highp vec4 light_POSITION_01;                                                                          \n" 
    "     uniform        mat4 ModelView;                                                                                  \n" 
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
    "   //uniform        mat4 ModelViewProjectionInverse;                                                                 \n" 
    "     uniform        mat4 LightMatrix;                                                                                \n" 
    "     uniform        mat4 TextureMatrix;                                                                              \n" 
    "     uniform highp   vec4 offset;                                                                                     \n" 
    "     uniform highp   vec4 tileJump;                                                                                   \n" 
    "   //uniform highp  float counter;                                                                                    \n" 
    " //-------------------------------------------------                                                                 \n" 
    "     varying highp   vec4 TEMP_shadowTexcoord;                                                                        \n" 
    "     varying highp   vec4 shadowTexcoord;                                                                             \n" 
    "     varying highp   vec4 lightPosition_PASS;                                                                         \n" 
    "     varying highp   vec2 varTexcoord;                                                                                \n" 
    " //-------------------------------------------------                                                                 \n" 
    " 	  varying highp  float dist;                                                                                       \n" 
    "             highp   vec4 ecPos;                                                                                      \n" 
    "             highp   vec3 aux;                                                                                        \n" 
    
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 
    
    "		     ecPos = ModelView * vertex_01;                                                                           \n" //this portion comes from --> Lighthouse3d.com
    "		     aux   = vec3(light_POSITION_01 - ecPos);                                                                 \n" //this portion comes from --> Lighthouse3d.com 
    "		     dist = length(aux);                                                                                      \n" //this portion comes from --> Lighthouse3d.com 
    
    "     varTexcoord             = texture;                                                                              \n" 
    "     TEMP_shadowTexcoord     = TextureMatrix * ModelView * vertex_01;                                                \n" 
    "     TEMP_shadowTexcoord    += offset;                                                                               \n" 
    "     shadowTexcoord          = TEMP_shadowTexcoord  * 0.025;                                                         \n" 
    "     lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01-vertex_01);                                 \n" 
    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_wood =                                                                                  

    "#ifdef GL_ES                                                                                                         \n" 
    "#else                                                                                                                \n" 
    "#define highp                                                                                                         \n" 
    "#endif                                                                                                               \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                     \n" 

    "     uniform sampler2D   Texture1;                                                                                   \n" 
    "     uniform sampler2D   NormalMap;                                                                                  \n" 
    "     uniform sampler2D   ShadowTexture;                                                                              \n" 
     
    "     uniform highp float  ambient;                                                                                    \n" 
    "     uniform highp float  shininess;                                                                                  \n"      
    "     uniform highp float  counter;                                                                                    \n"    
    "     uniform highp float  ambient_shiny;                                                                              \n"    
    "//--------------------------------------------                                                                       \n" 
    "     varying highp  vec4  lightPosition_PASS;                                                                         \n" 
    "     varying highp  vec2  varTexcoord;                                                                                \n" 
    "     varying highp  vec4  shadowTexcoord;                                                                             \n" 
    "//--------------------------------------------                                                                       \n" 
    "             highp  vec4  tempColor;                                                                                  \n" 
    "             highp  vec3  NormalTex;                                                                                  \n" 
    "             highp  vec4  shadow;                                                                                     \n" 
    "             highp  vec4  specular;                                                                                   \n"     
    "             highp float  shadowLayer_01;                                                                             \n"     
    "             highp float  shadowLayer_02;                                                                             \n"  
    "             highp float  shadowLayer_03;                                                                             \n"     
    "             highp float  shadowLayer_04;                                                                             \n"   
   "             //------------------------                                                                               \n" 
    "             highp float  NdotL1;                                                                                     \n" 
    "//-------------------------------------------------                                                                  \n" 
    " 	  varying highp float  dist;                                                                                       \n"     
    "             highp float  attenuation;                                                                                \n" 
    "             highp float  attenuation_SHINY;                                                                          \n" 
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
	"		     attenuation = 1.0 / (ambient * dist * dist);                                                             \n"     //this portion comes from --> Lighthouse3d.com 
	"		     attenuation += counter;                                                                                  \n"      
    "            //----------------------------------------------------------------------------                           \n"     
	"		     attenuation_SHINY = 1.0 / (dist * dist) * ambient_shiny;                                                 \n"     //this portion comes from --> Lighthouse3d.com 
    "            //----------------------------------------------------------------------------                           \n"     
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                            \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5));                                                        \n" 
    "            NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);                                               \n"   
    "            //----------------------------------------------------------------------------                           \n"        
    "            shadowLayer_01  =  texture2D(ShadowTexture, shadowTexcoord.st).r;                                        \n" 
    "            shadowLayer_02  =  texture2D(ShadowTexture, shadowTexcoord.st).g;                                        \n"     
    "            shadow          =  vec4(shadowLayer_01*shadowLayer_02,                                                   \n" 
    "                                    shadowLayer_01*shadowLayer_02,                                                   \n" 
    "                                    shadowLayer_01*shadowLayer_02,                                                   \n" 
    "                                    shadowLayer_01*shadowLayer_02);                                                  \n" 
    "            //----------------------------------------------------------------------------                           \n" 
    "            tempColor       =  texture2D(Texture1, varTexcoord.xy);                                                  \n" 
    "	         specular        =  pow(NdotL1,  shininess) * tempColor * attenuation_SHINY;                              \n" 
    "            gl_FragColor    =   tempColor * shadow * attenuation * NdotL1* NdotL1 + specular;                         \n" 
    "            //gl_FragColor    =   tempColor * attenuation * NdotL1* NdotL1 + specular;                         \n" 

    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        wood_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( wood_SHADER_VERTEX, 1, &vertexSource_wood, NULL );                                        
        glCompileShader( wood_SHADER_VERTEX);                                               //glShaderBinary                                                                             
        //----------------------------------------------------                                                                  
        wood_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( wood_SHADER_FRAGMENT, 1, &fragmentSource_wood, NULL );                                    
        glCompileShader(wood_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( wood_SHADER, wood_SHADER_VERTEX );                                                        
        glAttachShader( wood_SHADER, wood_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(wood_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(wood_SHADER,   1, "normal");                                                            
        glBindAttribLocation(wood_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glLinkProgram(wood_SHADER); 
        glDeleteShader( wood_SHADER_VERTEX);                                                                             
        glDeleteShader( wood_SHADER_FRAGMENT);                                                                           
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_wood               = glGetUniformLocation(wood_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_wood           = glGetUniformLocation(wood_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_wood = glGetUniformLocation(wood_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_wood            = glGetUniformLocation(wood_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_wood          = glGetUniformLocation(wood_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_wood       = glGetUniformLocation(wood_SHADER, "light_POSITION_01");          
        UNIFORM_offset_wood                  = glGetUniformLocation(wood_SHADER, "offset");                     
        UNIFORM_tileJump_wood                = glGetUniformLocation(wood_SHADER, "tileJump");                   
        UNIFORM_ambient_wood                 = glGetUniformLocation(wood_SHADER, "ambient");         
        UNIFORM_attenuation_SHINY_wood       = glGetUniformLocation(wood_SHADER, "ambient_shiny");        
        UNIFORM_shininess_wood               = glGetUniformLocation(wood_SHADER, "shininess");     
        UNIFORM_counter_wood                 = glGetUniformLocation(wood_SHADER, "counter");       
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_wood          = glGetUniformLocation(wood_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_wood            = glGetUniformLocation(wood_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_wood                 = glGetUniformLocation(wood_SHADER, "Texture1");  
