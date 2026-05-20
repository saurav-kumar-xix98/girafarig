#include "graphics/buffer/VertexArray.h"

#include "glad/glad.h"

girafarig::graphics::buffer::VertexArray::VertexArray() {
    glGenVertexArrays(1, &id);
}

girafarig::graphics::buffer::VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &id);
}

void girafarig::graphics::buffer::VertexArray::bind() const {
    glBindVertexArray(id);
}

void girafarig::graphics::buffer::VertexArray::unbind() {
    glBindVertexArray(0);
}
