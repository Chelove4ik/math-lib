include_directories(${math_lib_SOURCE_DIR}/include/)
add_library(math_lib STATIC Vector2.cpp Vector3.cpp Vector4.cpp)
target_compile_definitions(math_lib PUBLIC BUILD_LIB)
