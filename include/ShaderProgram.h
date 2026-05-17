#pragma once

#include <filesystem>

namespace girafarig {
    class ShaderProgram {
    public:
        ShaderProgram(const std::filesystem::path &vertexShaderFilePath, const std::filesystem::path &fragmentShaderFilePath);
        ~ShaderProgram();
    private:
        const unsigned int id;
    };
}
