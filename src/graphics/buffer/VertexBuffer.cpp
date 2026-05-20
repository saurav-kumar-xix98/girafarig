#include "graphics/buffer/VertexBuffer.h"

#include "glad/glad.h"

girafarig::graphics::buffer::VertexBuffer::VertexBuffer() {
    glGenBuffers(1, &id);
}

girafarig::graphics::buffer::VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id);
}

void girafarig::graphics::buffer::VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void girafarig::graphics::buffer::VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void girafarig::graphics::buffer::VertexBuffer::addVertices(const std::vector<Vertex>& vertices) {
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}
