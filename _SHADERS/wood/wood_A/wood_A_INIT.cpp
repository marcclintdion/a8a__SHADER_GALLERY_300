    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      wood_A_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_wood_A =                                                                                                        

      "    #define highp                                                                                       \n"                           

      "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
      "    uniform       mat4   mvpMatrix;                                                                     \n"                           
      "    uniform       mat4   mvMatrix;                                                                     \n"        
      "    uniform       mat4   lightMatrix1;                                                                   \n"                           
      "    uniform       mat4   lightMatrix2;                                                                   \n"   

      "    varying    highp   vec4    lightPosition_PASS_01;                                                    \n"             
      
      "    varying highp   vec3   column0;                                                                      \n"   
      "    varying highp   vec3   column1;                                                                      \n"   
      "    varying highp   vec3   column2;                                                                      \n"        


      "    attribute     vec4   position;                                                                      \n"                           
      "    attribute     vec3   normal;                                                                        \n"      
      "    attribute     vec2   texture;                                                                       \n"                           

      "    varying       mat4   pass_mvp;                                                                      \n"         
      "    varying highp vec3   vViewVec;                                                                      \n"        
      "    varying highp vec3   vNormal;                                                                       \n"       
      "    varying highp vec2   varTexcoord;                                                                   \n"                           

      "    void main()                                                                                         \n"                           
      "    {                                                                                                   \n"                           
  
      //---------------------------------------------------------------------------------------------------------------------
      
      "        pass_mvp              = mvpMatrix;                                                              \n"    
      
      "        column0               =  vec3(lightMatrix1[0].xyz);                                             \n"   
      "        column1               =  vec3(lightMatrix1[1].xyz);                                             \n"   
      "        column2               =  vec3(lightMatrix1[2].xyz);                                             \n"        
       
      //---------------------------------------------------------------------------------------------------------------------
      "        vec4 tempLight         =  light_POSITION_01;                                                      \n"
      "        tempLight.z            =  light_POSITION_01.z * -1.0;                                            \n"      
      "        lightPosition_PASS_01  = normalize(lightMatrix2 * tempLight);                            \n"
      
      "        varTexcoord             = texture;                                                               \n"                           
      "        gl_Position             = mvpMatrix * position;                                                  \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      wood_A_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(wood_A_SHADER_VERTEX, 1, &vertexSource_wood_A, NULL);                                                                        
      glCompileShader(wood_A_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_wood_A =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"                       

      "    uniform highp vec4   light_POSITION_01;                                                                       \n"          
      "    uniform sampler2D    Texture1;                                                                                \n"                       
      "    uniform sampler2D    NormalMap;                                                                               \n"                       
      "    uniform highp float  shininess;                                                                               \n"                       
      "    uniform highp float  attenuation;                                                                             \n"                       
      
      "    varying       mat4   pass_mvp;                                                                                \n"  
      "    varying highp vec4   lightPosition_PASS_01;                                                                   \n"     
           
      "    varying highp vec3   column0;                                                                                 \n"   
      "    varying highp vec3   column1;                                                                                 \n"   
      "    varying highp vec3   column2;                                                                                 \n"        

      "    varying highp vec2   varTexcoord;                                                                             \n"                       

      "            highp float  NdotL1;                                                                                  \n"                       
      "            highp vec3   normal_1;                                                                                \n"                       
      "            highp float  NdotL2;                                                                                  \n"                       
      "            highp vec3   normal_2;                                                                                \n"       
      "            highp vec3   NormalTex;                                                                               \n"                       
      
      "     void main()                                                                                                 \n"                       
      "     {                                                                                                           \n"                       
     

//===================================================================================================================================      
      "         mat3 n = mat3(column0, column1, column2);                                                               \n"       
      
            
      "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                        \n"                       
      "         NormalTex             = (NormalTex - 0.5);                                                              \n"                       
      //------------------------------------------------------------------------------------
      "         normal_1              =  normalize(n * NormalTex);                                                      \n"      
      "         NdotL1                =  max(dot(normal_1, normalize(light_POSITION_01.xyz)), 0.0);                     \n"                       
      //------------------------------------------------------------------------------------     
      "         normal_2              =  normalize(NormalTex);                                                          \n"      
      "         NdotL2                =  max(dot(normal_2, lightPosition_PASS_01), 0.0);                                \n"                       
      //------------------------------------------------------------------------------------     
    
      "         vec4 color_1          =  vec4(1.0, 1.0, 1.0, 1.0) *  NdotL1*  NdotL1 ;                                  \n"      
      "         vec4 color_2          =  vec4(1.0, 1.0, 1.0, 1.0) *  NdotL2*  NdotL2;                                   \n"       
      
      "         float shiny           =  max(pow(NdotL2, 40.0), 0.0);                                                  \n"  
      
      "         gl_FragColor          =  mix(color_1, color_2, attenuation) + vec4(1.0, .7, .2, 1.0) * shiny*0.5;                                    \n"                       
    
    //"         gl_FragColor.a        = 0.5;                                                                            \n"
      
      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      wood_A_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(wood_A_SHADER_FRAGMENT, 1, &fragmentSource_wood_A, NULL);                                                                          
      glCompileShader(wood_A_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(wood_A_SHADER, wood_A_SHADER_VERTEX);                                                                                              
      glAttachShader(wood_A_SHADER, wood_A_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(wood_A_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(wood_A_SHADER,    1, "normal");       
      glBindAttribLocation(wood_A_SHADER,    2, "texture");                                                                                            
      //------------------------------------------------                                                                                              
      glLinkProgram(wood_A_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(wood_A_SHADER, wood_A_SHADER_VERTEX);                                                                                              
      glDetachShader(wood_A_SHADER, wood_A_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(wood_A_SHADER_VERTEX);                                                                                                            
      glDeleteShader(wood_A_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_wood_A                   = glGetUniformLocation(wood_A_SHADER,   "mvpMatrix"); 
      UNIFORM_MODELVIEW_wood_A                       = glGetUniformLocation(wood_A_SHADER,   "mvMatrix");                                                    
      UNIFORM_LIGHT_MATRIX_1_wood_A                    = glGetUniformLocation(wood_A_SHADER,   "lightMatrix1");
      UNIFORM_LIGHT_MATRIX_2_wood_A                    = glGetUniformLocation(wood_A_SHADER,   "lightMatrix2");                                                 
      UNIFORM_LIGHT_POSITION_01_wood_A               = glGetUniformLocation(wood_A_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_wood_A                       = glGetUniformLocation(wood_A_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_wood_A                     = glGetUniformLocation(wood_A_SHADER,   "attenuation");                                              
      UNIFORM_TEXTURE_DOT3_wood_A                    = glGetUniformLocation(wood_A_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_wood_A                         = glGetUniformLocation(wood_A_SHADER,   "Texture1");   
      
      loadTexture("_SHADERS/wood/wood_A/rainbow.png",                rainbow_FRESNELMAP);       
      
                                      
