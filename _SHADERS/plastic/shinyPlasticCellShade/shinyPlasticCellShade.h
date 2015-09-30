" varying vec4 diffuse;                                                                                 \n"
" varying vec4 ambientGlobal;                                                                                 \n"
" varying vec4 ambient;                                                                                 \n"
"                                                                                  \n"
" varying vec3 normal;                                                                                 \n"
" varying vec3 lightDir;                                                                                 \n"
"                                                                                  \n"
"                                                                                  \n"
" varying float dist;                                                                                 \n"
" 	                                                                                 \n"
" void main()                                                                                 \n"
" {	                                                                                 \n"
" 	vec4 ecPos;                                                                                 \n"
" 	vec3 aux;                                                                                 \n"
" 		                                                                                 \n"
" 	normal = normalize(gl_NormalMatrix * gl_Normal);                                                                                 \n"

"     ecPos = gl_ModelViewMatrix * gl_Vertex;                                                                                 \n"

"     aux = vec3(gl_LightSource[0].position - ecPos);                                                                                 \n"
"     dist = length(aux);                                                                                  \n"

"     lightDir = normalize(aux);                                                                           \n"


"     diffuse = vec4( 0.00,  1.0,  1.00, 1.0)  * vec4(1.0, 48.6, 1.0, 1.0);                                \n"
"     ambient = vec4(-1.75, -1.75, 0.0,  1.0)  * vec4(1.1, 26.1, 1.1, 1.0);                                \n"
"     ambientGlobal =  vec4(-1.75, -1.75, 0.0, 1.0);                                                       \n"

"     gl_Position = ftransform();                                                                                 \n"
" }                                                                                  \n"
