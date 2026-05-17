#include "ShaderProgram.h"

#include <filesystem>

#include "Shader.h"

#include <fstream>
#include <iostream>

#include "glad/glad.h"

namespace {
    std::string readFile(const std::filesystem::path &path);
}

girafarig::ShaderProgram::ShaderProgram(const std::filesystem::path &vertexShaderFilePath, const std::filesystem::path &fragmentShaderFilePath)
    : id(glCreateProgram()) {

    const std::string vertexShaderSource = readFile(vertexShaderFilePath);
    const Shader vertexShader(vertexShaderSource, VERTEX_SHADER);

    const std::string fragmentShaderSource = readFile(fragmentShaderFilePath);
    const Shader fragmentShader(fragmentShaderSource, FRAGMENT_SHADER);

    glAttachShader(id, vertexShader.getId());
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

girafarig::ShaderProgram::~ShaderProgram() {
    glDeleteProgram(id);
}

void girafarig::ShaderProgram::useProgram() const {
    glUseProgram(id);
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
