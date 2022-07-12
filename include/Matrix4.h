#ifndef MATH_LIB_MATRIX4_H
#define MATH_LIB_MATRIX4_H

#include "Vector4.h"

namespace mml {
    class Matrix4 {
     public:
        Matrix4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w);

        explicit Matrix4(const float arr[16]);

        Vector4 &operator[](int index);

        const Vector4 &operator[](int index) const;

     private:
        Vector4 data[4];
    };

}//namespace mml

#endif //MATH_LIB_MATRIX4_H
