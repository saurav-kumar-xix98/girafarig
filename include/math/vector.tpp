#pragma once

#include <cassert>

template<uint8_t N>
girafarig::math::Vector<N>::Vector() {
    data.fill(0.0f);
}

template <uint8_t N>
girafarig::math::Vector<N>::Vector(std::initializer_list<float> values) {
    assert(values.size() == N);

    std::copy(values.begin(), values.end(), data.begin());
}

template <uint8_t N>
float& girafarig::math::Vector<N>::operator[](uint8_t index) {
    return data[index];
}

template <uint8_t N>
const float& girafarig::math::Vector<N>::operator[](uint8_t index) const {
    return data[index];
}
