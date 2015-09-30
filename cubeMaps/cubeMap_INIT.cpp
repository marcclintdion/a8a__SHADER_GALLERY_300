

#ifdef WIN32
glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
#endif

glEnable(GL_TEXTURE_CUBE_MAP);
   
//glGenTextures(1, &cubemapTexture[0]);
glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]);

       
       
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

#ifdef WIN32   
   
   
    char textName_POSX[] = "cubeMaps/Terrain_posx.png";	
    char textName_NEGX[] = "cubeMaps/Terrain_negx.png";	
    char textName_POSY[] = "cubeMaps/Terrain_posy.png";    
    char textName_NEGY[] = "cubeMaps/Terrain_negy.png";	
    char textName_POSZ[] = "cubeMaps/Terrain_posz.png";	
    char textName_NEGZ[] = "cubeMaps/Terrain_negz.png";    
    

    FREE_IMAGE_FORMAT fifmt;
    FIBITMAP *dib;
    FIBITMAP *temp = dib;    
    
    //========================================================================================================================================   
   
    fifmt = FreeImage_GetFileType(textName_POSX, 0);
    dib = FreeImage_Load(fifmt,   textName_POSX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}

    //========================================================================================================================================
    
    fifmt = FreeImage_GetFileType(textName_NEGX, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
   
    //========================================================================================================================================
  
    fifmt = FreeImage_GetFileType(textName_POSY, 0);
    dib = FreeImage_Load(fifmt,   textName_POSY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
  
    //========================================================================================================================================
  
    fifmt = FreeImage_GetFileType(textName_NEGY, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}

    //========================================================================================================================================
   
    fifmt = FreeImage_GetFileType(textName_POSZ, 0);
    dib = FreeImage_Load(fifmt,   textName_POSZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
  
    //========================================================================================================================================
  
    fifmt = FreeImage_GetFileType(textName_NEGZ, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
   
   //========================================================================================================================================       
        //-------------------------------------------
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        //----------------
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
        //----------------
        glTexParameteri( GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );        
#endif       
      
//==================================================================================================================================================
//--------------------------------------------------------------------------------------------------------------------------------------------------
//==================================================================================================================================================

#ifdef __APPLE__

      //-------------------------------------------------                                                                                                                 
        spriteImage             = [UIImage imageNamed:@"Terrain_posx.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, width, height, 0,    GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        } 
        //=================================================================================================================================
        spriteImage             = [UIImage imageNamed:@"Terrain_negx.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        }                                                                                                                    
        //=================================================================================================================================
        spriteImage             = [UIImage imageNamed:@"Terrain_posy.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        }                                                                                                                   
        //=================================================================================================================================
        spriteImage             = [UIImage imageNamed:@"Terrain_negy.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        }                                                                                                                      
        //=================================================================================================================================
        spriteImage             = [UIImage imageNamed:@"Terrain_posz.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        }                                                                                                                    
        //=================================================================================================================================
        spriteImage             = [UIImage imageNamed:@"Terrain_negz.png"].CGImage;
        width                   =  CGImageGetWidth(spriteImage);
        height                  =  CGImageGetHeight(spriteImage);
        spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
        spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);    

        CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);
        CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS
        CGContextScaleCTM (spriteContext, 1.0, -1.0); //---------------------------FLIP_Y_AXIS          

        CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);
        CGContextRelease(spriteContext);
        //---------
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);          
        if(spriteData != NULL)
        {
                free(spriteData);    
        }                                                                                                                      
        //=================================================================================================================================
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,        GL_REPEAT);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,        GL_REPEAT);    
        //---------------
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8.0);
        //---------------
        glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

#endif        
       
       
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



       


    

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);













