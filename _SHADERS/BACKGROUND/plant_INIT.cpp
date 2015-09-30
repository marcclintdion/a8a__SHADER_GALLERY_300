    plant_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_plant =                                                                                    

    " #define highp                                                                                                       \n" 
    "     attribute vec4 vertex_01;                                                                                      \n" 
    "     attribute vec2 texture;                                                                                        \n" 
    " //-------------------------------------------------                                                                \n"     
    "     uniform   highp vec4 light_POSITION_01;                                                                         \n" 
    "     uniform        mat4 ModelView;                                                                                 \n" 
    "     uniform        mat4 ModelViewProjection;                                                                       \n" 
    "   //uniform        mat4 ModelViewProjectionInverse;                                                                \n" 
    "     uniform        mat4 LightMatrix;                                                                               \n" 
    "     uniform        mat4 TextureMatrix;                                                                             \n" 
    "     uniform highp   vec4 offset;                                                                                    \n" 
    "     uniform highp   vec4 tileJump;                                                                                  \n" 
    "   //uniform highp  float counter;                                                                                   \n" 
    " //-------------------------------------------------                                                                \n" 
    "     varying highp   vec4 TEMP_shadowTexcoord;                                                                       \n" 
    "     varying highp   vec4 shadowTexcoord;                                                                            \n" 
    "     varying highp   vec4 lightPosition_PASS;                                                                        \n" 
    "     varying highp   vec2 varTexcoord;                                                                               \n" 
    " //-------------------------------------------------                                                                \n" 
    " 	  varying highp  float dist;                                                                                      \n" 
    "             highp   vec4 ecPos;                                                                                     \n" 
    "             highp   vec3 aux;                                                                                       \n" 
    
    " void main()                                                                                                        \n" 
    " {                                                                                                                  \n" 
    
    "		     ecPos = ModelView * vertex_01;                                                                          \n" //this portion comes from --> Lighthouse3d.com
    "		     aux   = vec3(light_POSITION_01 - ecPos);                                                                \n" //this portion comes from --> Lighthouse3d.com 
    "		     dist = length(aux);                                                                                     \n" //this portion comes from --> Lighthouse3d.com 
    "            //----------------------------------------------------------------------------                          \n" 
    "            varTexcoord             = texture;                                                                      \n" 
    "            TEMP_shadowTexcoord     = TextureMatrix * ModelView * vertex_01;                                        \n" 
    "            TEMP_shadowTexcoord    += offset;                                                                       \n" 
    "            shadowTexcoord          = TEMP_shadowTexcoord  * 0.025;                                                 \n" 
    "            //----------------------------------------------------------------------------                          \n"    
    "            lightPosition_PASS      = normalize(LightMatrix * light_POSITION_01-vertex_01);                         \n" 
    "            gl_Position             = ModelViewProjection * vertex_01;                                              \n" 
    " } \n";   
    //--------------------------------------------------------------------------------------------------------                  

    const GLchar *fragmentSource_plant =                                                                                  

    "#ifdef GL_ES                                                                                                         \n" 
    "#else                                                                                                                \n" 
    "#define highp                                                                                                         \n" 
    "#endif                                                                                                               \n" 

    "//---------------------------------------------------------------------------------------GLOBALS                     \n" 

    "     uniform sampler2D   Texture1;                                                                                   \n" 
    "     uniform sampler2D   NormalMap;                                                                                  \n" 
    "     uniform sampler2D   ShadowTexture;                                                                              \n" 
    "     uniform highp  float ambient;                                                                                    \n" 
    "//--------------------------------------------                                                                       \n" 
    "     varying highp vec4   lightPosition_PASS;                                                                         \n" 
    "     varying highp vec2   varTexcoord;                                                                                \n" 
    "     varying highp vec4   shadowTexcoord;                                                                             \n" 
    "//--------------------------------------------                                                                       \n" 
    "             highp vec4   tempColor;                                                                                  \n" 
    "             highp vec3   NormalTex;                                                                                  \n" 
    "             highp vec4   shadow;                                                                                     \n" 
    "             highp float  shadowLayer_01;                                                                             \n"     
    "             highp float  shadowLayer_02;                                                                             \n"  
    "             highp float  shadowLayer_03;                                                                             \n"     
    "             highp float  shadowLayer_04;                                                                             \n"      
    
    "             highp float  specular;                                                                                   \n"     
    "             //------------------------                                                                              \n" 
    "             highp float  NdotL1;                                                                                     \n" 
    "//-------------------------------------------------                                                                  \n" 
    " 	  varying highp float  dist;                                                                                       \n"     
    "             highp float  attenuation;                                                                                \n" 
    
    
    "//---------------------------------------------------------------------------------------MAIN                        \n" 
    "void main()                                                                                                          \n" 
    "{                                                                                                                    \n" 
	"		attenuation = 1.0 / (ambient * dist * dist);                                                                         \n"     //this portion comes from --> Lighthouse3d.com 
     
    "            //----------------------------------------------------------------------------                           \n"     
    "            shadowLayer_01  =  texture2D(ShadowTexture, shadowTexcoord.st).r;                                        \n" 
    "            shadow          =  vec4(shadowLayer_01, shadowLayer_01, shadowLayer_01, shadowLayer_01);                 \n" 
    "            //----------------------------------------------------------------------------                           \n" 
    "            NormalTex       =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                            \n" 
    "            NormalTex       =  normalize((NormalTex  - 0.5));                                                                              \n" 
    "            NdotL1          =  dot(NormalTex, lightPosition_PASS.xyz);                                                                     \n" 
    "            //----------------------------------------------------------------------------                                                 \n" 
    "           tempColor       =  pow(NdotL1, 50.0)*texture2D(Texture1, varTexcoord.xy)+texture2D(Texture1, varTexcoord.xy);                  \n" 

    "            gl_FragColor    =  tempColor * shadow * attenuation *NdotL1*NdotL1+ambient*.00;                                                                  \n" 
    "            //gl_FragColor    =  tempColor * attenuation *NdotL1*NdotL1+ambient*.00;                                                                  \n" 

    "}\n";

    
    
        //--------------------------------------------------------------------------------------------------                    

        plant_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( plant_SHADER_VERTEX, 1, &vertexSource_plant, NULL );                                        
        glCompileShader( plant_SHADER_VERTEX);                                              //glShaderBinary                                                                              
        //----------------------------------------------------                                                                  
        plant_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( plant_SHADER_FRAGMENT, 1, &fragmentSource_plant, NULL );                                    
        glCompileShader(plant_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( plant_SHADER, plant_SHADER_VERTEX );                                                        
        glAttachShader( plant_SHADER, plant_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(plant_SHADER,   0, "vertex_01");                                                              
        //glBindAttribLocation(plant_SHADER,   1, "normal");                                                            
        glBindAttribLocation(plant_SHADER,   1, "texture");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( plant_SHADER_VERTEX);                                                                             
        glDeleteShader( plant_SHADER_FRAGMENT);                                                                           
        glLinkProgram(plant_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_MODELVIEW_plant               = glGetUniformLocation(plant_SHADER, "ModelView");                  
        UNIFORM_MODELVIEWPROJ_plant           = glGetUniformLocation(plant_SHADER, "ModelViewProjection");        
        //UNIFORM_MODELVIEWPROJ_INVERSE_plant = glGetUniformLocation(plant_SHADER, "ModelViewProjectionInverse"); 
        UNIFORM_LIGHT_MATRIX_plant            = glGetUniformLocation(plant_SHADER, "LightMatrix");                
        UNIFORM_TEXTURE_MATRIX_plant          = glGetUniformLocation(plant_SHADER, "TextureMatrix");         
        //-----------------------------                                                                                         
        UNIFORM_LIGHT_POSITION_01_plant       = glGetUniformLocation(plant_SHADER, "light_POSITION_01");          
        UNIFORM_offset_plant                  = glGetUniformLocation(plant_SHADER, "offset");                     
        UNIFORM_tileJump_plant                = glGetUniformLocation(plant_SHADER, "tileJump");                   
        UNIFORM_ambient_plant                 = glGetUniformLocation(plant_SHADER, "ambient");         
        //-----------------------------                                                                                         
        UNIFORM_TEXTURE_SHADOW_plant          = glGetUniformLocation(plant_SHADER, "ShadowTexture");              
        UNIFORM_TEXTURE_DOT3_plant            = glGetUniformLocation(plant_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_plant                 = glGetUniformLocation(plant_SHADER, "Texture1");  
