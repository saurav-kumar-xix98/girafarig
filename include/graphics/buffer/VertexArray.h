#pragma once

namespace girafarig::graphics::buffer {
    class VertexArray {
    public:
        VertexArray();
        ~VertexArray();
        void bind() const;
        static void unbind();
    private:
        unsigned int id;
    };
}
