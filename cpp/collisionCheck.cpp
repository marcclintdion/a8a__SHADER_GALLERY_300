
//###########################################################################################################################################################################################################################################################################
//--------------------------------------------------------------#############################################################################################################################################################################################################

void CollisionCheck_LEFT(float X1, float X2, float Y1, float Y2, float Z1, float Z2)        
{
     LEFT = true;

     for( int i = 1; i < numberOfCollisionObjects; i++)
     {
         if((X2-moveSet[0] >= left_edge_SecondaryObjects[i]) && (right_edge_SecondaryObjects[i] >= X1-moveSet[0]) && (Y2 >= lower_edge_SecondaryObjects[i]) && (upper_edge_SecondaryObjects[i] >= Y1)&& (Z1-moveSet[2] >= far_edge_SecondaryObjects[i]) && (Z2-moveSet[2] <= near_edge_SecondaryObjects[i]))//--------->>THE BASIC COLISION FORMULA.  THIS TEST CHECKS FOR TWO SQUARES OVERLAPPING 
         {       
                LEFT = FALSE;//--------------------------------------------------------->>THIS TEST WILL LOCK ALL DIRECTIONS FOR EACH AXIS OF MOTION, SINCE (RIGHT, UP, DOWN) ALSO START WITH THIS SAME CONDITIONAL STATEMENT, THE FOLLOWING TESTS CAN VERIFY OR RELEASE THIS DECISION
         
         }
         //----------------------------------------------------------------------------------------------------------          
         
         if((X2 - 0.1-moveSet[0]) <= left_edge_SecondaryObjects[i])
         {
               LEFT = true;  
         }
         
         if((Z2 + 0.1-moveSet[2]) >= near_edge_SecondaryObjects[i])
         {
               LEFT = true;  
         }         
         
         if((Z1 - 0.1-moveSet[2]) <= far_edge_SecondaryObjects[i])
         {
               LEFT = true;  
         }         
         
         //----------------------------------------------------------------------------------------------------------         
         if(LEFT == FALSE)//------------------------------------------------------------>>THIS TEST BREAKS THE LOOP WHEN A COLLISION OCCURS, IT IS ASSUMED THAT TWO LEFTWARD COLLISIONS CANNOT TAKE PLACE AT THE SAME TIME, HOWEVER
         {       
                 objectNumber = i;
                 break;//---------------------------------------------------------------->>USING COLLISION BLOCKS WITHIN COLLISION BLOCKS CAN GIVE US A VALUE FOR HOW DEEP A FAST MOVING OBJECT PENETRATES BY REGISTERING ONE OR MORE HITS IN THE SAME DIRECTION
         }
      }        
}
//--------------------------------------------------------------#############################################################################################################################################################################################################
void CollisionCheck_RIGHT(float X1, float X2, float Y1, float Y2, float Z1, float Z2) //--------------------->>THESE FUNCTIONS ARE BEING ACTIVATED AND FED THE BOUNDARIES OF THE MAIN OBJECT.(see bottom of page)       
{
     RIGHT = true;////////////////////////////////////////////////---------------------->>IF THE FINAL RESULT IS FALSE THEN THE KEYBOARD FUNCTION WILL INCREMENT THE MAIN OBJECT POSITION(see bottom of page)
  
     for( int i = 1; i < numberOfCollisionObjects; i++)
     {
          if((X2-moveSet[0] >= left_edge_SecondaryObjects[i]) && (right_edge_SecondaryObjects[i] >= X1-moveSet[0]) && (Y2 >= lower_edge_SecondaryObjects[i]) && (upper_edge_SecondaryObjects[i] >= Y1)&& (Z1-moveSet[2] >= far_edge_SecondaryObjects[i]) && (Z2-moveSet[2] <= near_edge_SecondaryObjects[i]))//-->> 
          {       
                  RIGHT = FALSE;
          }
          //----------------------------------------------------------------------------------------------------------          
          
          if((X1 + 0.1-moveSet[0]) >= right_edge_SecondaryObjects[i])
          {
               RIGHT = true;  
          }
          if((Z2 + 0.1-moveSet[2]) >= near_edge_SecondaryObjects[i])
          {
               RIGHT = true;  
          }  
          if((Z1 - 0.1-moveSet[2]) <= far_edge_SecondaryObjects[i])
          {
               RIGHT = true;  
          }           
          
          //----------------------------------------------------------------------------------------------------------        
          
          if(RIGHT == FALSE)
          {       
                 objectNumber = i;
                 break; 
          }       
      }  
}
//--------------------------------------------------------------#############################################################################################################################################################################################################
void CollisionCheck_UP(float X1, float X2, float Y1, float Y2, float Z1, float Z2)              
{
     UP = true;
    
     for( int i = 1; i < numberOfCollisionObjects; i++)
     {
         if((X2-moveSet[0] >= left_edge_SecondaryObjects[i]) && (right_edge_SecondaryObjects[i] >= X1-moveSet[0]) && (Y2 >= lower_edge_SecondaryObjects[i]) && (upper_edge_SecondaryObjects[i] >= Y1)&& (Z1-moveSet[2] >= far_edge_SecondaryObjects[i]) && (Z2-moveSet[2] <= near_edge_SecondaryObjects[i]))        
         {
               UP = FALSE;
         }
         //----------------------------------------------------------------------------------------------------------         
         
         if((Z1 - 0.1-moveSet[2]) <= far_edge_SecondaryObjects[i])
         {
               UP = true;  
         }
         if((X1 + 0.1-moveSet[0]) >= right_edge_SecondaryObjects[i])
         {
               UP = true;  
         }       
         if((X2 - 0.1-moveSet[0]) <= left_edge_SecondaryObjects[i])
         {
               UP = true;  
         }        
        
         //----------------------------------------------------------------------------------------------------------        
         if(UP == FALSE)
         {      
                objectNumber = i;
                break;
         }
     }   
}
//--------------------------------------------------------------#############################################################################################################################################################################################################
void CollisionCheck_DOWN(float X1, float X2, float Y1, float Y2, float Z1, float Z2)          
{    
     DOWN = true;
    
     for( int i = 1; i < numberOfCollisionObjects; i++)
     {
          
         if((X2-moveSet[0] >= left_edge_SecondaryObjects[i]) && (right_edge_SecondaryObjects[i] >= X1-moveSet[0]) && (Y2 >= lower_edge_SecondaryObjects[i]) && (upper_edge_SecondaryObjects[i] >= Y1)&& (Z1-moveSet[2] >= far_edge_SecondaryObjects[i]) && (Z2-moveSet[2] <= near_edge_SecondaryObjects[i]))
         {        
                  DOWN = FALSE;
         } 
         //----------------------------------------------------------------------------------------------------------
         
         if((Z2 + 0.1-moveSet[2]) >= near_edge_SecondaryObjects[i])
         {
               DOWN = true;  
         }
         if((X1 + 0.1-moveSet[0]) >= right_edge_SecondaryObjects[i])
         {
               DOWN = true;  
         }         
         if((X2 - 0.1-moveSet[0]) <= left_edge_SecondaryObjects[i])
         {
               DOWN = true;  
         }        
         
         //----------------------------------------------------------------------------------------------------------         
         if(DOWN == FALSE)
         {
                objectNumber = i;
                break;
         }       
      }        
}
//--------------------------------------------------------------#############################################################################################################################################################################################################
//###########################################################################################################################################################################################################################################################################
