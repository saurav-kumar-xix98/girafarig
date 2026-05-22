#include "graphics/shader/ShaderProgram.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "glad/glad.h"
#include "graphics/shader/Shader.h"

namespace {
    std::string readFile(const std::filesystem::path &path);
}

girafarig::graphics::shader::ShaderProgram::ShaderProgram(const std::filesystem::path &vertexShaderFilePath,
        const std::filesystem::path &geometryShaderFilePath,
        const std::filesystem::path &fragmentShaderFilePath)
    : id(glCreateProgram()) {

    const std::string vertexShaderSource = readFile(vertexShaderFilePath);
    const Shader vertexShader(vertexShaderSource, ShaderType::VERTEX_SHADER);

    const std::string geometryShaderSource = readFile(geometryShaderFilePath);
    const Shader geometryShader(geometryShaderSource, ShaderType::GEOMETRY_SHADER);

    const std::string fragmentShaderSource = readFile(fragmentShaderFilePath);
    const Shader fragmentShader(fragmentShaderSource, ShaderType::FRAGMENT_SHADER);

    glAttachShader(id, vertexShader.getId());
    glAttachShader(id, geometryShader.getId());
    glAttachShader(id, fragmentShader.getId());

    glLinkProgram(id);

    int success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        std::cout << infoLog << std::endl;
        throw std::runtime_error("Failed to link shader program: " + std::string(infoLog));
    }
}

girafarig::graphics::shader::ShaderProgram::~ShaderProgram() {
    glDeleteProgram(id);
}

void girafarig::graphics::shader::ShaderProgram::useProgram() const {
    glUseProgram(id);
}

void girafarig::graphics::shader::ShaderProgram::setUniform(const std::string& name, const math::Vector<4> &value) const {
    glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, reinterpret_cast<const GLfloat*>(&value));
}

void girafarig::graphics::shader::ShaderProgram::setUniform(const std::string& name, const math::Matrix<4, 4> &value) const {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_TRUE, reinterpret_cast<const GLfloat*>(&value));
}

namespace {
    std::string readFile(const std::filesystem::path &path) {
        std::ifstream fileStream(path, std::ios::binary);

        if (!fileStream) {
            throw std::runtime_error("Could not open file " + path.string());
        }

        fileStream.seekg(0, std::ios::end);
        const size_t fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        std::string fileContents(fileSize, '\0');
        fileStream.read(fileContents.data(), fileSize);

        return fileContents;
    }
}
