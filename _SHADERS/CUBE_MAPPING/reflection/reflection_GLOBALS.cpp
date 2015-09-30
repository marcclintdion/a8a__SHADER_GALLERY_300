var         reflection_LIGHT_POSITION_01[]    =  {9.89999, 10.0, 83.5999, 1.0};

var         reflection_ATTENUATION    =  0.718998;
var         reflection_SHININESS    =  1.00098;
//-------------------------------------- 
GLuint      reflection_SHADER_VERTEX;                                                                                                      
GLuint      reflection_SHADER_FRAGMENT;                                                                                                    
GLuint      reflection_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_reflection;  
GLuint      UNIFORM_MODELVIEW_reflection;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_reflection;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_reflection;                                                                                          
GLuint      UNIFORM_SHININESS_reflection;                                                                                                  
GLuint      UNIFORM_ATTENUATION_reflection;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_reflection;                                                                                               
GLuint      UNIFORM_TEXTURE_reflection;        
