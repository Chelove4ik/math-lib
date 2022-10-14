#include "Matrix3.h"
#include <stdexcept>

namespace mml {
    Matrix3::Matrix3(const Vector3 &x, const Vector3 &y, const Vector3 &z) : data{x, y, z} {

    }

    Matrix3::Matrix3(const float arr[9]) : data{{arr[0], arr[1], arr[2]},
                                                {arr[3], arr[4], arr[5]},
                                                {arr[6], arr[7], arr[8]}} {

    }

    Vector3 &Matrix3::operator[](int index) {
        if (index < 0 || index > 2)
            throw std::out_of_range("index must be in range [0,2]");
        return data[index];
    }

    const Vector3 &Matrix3::operator[](int index) const {
        if (index < 0 || index > 2)
            throw std::out_of_range("index must be in range [0,2]");
        return data[index];
    }

    Matrix3 Matrix3::operator+(const Matrix3 &other) {
        Matrix3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix3 Matrix3::operator-(const Matrix3 &other) {
        Matrix3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix3 Matrix3::operator*(float num) {
        Matrix3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[i][j] * num;
            }
        }
        return result;
    }

    Matrix3 Matrix3::operator*(const Matrix3 &other) {
        Matrix3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    result.data[j][i] += data[k][i] * other.data[j][k];
                }
            }
        }

        return result;
    }

    Matrix3 Matrix3::transpose() {
        Matrix3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }

    float Matrix3::det() const {
        return (data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2])
                - data[1][0] * (data[0][1] * data[2][2] - data[2][1] * data[0][2])
                + data[2][0] * (data[0][1] * data[1][2] - data[1][1] * data[0][2]));
    }

    Matrix3 Matrix3::inverse() const {
        float determinant = this->det();
        if (determinant == 0) {
            throw std::runtime_error("Can't invert a matrix with a determinant of 0");
        }

        Matrix3 result;
        float one_div_det  = 1.0f / determinant;

        result[0][0] = + (data[1][1] * data[2][2] - data[2][1] * data[1][2]) * one_div_det;
        result[1][0] = - (data[1][0] * data[2][2] - data[2][0] * data[1][2]) * one_div_det;
        result[2][0] = + (data[1][0] * data[2][1] - data[2][0] * data[1][1]) * one_div_det;
        result[0][1] = - (data[0][1] * data[2][2] - data[2][1] * data[0][2]) * one_div_det;
        result[1][1] = + (data[0][0] * data[2][2] - data[2][0] * data[0][2]) * one_div_det;
        result[2][1] = - (data[0][0] * data[2][1] - data[2][0] * data[0][1]) * one_div_det;
        result[0][2] = + (data[0][1] * data[1][2] - data[1][1] * data[0][2]) * one_div_det;
        result[1][2] = - (data[0][0] * data[1][2] - data[1][0] * data[0][2]) * one_div_det;
        result[2][2] = + (data[0][0] * data[1][1] - data[1][0] * data[0][1]) * one_div_det;

        return result;
    }


}//namespace mml
