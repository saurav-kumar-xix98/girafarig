#include "Shader.h"

#include <iostream>
#include <ostream>

#include "glad/glad.h"

girafarig::Shader::Shader(const std::string_view source, const ShaderType type)
    : id(glCreateShader(type == VERTEX_SHADER ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER)) {

    const char* shaderSource = source.data();
    glShaderSource(id, 1, &shaderSource, nullptr);
    glCompileShader(id);

    int success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(id, 512, nullptr, infoLog);
        std::cout << infoLog << std::endl;
        throw std::runtime_error("Failed to compile shader: " + std::string(infoLog));
    }
}

girafarig::Shader::~Shader() {
    glDeleteShader(id);
}

unsigned int girafarig::Shader::getId() const {
    return id;
}
