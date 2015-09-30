uniform float mRefractionRatio; // = 1.02
uniform float mFresnelBias;     // = 0.1
uniform float mFresnelScale;    // = 1.0
uniform float mFresnelPower;    // = 2.0
varying vec3  vReflect;
varying vec3  vRefract[3];
varying float vReflectionFactor;

void main() 
{
 	vec4 mvPosition         = modelViewMatrix * vec4( position, 1.0 );
    vec4 mPosition          = objectMatrix * vec4( position, 1.0 );
    vec3 nWorld             = normalize ( mat3( objectMatrix[0].xyz, objectMatrix[1].xyz, objectMatrix[2].xyz ) * normal);
    vec3 I                  = mPosition.xyz - cameraPosition;
    nvReflect               = reflect( I, nWorld );
    vRefract[0]             = refract( normalize( I ), nWorld, mRefractionRatio );
    vRefract[1]             = refract( normalize( I ), nWorld, mRefractionRatio * 0.99 );
    vRefract[2]             = refract( normalize( I ), nWorld, mRefractionRatio * 0.98 );
    vReflectionFactor       = mFresnelBias + mFresnelScale * pow( 1.0 + dot( normalize( I ), nWorld ), mFresnelPower );
    gl_Position             = projectionMatrix * mvPosition;
}
//=========================================================================================================================================

uniform samplerCube tCube;
varying vec3 vReflect;
varying vec3 vRefract[3];
varying float vReflectionFactor;

void main()
{

    vec4 reflectedColor     = textureCube( tCube, vec3( -vReflect.x, vReflect.yz ) );
    vec4 refractedColor     = vec4( 1.0, 1.0, 1.0, 1.0 );
    refractedColor.r        = textureCube( tCube, vec3( -vRefract[0].x, vRefract[0].yz ) ).r;
    refractedColor.g        = textureCube( tCube, vec3( -vRefract[1].x, vRefract[1].yz ) ).g;
    refractedColor.b        = textureCube( tCube, vec3( -vRefract[2].x, vRefract[2].yz ) ).b;
    refractedColor.a        = 1.0;
    gl_FragColor            = mix( refractedColor, reflectedColor, clamp( vReflectionFactor, 0.0, 1.0 ) );
}
