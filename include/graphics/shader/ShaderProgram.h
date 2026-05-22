#pragma once

#include <filesystem>

#include "math/Matrix.h"
#include "math/Vector.h"

namespace girafarig::graphics::shader {
    class ShaderProgram {
    public:
        ShaderProgram(const std::filesystem::path &vertexShaderFilePath,
                      const std::filesystem::path &geometryShaderFilePath,
                      const std::filesystem::path &fragmentShaderFilePath);
        ~ShaderProgram();

        void useProgram() const;
        void setUniform(const std::string &name, const math::Vector<4> &value) const;
        void setUniform(const std::string &name, const math::Matrix<4, 4> &value) const;
    private:
        const unsigned int id;
    };
}
