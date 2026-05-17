#include "IndexBuffer.h"

#include "glad/glad.h"

girafarig::IndexBuffer::IndexBuffer() {
    glGenBuffers(1, &id);
}

girafarig::IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &id);
}

void girafarig::IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void girafarig::IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void girafarig::IndexBuffer::addIndices(const std::vector<unsigned int>& indices) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}
