var         wood_A_LIGHT_POSITION_01[]    =  {9.7, 3.5, -30, 1.0};

var         wood_A_ATTENUATION            =  0.3;
var         wood_A_SHININESS              =  0.18;
var         adjustLightProjectionMatrix   =  10;

//var         wood_A_ATTENUATION            =  0.396998; //-> secondPattern underlayed
//var         wood_A_SHININESS              =  1.74603;  //-> secondPattern underlayed


GLuint      rainbow_FRESNELMAP;
//-------------------------------------- 
GLuint      wood_A_SHADER_VERTEX;                                                                                                      
GLuint      wood_A_SHADER_FRAGMENT;                                                                                                    
GLuint      wood_A_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_wood_A; 
GLuint      UNIFORM_MODELVIEW_wood_A;                                                                                             
GLuint      UNIFORM_LIGHT_MATRIX_1_wood_A;
GLuint      UNIFORM_LIGHT_MATRIX_2_wood_A;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_wood_A;                                                                                          
GLuint      UNIFORM_SHININESS_wood_A;                                                                                                  
GLuint      UNIFORM_ATTENUATION_wood_A;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_wood_A;                                                                                               
GLuint      UNIFORM_TEXTURE_wood_A;        
GLuint      UNIFORM_rainbow_FRESNELMAP;
