#version   100
uniform    mat4 g_scaleMat;
uniform    mat4 g_roataMat;
attribute  vec4 g_vPosition;
attribute  vec4 g_vColor;
varying    vec4 g_vVSColor;

void main()
{
    vec4 vPositionES = g_scaleMat * g_vPosition;
    gl_Position  = g_roataMat * vPositionES;
    g_vVSColor = g_vColor;
}

