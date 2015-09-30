    #ifdef __APPLE__                                                                                                                          
      #import <OpenGLES/ES2/gl.h>                                                                                                               
      #import <OpenGLES/ES2/glext.h>                                                                                                            
      #endif                                                                                                                                    
      //===============================================================================================                                         
      reflection_SHADER = glCreateProgram();                                                                                                         
      //---------------------------------------------------------------------                                                                   
      const GLchar *vertexSource_reflection =                                                                                                        

      "    #define highp                                                                                       \n"                           

        "    uniform highp vec4   light_POSITION_01;                                                             \n"                           
        "    uniform       mat4   mvpMatrix;                                                                     \n"                           
        "    uniform       mat4   mvMatrix;                                                                     \n"            
        "    uniform       mat4   lightMatrix;                                                                   \n"                           
                   
      
        "    attribute     vec4   position;                                                                      \n"                           
        "    attribute     vec3   normal;                                                                        \n"         
        "    attribute     vec2   texture;                                                                       \n"                           


        "    varying highp vec4   lightPosition_PASS;                                                            \n"                           
        "    varying highp vec2   varTexcoord;                                                                   \n"                           
           //----------------------------------------
        "    varying highp vec4 Vertex;                                                                          \n"  
        "    varying highp vec3 wsI;                                                                             \n"  

        "    void main()                                                                                         \n"                           
        "    {                                                                                                   \n"                           
        "        Vertex            = lightMatrix * position;                                                       \n" 
        "        wsI               = Vertex.xyz * -1.0;                                                          \n" 
  
        
        "        lightPosition_PASS    =  normalize(lightMatrix * light_POSITION_01);                            \n"                           
        "        varTexcoord           =  texture;                                                               \n"                           
        "        gl_Position           =  mvpMatrix * position;                                                  \n"                           

      "    }\n";                                                                                                                             
      //---------------------------------------------------------------------                                                                   
      reflection_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);                                                                                   
      glShaderSource(reflection_SHADER_VERTEX, 1, &vertexSource_reflection, NULL);                                                                        
      glCompileShader(reflection_SHADER_VERTEX);                                                                                                     
      //---------------------------------------------------------------------                                                                   
      const GLchar *fragmentSource_reflection =                                                                                                            

     
     
      " #ifdef GL_ES                                                                                                     \n"                       
      " #else                                                                                                            \n"                       
      " #define highp                                                                                                    \n"                       
      " #endif                                                                                                           \n"   
    
        "    uniform sampler2D     Texture1;                                                                               \n"                       
        "    uniform sampler2D     NormalMap;                                                                              \n"                       
        "    uniform samplerCube   EnvMap;                                                                                 \n"    
        "    uniform highp vec4    light_POSITION_01;                                                                      \n"       
        "    uniform highp float   shininess;                                                                              \n"                       
        "    uniform highp float   attenuation;                                                                            \n"                       


        "    varying highp vec4    lightPosition_PASS;                                                                     \n"                       

        "    varying highp vec2    varTexcoord;                                                                            \n"                       

        "            highp float   NdotL1;                                                                                 \n"                       
        "            highp vec3    normal;                                                                                 \n"                       
        "            highp vec3    NormalTex;                                                                              \n"                       

             //----------------------------------------
        "    varying highp vec4 Vertex;                                                                                    \n"  
        "    varying highp vec3 wsI;                                                                                       \n"  
     
    
        "     void main()                                                                                                  \n"                       
        "     {                                                                                                            \n"                       

        "         NormalTex             =  texture2D(NormalMap,  varTexcoord).xyz;                                         \n"                       
        "         NormalTex             = (NormalTex - 0.5);                                                               \n"                       
        "         normal                =  normalize(NormalTex);                                                           \n"          
        "         NdotL1                =  dot(normal, lightPosition_PASS.xyz);                                            \n"                     
                  //----------------------------------------------------------------------
        "         highp vec3 wsR        =  reflect(normalize(wsI), normal);                                                           \n"      
        "         highp vec3 envColor   =  highp vec3(textureCube(EnvMap, wsR));                                           \n"      

 
                  //----------------------------------------------------------------------     
        "         gl_FragColor          =  mix(highp vec4(1.0), highp vec4(envColor, 1.0), attenuation) * NdotL1 * NdotL1;          \n"                       

      "    }\n";                                                                                                                                   

      //---------------------------------------------------------------------                                                                         
      reflection_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);                                                                                     
      glShaderSource(reflection_SHADER_FRAGMENT, 1, &fragmentSource_reflection, NULL);                                                                          
      glCompileShader(reflection_SHADER_FRAGMENT);                                                                                                         
      //------------------------------------------------                                                                                              
      glAttachShader(reflection_SHADER, reflection_SHADER_VERTEX);                                                                                              
      glAttachShader(reflection_SHADER, reflection_SHADER_FRAGMENT);                                                                                            
      //------------------------------------------------                                                                                              
      glBindAttribLocation(reflection_SHADER,    0, "position");                                                                                            
      glBindAttribLocation(reflection_SHADER,    1, "normal");       
      glBindAttribLocation(reflection_SHADER,    2, "texture");                                                                                           
      //------------------------------------------------                                                                                              
      glLinkProgram(reflection_SHADER);                                                                                                                    
      //------------------------------------------------                                                                                              
      #ifdef __APPLE__                                                                                                                                
      glDetachShader(reflection_SHADER, reflection_SHADER_VERTEX);                                                                                              
      glDetachShader(reflection_SHADER, reflection_SHADER_FRAGMENT);                                                                                            
      #endif                                                                                                                                          
      //------------------------------------------------                                                                                              
      glDeleteShader(reflection_SHADER_VERTEX);                                                                                                            
      glDeleteShader(reflection_SHADER_FRAGMENT);                                                                                                          
      //------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS                
      UNIFORM_MODELVIEWPROJ_reflection                   = glGetUniformLocation(reflection_SHADER,   "mvpMatrix"); 
      UNIFORM_MODELVIEW_reflection                       = glGetUniformLocation(reflection_SHADER,   "mvMatrix");                                                   
      UNIFORM_LIGHT_MATRIX_reflection                    = glGetUniformLocation(reflection_SHADER,   "lightMatrix");                                            
      UNIFORM_LIGHT_POSITION_01_reflection               = glGetUniformLocation(reflection_SHADER,   "light_POSITION_01");                                      
      UNIFORM_SHININESS_reflection                       = glGetUniformLocation(reflection_SHADER,   "shininess");                                              
      UNIFORM_ATTENUATION_reflection                     = glGetUniformLocation(reflection_SHADER,   "attenuation"); 
      UNIFORM_TEXTURE_DOT3_reflection                    = glGetUniformLocation(reflection_SHADER,   "NormalMap");                                                     
      UNIFORM_TEXTURE_DOT3_reflection                    = glGetUniformLocation(reflection_SHADER,   "NormalMap");                                              
      UNIFORM_TEXTURE_reflection                         = glGetUniformLocation(reflection_SHADER,   "Texture1");                                   
