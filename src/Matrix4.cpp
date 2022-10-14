#include "Matrix4.h"
#include "Vector3.h"
#include <stdexcept>
#include <cmath>

namespace mml {
    Matrix4::Matrix4(const Vector4 &x, const Vector4 &y, const Vector4 &z, const Vector4 &w) : data{x, y, z, w} {

    }

    Matrix4::Matrix4(const float arr[16]) : data{{arr[0],  arr[1],  arr[2],  arr[3]},
                                                 {arr[4],  arr[5],  arr[6],  arr[7]},
                                                 {arr[8],  arr[9],  arr[10], arr[11]},
                                                 {arr[12], arr[13], arr[14], arr[15]}} {

    }

    Vector4 &Matrix4::operator[](int index) {
        if (index < 0 || index > 3)
            throw std::out_of_range("index must be in range [0,3]");
        return data[index];
    }

    const Vector4 &Matrix4::operator[](int index) const {
        if (index < 0 || index > 3)
            throw std::out_of_range("index must be in range [0,3]");
        return data[index];
    }

    Matrix4 Matrix4::operator+(const Matrix4 &other) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix4 Matrix4::operator-(const Matrix4 &other) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix4 Matrix4::operator*(float num) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.data[i][j] = data[i][j] * num;
            }
        }
        return result;
    }

    Matrix4 Matrix4::operator*(const Matrix4 &other) {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    result.data[j][i] += data[k][i] * other.data[j][k];
                }
            }
        }
        return result;
    }

    Matrix4 Matrix4::transpose() {
        Matrix4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    float Matrix4::det() const {
        return
                data[0][3] * data[1][2] * data[2][1] * data[3][0] - data[0][2] * data[1][3] * data[2][1] * data[3][0] -
                data[0][3] * data[1][1] * data[2][2] * data[3][0] + data[0][1] * data[1][3] * data[2][2] * data[3][0] +
                data[0][2] * data[1][1] * data[2][3] * data[3][0] - data[0][1] * data[1][2] * data[2][3] * data[3][0] -
                data[0][3] * data[1][2] * data[2][0] * data[3][1] + data[0][2] * data[1][3] * data[2][0] * data[3][1] +
                data[0][3] * data[1][0] * data[2][2] * data[3][1] - data[0][0] * data[1][3] * data[2][2] * data[3][1] -
                data[0][2] * data[1][0] * data[2][3] * data[3][1] + data[0][0] * data[1][2] * data[2][3] * data[3][1] +
                data[0][3] * data[1][1] * data[2][0] * data[3][2] - data[0][1] * data[1][3] * data[2][0] * data[3][2] -
                data[0][3] * data[1][0] * data[2][1] * data[3][2] + data[0][0] * data[1][3] * data[2][1] * data[3][2] +
                data[0][1] * data[1][0] * data[2][3] * data[3][2] - data[0][0] * data[1][1] * data[2][3] * data[3][2] -
                data[0][2] * data[1][1] * data[2][0] * data[3][3] + data[0][1] * data[1][2] * data[2][0] * data[3][3] +
                data[0][2] * data[1][0] * data[2][1] * data[3][3] - data[0][0] * data[1][2] * data[2][1] * data[3][3] -
                data[0][1] * data[1][0] * data[2][2] * data[3][3] + data[0][0] * data[1][1] * data[2][2] * data[3][3];

    }

    Matrix4 Matrix4::inverse() const {
        float determinant = det();
        if (determinant == 0) {
            throw std::runtime_error("Can't invert a matrix with a determinant of 0");
        }
        Matrix4 result{
                {//0

                        data[1][1] * data[2][2] * data[3][3] -
                        data[1][1] * data[2][3] * data[3][2] -
                        data[2][1] * data[1][2] * data[3][3] +
                        data[2][1] * data[1][3] * data[3][2] +
                        data[3][1] * data[1][2] * data[2][3] -
                        data[3][1] * data[1][3] * data[2][2],

                        -data[0][1] * data[2][2] * data[3][3] +
                        data[0][1] * data[2][3] * data[3][2] +
                        data[2][1] * data[0][2] * data[3][3] -
                        data[2][1] * data[0][3] * data[3][2] -
                        data[3][1] * data[0][2] * data[2][3] +
                        data[3][1] * data[0][3] * data[2][2],

                        data[0][1] * data[1][2] * data[3][3] -
                        data[0][1] * data[1][3] * data[3][2] -
                        data[1][1] * data[0][2] * data[3][3] +
                        data[1][1] * data[0][3] * data[3][2] +
                        data[3][1] * data[0][2] * data[1][3] -
                        data[3][1] * data[0][3] * data[1][2],

                        -data[0][1] * data[1][2] * data[2][3] +
                        data[0][1] * data[1][3] * data[2][2] +
                        data[1][1] * data[0][2] * data[2][3] -
                        data[1][1] * data[0][3] * data[2][2] -
                        data[2][1] * data[0][2] * data[1][3] +
                        data[2][1] * data[0][3] * data[1][2]

                },
                {//1

                        -data[1][0] * data[2][2] * data[3][3] +
                        data[1][0] * data[2][3] * data[3][2] +
                        data[2][0] * data[1][2] * data[3][3] -
                        data[2][0] * data[1][3] * data[3][2] -
                        data[3][0] * data[1][2] * data[2][3] +
                        data[3][0] * data[1][3] * data[2][2],

                        data[0][0] * data[2][2] * data[3][3] -
                        data[0][0] * data[2][3] * data[3][2] -
                        data[2][0] * data[0][2] * data[3][3] +
                        data[2][0] * data[0][3] * data[3][2] +
                        data[3][0] * data[0][2] * data[2][3] -
                        data[3][0] * data[0][3] * data[2][2],

                        -data[0][0] * data[1][2] * data[3][3] +
                        data[0][0] * data[1][3] * data[3][2] +
                        data[1][0] * data[0][2] * data[3][3] -
                        data[1][0] * data[0][3] * data[3][2] -
                        data[3][0] * data[0][2] * data[1][3] +
                        data[3][0] * data[0][3] * data[1][2],

                        data[0][0] * data[1][2] * data[2][3] -
                        data[0][0] * data[1][3] * data[2][2] -
                        data[1][0] * data[0][2] * data[2][3] +
                        data[1][0] * data[0][3] * data[2][2] +
                        data[2][0] * data[0][2] * data[1][3] -
                        data[2][0] * data[0][3] * data[1][2]

                },
                {//2

                        data[1][0] * data[2][1] * data[3][3] -
                        data[1][0] * data[2][3] * data[3][1] -
                        data[2][0] * data[1][1] * data[3][3] +
                        data[2][0] * data[1][3] * data[3][1] +
                        data[3][0] * data[1][1] * data[2][3] -
                        data[3][0] * data[1][3] * data[2][1],

                        -data[0][0] * data[2][1] * data[3][3] +
                        data[0][0] * data[2][3] * data[3][1] +
                        data[2][0] * data[0][1] * data[3][3] -
                        data[2][0] * data[0][3] * data[3][1] -
                        data[3][0] * data[0][1] * data[2][3] +
                        data[3][0] * data[0][3] * data[2][1],

                        data[0][0] * data[1][1] * data[3][3] -
                        data[0][0] * data[1][3] * data[3][1] -
                        data[1][0] * data[0][1] * data[3][3] +
                        data[1][0] * data[0][3] * data[3][1] +
                        data[3][0] * data[0][1] * data[1][3] -
                        data[3][0] * data[0][3] * data[1][1],

                        -data[0][0] * data[1][1] * data[2][3] +
                        data[0][0] * data[1][3] * data[2][1] +
                        data[1][0] * data[0][1] * data[2][3] -
                        data[1][0] * data[0][3] * data[2][1] -
                        data[2][0] * data[0][1] * data[1][3] +
                        data[2][0] * data[0][3] * data[1][1]

                },
                {//3

                        -data[1][0] * data[2][1] * data[3][2] +
                        data[1][0] * data[2][2] * data[3][1] +
                        data[2][0] * data[1][1] * data[3][2] -
                        data[2][0] * data[1][2] * data[3][1] -
                        data[3][0] * data[1][1] * data[2][2] +
                        data[3][0] * data[1][2] * data[2][1],

                        data[0][0] * data[2][1] * data[3][2] -
                        data[0][0] * data[2][2] * data[3][1] -
                        data[2][0] * data[0][1] * data[3][2] +
                        data[2][0] * data[0][2] * data[3][1] +
                        data[3][0] * data[0][1] * data[2][2] -
                        data[3][0] * data[0][2] * data[2][1],

                        -data[0][0] * data[1][1] * data[3][2] +
                        data[0][0] * data[1][2] * data[3][1] +
                        data[1][0] * data[0][1] * data[3][2] -
                        data[1][0] * data[0][2] * data[3][1] -
                        data[3][0] * data[0][1] * data[1][2] +
                        data[3][0] * data[0][2] * data[1][1],

                        data[0][0] * data[1][1] * data[2][2] -
                        data[0][0] * data[1][2] * data[2][1] -
                        data[1][0] * data[0][1] * data[2][2] +
                        data[1][0] * data[0][2] * data[2][1] +
                        data[2][0] * data[0][1] * data[1][2] -
                        data[2][0] * data[0][2] * data[1][1]

                }
        };
        float one_div_det = 1.0f / determinant;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = result[i][j] * one_div_det;
            }
        }

        return result;
    }

    Matrix4 translate(const Vector3 &vec) {
        Matrix4 result;
        result[0][0] = 1;
        result[1][1] = 1;
        result[2][2] = 1;
        result[3][3] = 1;
        result[0][3] = vec.x;
        result[1][3] = vec.y;
        result[2][3] = vec.z;
        return result.transpose();
    }

    Matrix4 scale(const Vector3 &vec) {
        Matrix4 result;
        result[0][0] = vec.x;
        result[1][1] = vec.y;
        result[2][2] = vec.z;
        result[3][3] = 1;
        return result;
    }

    Matrix4 rotate(const Vector3 &vec, float a) {
        if (vec.len() == 0) {
            Matrix4 result;
            result[0][0] = 1;
            result[1][1] = 1;
            result[2][2] = 1;
            result[3][3] = 1;
            return result;
        } else {
            Vector3 R = vec.normalize();
            float c = cosf(a);
            float s = sinf(a);

            Matrix4 result{
                    {c + R.x * R.x * (1 - c),       R.x * R.y * (1 - c) - R.z * s, R.x * R.z * (1 - c) + R.y * s, 0},
                    {R.y * R.x * (1 - c) + R.z * s, c + R.y * R.y * (1 - c),       R.y * R.z * (1 - c) - R.x * s, 0},
                    {R.z * R.x * (1 - c) - R.y * s, R.z * R.y * (1 - c) + R.x * s, c + R.z * R.z * (1 - c),       0},
                    {0,                             0,                             0,                             1}
            };
            return result.transpose();
        }
    }

    Matrix4 model(Matrix4 translate, const Matrix4 &rotate, const Matrix4 &scale) {
        return translate * rotate * scale;
    }

    Matrix4 view(const Vector3 &from, const Vector3 &to, const Vector3 &worldUp) {
        Vector3 forward = mml::forward(from, to);
        Vector3 right = normalize(vector_product(forward, worldUp));
        Vector3 up = normalize(vector_product(right, forward));

        Matrix4 result{
                {right[0],                     up[0],                     -forward[0],                   0},
                {right[1],                     up[1],                     -forward[1],                   0},
                {right[2],                     up[2],                     -forward[2],                   0},
                {-scalar_product(right, from), -scalar_product(up, from), scalar_product(forward, from), 1}
        };
        return result;
    }

    Matrix4 ortho(float left, float right, float bottom, float top, float near, float far) {
        Matrix4 result;
        result[0][0] = 2 / (right - left);
        result[1][1] = 2 / (top - bottom);
        result[2][2] = -2 / (far - near);
        result[3][0] = -(right + left) / (right - left);
        result[3][1] = -(top + bottom) / (top - bottom);
        result[3][2] = -(far + near) / (far - near);
        result[3][3] = 1;
        return result;
    }

    Matrix4 perspective(float fov, float aspect, float near, float far) {
        Matrix4 result;
        float tfov = tanf(fov / 2);
        result[0][0] = 1 / (tfov * aspect);
        result[1][1] = 1 / tfov;
        result[2][2] = -(far + near) / (far - near);
        result[2][3] = -1;
        result[3][2] = -2 * far * near / (far - near);
        return result;
    }
}//namespace mml
