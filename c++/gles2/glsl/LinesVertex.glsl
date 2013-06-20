#version   100
#
uniform float uPointSize;
uniform mat4 uMatrix;
attribute vec4 vPosition;
void main()
{
    gl_PointSize = uPointSize;
    gl_Position  = uMatrix * vPosition;
    //gl_Position = vPosition;
}

