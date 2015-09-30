GLfloat     shinyMoss_LIGHT_POSITION_01[] = {  0, 0.3, 1, 1.0};
GLfloat     shinyMoss_ATTENUATION         =    0.72;
GLfloat     shinyMoss_SHININESS           =   14.86;

GLuint      shinyMoss_SHADER_VERTEX;                                                                                                      
GLuint      shinyMoss_SHADER_FRAGMENT;                                                                                                    
GLuint      shinyMoss_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_shinyMoss;  
GLuint      UNIFORM_MODELVIEW_shinyMoss;                                                                                             
GLuint      UNIFORM_MODELROTATION_shinyMoss; 
//----  
GLuint      UNIFORM_SHADOW_PROJ_shinyMoss;   
GLuint      UNIFORM_modelViewShadow_shinyMoss; 
//----
GLuint      UNIFORM_viewMatrix_shinyMoss; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_shinyMoss;  
GLuint      UNIFORM_textureMatrix_shinyMoss;
GLuint      UNIFORM_INVERSEMATRIX_shinyMoss;
GLuint      UNIFORM_reverseModelView_shinyMoss;
//---------------------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_shinyMoss;                                                                                          
//----------------------------------------------------------  
GLuint      UNIFORM_TEXTURE_COORDINATES_ADJUST_shinyMoss;

GLuint      UNIFORM_SHININESS_shinyMoss; 
GLuint      UNIFORM_GENERIC_shinyMoss; 

GLuint      UNIFORM_zDirBias_shinyMoss;  
GLuint      UNIFORM_TEXTURE_LightMap_shinyMoss;
GLuint      UNIFORM_TEXTURE_SHADOW_shinyMoss;                                                                                              
GLuint      UNIFORM_TEXTURE_FRESNEL_shinyMoss;
GLuint      UNIFORM_TEXTURE_DOT3_shinyMoss;
GLuint      UNIFORM_TEXTURE_shinyMoss;     
//----------------------------------
GLuint      shinyMoss_FRESNELMAP;                                                                                                    
//----------------------------------                                                                                                  
GLfloat     shinyMoss_POSITION[]            =  {  0.0, 0.0,  0.0, 1.0};                                                                    
GLfloat     shinyMoss_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     shinyMoss_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
