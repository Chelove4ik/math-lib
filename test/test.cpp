#include "Vector2.h"

#include <iostream>
#include <cassert>

void test_vec2();

int main() {
    std::cout << "test" << std::endl;

    test_vec2();

    return 0;
}

#define IF_FALSE_RET(x) if (!(x)) return false

bool operator==(mml::Vector2 &self, mml::Vector2 &other) {
    IF_FALSE_RET(self.x == other.x);
    IF_FALSE_RET(self.y == other.y);
    return true;
}

void test_vec2() {
    using vec2 = mml::Vector2;

    {
        auto a = vec2(1, 3);
        auto b = vec2(5, 55);
        assert(a.x == 1);
        assert(a.y == 3);
        assert(b.x == 5);
        assert(b.y == 55);
    }
    {
        auto a = vec2(1, 3);
        auto b = vec2(5, 55);
        auto c = a + b;
        auto ans = vec2(6, 58);
        assert(c == ans);
    }
    {
        auto a = vec2(1, 3);
        auto b = vec2(5, 55);
        auto c = a - b;
        auto ans = vec2(-4, -52);
        assert(c == ans);
    }
    {
        auto a = vec2(1, 3);
        auto c = a * 3;
        auto ans = vec2(3, 9);
        assert(c == ans);
    }
}