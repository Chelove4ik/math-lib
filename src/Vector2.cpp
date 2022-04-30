#include <cmath>
#include <stdexcept>
#include "Vector2.h"

namespace mml {
    Vector2::Vector2(float x, float y) : x(x), y(y) {

    }

    Vector2 Vector2::operator+(Vector2 &other) const {
        return {x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-() const {
        return {-x, -y};
    }

    Vector2 Vector2::operator-(Vector2 &other) const {
        return {x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(float num) const {
        return {x * num, y * num};
    }

    Vector2 Vector2::operator/(float num) const {
        return {x / num, y / num};
    }
    float Vector2::operator[](int index) const {
        if (index < 0 || index > 1)
            throw std::out_of_range("index must be in range [0,1]");
        switch (index) {
            default:
            case 0:
                return x;
            case 1:
                return y;
        }
    }

    float Vector2::scalar_product(Vector2 &other) const {
        return x * other.x + y * other.y;
    }

    float Vector2::len() const {
        return sqrtf(powf(x, 2) + powf(y, 2));
    }

    Vector2 Vector2::normalize() const {
        return *this / this->len();
    }

}//namespace mml