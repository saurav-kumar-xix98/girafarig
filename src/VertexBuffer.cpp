#include "VertexBuffer.h"

#include "glad/glad.h"

girafarig::VertexBuffer::VertexBuffer() {
    glGenBuffers(1, &id);
}

girafarig::VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void girafarig::VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void girafarig::VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void girafarig::VertexBuffer::addVertices(const std::vector<Vertex>& vertices) {
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}
