#include "library.h"

#include <iostream>

extern "C" {
LIB_CLASS void hello() {
    std::cout << "Hello, World!" << std::endl;
}
}