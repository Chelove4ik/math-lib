include_directories(${math_lib_SOURCE_DIR}/include/)
add_executable(test test.cpp)
target_link_libraries(test math_lib)
