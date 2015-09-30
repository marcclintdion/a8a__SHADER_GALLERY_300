var         refraction_LIGHT_POSITION_01[]    =  {0.0, 13.2, 83.5999, 1.0};

var         refraction_SHININESS                  =  1.00098;
var         refraction_ATTENUATION                =  0.78;
//-------------------------------------- 
GLuint      refraction_SHADER_VERTEX;                                                                                                      
GLuint      refraction_SHADER_FRAGMENT;                                                                                                    
GLuint      refraction_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_refraction; 
GLuint      UNIFORM_MODELVIEW_refraction;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_refraction;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_refraction;                                                                                          
GLuint      UNIFORM_SHININESS_refraction;                                                                                                  
GLuint      UNIFORM_ATTENUATION_refraction;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_refraction;                                                                                               
GLuint      UNIFORM_TEXTURE_refraction;        
