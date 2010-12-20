// simple fragment shader

varying vec3 N;
varying vec3 L;
varying vec3 H;
varying vec3 V;
varying vec4 Md;
varying vec4 Ms;
varying vec4 Pd;
varying vec4 Ps;
varying vec4 ambient;
uniform bool lambert;
uniform bool ashikhmin_spec;
uniform bool ashikhmin_diff;
uniform float Nu;
uniform float Nv;

vec4 calculate_lambert()
{
    vec4 color = ambient;
    vec3 normal = normalize(N);
    float NdotL = max(0.0, dot(normal, L));

    if (NdotL > 0.0) { 
        color += Md * Pd * NdotL;
    }
    return color;
}

vec4 fresnel(float x)
{
    return Ms + (1.0 - Ms) * pow((1.0 - x),5);
}

vec4 calculate_ashikhmin_spec()
{
    vec4 color  = ambient;
    vec3 normal = normalize(N);
    vec3 Hn     = normalize(H);
    vec3 eye    = normalize(V);
    vec3 t1     = normalize(cross(normal, vec3(1.0,0.0,0.0)));
    vec3 t2     = normalize(cross(normal, t1));
    float PI = 3.14159265358979323846264;
      
    vec4  expr1 = Ms * Ps;
    float expr2_num = sqrt((Nu + 1.0)*(Nv + 1.0));
    float expr2_den = 8.0 * PI * dot(Hn, L) * 
                      max(dot(normal, L), dot(normal, eye));
    float powExp = (Nu * pow(dot(Hn, t1), 2.0) + Nv * 
                         pow(dot(Hn, t2), 2.0)) / (1.0 - pow(dot(Hn, normal), 2.0));
    
    color += expr1 * (expr2_num / expr2_den) * 
                    pow(dot(normal, Hn), powExp) * fresnel(dot(Hn, L));
    return color;
}


vec4 calculate_ashikhmin_diff()
{
    vec4 color  = ambient;
    vec3 eye    = normalize(V);
    vec3 normal = normalize(N);
    float PI = 3.14159265358979323846264;

    vec4  expr1 = (28.0 * Md * Pd) / (23.0 * PI);
    vec4  expr2 = 1.0 - Ms;
    float expr3 = 1.0 - pow(1.0 - (dot(normal, L) / 2.0), 5.0);
    float expr4 = 1.0 - pow(1.0 - (dot(normal, eye) / 2.0), 5.0);
    
    color += expr1 * expr2 * expr3 * expr4;
    return color;
}


void main()
{   
    if (lambert) {
	    gl_FragColor = calculate_lambert();
    } 
    if (ashikhmin_spec){
        gl_FragColor = calculate_ashikhmin_spec();
    } 
    if (ashikhmin_diff) {
        gl_FragColor = calculate_ashikhmin_diff();
    }
}
