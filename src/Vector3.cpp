#include <cmath>
#include <stdexcept>
#include "Vector3.h"

namespace mml {

    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {

    }

    Vector3 Vector3::operator+(Vector3 &other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 Vector3::operator-() const {
        return {-x, -y, -z};
    }

    Vector3 Vector3::operator-(Vector3 &other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 Vector3::operator*(float num) const {
        return {x * num, y * num, z * num};
    }

    Vector3 Vector3::operator/(float num) const {
        return {x / num, y / num, z / num};
    }

    float Vector3::operator[](int index) const {
        if (index < 0 || index > 2)
            throw std::out_of_range("index must be in range [0,2]");
        switch (index) {
            default:
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
        }
    }

    float Vector3::scalar_product(Vector3 &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::vector_product(Vector3 &other) const {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
    }

    float Vector3::len() const {
        return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
    }

    Vector3 Vector3::normalize() const {
        return *this / this->len();
    }
}