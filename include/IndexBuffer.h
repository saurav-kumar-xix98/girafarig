#pragma once
#include <vector>

namespace girafarig {
    class IndexBuffer {
    public:
        IndexBuffer();
        ~IndexBuffer();

        void bind() const;
        static void unbind();
        static void addIndices(const std::vector<unsigned int>& indices);
    private:
        unsigned int id;
    };
}
