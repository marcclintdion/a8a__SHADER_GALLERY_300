    wood_32B_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_wood_32B =                                                                                    

    " #define lowp                                                                                                        \n" 
    "     attribute vec4 vertex_01;                                                                                       \n" 
    "     attribute vec3 normal;                                                                                       \n"     
    "     attribute vec2 texture;                                                                                         \n" 
    " //-------------------------------------------------                                                                 \n"     
    "     uniform   lowp vec4 light_POSITION_01;                                                                          \n" 
    "     uniform        mat4 ModelView;                                                                                  \n" 
    "     uniform        mat4 ModelViewProjection;                                                                        \n" 
    "   //uniform        mat4 ModelViewProjectionInverse;                                                                 \n" 
    "     uniform        mat4 LightMatrix;                                                                                \n" 
    "     uniform        mat4 TextureMatrix;                                                                              \n" 
    "     uniform lowp   vec4 offset;                                                                                     \n" 
    "     uniform lowp   vec4 tileJump;                                                                                   \n" 
    "   //uniform lowp  float counter;                                                                                    \n" 
    " //-------------------------------------------------                                                                 \n" 
    "     varying lowp   vec4 TEMP_shadowTexcoord;                                                                        \n" 
    "     varying lowp   vec4 shadowTexcoord;                                                                             \n" 
    "     varying lowp   vec4 lightPosition_PASS;                                                                         \n" 
    "     varying lowp   vec3  normal_PASS;                                                                               \n"         
    "     varying lowp   vec2 varTexcoord;                                                                                \n" 
    " //-------------------------------------------------                                                                 \n" 
    " 	  varying lowp  float dist;                                                                                       \n" 
    "             lowp   vec4 ecPos;                                                                                      \n" 
    "             lowp   vec3 aux;                                                                                        \n" 
    
    " void main()                                                                                                         \n" 
    " {                                                                                                                   \n" 
    
    "		     ecPos = ModelView * vertex_01;                                                                           \n" //this portion comes from --> Lighthouse3d.com
    "		     aux   = vec3(light_POSITION_01 - ecPos);                                                                 \n" //this portion comes from --> Lighthouse3d.com 
    "		     dist = length(aux);                                                                                      \n" //this portion comes from --> Lighthouse3d.com 
    
    "     normal_PASS             = normalize(normal);                                                  \n" 
    
    "     varTexcoord             = texture;                                                                              \n" 
    "     TEMP_shadowTexcoord     = TextureMatrix * ModelView * vertex_01;                                                \n" 
    "     TEMP_shadowTexcoord    += offset;                                                                               \n" 
    "     shadowTexcoord          = TEMP_shadowTexcoord  * 0.025;                                                         \n" 
    "     lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01-vertex_01);                                 \n" 
    "     gl_Position             = ModelViewProjection * vertex_01;                                                      \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_wood_32B =                                                                                  

    "#ifdef GL_ES                                                                                                         \n" 
    "#else                                                                                                                \n" 
    "#define lowp                                                                                                         \n" 
    "#endif                                                                                                               \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                     \n" 

    "     uniform sampler2D   Texture1;                                                                                   \n" 
    "     uniform sampler2D   NormalMap;                                                                                  \n" 
    "     uniform sampler2D   ShadowTexture;                                                                              \n" 
    "     uniform lowp float  ambient;                                                                                    \n" 
    "//--------------------------------------------                                                                       \n" 
    "     varying lowp  vec4  lightPosition_PASS;                                                                         \n" 
    "     varying lowp  vec3  normal_PASS;                                                                                \n"     
    "     varying lowp  vec2  varTexcoord;                                                                                \n" 
    "     varying lowp  vec4  shadowTexcoord;                                                                             \n" 
    "//--------------------------------------------                                                                       \n" 
    "             lowp  vec4  tempColor;                                                                                  \n" 
    "             lowp  vec3  NormalTex;                                                                                  \n" 
    "             lowp  vec4  shadow;                                                                                     \n" 
    "             lowp float  shadowLayer_01;                                                                             \n"     
    "             lowp float  shadowLayer_02;                                                                             \n"  
    "             lowp float  shadowLayer_03;                                                                             \n"     
    "             lowp float  shadowLayer_04;                                                                             \n"   
    "             lowp vec4   specular;                                                                                   \n"     
    "             //------------------------                                                                              \n" 
    "             lowp float  NdotL1;                                                                                     \n" 
    "//-------------------------------------------------                                                                  \n" 
    " 	  varying lowp float  dist;                                                                                       \n"     
    "             lowp float  attenuation;                                                                                \n" 

    
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
	"		     attenuation = 1.0 / (ambient * dist* dist);                                                              \n"     //this portion comes from --> Lighthouse3d.com 
    "            //----------------------------------------------------------------------------                           \n"     
    "            NormalTex       =  normalize(normal_PASS);                                                               \n" 
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
    "	         specular        =  (vec4(5.2, 3.1, 1.0, 1.0) * pow(NdotL1,  35.0) * tempColor + tempColor);              \n" 
    "            gl_FragColor    =  specular * shadow * attenuation * NdotL1 ;                                            \n" 

    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        wood_32B_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( wood_32B_SHADER_VERTEX, 1, &vertexSource_wood_32B, NULL );                                        
        glCompileShader( wood_32B_SHADER_VERTEX);                                                                            
        //----------------------------------------------------                                                                  
        wood_32B_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( wood_32B_SHADER_FRAGMENT, 1, &fragmentSource_wood_32B, NULL );                                    
        glCompileShader(wood_32B_SHADER_FRAGMENT);                                                                           
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( wood_32B_SHADER, wood_32B_SHADER_VERTEX );                                                        
        glAttachShader( wood_32B_SHADER, wood_32B_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(wood_32B_SHADER,   0, "vertex_01");                                                              
        glBindAttribLocation(wood_32B_SHADER,   1, "normal");                                                            
        glBindAttribLocation(wood_32B_SHADER,   2, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( wood_32B_SHADER_VERTEX);                                                                             
        glDeleteShader( wood_32B_SHADER_FRAGMENT);                                                                           
        glLinkProgram(wood_32B_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_wood_32B               = glGetUniformLocation(wood_32B_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_wood_32B           = glGetUniformLocation(wood_32B_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_wood_32B = glGetUniformLocation(wood_32B_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_wood_32B            = glGetUniformLocation(wood_32B_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_wood_32B          = glGetUniformLocation(wood_32B_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_wood_32B       = glGetUniformLocation(wood_32B_SHADER, "light_POSITION_01");          
        UNIFORM_offset_wood_32B                  = glGetUniformLocation(wood_32B_SHADER, "offset");                     
        UNIFORM_tileJump_wood_32B                = glGetUniformLocation(wood_32B_SHADER, "tileJump");                   
        UNIFORM_ambient_wood_32B                 = glGetUniformLocation(wood_32B_SHADER, "ambient");         
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_wood_32B          = glGetUniformLocation(wood_32B_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_wood_32B            = glGetUniformLocation(wood_32B_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_wood_32B                 = glGetUniformLocation(wood_32B_SHADER, "Texture1");  
