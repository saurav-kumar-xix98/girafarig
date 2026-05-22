#pragma once

#include <string_view>

#include "glad/glad.h"

namespace girafarig::graphics::shader {
    enum class ShaderType : GLenum {
        VERTEX_SHADER   = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
        GEOMETRY_SHADER = GL_GEOMETRY_SHADER
    };

    class Shader {
    public:
        explicit Shader(std::string_view source, ShaderType type);
        ~Shader();
        [[nodiscard]] unsigned int getId() const;
    private:
        const unsigned int id;
    };
}
