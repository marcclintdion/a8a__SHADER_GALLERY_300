GLuint      knight_SHADER_VERTEX;                                                                                                      
GLuint      knight_SHADER_FRAGMENT;                                                                                                    
GLuint      knight_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_knight;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_knight;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_knight;                                                                                          
GLuint      UNIFORM_SHININESS_knight;                                                                                                  
GLuint      UNIFORM_ATTENUATION_knight;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_knight;                                                                                               
GLuint      UNIFORM_TEXTURE_knight;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     knight_POSITION[]            =  {  0.6, -1.0,  0.0, 1.0};                                                                    
GLfloat     knight_ROTATE[]              =  {  0.0,  1.0,  0.0, 0.0};                                                                   
GLfloat     knight_SCALE[]               =  {  1.0,  1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     knight_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     knight_SHININESS             =    80.0;                                                                                    
GLfloat     knight_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      knight_VBO;  
GLuint      knight_INDICES_VBO;  
                                                                                                              
//-----------------------------------------------------------------                                                                       
GLuint      knight_NORMALMAP;                                                                                                          
GLuint      knight_TEXTUREMAP;                                                                                                         
