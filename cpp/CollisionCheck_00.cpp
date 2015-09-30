



void CollisionCheck_LEFT(float X1, float Y1, float X2, float Y2)           //////*****************************************
{

    
    LEFT = TRUE;
    
    
  
for( int i = 0; i < numberOfCollisionObjects; i++)
{
       /*    X3[i] = left_edge[i];     
           Y3[i] = lower_edge[i];      
           X4[i] = right_edge[i];    
           Y4[i] = upper_edge[i];  */
           
           //out << 'left_edge'+'i' << endl;  

 planeX3_inner[i] = X3[i] + 0.1f;   ////left edge
 planeX3_outer[i] = X3[i] - 0.1f;   ////left edge
 planeX4_inner[i] = X4[i] - 0.1f;   ////right edge
 planeX4_outer[i] = X4[i] + 0.1f;   ////right edge
 planeY3_inner[i] = Y3[i] + 0.1f;   ////bottom edge
 planeY3_outer[i] = Y3[i] - 0.1f;   ////bottom edge
 planeY4_inner[i] = Y4[i] - 0.1f;   ////top edge
 planeY4_outer[i] = Y4[i] + 0.1f;   ////top edge


     
   if((X2 >= X3[i]) && (X4[i] >= X1) && (Y2 >= Y3[i]) && (Y4[i] >= Y1))   
   {
                       LEFT = FALSE;
                       RIGHT = TRUE;
    }



    
    
    if((Y2 >= planeY3_outer[i]) && (Y2 <= planeY3_inner[i]) && (X2 >= planeX3_outer[i]) && (X1 <= planeX4_outer[i]) && (LEFT == FALSE))  /////tests for bottom edge on secondary object
        LEFT = TRUE;                                                       /////top edge of moving primary object
    if((Y1 <= planeY4_outer[i]) && (Y1 >= planeY4_inner[i]) && (X2 >= planeX3_outer[i]) && (X1 <= planeX4_outer[i]) && (LEFT == FALSE))  /////tests for top edge on secondary object
        LEFT = TRUE;                                                       /////bottom edge of moving primary object
        
    
    

 
    if((X2 >= planeX3_outer[i]) && (X1 <= planeX3_outer[i]) && (Y2 >= planeY3_outer[i]) && (Y1 <= planeY4_outer[i]) && (LEFT == FALSE))
        LEFT = TRUE;
        
    if(LEFT == FALSE)
         break;
              
}        


      

}

