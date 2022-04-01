include_directories(${math_lib_SOURCE_DIR}/include/)
add_library(math_lib library.cpp)
target_compile_definitions(math_lib PUBLIC BUILD_LIB)
