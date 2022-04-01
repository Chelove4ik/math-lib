include_directories(${math_lib_SOURCE_DIR}/include/)
link_directories(${math_lib_SOURCE_DIR}/src)
add_executable(test test.cpp)
target_link_libraries(test math_lib)
