#version 330 core

layout (location = 0) in vec3 aPos;

uniform mat4 uPerspective;

void main() {
    gl_Position = uPerspective * vec4(aPos, 1.0);
}
