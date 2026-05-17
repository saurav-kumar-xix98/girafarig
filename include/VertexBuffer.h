#pragma once
#include <vector>

#include "Vertex.h"

namespace girafarig {
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
