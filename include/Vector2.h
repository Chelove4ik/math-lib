#ifndef MATH_LIB_VECTOR2_H
#define MATH_LIB_VECTOR2_H

#include "library.h"

namespace mml {

    class LIB_CLASS Vector2 {
     public:
        float x;
        float y;

        Vector2(float x, float y);

        Vector2(const Vector2 &other);

        Vector2();

        Vector2 operator+(const Vector2 &other) const;

        Vector2 operator-() const;

        Vector2 operator-(const Vector2 &other) const;

        Vector2 operator*(float num) const;

        Vector2 operator/(float num) const;

        float &operator[](int index);

        const float &operator[](int index) const;

        float scalar_product(const Vector2 &other) const;

        [[nodiscard]] float len() const;

        [[nodiscard]] Vector2 normalize() const;
    };

    [[nodiscard]] LIB_CLASS inline float scalar_product(const Vector2 &self, const Vector2 &other) {
        return self.scalar_product(other);
    }

    [[nodiscard]] LIB_CLASS inline float len(const Vector2 &self) {
        return self.len();
    }

    [[nodiscard]] LIB_CLASS inline Vector2 normalize(const Vector2 &self) {
        return self.normalize();
    }

}//namespace mml

#endif //MATH_LIB_VECTOR2_H
