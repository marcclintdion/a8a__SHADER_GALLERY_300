GLuint      spiralGear_SHADER_VERTEX;                                                                                                      
GLuint      spiralGear_SHADER_FRAGMENT;                                                                                                    
GLuint      spiralGear_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_spiralGear;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_spiralGear;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_spiralGear;                                                                                          
GLuint      UNIFORM_SHININESS_spiralGear;                                                                                                  
GLuint      UNIFORM_ATTENUATION_spiralGear;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_spiralGear;                                                                                               
GLuint      UNIFORM_TEXTURE_spiralGear;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     spiralGear_POSITION[]            =  {-0.8, 1.0, 0.03, 1.0};                                                                   
GLfloat     spiralGear_ROTATE[]              =  {  1.0, 1.0,  1.0, 0.0};                                                                   
GLfloat     spiralGear_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     spiralGear_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     spiralGear_SHININESS             =    80.0;                                                                                    
GLfloat     spiralGear_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      spiralGear_VBO;  
GLuint      spiralGear_INDEX_VBO;  
                                                                                                                                         
//-----------------------------------------------------------------                                                                       
GLuint      spiralGear_NORMALMAP;                                                                                                          
GLuint      spiralGear_TEXTUREMAP;                                                                                                         
