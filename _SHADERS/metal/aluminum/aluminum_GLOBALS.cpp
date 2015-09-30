var         aluminum_LIGHT_POSITION_01[]    =  {9.7, 3.5, 30, 1.0};

var         aluminum_ATTENUATION            =  0.3;
var         aluminum_SHININESS              =  0.18;
var         adjustLightProjectionMatrix   =  10;


//-------------------------------------- 
GLuint      aluminum_SHADER_VERTEX;                                                                                                      
GLuint      aluminum_SHADER_FRAGMENT;                                                                                                    
GLuint      aluminum_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_aluminum; 
GLuint      UNIFORM_MODELVIEW_aluminum;                                                                                             
GLuint      UNIFORM_LIGHT_MATRIX_1_aluminum;
GLuint      UNIFORM_LIGHT_MATRIX_2_aluminum;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_aluminum;                                                                                          
GLuint      UNIFORM_SHININESS_aluminum;                                                                                                  
GLuint      UNIFORM_ATTENUATION_aluminum;                                                                                                  
//-------------------------------------- 
GLuint      UNIFORM_TEXTURE_aluminum_FRESNEL;  
GLuint      UNIFORM_TEXTURE_DOT3_aluminum;                                                                                               
GLuint      UNIFORM_TEXTURE_aluminum;        
//--------------------------------------
GLuint      aluminum_FRESNELMAP; 
