    //=======================================================================================                                           
    /*if (keys['J'])                                                                                                                      
    {                                                                                                                                   
             flowerShield_POSITION[0]         -=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_POSITION[0]         +=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_POSITION[1]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_POSITION[1]         -=  .01;                                                                                  
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_POSITION[2]         +=  .01;                                                                                  
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_POSITION[2]         -=  .01;                                                                                  
    }*/                                                                                                                                   
    //=======================================================================================                                           
    //=======================================================================================                                           
     if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             flowerShield_LIGHT_POSITION_02[0]         -=  .11;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_LIGHT_POSITION_02[0]         +=  .11;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_LIGHT_POSITION_02[1]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_LIGHT_POSITION_02[1]         -=  .11;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_LIGHT_POSITION_02[2]         +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_LIGHT_POSITION_02[2]         -=  .11;                                                                            
    }                                                                                                                                 
    //=======================================================================================                                           
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_ATTENUATION_01                  +=  .001;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_ATTENUATION_01                  -=  .001;                                                                            
    }                                                                                                                                   
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_SHININESS_02                  +=  1.01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             flowerShield_SHININESS_02                  -=  1.01;                                                                                       
    }                                                                                                                                            
    
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
        ofstream outKeys("_MODEL_FOLDERS_/flowerShield/flowerShield_SHADER_SETTINGS.cpp");                                                                                     
       
        outKeys << "  GLfloat     flowerShield_LIGHT_POSITION_02[] = {" << flowerShield_LIGHT_POSITION_02[0] << ", "                               
                                                                       << flowerShield_LIGHT_POSITION_02[1] << ", "                               
                                                                       << flowerShield_LIGHT_POSITION_02 [2] << ", " << 1.0 << "};\n";          
        outKeys << "  GLfloat     flowerShield_ATTENUATION_01         =  " << flowerShield_ATTENUATION_01   << ";\n";                                    
        outKeys << "  GLfloat     flowerShield_SHININESS_02           =  " << flowerShield_SHININESS_02  << ";\n";                                       
    }                                                                                                                                            
