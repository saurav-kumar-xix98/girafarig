#pragma once

#include <cassert>

template<uint8_t R, uint8_t C>
girafarig::math::Matrix<R, C>::Matrix() {
    data.fill(Vector<C>());
}

template <uint8_t R, uint8_t C>
girafarig::math::Matrix<R, C>::Matrix(std::initializer_list<Vector<C>> values) {
    assert(values.size() == R);
    std::copy(values.begin(), values.end(), data.begin());
}

template <uint8_t R, uint8_t C>
girafarig::math::Vector<C>& girafarig::math::Matrix<R, C>::operator[](uint8_t index) {
    return data[index];
}

template <uint8_t R, uint8_t C>
const girafarig::math::Vector<C>& girafarig::math::Matrix<R, C>::operator[](uint8_t index) const {
    return data[index];
}

template <uint8_t R, uint8_t C>
template <uint8_t C2>
girafarig::math::Matrix<R, C2> girafarig::math::Matrix<R, C>::operator*(Matrix<C, C2> matrix) {
    Matrix<R, C2> result;
    for (uint8_t i = 0; i < R; i++) {
        for (uint8_t j = 0; j < C2; j++) {
            for (uint8_t k = 0; k < C; k++) {
                result[i][j] += (*this)[i][k] * matrix[k][j];
            }
        }
    }
    return result;
}
