  
    if (keys[VK_F8]) 			                                                                                                                   
	{                                                                                                                                              
         ofstream outKeys("lightPosition.cpp");                                                                                     
        
         outKeys << "  var     eyePosition[] = {" << eyePosition[0] << ", "  << eyePosition[1] << ", " << eyePosition[2] << ", " << 1.0 << "};\n";          
         outKeys << "  var     look_LEFT_RIGHT           =  " << look_LEFT_RIGHT  << ";\n";  
         outKeys << "  var     look_UP_DOWN         =  " << look_UP_DOWN   << ";\n";                                    
    }             
       
//--------------------------------------------------------------------    
    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }
//-----------------------------------
    if (keys['S'])
	{
          eyePosition[2] += .05;
    }
          if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += 0.5;
          
          }    
//-----------------------------------	
    if (keys['W'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= 0.5;      
          }	
//-----------------------------------    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	      if (keys['E'] && keys[VK_SHIFT])
	      {
                eyePosition[1] -= 0.5;      
          }		
    
    if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }
	      if (keys['Q'] && keys[VK_SHIFT])
	      {
                eyePosition[1] += 0.5;      
          }    
        
//--------------------------------------------------------------------
