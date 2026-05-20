#pragma once

#include <cassert>
#include <complex>

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

template <uint8_t N>
girafarig::math::Vector<N> girafarig::math::Vector<N>::operator*(float scale) const {
    Vector result;
    for (uint8_t i = 0; i < N; i++) {
        result[i] = data[i] * scale;
    }
    return result;
}

template <uint8_t N>
void girafarig::math::Vector<N>::normalize() {
    float normFactor = 0.0f;
    for (uint8_t i = 0; i < N; i++) {
        normFactor += data[i] * data[i];
    }
    normFactor = 1.0f / std::sqrt(normFactor);
    for (uint8_t i = 0; i < N; i++) {
        data[i] *= normFactor;
    }
}
