uniform float noiseRate;
uniform mat4 view_proj_matrix;



varying vec3 vNormal;

varying vec3 vViewVec;
varying vec3 vPos;


void main(void)
{
   gl_Position = ftransform();


    vNormal   = gl_NormalMatrix * gl_Normal;

    vViewVec.xyz    = vec3(  gl_ModelViewMatrix * gl_Vertex );
    
    vViewVec.z  = -vViewVec.z;
   
   vPos      = gl_Vertex.xyz * noiseRate;
   
}
