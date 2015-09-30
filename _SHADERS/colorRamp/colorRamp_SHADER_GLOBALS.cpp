var         colorRamp_LIGHT_POSITION_01[]    =  {0, 1.04, 30.6504, 1.0};
GLfloat     colorRamp_ATTENUATION         =    0.72;
GLfloat     colorRamp_SHININESS           =   14.86;


GLfloat     colorRamp_RAMP_VALUE_XY[]            = {0.0, -1.75203}; //_This value really doesn't have to make much sense.  It repeats.
GLuint      UNIFORM_RAMP_XY_COORDS_colorRamp; 
//--------------------------------------------------- 
GLuint      colorRamp_SHADER_VERTEX;                                                                                                      
GLuint      colorRamp_SHADER_FRAGMENT;                                                                                                    
GLuint      colorRamp_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_colorRamp;  
GLuint      UNIFORM_MODELVIEW_colorRamp;                                                                                             
GLuint      UNIFORM_MODELROTATION_colorRamp; 
//----  
GLuint      UNIFORM_SHADOW_PROJ_colorRamp;   
GLuint      UNIFORM_modelViewShadow_colorRamp; 
//----
GLuint      UNIFORM_viewMatrix_colorRamp; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_colorRamp;  
GLuint      UNIFORM_textureMatrix_colorRamp;
GLuint      UNIFORM_INVERSEMATRIX_colorRamp;
//---------------------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_colorRamp;                                                                                          
//---------------------------------------------------  
GLuint      UNIFORM_TEXTURE_COORDINATES_ADJUST_colorRamp;
//---------------------------------------------------  
 
GLuint      UNIFORM_SHININESS_colorRamp; 
GLuint      UNIFORM_GENERIC_colorRamp; 


GLuint      UNIFORM_TEXTURE_SHADOW_colorRamp;                                                                                              
GLuint      UNIFORM_TEXTURE_RAMP_colorRamp;
GLuint      UNIFORM_TEXTURE_DOT3_colorRamp;
GLuint      UNIFORM_TEXTURE_colorRamp; 

GLuint      RampTexture;
                                                                                                   
//--------------------------------------                                                                                                  
GLfloat     colorRamp_POSITION[]            =  {  0.0, 0.0,  0.0, 1.0};                                                                    
GLfloat     colorRamp_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     colorRamp_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
