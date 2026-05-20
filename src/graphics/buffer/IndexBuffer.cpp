#include "graphics/buffer/IndexBuffer.h"

#include "glad/glad.h"

girafarig::graphics::buffer::IndexBuffer::IndexBuffer() {
    glGenBuffers(1, &id);
}

girafarig::graphics::buffer::IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &id);
}

void girafarig::graphics::buffer::IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void girafarig::graphics::buffer::IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void girafarig::graphics::buffer::IndexBuffer::addIndices(const std::vector<unsigned int>& indices) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}
