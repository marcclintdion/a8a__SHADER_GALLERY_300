void create_fringe()
{
	unsigned char data[256*3];
	
	// these lambdas are in 100's of nm,
	//  they represent the wavelengths of light for each respective 
	//  color channel.  They are only approximate so that the texture
	//  can repeat.

	float lamR = 6;  // 600 nm
	float lamG = 5;  // 500 nm, should be more like 550
	float lamB = 4;  // 400 nm. should be more like 440

	// these offsets are used to perturb the phase of the interference
	//   if you are using very thick "thin films" you will want to
	//   modify these offests to avoid complete contructive interference
	//   at a particular depth.. Just a tweak able.
	float offsetR = 0;
	float offsetG = 0;
	float offsetB = 0;

	// p is the period of the texture, it is the LCM of the wavelengths,
	//  this is the depth in nm when the pattern will repeat.  I was too
	//  lazy to write up a LCM function, so you have to provide it.
	float p = 60;   //lcm(6,5,4)

	// vd is the depth of the thin film relative to the texture index
	float vd = 1/256.0 * p;

	// now compute the color values using this formula:
	//  1/2 ( Sin( 2Pi * d/lam* + Pi/2 + O) + 1 )
	//   where d is the current depth, or "i*vd" and O is some offset* so that
	//   we avoid complete constructive interference in all wavelenths at some depth.
	float pi = 3.1415926535f;
	for(int i=0; i<256; ++i)
	{
		data[i*3 + 0] = (unsigned char)((.5*(sin(2*pi*(i*vd)/lamR + pi/2.0 + offsetR) + 1))*255);
		data[i*3 + 1] = (unsigned char)((.5*(sin(2*pi*(i*vd)/lamG + pi/2.0 + offsetG) + 1))*255);
		data[i*3 + 2] = (unsigned char)((.5*(sin(2*pi*(i*vd)/lamB + pi/2.0 + offsetB) + 1))*255);
	}

	// Now just load the texture, I use mipmapping since the depth may change very
	// fast in places.

	glGenTextures(1, &fringeTexture);

	glBindTexture(GL_TEXTURE_2D, fringeTexture);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, 256, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
glGenerateMipmapEXT(GL_TEXTURE_2D);
    
}
