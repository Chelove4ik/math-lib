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

        Vector3 operator+(const Vector3 &other) const;

        Vector3 operator-() const;

        Vector3 operator-(const Vector3 &other) const;

        Vector3 operator*(float num) const;

        Vector3 operator/(float num) const;

        float operator[](int index) const;

        float scalar_product(const Vector3 &other) const;

        Vector3 vector_product(const Vector3 &other) const;

        [[nodiscard]] float len() const;

        [[nodiscard]] Vector3 normalize() const;
    };

    [[nodiscard]] LIB_CLASS inline float scalar_product(const Vector3 &self, const Vector3 &other) {
        return self.scalar_product(other);
    }

    [[nodiscard]] LIB_CLASS inline Vector3 vector_product(const Vector3 &self, const Vector3 &other) {
        return self.vector_product(other);
    }

    [[nodiscard]] LIB_CLASS inline float len(const Vector3 &self) {
        return self.len();
    }

    [[nodiscard]] LIB_CLASS inline Vector3 normalize(const Vector3 &self) {
        return self.normalize();
    }
}

#endif //MATH_LIB_VECTOR3_H
