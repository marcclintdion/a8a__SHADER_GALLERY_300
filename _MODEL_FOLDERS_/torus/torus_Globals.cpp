GLuint      torus_SHADER_VERTEX;                                                                                                      
GLuint      torus_SHADER_FRAGMENT;                                                                                                    
GLuint      torus_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_torus;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_torus;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_torus;                                                                                          
GLuint      UNIFORM_SHININESS_torus;                                                                                                  
GLuint      UNIFORM_ATTENUATION_torus;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_torus;                                                                                               
GLuint      UNIFORM_TEXTURE_torus;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     torus_POSITION[]             =  {-0.5, -1.05, 0, 1.0};                                                                    
GLfloat     torus_ROTATE[]              =  {  1.0, 1.0,  1.0, 0.0};                                                                   
GLfloat     torus_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     torus_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     torus_SHININESS             =    80.0;                                                                                    
GLfloat     torus_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      torus_VBO; 
GLuint      torus_INDEX_VBO;                                                                                                               
//-----------------------------------------------------------------                                                                       
GLuint      torus_NORMALMAP;                                                                                                          
GLuint      torus_TEXTUREMAP;                                                                                                         
