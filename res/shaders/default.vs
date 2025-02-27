#version 410 core
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 vc;
layout(location = 2) in vec2 vt;

uniform float offsetX;

out vec3 vertexColor;
out vec2 texCoord;

void main()
{
    gl_Position = vec4(vp, 1.0) + vec4(offsetX, 0.0, 0.0, 0.0);
    vertexColor = vc;
    texCoord = vt;
}
