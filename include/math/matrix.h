# pragma once

#include <array>
#include <cstdint>

#include "vector.h"

namespace girafarig::math {
    template <uint8_t R, uint8_t C>
    class Matrix {
    public:
        Matrix();
        Matrix(std::initializer_list<Vector<C>> values);
        Vector<C>& operator[](uint8_t index);
        const Vector<C>& operator[](uint8_t index) const;
    private:
        std::array<Vector<C>, R> data;
    };
}

#include "matrix.tpp"
