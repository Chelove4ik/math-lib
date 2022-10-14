#ifndef MATH_LIB_MATRIX4_H
#define MATH_LIB_MATRIX4_H

#include "Vector3.h"
#include "Vector4.h"

namespace mml {
    class Matrix4 {
     public:
        Matrix4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w);

        explicit Matrix4(const float arr[16]);

        Matrix4() = default;

        Vector4 &operator[](int index);

        const Vector4 &operator[](int index) const;

        Matrix4 operator+(const Matrix4 &other);

        Matrix4 operator-(const Matrix4 &other);

        Matrix4 operator*(float num);

        Matrix4 operator*(const Matrix4 &other);

        Matrix4 transpose();

        float det() const;

        Matrix4 inverse() const;

     private:
        Vector4 data[4];
    };


    LIB_CLASS Matrix4 translate(const Vector3 &vec);

    LIB_CLASS Matrix4 scale(const Vector3 &vec);

    LIB_CLASS Matrix4 rotate(const Vector3 &vec, float a);

    LIB_CLASS Matrix4 model(Matrix4 translate, const Matrix4 &rotate, const Matrix4 &scale);

    LIB_CLASS Matrix4 view(const Vector3 &from, const Vector3 &to, const Vector3 &worldUp);

    LIB_CLASS Matrix4 ortho(float left, float right, float bottom, float top, float near, float far);

    LIB_CLASS Matrix4 perspective(float fov, float aspect, float near, float far);

}//namespace mml

#endif //MATH_LIB_MATRIX4_H
