#include "VertexArray.h"

#include "glad/glad.h"

girafarig::VertexArray::VertexArray() {
    glGenVertexArrays(1, &id);
}

girafarig::VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &id);
}

void girafarig::VertexArray::bind() const {
    glBindVertexArray(id);
}

void girafarig::VertexArray::unbind() {
    glBindVertexArray(0);
}
