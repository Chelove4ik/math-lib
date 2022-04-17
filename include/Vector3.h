#ifndef MATH_LIB_VECTOR3_H
#define MATH_LIB_VECTOR3_H

#include "library.h"

namespace mml {
    class LIB_CLASS Vector3 {
     public:
        float x;
        float y;
        float z;

        Vector3(float x, float y, float z);

        Vector3 operator+(Vector3 &other) const;

        Vector3 operator-() const;

        Vector3 operator-(Vector3 &other) const;

        Vector3 operator*(float num) const;

        float scalar_product(Vector3 &other) const;

        Vector3 vector_product(Vector3 &other) const;
    };

    LIB_CLASS float scalar_product(Vector3 &self, Vector3 &other);

    LIB_CLASS Vector3 vector_product(Vector3 &self, Vector3 &other);
}

#endif //MATH_LIB_VECTOR3_H
