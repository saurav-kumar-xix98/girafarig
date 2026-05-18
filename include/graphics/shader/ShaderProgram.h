#pragma once

#include "math/vector.h"

#include <filesystem>

namespace girafarig::graphics::shader {
    class ShaderProgram {
    public:
        ShaderProgram(const std::filesystem::path &vertexShaderFilePath, const std::filesystem::path &fragmentShaderFilePath);
        ~ShaderProgram();

        void useProgram() const;
        void setUniform(const std::string &name, math::Vector<4> value) const;
    private:
        const unsigned int id;
    };
}
