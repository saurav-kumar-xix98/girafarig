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
    private:
        std::array<float, N> data;
    };
}

#include "vector.tpp"
