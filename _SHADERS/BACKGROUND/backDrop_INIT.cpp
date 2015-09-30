    backDrop_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_backDrop =                                                                                    

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

    const GLchar *fragmentSource_backDrop =                                                                                  

    "#ifdef GL_ES                                                                                                         \n" 
    "#else                                                                                                                \n" 
    "#define highp                                                                                                         \n" 
    "#endif                                                                                                               \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                     \n" 

    "     uniform sampler2D   Texture1;                                                                                   \n" 
    "     uniform sampler2D   NormalMap;                                                                                  \n" 
    "     uniform sampler2D   ShadowTexture;                                                                              \n" 
     
    "     uniform highp float  ambient;                                                                                    \n" 
    "     uniform highp float  shininess;                                                                                    \n"      
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
   "             //------------------------                                                                              \n" 
    "             highp float  NdotL1;                                                                                     \n" 
    "//-------------------------------------------------                                                                  \n" 
    " 	  varying highp float  dist;                                                                                       \n"     
    "             highp float  attenuation;                                                                                \n" 

    
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
	"		     attenuation = 1.0 / (ambient * dist* dist);                                                              \n"     //this portion comes from --> Lighthouse3d.com 
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
    "	         specular        =  pow(NdotL1,  shininess) * tempColor* NdotL1* NdotL1;                                  \n" 
    "            gl_FragColor    =   texture2D(Texture1, varTexcoord.xy);                                                 \n" 

    "}\n";

    
      //--------------------------------------------------------------------------------------------------                    

        backDrop_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( backDrop_SHADER_VERTEX, 1, &vertexSource_backDrop, NULL );                                        
        glCompileShader( backDrop_SHADER_VERTEX);                                                                            
        //----------------------------------------------------                                                                  
        backDrop_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( backDrop_SHADER_FRAGMENT, 1, &fragmentSource_backDrop, NULL );                                    
        glCompileShader(backDrop_SHADER_FRAGMENT);                                                                           
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( backDrop_SHADER, backDrop_SHADER_VERTEX );                                                        
        glAttachShader( backDrop_SHADER, backDrop_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(backDrop_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(backDrop_SHADER,   1, "normal");                                                            
        glBindAttribLocation(backDrop_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( backDrop_SHADER_VERTEX);                                                                             
        glDeleteShader( backDrop_SHADER_FRAGMENT);                                                                           
        glLinkProgram(backDrop_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_backDrop               = glGetUniformLocation(backDrop_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_backDrop           = glGetUniformLocation(backDrop_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_backDrop = glGetUniformLocation(backDrop_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_backDrop            = glGetUniformLocation(backDrop_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_backDrop          = glGetUniformLocation(backDrop_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_backDrop       = glGetUniformLocation(backDrop_SHADER, "light_POSITION_01");          
        UNIFORM_offset_backDrop                  = glGetUniformLocation(backDrop_SHADER, "offset");                     
        UNIFORM_tileJump_backDrop                = glGetUniformLocation(backDrop_SHADER, "tileJump");                   
        UNIFORM_ambient_backDrop                 = glGetUniformLocation(backDrop_SHADER, "ambient");         
        UNIFORM_shininess_backDrop               = glGetUniformLocation(backDrop_SHADER, "shininess");     
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_backDrop          = glGetUniformLocation(backDrop_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_backDrop            = glGetUniformLocation(backDrop_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_backDrop                 = glGetUniformLocation(backDrop_SHADER, "Texture1");  
