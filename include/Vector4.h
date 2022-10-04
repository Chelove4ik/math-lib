#ifndef MATH_LIB_VECTOR4_H
#define MATH_LIB_VECTOR4_H

#include "library.h"

namespace mml {

    class LIB_CLASS Vector4 {
     public:
        float x;
        float y;
        float z;
        float w;

        Vector4(float x, float y, float z, float w);

        Vector4(const Vector4 &other);

        Vector4();

        Vector4 operator+(const Vector4 &other) const;

        Vector4 operator-() const;

        Vector4 operator-(const Vector4 &other) const;

        Vector4 operator*(float num) const;

        Vector4 operator/(float num) const;

        float &operator[](int index);

        const float &operator[](int index) const;

        float scalar_product(const Vector4 &other) const;

        [[nodiscard]] float len() const;

        [[nodiscard]] Vector4 normalize() const;
    };

    [[nodiscard]] LIB_CLASS inline float scalar_product(const Vector4 &self, const Vector4 &other) {
        return self.scalar_product(other);
    }

    [[nodiscard]] LIB_CLASS inline float len(const Vector4 &self) {
        return self.len();
    }

    [[nodiscard]] LIB_CLASS inline Vector4 normalize(const Vector4 &self) {
        return self.normalize();
    }

}//namespace mml


#endif //MATH_LIB_VECTOR4_H
