#pragma once

#include <cassert>

#include "matrix.h"

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
