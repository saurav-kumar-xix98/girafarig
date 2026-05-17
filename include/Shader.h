#pragma once
#include <string_view>

namespace girafarig {
    enum ShaderType {
        VERTEX_SHADER,
        FRAGMENT_SHADER,
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
