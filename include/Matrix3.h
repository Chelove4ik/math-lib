#ifndef MATH_LIB_MATRIX3_H
#define MATH_LIB_MATRIX3_H

#include "Vector3.h"

namespace mml {
    class Matrix3 {
     public:
        Matrix3(const Vector3 &x, const Vector3 &y, const Vector3 &z);

        explicit Matrix3(const float arr[9]);

        Matrix3() = default;

        Vector3 &operator[](int index);

        const Vector3 &operator[](int index) const;

        Matrix3 operator+(const Matrix3 &other);

        Matrix3 operator-(const Matrix3 &other);

        Matrix3 operator*(float num);

        Matrix3 operator*(const Matrix3 &other);

        Matrix3 transpose();

        float det() const;

        Matrix3 inverse() const;

     private:
        Vector3 data[3];
    };

}//namespace mml
#endif //MATH_LIB_MATRIX3_H
