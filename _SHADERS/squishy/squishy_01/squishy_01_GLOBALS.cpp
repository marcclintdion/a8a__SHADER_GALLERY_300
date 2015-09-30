var     squishy_LIGHT_POSITION_01[] = {-4, 8, 27.9, 1};
var     squishy_ATTENUATION_01         =  -0.601998;
var     squishy_SHININESS_01           =  0.210099;
//------
var     squishy_LIGHT_POSITION_02[]      =  {    0.0, 0.0, 15.0,  1};   
var     squishy_ATTENUATION_02           =       7.48008;                                  
var     squishy_SHININESS_02             =     340.0;
//------
GLuint      squishy_SHADER_VERTEX;                                                                                                      
GLuint      squishy_SHADER_FRAGMENT;                                                                                                    
GLuint      squishy_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_squishy;                                                                                              
GLuint      UNIFORM_MODELVIEW_squishy;
GLuint      UNIFORM_LIGHT_MATRIX_squishy;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_squishy;     
GLuint      UNIFORM_LIGHT_POSITION_02_squishy;                                                                                          
GLuint      UNIFORM_SHININESS_01_squishy;                                                                                                  
GLuint      UNIFORM_SHININESS_02_squishy; 
GLuint      UNIFORM_ATTENUATION_01_squishy;   
GLuint      UNIFORM_ATTENUATION_02_squishy;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_squishy;                                                                                               
GLuint      UNIFORM_TEXTURE_squishy;                                                                                                    
GLuint      UNIFORM_CUBEMAP_squishy;                                                                       
GLuint      UNIFORM_FRESNELMAP_squishy;    
