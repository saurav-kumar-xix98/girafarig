#pragma once
#include <vector>

#include "graphics/Vertex.h"

namespace girafarig::graphics::buffer {
    class VertexBuffer {
        public:
        VertexBuffer();
        ~VertexBuffer();

        void bind() const;
        static void unbind();

        static void addVertices(const std::vector<Vertex>& vertices);
    private:
        unsigned int id;
    };
}
