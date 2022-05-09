#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/quaternion_geometric.hpp>

#include <iostream>
#include <cassert>
#include <random>

#define LOOPS 1000000

void test_vec2();

void test_vec3();

void test_vec4();

int main() {
    std::cout << "test" << std::endl;

    test_vec2();
    test_vec3();
    test_vec4();

    return 0;
}

static float eps = powf(10, -6);

bool operator==(mml::Vector2 const &self, glm::vec2 const &other) {
    for (int i = 0; i < 2; ++i) {
        if (std::abs(self[i] - other[i]) > eps)
            return false;
    }
    return true;
}

bool operator==(mml::Vector3 const &self, glm::vec3 const &other) {
    for (int i = 0; i < 3; ++i) {
        if (std::abs(self[i] - other[i]) > eps)
            return false;
    }
    return true;
}

bool operator==(mml::Vector4 const &self, glm::vec4 const &other) {
    for (int i = 0; i < 4; ++i) {
        if (std::abs(self[i] - other[i]) > eps)
            return false;
    }
    return true;
}

template<typename T, typename U>
void test_vec(T my_first, T my_second, U glm_first, U glm_second);

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<float> distr(-10000, 10000);

void test_vec2() {
    printf("test Vector2 ... ");
    for (int i = 0; i < LOOPS; ++i) {
        float a1 = distr(eng), a2 = distr(eng);
        float b1 = distr(eng), b2 = distr(eng);

        mml::Vector2 my_first{a1, a2}, my_second{b1, b2};
        glm::vec2 glm_first{a1, a2}, glm_second{b1, b2};

        {  // basic
            for (int j = 0; j < 2; ++j) {
                assert(my_first[j] == glm_first[j]);
                assert(my_second[j] == glm_second[j]);
            }
        }

        test_vec(my_first, my_second, glm_first, glm_second);  // common test
    }
    printf("done\n");
}

void test_vec3() {
    printf("test Vector3 ... ");

    for (int i = 0; i < LOOPS; ++i) {
        float a1 = distr(eng), a2 = distr(eng), a3 = distr(eng);
        float b1 = distr(eng), b2 = distr(eng), b3 = distr(eng);

        mml::Vector3 my_first{a1, a2, a3}, my_second{b1, b2, b3};
        glm::vec3 glm_first{a1, a2, a3}, glm_second{b1, b2, b3};

        {  // basic
            for (int j = 0; j < 3; ++j) {
                assert(my_first[j] == glm_first[j]);
                assert(my_second[j] == glm_second[j]);
            }

        }

        test_vec(my_first, my_second, glm_first, glm_second);  // common test

        {  // векторное произведение
            assert(mml::vector_product(my_first, my_second) == glm::cross(glm_first, glm_second));
        }
    }
    printf("done\n");
}

void test_vec4() {
    printf("test Vector4 ... ");
    for (int i = 0; i < LOOPS; ++i) {
        float a1 = distr(eng), a2 = distr(eng), a3 = distr(eng), a4 = distr(eng);
        float b1 = distr(eng), b2 = distr(eng), b3 = distr(eng), b4 = distr(eng);

        mml::Vector4 my_first{a1, a2, a3, a4}, my_second{b1, b2, b3, b4};
        glm::vec4 glm_first{a1, a2, a3, a4}, glm_second{b1, b2, b3, b4};

        {  // basic
            for (int j = 0; j < 4; ++j) {
                assert(my_first[j] == glm_first[j]);
                assert(my_second[j] == glm_second[j]);
            }
        }

        test_vec(my_first, my_second, glm_first, glm_second);  // common test
    }
    printf("done\n");
}

template<typename T, typename U>
void test_vec(T my_first, T my_second, U glm_first, U glm_second) {
    static_assert(
            std::is_same<T, mml::Vector2>::value && std::is_same<U, glm::vec2>::value ||
            std::is_same<T, mml::Vector3>::value && std::is_same<U, glm::vec3>::value ||
            std::is_same<T, mml::Vector4>::value && std::is_same<U, glm::vec4>::value,
            "Unsupported types"
    );
    {  // сложение
        auto my_ans = my_first + my_second;
        auto glm_ans = glm_first + glm_second;
        assert(my_ans == glm_ans);
    }
    {  // вычитание
        auto my_ans = my_first - my_second;
        auto glm_ans = glm_first - glm_second;
        assert(my_ans == glm_ans);
    }
    {  // отрицание
        assert(-my_first == -glm_first);
    }
    {  // умножение на число
        float num = 3;
        auto my_ans = my_first * num;
        auto glm_ans = glm_first * num;
        assert(my_ans == glm_ans);
    }
    {  // скалярное произведение
        auto my_ans = mml::scalar_product(my_first, my_second);
        auto glm_ans = glm::dot(glm_first, glm_second);
        assert(my_ans == glm_ans);
    }
    {
        assert(mml::len(my_first) == glm::length(glm_first));
        assert(mml::normalize(my_first) == glm::normalize(glm_first));
    }
}