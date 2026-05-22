#include "graphics/shader/Shader.h"

#include <iostream>

girafarig::graphics::shader::Shader::Shader(const std::string_view source, const ShaderType type)
    : id(glCreateShader(static_cast<GLenum>(type))) {

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

girafarig::graphics::shader::Shader::~Shader() {
    glDeleteShader(id);
}

unsigned int girafarig::graphics::shader::Shader::getId() const {
    return id;
}
