GLuint      diamond_SHADER_VERTEX;                                                                                                      
GLuint      diamond_SHADER_FRAGMENT;                                                                                                    
GLuint      diamond_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_diamond;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_diamond;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_diamond;                                                                                          
GLuint      UNIFORM_SHININESS_diamond;                                                                                                  
GLuint      UNIFORM_ATTENUATION_diamond;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_diamond;                                                                                               
GLuint      UNIFORM_TEXTURE_diamond;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     diamond_POSITION[]            =  {0.74, 1.07, 0, 1.0};                                                                  
GLfloat     diamond_ROTATE[]              =  {  1.0, 1.0,  1.0, 0.0};                                                                   
GLfloat     diamond_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     diamond_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     diamond_SHININESS             =    80.0;                                                                                    
GLfloat     diamond_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      diamond_VBO;
GLuint      diamond_INDEX_VBO;  
//-----------------------------------------------------------------                                                                       
GLuint      diamond_NORMALMAP;                                                                                                          
GLuint      diamond_TEXTUREMAP;                                                                                                         
