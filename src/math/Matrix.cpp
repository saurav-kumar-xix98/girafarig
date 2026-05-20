#include "math/Matrix.h"

girafarig::math::Matrix<4, 4> girafarig::math::createTranslationMatrix(const Vector<3> position) {
    return {
            { 1.0f, 0.0f, 0.0f, position[0] },
            { 0.0f, 1.0f, 0.0f, position[1] },
            { 0.0f, 0.0f, 1.0f, position[2] },
            { 0.0f, 0.0f, 0.0f, 1.0f }
    };
}

girafarig::math::Matrix<4, 4> girafarig::math::createRotationMatrix(Quaternion rotation) {
    const float w = rotation.getW();
    const float x = rotation.getX();
    const float y = rotation.getY();
    const float z = rotation.getZ();
    return {
        { 1.0f - 2.0f * (y * y + z * z),  2.0f * (x * y - w * z),         2.0f * (x * z + w * y),         0.0f },
        { 2.0f * (x * y + w * z),         1.0f - 2.0f * (x * x + z * z),  2.0f * (y * z - w * x),         0.0f },
        { 2.0f * (x * z - w * y),         2.0f * (y * z + w * x),         1.0f - 2.0f * (x * x + y * y),  0.0f },
        { 0.0f,                           0.0f,                           0.0f,                           1.0f },
    };
}

girafarig::math::Matrix<4, 4> girafarig::math::createPerspectiveProjectionMatrix(const float fovYRadians, const float aspectRatio, const float near, const float far) {
    const float k = std::tan(fovYRadians * 0.5f);
    return {
                { 1 / (k * aspectRatio), 0.0f, 0.0f, 0.0f },
                { 0.0f, 1 / k, 0.0f, 0.0f },
                { 0.0f, 0.0f, (far + near) / (near - far), 2 * far * near / (near - far) },
                { 0.0f, 0.0f, -1.0f, 0.0f }
    };
}

girafarig::math::Matrix<4, 4> girafarig::math::createViewMatrix(const Vector<3> position, const Quaternion rotation) {
    return createRotationMatrix(rotation.conjugate()) * createTranslationMatrix(position * -1.0f);
}
