#include "../_MODEL_FOLDERS_/marcParts/marcAnimations/animationFiles/ME_AnimationSet.cpp"





if(moveSet_AnimationSequence)
{
    if(moveSet_animationBlendFactor >= 0.0f && moveSet_animationBlendFactor <= 1.0f)
    {
        moveSet[0]           =      moveSet_MOVE_FRAMEA[0] * (1 - moveSet_animationBlendFactor) 
        +      moveSet_MOVE_FRAMEB[0] *      moveSet_animationBlendFactor;        
        
        moveSet[1]           =      moveSet_MOVE_FRAMEA[1] * (1 - moveSet_animationBlendFactor) 
        +      moveSet_MOVE_FRAMEB[1] *      moveSet_animationBlendFactor; 
        
        moveSet[2]           =      moveSet_MOVE_FRAMEA[2] * (1 - moveSet_animationBlendFactor) 
        +      moveSet_MOVE_FRAMEB[2] *      moveSet_animationBlendFactor;
    }
    if(moveSet_animationBlendFactor >= 1.0f)
    {
        moveSet_setSelection ++;
        moveSet_animationBlendFactor = 0.0f;
        //reset_LoadSet        = true;
    }
    if(moveSet_setSelection == moveSet_setSelectionLimit + 1)
    {
        moveSet_setSelection      = 1;
    }   
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        moveSet_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------
    
    moveSet_animationBlendFactor += moveSet_ROTATION_FRAME_TIME[moveSet_setSelection-1]; 
    
    //moveSet_animationBlendFactor += moveSet_FRAME_TIME_01 * runSlowMotion;
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    if(moveSet_setSelection == 1 )
    {
        moveSet_SET_01[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_01[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_01[2] = moveSet_MOVE_FRAMEA[2];
    }
    if(moveSet_setSelection == 2)
    {
        moveSet_SET_02[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_02[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_02[2] = moveSet_MOVE_FRAMEA[2];
    }     
    if(moveSet_setSelection == 3)
    {
        moveSet_SET_03[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_03[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_03[2] = moveSet_MOVE_FRAMEA[2];
    }     
    if(moveSet_setSelection == 4)
    {
        moveSet_SET_04[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_04[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_04[2] = moveSet_MOVE_FRAMEA[2];
    }     
    if(moveSet_setSelection == 5)
    {
        moveSet_SET_05[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_05[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_05[2] = moveSet_MOVE_FRAMEA[2];
    }      
    if(moveSet_setSelection == 6)
    {
        moveSet_SET_06[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_06[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_06[2] = moveSet_MOVE_FRAMEA[2];
    }         
    if(moveSet_setSelection == 7)
    {
        moveSet_SET_07[0] = moveSet_MOVE_FRAMEA[0];
        moveSet_SET_07[1] = moveSet_MOVE_FRAMEA[1];                   
        moveSet_SET_07[2] = moveSet_MOVE_FRAMEA[2];
    }           
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo     
}        
//----------------------------------------------------------------------------------------------------------------------------------    
if(hips_AnimationSequence)         
{   
    if(animationBlendFactor_HIPS >= 0.0f && animationBlendFactor_HIPS <= 1.0f)
    {     
        hips_ROTATE[3]      =      hips_ROTATE_FRAMEA[3] 
        * (1 - animationBlendFactor_HIPS) 
        +      hips_ROTATE_FRAMEB[3] 
        *      animationBlendFactor_HIPS;        
        
        hips_ROTATE[0]      =      hips_ROTATE_FRAMEA[0] 
        * (1 - animationBlendFactor_HIPS) 
        +      hips_ROTATE_FRAMEB[0] 
        *      animationBlendFactor_HIPS; 
        
        hips_ROTATE[1]      =      hips_ROTATE_FRAMEA[1] 
        * (1 - animationBlendFactor_HIPS) 
        +      hips_ROTATE_FRAMEB[1] 
        *      animationBlendFactor_HIPS;
        
        hips_ROTATE[2]      =      hips_ROTATE_FRAMEA[2] 
        * (1 - animationBlendFactor_HIPS) 
        +      hips_ROTATE_FRAMEB[2] 
        *      animationBlendFactor_HIPS;    
    }
    if(animationBlendFactor_HIPS >= 1.0f)
    {
        setSelection_HIPS ++;
        animationBlendFactor_HIPS = 0.0f;
    }
    if(setSelection_HIPS == setSelectionLimit_HIPS+1)
    {
        setSelection_HIPS = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        hips_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------    
    animationBlendFactor_HIPS += hips_ROTATION_FRAME_TIME[setSelection_HIPS - 1];
    
    // animationBlendFactor_HIPS       += HIPS_FRAME_TIME_01 * runSlowMotion;       
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    
    if(setSelection_HIPS == 1)
    {
        hips_SET_01[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_01[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_01[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_01[3] = hips_ROTATE_FRAMEA[3];          
    }
    if(setSelection_HIPS == 2)
    {
        hips_SET_02[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_02[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_02[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_02[3] = hips_ROTATE_FRAMEA[3];         
    }     
    if(setSelection_HIPS == 3)
    {
        hips_SET_03[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_03[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_03[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_03[3] = hips_ROTATE_FRAMEA[3];             
    }     
    if(setSelection_HIPS == 4)
    {
        hips_SET_04[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_04[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_04[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_04[3] = hips_ROTATE_FRAMEA[3];             
    }     
    if(setSelection_HIPS == 5)
    {
        hips_SET_05[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_05[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_05[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_05[3] = hips_ROTATE_FRAMEA[3];             
    }      
    if(setSelection_HIPS == 6)
    {
        hips_SET_06[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_06[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_06[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_06[3] = hips_ROTATE_FRAMEA[3];             
    }         
    if(setSelection_HIPS == 7)
    {
        hips_SET_07[0] = hips_ROTATE_FRAMEA[0];
        hips_SET_07[1] = hips_ROTATE_FRAMEA[1];                   
        hips_SET_07[2] = hips_ROTATE_FRAMEA[2];
        hips_SET_07[3] = hips_ROTATE_FRAMEA[3];             
    }           
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    
}
//----------------------------------------------------------------------------------------------------------------------------------      
if(torso_AnimationSequence)
{        
    if(animationBlendFactor_TORSO >= 0.0f && animationBlendFactor_TORSO <= 1.0f)
    {    
        torso_ROTATE[3]           =      torso_ROTATE_FRAMEA[3]           
        * (1 - animationBlendFactor_TORSO) 
        +      torso_ROTATE_FRAMEB[3]           
        *      animationBlendFactor_TORSO;        
        
        torso_ROTATE[0]           =      torso_ROTATE_FRAMEA[0]           
        * (1 - animationBlendFactor_TORSO) 
        +      torso_ROTATE_FRAMEB[0]           
        *      animationBlendFactor_TORSO; 
        
        torso_ROTATE[1]           =      torso_ROTATE_FRAMEA[1]           
        * (1 - animationBlendFactor_TORSO) 
        +      torso_ROTATE_FRAMEB[1]           
        *      animationBlendFactor_TORSO;
        
        torso_ROTATE[2]           =      torso_ROTATE_FRAMEA[2]           
        * (1 - animationBlendFactor_TORSO) 
        +      torso_ROTATE_FRAMEB[2]           
        *      animationBlendFactor_TORSO;     
    }    
    if(animationBlendFactor_TORSO >= 1.0f)
    {
        setSelection_TORSO ++;
        animationBlendFactor_TORSO = 0.0f;
    }
    if(setSelection_TORSO == setSelectionLimit_TORSO+1)
    {
        setSelection_TORSO = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        torso_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------      
    animationBlendFactor_TORSO      += torso_ROTATION_FRAME_TIME[setSelection_TORSO - 1];  
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    if(setSelection_TORSO == 1)
    {
        torso_SET_01[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_01[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_01[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_01[3] = torso_ROTATE_FRAMEA[3];          
    }
    if(setSelection_TORSO == 2)
    {
        torso_SET_02[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_02[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_02[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_02[3] = torso_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_TORSO == 3)
    {
        torso_SET_03[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_03[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_03[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_03[3] = torso_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_TORSO == 4)
    {
        torso_SET_04[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_04[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_04[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_04[3] = torso_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_TORSO == 5)
    {
        torso_SET_05[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_05[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_05[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_05[3] = torso_ROTATE_FRAMEA[3];          
    }      
    if(setSelection_TORSO == 6)
    {
        torso_SET_06[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_06[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_06[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_06[3] = torso_ROTATE_FRAMEA[3];          
    }         
    if(setSelection_TORSO == 7)
    {
        torso_SET_07[0] = torso_ROTATE_FRAMEA[0];
        torso_SET_07[1] = torso_ROTATE_FRAMEA[1];                   
        torso_SET_07[2] = torso_ROTATE_FRAMEA[2];
        torso_SET_07[3] = torso_ROTATE_FRAMEA[3];          
    }         
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
}    
//----------------------------------------------------------------------------------------------------------------------------------     
if(head_AnimationSequence)
{  
    if(animationBlendFactor_HEAD >= 0.0f && animationBlendFactor_HEAD <= 1.0f)
    {                          
        head_ROTATE[3]            = head_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_HEAD) 
        + head_ROTATE_FRAMEB[3] * animationBlendFactor_HEAD;        
        
        head_ROTATE[0]            = head_ROTATE_FRAMEA[0] * (1 - animationBlendFactor_HEAD) 
        + head_ROTATE_FRAMEB[0] * animationBlendFactor_HEAD; 
        
        head_ROTATE[1]            = head_ROTATE_FRAMEA[1] * (1 - animationBlendFactor_HEAD) 
        + head_ROTATE_FRAMEB[1] * animationBlendFactor_HEAD;
        
        head_ROTATE[2]            = head_ROTATE_FRAMEA[2] * (1 - animationBlendFactor_HEAD) 
        + head_ROTATE_FRAMEB[2] * animationBlendFactor_HEAD; 
    }
    if(animationBlendFactor_HEAD >= 1.0f)
    {
        setSelection_HEAD ++;
        animationBlendFactor_HEAD = 0.0f;
    }
    if(setSelection_HEAD == setSelectionLimit_HEAD+1)
    {
        setSelection_HEAD = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
          head_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------      
         
    animationBlendFactor_HEAD         += head_ROTATION_FRAME_TIME[setSelectionLimit_HEAD - 1];  
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    if(setSelection_HEAD == 1)
    {
        head_SET_01[0] = head_ROTATE_FRAMEA[0];
        head_SET_01[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_01[2] = head_ROTATE_FRAMEA[2];
        head_SET_01[3] = head_ROTATE_FRAMEA[3];          
    }
    if(setSelection_HEAD == 2)
    {
        head_SET_02[0] = head_ROTATE_FRAMEA[0];
        head_SET_02[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_02[2] = head_ROTATE_FRAMEA[2];
        head_SET_02[3] = head_ROTATE_FRAMEA[3];
    }     
    if(setSelection_HEAD == 3)
    {
        head_SET_03[0] = head_ROTATE_FRAMEA[0];
        head_SET_03[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_03[2] = head_ROTATE_FRAMEA[2];
        head_SET_03[3] = head_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_HEAD == 4)
    {
        head_SET_04[0] = head_ROTATE_FRAMEA[0];
        head_SET_04[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_04[2] = head_ROTATE_FRAMEA[2];
        head_SET_04[3] = head_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_HEAD == 5)
    {
        head_SET_05[0] = head_ROTATE_FRAMEA[0];
        head_SET_05[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_05[2] = head_ROTATE_FRAMEA[2];
        head_SET_05[3] = head_ROTATE_FRAMEA[3];          
    }      
    if(setSelection_HEAD == 6)
    {
        head_SET_06[0] = head_ROTATE_FRAMEA[0];
        head_SET_06[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_06[2] = head_ROTATE_FRAMEA[2];
        head_SET_06[3] = head_ROTATE_FRAMEA[3];          
    }         
    if(setSelection_HEAD == 7)
    {
        head_SET_07[0] = head_ROTATE_FRAMEA[0];
        head_SET_07[1] = head_ROTATE_FRAMEA[1];                   
        head_SET_07[2] = head_ROTATE_FRAMEA[2];
        head_SET_07[3] = head_ROTATE_FRAMEA[3];          
    }          
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
}
//----------------------------------------------------------------------------------------------------------------------------------
if(leftUpperArm_AnimationSequence)
{         
    if(animationBlendFactor_LEFT_ARM >= 0.0f && animationBlendFactor_LEFT_ARM <= 1.0f)
    {    
        leftUpperArm_ROTATE[3]    = leftUpperArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_ARM) 
        + leftUpperArm_ROTATE_FRAMEB[3]    *      animationBlendFactor_LEFT_ARM;        
        
        leftUpperArm_ROTATE[0]    = leftUpperArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_ARM) 
        + leftUpperArm_ROTATE_FRAMEB[0]    *      animationBlendFactor_LEFT_ARM; 
        
        leftUpperArm_ROTATE[1]    = leftUpperArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_ARM) 
        + leftUpperArm_ROTATE_FRAMEB[1]    *      animationBlendFactor_LEFT_ARM;
        
        leftUpperArm_ROTATE[2]    = leftUpperArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_ARM) 
        + leftUpperArm_ROTATE_FRAMEB[2]    *      animationBlendFactor_LEFT_ARM;
        
        leftLowerArm_ROTATE[3]     = leftLowerArm_ROTATE_FRAMEA[3]     * (1 - animationBlendFactor_LEFT_ARM) 
        + leftLowerArm_ROTATE_FRAMEB[3]     *      animationBlendFactor_LEFT_ARM;        
        
        leftLowerArm_ROTATE[0]     = leftLowerArm_ROTATE_FRAMEA[0]     * (1 - animationBlendFactor_LEFT_ARM) 
        + leftLowerArm_ROTATE_FRAMEB[0]     *      animationBlendFactor_LEFT_ARM; 
        
        leftLowerArm_ROTATE[1]     = leftLowerArm_ROTATE_FRAMEA[1]     * (1 - animationBlendFactor_LEFT_ARM) 
        + leftLowerArm_ROTATE_FRAMEB[1]     *      animationBlendFactor_LEFT_ARM;
        
        leftLowerArm_ROTATE[2]     = leftLowerArm_ROTATE_FRAMEA[2]     * (1 - animationBlendFactor_LEFT_ARM) 
        + leftLowerArm_ROTATE_FRAMEB[2]     *      animationBlendFactor_LEFT_ARM;                                          
        
        leftHand_ROTATE[3]  = leftHand_ROTATE_FRAMEA[3]  * (1 - animationBlendFactor_LEFT_ARM) 
        + leftHand_ROTATE_FRAMEB[3]  *      animationBlendFactor_LEFT_ARM;        
        
        leftHand_ROTATE[0]  = leftHand_ROTATE_FRAMEA[0]  * (1 - animationBlendFactor_LEFT_ARM) 
        + leftHand_ROTATE_FRAMEB[0]  *      animationBlendFactor_LEFT_ARM; 
        
        leftHand_ROTATE[1]  = leftHand_ROTATE_FRAMEA[1]  * (1 - animationBlendFactor_LEFT_ARM) 
        + leftHand_ROTATE_FRAMEB[1]  *      animationBlendFactor_LEFT_ARM;
        
        leftHand_ROTATE[2]  = leftHand_ROTATE_FRAMEA[2]  * (1 - animationBlendFactor_LEFT_ARM) 
        + leftHand_ROTATE_FRAMEB[2]  *      animationBlendFactor_LEFT_ARM;      
    }    
    
    if(animationBlendFactor_LEFT_ARM >= 1.0f)
    {
        setSelection_LEFT_ARM ++;
        animationBlendFactor_LEFT_ARM = 0.0f;
    }
    if(setSelection_LEFT_ARM == setSelectionLimit_LEFT_ARM + 1)
    {
        setSelection_LEFT_ARM = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        leftUpperArm_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------       
    animationBlendFactor_LEFT_ARM  += leftArm_ROTATION_FRAME_TIME[setSelectionLimit_LEFT_ARM - 1];
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    if(setSelection_LEFT_ARM == 1)
    {
        leftUpperArm_SET_01[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_01[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_01[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_01[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------
        leftLowerArm_SET_01[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_01[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_01[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_01[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------
        leftHand_SET_01[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_01[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_01[2] = leftHand_ROTATE_FRAMEA[2];            
        leftHand_SET_01[3] = leftHand_ROTATE_FRAMEA[3];    
    }
    if(setSelection_LEFT_ARM == 2)
    {
        leftUpperArm_SET_02[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_02[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_02[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_02[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftLowerArm_SET_02[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_02[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_02[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_02[3] = leftLowerArm_ROTATE_FRAMEA[3];              
        //----------------------------------------------------------------              
        leftHand_SET_02[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_02[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_02[2] = leftHand_ROTATE_FRAMEA[2];          
        leftHand_SET_02[3] = leftHand_ROTATE_FRAMEA[3];            
    }     
    if(setSelection_LEFT_ARM == 3)
    {
        leftUpperArm_SET_03[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_03[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_03[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_03[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftLowerArm_SET_03[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_03[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_03[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_03[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        leftHand_SET_03[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_03[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_03[2] = leftHand_ROTATE_FRAMEA[2];           
        leftHand_SET_03[3] = leftHand_ROTATE_FRAMEA[3];         
    }     
    if(setSelection_LEFT_ARM == 4)
    {
        leftUpperArm_SET_04[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_04[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_04[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_04[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftLowerArm_SET_04[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_04[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_04[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_04[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftHand_SET_04[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_04[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_04[2] = leftHand_ROTATE_FRAMEA[2];            
        leftHand_SET_04[3] = leftHand_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_LEFT_ARM == 5)
    {
        leftUpperArm_SET_05[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_05[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_05[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_05[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftLowerArm_SET_05[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_05[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_05[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_05[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------               
        leftHand_SET_05[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_05[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_05[2] = leftHand_ROTATE_FRAMEA[2];            
        leftHand_SET_05[3] = leftHand_ROTATE_FRAMEA[3];          
    }      
    if(setSelection_LEFT_ARM == 6)
    {
        leftUpperArm_SET_06[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_06[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_06[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_06[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        leftLowerArm_SET_06[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_06[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_06[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_06[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftHand_SET_06[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_06[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_06[2] = leftHand_ROTATE_FRAMEA[2];           
        leftHand_SET_06[3] = leftHand_ROTATE_FRAMEA[3];            
    }         
    if(setSelection_LEFT_ARM == 7)
    {
        leftUpperArm_SET_07[0] = leftUpperArm_ROTATE_FRAMEA[0];
        leftUpperArm_SET_07[1] = leftUpperArm_ROTATE_FRAMEA[1];                   
        leftUpperArm_SET_07[2] = leftUpperArm_ROTATE_FRAMEA[2];
        leftUpperArm_SET_07[3] = leftUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        leftLowerArm_SET_07[0] = leftLowerArm_ROTATE_FRAMEA[0];
        leftLowerArm_SET_07[1] = leftLowerArm_ROTATE_FRAMEA[1];                   
        leftLowerArm_SET_07[2] = leftLowerArm_ROTATE_FRAMEA[2];
        leftLowerArm_SET_07[3] = leftLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        leftHand_SET_07[0] = leftHand_ROTATE_FRAMEA[0];
        leftHand_SET_07[1] = leftHand_ROTATE_FRAMEA[1];                   
        leftHand_SET_07[2] = leftHand_ROTATE_FRAMEA[2];           
        leftHand_SET_07[3] = leftHand_ROTATE_FRAMEA[3];            
    }          
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    
}        
//----------------------------------------------------------------------------------------------------------------------------------      
if(rightUpperArm_AnimationSequence)
{     
    if(animationBlendFactor_RIGHT_ARM >= 0.0f && animationBlendFactor_RIGHT_ARM <= 1.0f)
    {     
        rightUpperArm_ROTATE[3]   = rightUpperArm_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightUpperArm_ROTATE_FRAMEB[3]   * animationBlendFactor_RIGHT_ARM;        
        
        rightUpperArm_ROTATE[0]   = rightUpperArm_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightUpperArm_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_ARM; 
        
        rightUpperArm_ROTATE[1]   = rightUpperArm_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightUpperArm_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_ARM;
        
        rightUpperArm_ROTATE[2]   = rightUpperArm_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightUpperArm_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_ARM;
        
        rightLowerArm_ROTATE[3]    = rightLowerArm_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightLowerArm_ROTATE_FRAMEB[3]    * animationBlendFactor_RIGHT_ARM;        
        
        rightLowerArm_ROTATE[0]    = rightLowerArm_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightLowerArm_ROTATE_FRAMEB[0]    * animationBlendFactor_RIGHT_ARM; 
        
        rightLowerArm_ROTATE[1]    = rightLowerArm_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightLowerArm_ROTATE_FRAMEB[1]    * animationBlendFactor_RIGHT_ARM;
        
        rightLowerArm_ROTATE[2]    = rightLowerArm_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightLowerArm_ROTATE_FRAMEB[2]    * animationBlendFactor_RIGHT_ARM;                                          
        
        rightHand_ROTATE[3] = rightHand_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightHand_ROTATE_FRAMEB[3] * animationBlendFactor_RIGHT_ARM;        
        
        rightHand_ROTATE[0] = rightHand_ROTATE_FRAMEA[0] * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightHand_ROTATE_FRAMEB[0] * animationBlendFactor_RIGHT_ARM; 
        
        rightHand_ROTATE[1] = rightHand_ROTATE_FRAMEA[1] * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightHand_ROTATE_FRAMEB[1] * animationBlendFactor_RIGHT_ARM;
        
        rightHand_ROTATE[2] = rightHand_ROTATE_FRAMEA[2] * (1 - animationBlendFactor_RIGHT_ARM) 
        + rightHand_ROTATE_FRAMEB[2] * animationBlendFactor_RIGHT_ARM;    
    }
    if(animationBlendFactor_RIGHT_ARM >= 1.0f)
    {
        setSelection_RIGHT_ARM ++;
        animationBlendFactor_RIGHT_ARM = 0.0f;
    }
    
    if(setSelection_RIGHT_ARM == setSelectionLimit_RIGHT_ARM + 1)
    {
        setSelection_RIGHT_ARM = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        rightUpperArm_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------     
    animationBlendFactor_RIGHT_ARM += rightArm_ROTATION_FRAME_TIME[setSelectionLimit_RIGHT_ARM - 1];
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    
    if(setSelection_RIGHT_ARM == 1)
    {
        rightUpperArm_SET_01[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_01[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_01[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_01[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------
        rightLowerArm_SET_01[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_01[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_01[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_01[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------
        rightHand_SET_01[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_01[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_01[2] = rightHand_ROTATE_FRAMEA[2];            
        rightHand_SET_01[3] = rightHand_ROTATE_FRAMEA[3];    
    }
    if(setSelection_RIGHT_ARM == 2)
    {
        rightUpperArm_SET_02[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_02[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_02[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_02[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightLowerArm_SET_02[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_02[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_02[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_02[3] = rightLowerArm_ROTATE_FRAMEA[3];              
        //----------------------------------------------------------------              
        rightHand_SET_02[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_02[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_02[2] = rightHand_ROTATE_FRAMEA[2];          
        rightHand_SET_02[3] = rightHand_ROTATE_FRAMEA[3];            
    }     
    if(setSelection_RIGHT_ARM == 3)
    {
        rightUpperArm_SET_03[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_03[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_03[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_03[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightLowerArm_SET_03[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_03[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_03[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_03[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        rightHand_SET_03[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_03[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_03[2] = rightHand_ROTATE_FRAMEA[2];           
        rightHand_SET_03[3] = rightHand_ROTATE_FRAMEA[3];         
    }     
    if(setSelection_RIGHT_ARM == 4)
    {
        rightUpperArm_SET_04[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_04[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_04[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_04[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightLowerArm_SET_04[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_04[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_04[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_04[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightHand_SET_04[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_04[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_04[2] = rightHand_ROTATE_FRAMEA[2];            
        rightHand_SET_04[3] = rightHand_ROTATE_FRAMEA[3];          
    }     
    if(setSelection_RIGHT_ARM == 5)
    {
        rightUpperArm_SET_05[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_05[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_05[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_05[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightLowerArm_SET_05[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_05[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_05[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_05[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------               
        rightHand_SET_05[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_05[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_05[2] = rightHand_ROTATE_FRAMEA[2];            
        rightHand_SET_05[3] = rightHand_ROTATE_FRAMEA[3];          
    }      
    if(setSelection_RIGHT_ARM == 6)
    {
        rightUpperArm_SET_06[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_06[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_06[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_06[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        rightLowerArm_SET_06[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_06[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_06[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_06[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightHand_SET_06[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_06[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_06[2] = rightHand_ROTATE_FRAMEA[2];           
        rightHand_SET_06[3] = rightHand_ROTATE_FRAMEA[3];            
    }         
    if(setSelection_RIGHT_ARM == 7)
    {
        rightUpperArm_SET_07[0] = rightUpperArm_ROTATE_FRAMEA[0];
        rightUpperArm_SET_07[1] = rightUpperArm_ROTATE_FRAMEA[1];                   
        rightUpperArm_SET_07[2] = rightUpperArm_ROTATE_FRAMEA[2];
        rightUpperArm_SET_07[3] = rightUpperArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------         
        rightLowerArm_SET_07[0] = rightLowerArm_ROTATE_FRAMEA[0];
        rightLowerArm_SET_07[1] = rightLowerArm_ROTATE_FRAMEA[1];                   
        rightLowerArm_SET_07[2] = rightLowerArm_ROTATE_FRAMEA[2];
        rightLowerArm_SET_07[3] = rightLowerArm_ROTATE_FRAMEA[3];               
        //----------------------------------------------------------------          
        rightHand_SET_07[0] = rightHand_ROTATE_FRAMEA[0];
        rightHand_SET_07[1] = rightHand_ROTATE_FRAMEA[1];                   
        rightHand_SET_07[2] = rightHand_ROTATE_FRAMEA[2];           
        rightHand_SET_07[3] = rightHand_ROTATE_FRAMEA[3];            
    }           
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
}
//----------------------------------------------------------------------------------------------------------------------------------
if(leftUpperLeg_AnimationSequence)
{  
    
    
    if(animationBlendFactor_LEFT_LEG >= 0.0f && animationBlendFactor_LEFT_LEG <= 1.0f)
    {    
        
        leftUpperLeg_ROTATE[3]    = leftUpperLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftUpperLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_LEFT_LEG;        
        
        leftUpperLeg_ROTATE[0]    = leftUpperLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftUpperLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_LEFT_LEG; 
        
        leftUpperLeg_ROTATE[1]    = leftUpperLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftUpperLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_LEFT_LEG;
        
        leftUpperLeg_ROTATE[2]    = leftUpperLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftUpperLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_LEFT_LEG;
        
        leftLowerLeg_ROTATE[3]    = leftLowerLeg_ROTATE_FRAMEA[3]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftLowerLeg_ROTATE_FRAMEB[3]    * animationBlendFactor_LEFT_LEG;        
        
        leftLowerLeg_ROTATE[0]    = leftLowerLeg_ROTATE_FRAMEA[0]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftLowerLeg_ROTATE_FRAMEB[0]    * animationBlendFactor_LEFT_LEG; 
        
        leftLowerLeg_ROTATE[1]    = leftLowerLeg_ROTATE_FRAMEA[1]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftLowerLeg_ROTATE_FRAMEB[1]    * animationBlendFactor_LEFT_LEG;
        
        leftLowerLeg_ROTATE[2]    = leftLowerLeg_ROTATE_FRAMEA[2]    * (1 - animationBlendFactor_LEFT_LEG) 
        + leftLowerLeg_ROTATE_FRAMEB[2]    * animationBlendFactor_LEFT_LEG;                                          
        
        leftFoot_ROTATE[3]        = leftFoot_ROTATE_FRAMEA[3]        * (1 - animationBlendFactor_LEFT_LEG) 
        + leftFoot_ROTATE_FRAMEB[3]        * animationBlendFactor_LEFT_LEG;        
        
        leftFoot_ROTATE[0]        = leftFoot_ROTATE_FRAMEA[0]        * (1 - animationBlendFactor_LEFT_LEG) 
        + leftFoot_ROTATE_FRAMEB[0]        * animationBlendFactor_LEFT_LEG; 
        
        leftFoot_ROTATE[1]        = leftFoot_ROTATE_FRAMEA[1]        * (1 - animationBlendFactor_LEFT_LEG) 
        + leftFoot_ROTATE_FRAMEB[1]        * animationBlendFactor_LEFT_LEG;
        
        leftFoot_ROTATE[2]        = leftFoot_ROTATE_FRAMEA[2]        * (1 - animationBlendFactor_LEFT_LEG) 
        + leftFoot_ROTATE_FRAMEB[2]        * animationBlendFactor_LEFT_LEG;     
    }    
    if(animationBlendFactor_LEFT_LEG >= 1.0f)
    {
        setSelection_LEFT_LEG ++;
        animationBlendFactor_LEFT_LEG = 0.0f;
    }
    if(setSelection_LEFT_LEG == setSelectionLimit_LEFT_LEG+1)
    {
        setSelection_LEFT_LEG = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        leftUpperLeg_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------         
    animationBlendFactor_LEFT_LEG     += leftLeg_ROTATION_FRAME_TIME[setSelectionLimit_LEFT_LEG - 1];
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(setSelection_LEFT_LEG == 1)
    {
        leftUpperLeg_SET_01[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_01[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_01[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_01[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }
    if(setSelection_LEFT_LEG == 2)
    {
        leftUpperLeg_SET_02[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_02[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_02[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_02[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 3)
    {
        leftUpperLeg_SET_03[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_03[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_03[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_03[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 4)
    {
        leftUpperLeg_SET_04[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_04[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_04[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_04[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 5)
    {
        leftUpperLeg_SET_05[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_05[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_05[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_05[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }      
    if(setSelection_LEFT_LEG == 6)
    {
        leftUpperLeg_SET_06[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_06[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_06[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_06[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }         
    if(setSelection_LEFT_LEG == 7)
    {
        leftUpperLeg_SET_07[0] = leftUpperLeg_ROTATE_FRAMEA[0];
        leftUpperLeg_SET_07[1] = leftUpperLeg_ROTATE_FRAMEA[1];                   
        leftUpperLeg_SET_07[2] = leftUpperLeg_ROTATE_FRAMEA[2];
        leftUpperLeg_SET_07[3] = leftUpperLeg_ROTATE_FRAMEA[3];
    }          
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    if(setSelection_LEFT_LEG == 1)
    {
        leftLowerLeg_SET_01[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_01[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_01[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_01[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }
    if(setSelection_LEFT_LEG == 2)
    {
        leftLowerLeg_SET_02[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_02[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_02[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_02[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 3)
    {
        leftLowerLeg_SET_03[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_03[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_03[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_03[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 4)
    {
        leftLowerLeg_SET_04[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_04[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_04[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_04[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 5)
    {
        leftLowerLeg_SET_05[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_05[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_05[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_05[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }      
    if(setSelection_LEFT_LEG == 6)
    {
        leftLowerLeg_SET_06[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_06[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_06[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_06[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }         
    if(setSelection_LEFT_LEG == 7)
    {
        leftLowerLeg_SET_07[0] = leftLowerLeg_ROTATE_FRAMEA[0];
        leftLowerLeg_SET_07[1] = leftLowerLeg_ROTATE_FRAMEA[1];                   
        leftLowerLeg_SET_07[2] = leftLowerLeg_ROTATE_FRAMEA[2];
        leftLowerLeg_SET_07[3] = leftLowerLeg_ROTATE_FRAMEA[3];
    }           
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    if(setSelection_LEFT_LEG == 1)
    {
        leftFoot_SET_01[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_01[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_01[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_01[3] = leftFoot_ROTATE_FRAMEA[3];
    }
    if(setSelection_LEFT_LEG == 2)
    {
        leftFoot_SET_02[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_02[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_02[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_02[3] = leftFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 3)
    {
        leftFoot_SET_03[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_03[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_03[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_03[3] = leftFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 4)
    {
        leftFoot_SET_04[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_04[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_04[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_04[3] = leftFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_LEFT_LEG == 5)
    {
        leftFoot_SET_05[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_05[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_05[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_05[3] = leftFoot_ROTATE_FRAMEA[3];
    }      
    if(setSelection_LEFT_LEG == 6)
    {
        leftFoot_SET_06[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_06[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_06[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_06[3] = leftFoot_ROTATE_FRAMEA[3];
    }         
    if(setSelection_LEFT_LEG == 7)
    {
        leftFoot_SET_07[0] = leftFoot_ROTATE_FRAMEA[0];
        leftFoot_SET_07[1] = leftFoot_ROTATE_FRAMEA[1];                   
        leftFoot_SET_07[2] = leftFoot_ROTATE_FRAMEA[2];
        leftFoot_SET_07[3] = leftFoot_ROTATE_FRAMEA[3];
    }             
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo    
}    
//----------------------------------------------------------------------------------------------------------------------------------        
if(rightUpperLeg_AnimationSequence)
{          
    
    if(animationBlendFactor_RIGHT_LEG >= 0.0f && animationBlendFactor_RIGHT_LEG <= 1.0f)
    {     
        rightUpperLeg_ROTATE[3]   = rightUpperLeg_ROTATE_FRAMEA[3] * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightUpperLeg_ROTATE_FRAMEB[3] * animationBlendFactor_RIGHT_LEG;        
        
        rightUpperLeg_ROTATE[0]   = rightUpperLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightUpperLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_LEG; 
        
        rightUpperLeg_ROTATE[1]   = rightUpperLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightUpperLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_LEG;
        
        rightUpperLeg_ROTATE[2]   = rightUpperLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightUpperLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_LEG;
        
        rightLowerLeg_ROTATE[3]   = rightLowerLeg_ROTATE_FRAMEA[3]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightLowerLeg_ROTATE_FRAMEB[3]   * animationBlendFactor_RIGHT_LEG;        
        
        rightLowerLeg_ROTATE[0]   = rightLowerLeg_ROTATE_FRAMEA[0]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightLowerLeg_ROTATE_FRAMEB[0]   * animationBlendFactor_RIGHT_LEG; 
        
        rightLowerLeg_ROTATE[1]   = rightLowerLeg_ROTATE_FRAMEA[1]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightLowerLeg_ROTATE_FRAMEB[1]   * animationBlendFactor_RIGHT_LEG;
        
        rightLowerLeg_ROTATE[2]   = rightLowerLeg_ROTATE_FRAMEA[2]   * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightLowerLeg_ROTATE_FRAMEB[2]   * animationBlendFactor_RIGHT_LEG;                                          
        
        rightFoot_ROTATE[3]       = rightFoot_ROTATE_FRAMEA[3]       * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightFoot_ROTATE_FRAMEB[3]       * animationBlendFactor_RIGHT_LEG;        
        
        rightFoot_ROTATE[0]       = rightFoot_ROTATE_FRAMEA[0]       * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightFoot_ROTATE_FRAMEB[0]       * animationBlendFactor_RIGHT_LEG; 
        
        rightFoot_ROTATE[1]       = rightFoot_ROTATE_FRAMEA[1]       * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightFoot_ROTATE_FRAMEB[1]       * animationBlendFactor_RIGHT_LEG;
        
        rightFoot_ROTATE[2]       = rightFoot_ROTATE_FRAMEA[2]       * (1 - animationBlendFactor_RIGHT_LEG) 
        + rightFoot_ROTATE_FRAMEB[2]       * animationBlendFactor_RIGHT_LEG; 
    }
    if(animationBlendFactor_RIGHT_LEG >= 1.0f)
    {
        setSelection_RIGHT_LEG ++;
        animationBlendFactor_RIGHT_LEG = 0.0f;
    }
    if(setSelection_RIGHT_LEG == setSelectionLimit_RIGHT_LEG + 1)
    {
        setSelection_RIGHT_LEG = 1;
    }
    //---------------------------------------------------------------------------------------
    if(breakAnimation)
    {
        rightUpperLeg_AnimationSequence = false;
    }
    //---------------------------------------------------------------------------------------      
    animationBlendFactor_RIGHT_LEG       +=  rightLeg_ROTATION_FRAME_TIME[setSelectionLimit_RIGHT_LEG - 1];  
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    if(setSelection_RIGHT_LEG == 1)
    {
        rightUpperLeg_SET_01[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_01[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_01[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_01[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }
    if(setSelection_RIGHT_LEG == 2)
    {
        rightUpperLeg_SET_02[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_02[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_02[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_02[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 3)
    {
        rightUpperLeg_SET_03[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_03[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_03[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_03[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 4)
    {
        rightUpperLeg_SET_04[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_04[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_04[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_04[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 5)
    {
        rightUpperLeg_SET_05[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_05[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_05[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_05[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }      
    if(setSelection_RIGHT_LEG == 6)
    {
        rightUpperLeg_SET_06[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_06[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_06[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_06[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }         
    if(setSelection_RIGHT_LEG == 7)
    {
        rightUpperLeg_SET_07[0] = rightUpperLeg_ROTATE_FRAMEA[0];
        rightUpperLeg_SET_07[1] = rightUpperLeg_ROTATE_FRAMEA[1];                   
        rightUpperLeg_SET_07[2] = rightUpperLeg_ROTATE_FRAMEA[2];
        rightUpperLeg_SET_07[3] = rightUpperLeg_ROTATE_FRAMEA[3];
    }          
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    if(setSelection_RIGHT_LEG == 1)
    {
        rightLowerLeg_SET_01[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_01[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_01[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_01[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }
    if(setSelection_RIGHT_LEG == 2)
    {
        rightLowerLeg_SET_02[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_02[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_02[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_02[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 3)
    {
        rightLowerLeg_SET_03[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_03[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_03[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_03[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 4)
    {
        rightLowerLeg_SET_04[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_04[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_04[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_04[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 5)
    {
        rightLowerLeg_SET_05[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_05[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_05[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_05[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }      
    if(setSelection_RIGHT_LEG == 6)
    {
        rightLowerLeg_SET_06[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_06[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_06[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_06[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }         
    if(setSelection_RIGHT_LEG == 7)
    {
        rightLowerLeg_SET_07[0] = rightLowerLeg_ROTATE_FRAMEA[0];
        rightLowerLeg_SET_07[1] = rightLowerLeg_ROTATE_FRAMEA[1];                   
        rightLowerLeg_SET_07[2] = rightLowerLeg_ROTATE_FRAMEA[2];
        rightLowerLeg_SET_07[3] = rightLowerLeg_ROTATE_FRAMEA[3];
    }           
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo      
    if(setSelection_RIGHT_LEG == 1)
    {
        rightFoot_SET_01[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_01[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_01[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_01[3] = rightFoot_ROTATE_FRAMEA[3];
    }
    if(setSelection_RIGHT_LEG == 2)
    {
        rightFoot_SET_02[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_02[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_02[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_02[3] = rightFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 3)
    {
        rightFoot_SET_03[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_03[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_03[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_03[3] = rightFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 4)
    {
        rightFoot_SET_04[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_04[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_04[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_04[3] = rightFoot_ROTATE_FRAMEA[3];
    }     
    if(setSelection_RIGHT_LEG == 5)
    {
        rightFoot_SET_05[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_05[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_05[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_05[3] = rightFoot_ROTATE_FRAMEA[3];
    }      
    if(setSelection_RIGHT_LEG == 6)
    {
        rightFoot_SET_06[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_06[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_06[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_06[3] = rightFoot_ROTATE_FRAMEA[3];
    }         
    if(setSelection_RIGHT_LEG == 7)
    {
        rightFoot_SET_07[0] = rightFoot_ROTATE_FRAMEA[0];
        rightFoot_SET_07[1] = rightFoot_ROTATE_FRAMEA[1];                   
        rightFoot_SET_07[2] = rightFoot_ROTATE_FRAMEA[2];
        rightFoot_SET_07[3] = rightFoot_ROTATE_FRAMEA[3];
    }          
    //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo    
}

