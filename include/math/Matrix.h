# pragma once

#include <array>
#include <cstdint>

#include "Quaternion.h"
#include "Vector.h"

namespace girafarig::math {
    template <uint8_t R, uint8_t C>
    class Matrix {
    public:
        Matrix();
        Matrix(std::initializer_list<Vector<C>> values);

        Vector<C>& operator[](uint8_t index);
        const Vector<C>& operator[](uint8_t index) const;

        template <uint8_t C2>
        Matrix<R, C2> operator*(Matrix<C, C2> matrix);
    private:
        std::array<Vector<C>, R> data;
    };

    Matrix<4, 4> createTranslationMatrix(Vector<3> position);
    Matrix<4, 4> createRotationMatrix(Quaternion rotation);
    Matrix<4, 4> createPerspectiveProjectionMatrix(float fovYRadians, float aspectRatio, float near, float far);
    Matrix<4, 4> createViewMatrix(Vector<3> position, Quaternion rotation);
}

#include "Matrix.tpp"
