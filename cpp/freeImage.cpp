		
		//FreeImage_Save(FIF_JPEG, dib, "mybitmap.jpg", JPEG_QUALITYSUPERB);
/*
void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);	
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
    
    glGenerateMipmapEXT(GL_TEXTURE_2D);
}
*/

void loadTexture(char *textureFileName, GLuint &textureMapID)	
{
	FREE_IMAGE_FORMAT fifmt = FreeImage_GetFileType(textureFileName, 0);

	FIBITMAP *dib = FreeImage_Load(fifmt, textureFileName,0);

	FIBITMAP *temp = dib;
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        
        glGenTextures( 1, &textureMapID );
		glBindTexture( GL_TEXTURE_2D, textureMapID );
        
         
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);		
      
        ConfigureAndLoadTexture(pixels,  FreeImage_GetWidth(dib),  FreeImage_GetHeight(dib) );           
       
       
        free(pixels);
        FreeImage_Unload(dib);
	}

}
