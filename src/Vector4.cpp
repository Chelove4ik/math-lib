#include <cmath>
#include <stdexcept>
#include "Vector4.h"

namespace mml {
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {

    }

    Vector4 Vector4::operator+(const Vector4 &other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Vector4 Vector4::operator-() const {
        return {-x, -y, -z, -w};
    }

    Vector4 Vector4::operator-(const Vector4 &other) const {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Vector4 Vector4::operator*(float num) const {
        return {x * num, y * num, z * num, w * num};
    }

    Vector4 Vector4::operator/(float num) const {
        return {x / num, y / num, z / num, w / num};
    }
    float Vector4::operator[](int index) const {
        if (index < 0 || index > 3)
            throw std::out_of_range("index must be in range [0,3]");
        switch (index) {
            default:
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
        }
    }

    float Vector4::scalar_product(const Vector4 &other) const {
        Vector4 temp{x * other.x, y * other.y, z * other.z, w * other.w};
        return (temp.x + temp.y) + (temp.z + temp.w);
    }

    float Vector4::len() const {
        Vector4 temp{*this};
        return sqrtf(scalar_product(temp));
    }

    Vector4 Vector4::normalize() const {
        return *this / this->len();
    }

}//namespace mml