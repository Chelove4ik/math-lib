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
}//namespace mml
