#pragma once

#include <array>
#include <cstdint>

namespace girafarig::math {
    template <uint8_t N>
    class Vector {
    public:
        Vector();
        Vector(std::initializer_list<float> values);

        float& operator[](uint8_t index);
        const float& operator[](uint8_t index) const;

        Vector<N> operator*(float scale) const;

        void normalize();
    private:
        std::array<float, N> data;
    };
}

#include "Vector.tpp"
