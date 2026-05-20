#include "math/Quaternion.h"

girafarig::math::Quaternion::Quaternion(Vector<3> axis, const float angle) {
    axis.normalize();

    const float s = std::sin(angle * 0.5f);
    const float c = std::cos(angle * 0.5f);

    w = c;
    x = axis[0] * s;
    y = axis[1] * s;
    z = axis[2] * s;
}

girafarig::math::Quaternion girafarig::math::Quaternion::conjugate() const {
    Quaternion other = *this;
    other.x *= -1.0f;
    other.y *= -1.0f;
    other.z *= -1.0f;
    return other;
}

float girafarig::math::Quaternion::getW() const {
    return w;
}

float girafarig::math::Quaternion::getX() const {
    return x;
}

float girafarig::math::Quaternion::getY() const {
    return y;
}

float girafarig::math::Quaternion::getZ() const {
    return z;
}
