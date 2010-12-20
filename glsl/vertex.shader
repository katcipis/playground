// simple vertex shader

varying vec3 N;
varying vec3 L;
varying vec3 V;
varying vec3 H;
varying vec4 Md;
varying vec4 Ms;
varying vec4 Pd;
varying vec4 Ps;
varying vec4 ambient;

void main()
{
    vec4 tmp = gl_ModelViewMatrix * gl_Vertex;
    vec3 eye = tmp.xyz;
    eye = -eye;
    eye = normalize(eye);
    N = normalize(gl_NormalMatrix * gl_Normal);
    V = eye.xyz;
    L = normalize(vec3(gl_LightSource[0].position));
    H = normalize(L + V);
    Md = gl_FrontMaterial.diffuse;
    Ms = gl_FrontMaterial.specular;
    Pd = gl_LightSource[0].diffuse;
    Ps = gl_LightSource[0].specular;
    ambient =  gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
    ambient += gl_LightModel.ambient * gl_FrontMaterial.ambient;
	gl_Position = ftransform();
}
