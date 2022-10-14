#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"

#include <glm/ext/vector_float2.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float4.hpp>
#include <glm/ext/matrix_float3x3.hpp>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <cassert>
#include <random>

#define LOOPS 1000000

void test_vec2();

void test_vec3();

void test_vec4();

void test_mat3();

void test_mat4();


int main() {
    std::cout << "test" << std::endl;

    test_vec2();
    test_vec3();
    test_vec4();

    test_mat3();
    test_mat4();

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

bool operator==(mml::Matrix3 const &self, glm::mat3 const &other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (abs(self[i][j] - other[i][j]) > powf(10, -3)) {
                return false;
            }
        }
    }
    return true;
}

bool operator==(mml::Matrix4 const &self, glm::mat4 const &other) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (abs(self[i][j] - other[i][j]) > powf(10, -3)) {
                return false;
            }
        }
    }
    return true;
}

template<typename T, typename U>
void test_vec(T my_first, T my_second, U glm_first, U glm_second);

template<typename T, typename U>
void test_mat(T my_mat_1, T my_mat_2, U glm_mat_1, U glm_mat_2);

std::random_device rd;
std::default_random_engine eng(rd());
std::uniform_real_distribution<float> distr(-1000, 1000);

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

void test_mat3() {
    printf("test Matrix3 ... ");

    for (int loop = 0; loop < LOOPS; ++loop) {
        mml::Matrix3 my_mat_1, my_mat_2;
        glm::mat3 glm_mat_1, glm_mat_2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                float temp = distr(eng);
                my_mat_1[i][j] = temp;
                glm_mat_1[i][j] = temp;

                temp = distr(eng);
                my_mat_2[i][j] = temp;
                glm_mat_2[i][j] = temp;
            }
        }

        test_mat(my_mat_1, my_mat_2, glm_mat_1, glm_mat_2);

    }

    printf("done\n");

}

void test_mat4() {
    printf("test Matrix4 ... ");

    for (int loop = 0; loop < LOOPS; ++loop) {
        mml::Matrix4 my_mat_1, my_mat_2;
        glm::mat4 glm_mat_1, glm_mat_2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                float temp = distr(eng);
                my_mat_1[i][j] = temp;
                glm_mat_1[i][j] = temp;

                temp = distr(eng);
                my_mat_2[i][j] = temp;
                glm_mat_2[i][j] = temp;
            }
        }

        test_mat(my_mat_1, my_mat_2, glm_mat_1, glm_mat_2);

        {//матрица переноса
            float temp[3] = {distr(eng), distr(eng), distr(eng)};
            auto my_ans = mml::translate({temp[0], temp[1], temp[2]});
            auto glm_ans = glm::translate(glm::mat4(1.f), {temp[0], temp[1], temp[2]});
            assert(my_ans == glm_ans);
        }
        {//матрица скейла
            float temp[3] = {distr(eng), distr(eng), distr(eng)};
            auto my_ans = mml::scale({temp[0], temp[1], temp[2]});
            auto glm_ans = glm::scale(glm::mat4(1.f), {temp[0], temp[1], temp[2]});
            assert(my_ans == glm_ans);
        }
        {//матрица поворота
            float temp[3] = {distr(eng), distr(eng), distr(eng)};
            float angle = distr(eng);
            auto my_ans = mml::rotate({temp[0], temp[1], temp[2]}, angle);
            auto glm_ans = glm::rotate(glm::mat4(1.f), angle, {temp[0], temp[1], temp[2]});
            assert(my_ans == glm_ans);
        }
        {//матрица модели

        }
        {//матрица view
            float from[3] = {distr(eng), distr(eng), distr(eng)};
            float to[3] = {distr(eng), distr(eng), distr(eng)};
            auto my_ans = mml::view({from[0], from[1], from[2]}, {to[0], to[1], to[2]}, {0, 1, 0});
            auto glm_ans = glm::lookAt(glm::vec3{from[0], from[1], from[2]}, {to[0], to[1], to[2]}, {0, 1, 0});
            assert(my_ans == glm_ans);
        }
        {//ортографическая
            float left = distr(eng);
            float right = distr(eng);
            if (left > right)
                std::swap(left, right);
            float bottom = distr(eng);
            float top = distr(eng);
            if (bottom > top)
                std::swap(bottom, top);
            float near = distr(eng);
            float far = distr(eng);
            if (near > far)
                std::swap(near, far);

            auto my_ans = mml::ortho(left, right, bottom, top, near, far);
            auto glm_ans = glm::ortho(left, right, bottom, top, near, far);
            assert(my_ans == glm_ans);
        }
        {//перспективная
            float fov = distr(eng);
            float aspect = distr(eng);
            float near = distr(eng);
            float far = distr(eng);
            if (near > far)
                std::swap(near, far);
            auto my_ans = mml::perspective(fov, aspect, near, far);
            auto glm_ans = glm::perspective(fov, aspect, near, far);
            assert(my_ans == glm_ans);
        }
    }


    printf("done\n");
}

template<typename T, typename U>
void test_mat(T my_mat_1, T my_mat_2, U glm_mat_1, U glm_mat_2) {
    static_assert(
            std::is_same<T, mml::Matrix3>::value && std::is_same<U, glm::mat3>::value ||
            std::is_same<T, mml::Matrix4>::value && std::is_same<U, glm::mat4>::value,
            "Unsupported types"
    );

    {//+
        auto my_ans = my_mat_1 + my_mat_2;
        auto glm_ans = glm_mat_1 + glm_mat_2;
        assert(my_ans == glm_ans);
    }
    {//-
        auto my_ans = my_mat_1 - my_mat_2;
        auto glm_ans = glm_mat_1 - glm_mat_2;
        assert(my_ans == glm_ans);
    }
    {// mat * mat
        auto my_ans = my_mat_1 * my_mat_2;
        auto glm_ans = glm_mat_1 * glm_mat_2;
        assert(my_ans == glm_ans);
    }
    {// mat * num
        auto my_ans = my_mat_1 * my_mat_2[0][0];
        auto glm_ans = glm_mat_1 * my_mat_2[0][0];
        assert(my_ans == glm_ans);
    }
    {// транспонирование
        auto my_ans = my_mat_1.transpose();
        auto glm_ans = glm::transpose(glm_mat_1);
        assert(my_ans == glm_ans);
    }
    /*
    {//обратная матрица
        if (my_mat_1.det() != 0) {
            auto my_ans = my_mat_1.inverse();
            auto glm_ans = glm::inverse(glm_mat_1);
            assert(my_ans == glm_ans);
        }
    }
    */
}