void CollisionCheck_RIGHT(float X1, float Y1, float X2, float Y2)          //////*****************************************
{
    RIGHT = TRUE;
  
    
for( int i = 0; i < numberOfCollisionObjects; i++)
{
    
    /* X3[i] = left_edge[i];     
     Y3[i] = lower_edge[i];      
     X4[i] = right_edge[i];    
     Y4[i] = upper_edge[i];   */
     
 planeX3_inner[i] = X3[i] + .1f;   ////left edge
 planeX3_outer[i] = X3[i] - .1f;   ////left edge
 planeX4_inner[i] = X4[i] - .1f;   ////right edge
 planeX4_outer[i] = X4[i] + .1f;   ////right edge
 planeY3_inner[i] = Y3[i] + .1f;   ////bottom edge
 planeY3_outer[i] = Y3[i] - .1f;   ////bottom edge
 planeY4_inner[i] = Y4[i] - .1f;   ////top edge
 planeY4_outer[i] = Y4[i] + .1f;   ////top edge
     
       
     
    if((X2 >= X3[i]) && (X4[i] >= X1) && (Y2 >= Y3[i]) && (Y4[i] >= Y1))
    {
               RIGHT = FALSE;
               LEFT = TRUE;
    }
    


   
   
    if((Y2 >= planeY3_outer[i]) && (Y2 <= planeY3_inner[i]) && (X2 >= planeX3_outer[i]) && (X1 <= planeX4_outer[i]) && (RIGHT == FALSE))  /////tests for bottom edge on secondary object
        RIGHT = TRUE;                                                       /////top edge of moving primary object
    if((Y1 >= planeY4_inner[i]) && (Y1 <= planeY4_outer[i]) && (X2 >= planeX3_outer[i]) && (X1 <= planeX4_outer[i]) && (RIGHT == FALSE))  /////tests for top edge on secondary object
        RIGHT = TRUE;                                                       /////bottom edge of moving primary object
        
     

    if((X1 >= planeX4_inner[i]) && (X1 <= planeX4_outer[i]) && (Y1 <= planeY4_outer[i]) && (Y2 >= planeY3_outer[i]) && (RIGHT == FALSE))
        RIGHT = TRUE;
        
    if(RIGHT == FALSE)
        break; 
}  
                                    ////****____end of for loop ____****        

          
}
void CollisionCheck_UP(float X1, float Y1, float X2, float Y2)             //////*****************************************
{
    UP = TRUE;
    
    
for( int i = 0; i < numberOfCollisionObjects; i++)
{
    
   /*  X3[i] = left_edge[i];     
     Y3[i] = lower_edge[i];      
     X4[i] = right_edge[i];    
     Y4[i] = upper_edge[i];  
   */  
     
 planeX3_inner[i] = X3[i] + .1f;   ////left edge
 planeX3_outer[i] = X3[i] - .1f;   ////left edge
 planeX4_inner[i] = X4[i] - .1f;   ////right edge
 planeX4_outer[i] = X4[i] + .1f;   ////right edge
 planeY3_inner[i] = Y3[i] + .1f;   ////bottom edge
 planeY3_outer[i] = Y3[i] - .1f;   ////bottom edge
 planeY4_inner[i] = Y4[i] - .1f;   ////top edge
 planeY4_outer[i] = Y4[i] + .1f;   ////top edge
     
        
     
    if((X2 >= X3[i]) && (X4[i] >= X1) && (Y2 >= Y3[i]) && (Y4[i] >= Y1))        
    {
               UP = FALSE;
               DOWN = TRUE;
    }
        
      
    
    
    if((X2 >= planeX3_outer[i]) && (X2 <= planeX3_inner[i]) && (Y1 <= planeY4_outer[i]) && (Y2 >= planeY3_outer[i]) && (UP == FALSE))
        UP = TRUE;
   
    if((X1 >= planeX4_inner[i]) && (X1 <= planeX4_outer[i]) && (Y1 <= planeY4_outer[i]) && (Y2 >= planeY3_outer[i]) && (UP == FALSE))
        UP = TRUE;

 
   
  
        
    if((Y1 >= planeY4_inner[i]) && (Y1 <= planeY4_outer[i]) && (X1 <= planeX4_outer[i]) && (X2 >= planeX3_outer[i]) && (UP == FALSE))
        UP = TRUE;
        
    if(UP == FALSE)
         break;
   
}   
    
                                            
}

void CollisionCheck_DOWN(float X1, float Y1, float X2, float Y2)           //////*****************************************
{   
    DOWN = TRUE;
    
    
for( int i = 0; i < numberOfCollisionObjects; i++)
{
    
    /* X3[i] = left_edge[i];     
     Y3[i] = lower_edge[i];      
     X4[i] = right_edge[i];    
     Y4[i] = upper_edge[i];   */
     
 planeX3_inner[i] = X3[i] + .1f;   ////left edge
 planeX3_outer[i] = X3[i] - .1f;   ////left edge
 planeX4_inner[i] = X4[i] - .1f;   ////right edge
 planeX4_outer[i] = X4[i] + .1f;   ////right edge
 planeY3_inner[i] = Y3[i] + .1f;   ////bottom edge
 planeY3_outer[i] = Y3[i] - .1f;   ////bottom edge
 planeY4_inner[i] = Y4[i] - .1f;   ////top edge
 planeY4_outer[i] = Y4[i] + .1f;   ////top edge
       
     
    if((X2 >= X3[i]) && (X4[i] >= X1) && (Y2 >= Y3[i]) && (Y4[i] >= Y1))
    {
                DOWN = FALSE;
                UP = TRUE;
    }
         
        
         
         
    if((X2 >= planeX3_outer[i]) && (X2 <= planeX3_inner[i]) && (Y1 <= planeY4_outer[i]) && (Y2 >= planeY3_outer[i]) && (DOWN == FALSE))
        DOWN = TRUE;
    if((X1 >= planeX4_inner[i]) && (X1 <= planeX4_outer[i]) && (Y1 <= planeY4_outer[i]) && (Y2 >= planeY3_outer[i]) && (DOWN == FALSE))
        DOWN = TRUE;

  
  if((Y2 >= planeY3_outer[i]) && (Y2 <= planeY3_inner[i]) && (X2 >= planeX3_outer[i]) && (X1 <= planeX4_outer[i]) && (DOWN == FALSE))  /////clears sticky edges
        DOWN = TRUE;
        
  if(DOWN == FALSE)
       break;      
        
}        
    
                                     ////****____end of for loop ____****          
}
