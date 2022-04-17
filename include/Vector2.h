#ifndef MATH_LIB_VECTOR2_H
#define MATH_LIB_VECTOR2_H

#include "library.h"

namespace mml {

    class LIB_CLASS Vector2 {
     public:
        float x;
        float y;

        Vector2(float x, float y);

        Vector2 operator+(Vector2 &other) const;

        Vector2 operator-() const;

        Vector2 operator-(Vector2 &other) const;

        Vector2 operator*(float num) const;

        float scalar_product(Vector2 &other) const;

        Vector2 vector_product(Vector2 &other) const;
    };

    LIB_CLASS float scalar_product(Vector2 &self, Vector2 &other);

    LIB_CLASS Vector2 vector_product(Vector2 &self, Vector2 &other);

}

#endif //MATH_LIB_VECTOR2_H
