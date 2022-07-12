#include "Matrix4.h"
#include <stdexcept>

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
}//namespace mml
