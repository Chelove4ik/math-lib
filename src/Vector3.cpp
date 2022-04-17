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

    float Vector3::scalar_product(Vector3 &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::vector_product(Vector3 &other) const {
        return {y * other.z - other.z * y, z * other.x - other.x * z, x * other.y - other.y * x};
    }

    // ------------------------------------------------------------------------

    float scalar_product(Vector3 &self, Vector3 &other) {
        return self.scalar_product(other);
    }

    Vector3 vector_product(Vector3 &self, Vector3 &other) {
        return self.vector_product(other);
    }
}