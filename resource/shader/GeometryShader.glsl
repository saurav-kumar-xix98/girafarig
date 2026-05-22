#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 24) out;

uniform mat4 uProjection;
uniform mat4 uView;

void emit(vec3 point) {
    gl_Position = uProjection * uView * (gl_in[0].gl_Position + vec4(point, 0.0)); 
    EmitVertex();
}

void quad(vec3 p1, vec3 p2, vec3 p3, vec3 p4) {
    emit(p1);
    emit(p2);
    emit(p3);
    emit(p4);

    EndPrimitive();
}

void main() {
    vec3 p000 = vec3(-0.5, -0.5, -0.5);
    vec3 p001 = vec3(-0.5, -0.5,  0.5);
    vec3 p010 = vec3(-0.5,  0.5, -0.5);
    vec3 p011 = vec3(-0.5,  0.5,  0.5);
    vec3 p100 = vec3( 0.5, -0.5, -0.5);
    vec3 p101 = vec3( 0.5, -0.5,  0.5);
    vec3 p110 = vec3( 0.5,  0.5, -0.5);
    vec3 p111 = vec3( 0.5,  0.5,  0.5);

    quad(p000, p001, p010, p011); // left face
    quad(p100, p101, p110, p111); // right face
    quad(p000, p001, p100, p101); // bottom face
    quad(p010, p011, p110, p111); // top face
    quad(p000, p010, p100, p110); // back face
    quad(p001, p011, p101, p111); // front face
}
