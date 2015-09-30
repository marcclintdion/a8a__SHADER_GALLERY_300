    
    SHADER_shadow = glCreateProgram();
    //---------------------------------------------------- 
const GLchar *vertexSource_shadow =

"    #define lowp                                                                                 \n"

"    uniform      mat4 ModelView;                                                                 \n"
"    uniform      mat4 ModelViewProjection;                                                       \n"

"    attribute    vec4 position;                                                                  \n"
"                 vec4 tempPosition;                                                              \n"

"    void main()                                                                                  \n"
"    {                                                                                            \n"

"        tempPosition        =   position;                                                        \n"



"        gl_Position         = ModelViewProjection * tempPosition;                                \n"


"    }\n";

    //---------------------------------------------------------------------

const GLchar *fragmentSource_shadow =     

" #ifdef GL_ES                                                                                    \n"
" #else                                                                                           \n"
" #define lowp                                                                                    \n"
" #endif                                                                                          \n"

"    uniform lowp vec4 darkness;                                                                  \n"


"     void main()                                                                                 \n"
"     {                                                                                           \n"

"         gl_FragColor          =  darkness;                                                      \n"         


"    }\n";
    //--------------------------------------------------------------------------------------------------------------------------------------   
    SHADER_VERTEX_shadow = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( SHADER_VERTEX_shadow, 1, &vertexSource_shadow, NULL );
    glCompileShader( SHADER_VERTEX_shadow);

    //----------------------------------------------------        
    SHADER_FRAGMENT_shadow = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource( SHADER_FRAGMENT_shadow, 1, &fragmentSource_shadow, NULL );
    glCompileShader(SHADER_FRAGMENT_shadow);
       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glAttachShader( SHADER_shadow, SHADER_VERTEX_shadow );
    glAttachShader( SHADER_shadow, SHADER_FRAGMENT_shadow );
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glBindAttribLocation(SHADER_shadow,   0, "position");    
    //glBindAttribLocation(SHADER_shadow, 1, "normal");    
    glBindAttribLocation(SHADER_shadow,   1, "texture");       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glDeleteShader(SHADER_VERTEX_shadow);
	glDeleteShader(SHADER_FRAGMENT_shadow);   
    glLinkProgram( SHADER_shadow);  
    //--------------------------------------------------------------------------------------------------------------------------------------  
    UNIFORM_darkness_shadow                = glGetUniformLocation(SHADER_shadow, "darkness");
    UNIFORM_MODELVIEW_shadow               = glGetUniformLocation(SHADER_shadow, "ModelView");  
    UNIFORM_MODELVIEWPROJ_shadow           = glGetUniformLocation(SHADER_shadow, "ModelViewProjection");
    UNIFORM_MODELVIEWPROJ_INVERSE_shadow   = glGetUniformLocation(SHADER_shadow, "ModelViewProjectionInverse");    
    UNIFORM_LIGHT_MATRIX_shadow            = glGetUniformLocation(SHADER_shadow, "LightMatrix");        
