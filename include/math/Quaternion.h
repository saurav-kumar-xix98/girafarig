#pragma once

#include "math/Vector.h"

namespace girafarig::math {
    class Quaternion {
    public:
        Quaternion(Vector<3> axis, float angle);

        [[nodiscard]] Quaternion conjugate() const;
        [[nodiscard]] float getW() const;
        [[nodiscard]] float getX() const;
        [[nodiscard]] float getY() const;
        [[nodiscard]] float getZ() const;
    private:
        float w, x, y, z;
    };
}
