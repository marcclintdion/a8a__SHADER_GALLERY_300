
uniform sampler3D Noise;
uniform vec4 lightDir;
uniform vec4 gloss;
uniform vec4 color;
uniform float noiseScale;

varying vec3 vNormal;

varying vec3 vViewVec;
varying vec3 vPos;


varying vec3 pos;void main(void)
{
   vec3 viewVec = normalize(vViewVec);
   vec3 oglLightDir = vec3(lightDir.x, lightDir.y, -lightDir.z);

   float angle = noiseScale;
   //float angle = noiseScale * (texture3D(Noise, vPos) - 0.5).x;   
  
  
   float cosA, sinA, tanA;
   sinA = sin(angle);
   cosA = cos(angle);
   tanA = tan(angle);
//==============================================================================================================
   // Rotate tangent around the normal gl_TexCoord[0].st
   
   vec3 tang =  tanA * vec3(vNormal.y, vNormal.z, vNormal.y);//(Noise, vPos) + 0.5) 
  
   //vec3 tang =  tanA * vec3(vNormal.y, vNormal.z, vNormal.y);  
   //vec3 tang =  tanA * vec3(vNormal.x, vNormal.z, vNormal.y) + sinA * vec3(vNormal.x, vNormal.y, vNormal.z) ;  
   //vec3 tang =  tanA * vec3(vNormal.z, vNormal.y, vNormal.x) + sinA * vec3(vNormal.x, vNormal.y, vNormal.z) ;   
   //vec3 tang =  sinA * vec3(vNormal.x, vNormal.x, vNormal.x) ;  //(Noise, vPos) + 0.5)
   //vec3 tang =  cosA * vec3(vNormal.x, vNormal.x, vNormal.x) ;   
   //vec3 tang =  tanA * vec3(vNormal.x, vNormal.x, vNormal.x) ; //(Noise, vPos) + 0.5) 
   //vec3 tang =  tanA * vec3(vNormal.x, vNormal.y, vNormal.y) ;   //(Noise, vPos) + 0.5)  
   //vec3 tang =  tanA * vec3(vNormal.y, vNormal.y, vNormal.y) ; //(Noise, vPos) + 0.5) 
   //vec3 tang =  tanA * vec3(vNormal.y, vNormal.z, vNormal.x) ;  //(Noise, vPos) + 0.5) 
   //vec3 tang =  cosA * vec3(vNormal.y, vNormal.z, vNormal.x) ;   
   //vec3 tang =  sinA * vec3(vNormal.y, vNormal.z, vNormal.x) ;  //(Noise, vPos) + 0.5)  
   //vec3 tang =  cosA * vec3(vNormal.y, vNormal.z, vNormal.x) ;  
   //vec3 tang =  cosA * vec3(vNormal.x, vNormal.z, vNormal.y) ;   
   //vec3 tang =  sinA * vec3(vNormal.x, vNormal.z, vNormal.y) ;  //(Noise, vPos) + 0.5)  
   //vec3 tang =  cosA * vec3(vNormal.x, vNormal.z, vNormal.y) + sinA * vec3(vNormal.z , vNormal.y, vNormal.x);  //(Noise, vPos) - 0.5)////(Noise, vPos) + 0.5)  
   //vec3 tang =  sinA * vec3(vNormal.x, vNormal.z, vNormal.y) + cosA * vec3(vNormal.z , vNormal.y, vNormal.x);//(Noise, vPos) - 0.5)////(Noise, vPos) + 0.5)  
   //--------------------------------------------------------------------------------------------------------------
   //vec3 tang =  sinA * vec3(vNormal.z, vNormal.y, vNormal.z) ;//(Noise, vPos) + 0.5) 
   //vec3 tang =  cosA * vec3(vNormal.x - gl_TexCoord[0].y, vNormal.y- gl_TexCoord[0].y, vNormal.z) ;  
   //vec3 tang =  sinA * vec3(vNormal.x * gl_TexCoord[0].x, vNormal.y* gl_TexCoord[0].y, vNormal.z) ;  
   //vec3 tang =  sinA * vTangent + cosA * vBinormal;
   
//==============================================================================================================   
  
   float diffuse = clamp( dot( oglLightDir.xyz, vNormal ), 0.0, 1.0 );
   float cs = -dot(viewVec, tang);
   float sn = sqrt(1.0 - cs * cs);
   float cl =  dot(oglLightDir.xyz, tang);
   float sl = sqrt(1.0 - cl * cl);
   float specular = pow( clamp( (cs * cl + sn * sl), 0.0, 1.0 ), 32.0);

  
   gl_FragColor = diffuse * color + gloss * specular;
    
}
