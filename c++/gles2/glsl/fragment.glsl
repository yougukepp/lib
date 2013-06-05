#version   100
precision highp float;

varying   vec4 g_vVSColor;

void main()
{
    gl_FragColor = g_vVSColor * 0.7;
}

