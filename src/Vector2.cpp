#include "Vector2.h"

namespace mml {
    Vector2::Vector2(float x, float y) : x(x), y(y) {

    }

    Vector2 Vector2::operator+(Vector2 &other) const {
        return {this->x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-() const {
        return {-x, -y};
    }

    Vector2 Vector2::operator-(Vector2 &other) const {
        return {this->x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(float num) const {
        return {this->x * num, y * num};
    }

    float Vector2::scalar_product(Vector2 &other) const {
        return this->x * other.x + this->y * other.y;
    }

    Vector2 Vector2::vector_product(Vector2 &other) const {
        return {this->y * other.x, this->x * other.y};
    }

    // ------------------------------------------------------------------------

    float scalar_product(Vector2 &self, Vector2 &other) {
        return self.scalar_product(other);
    }

    Vector2 vector_product(Vector2 &self, Vector2 &other) {
        return self.vector_product(other);
    }

}