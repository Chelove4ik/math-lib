include_directories(${math_lib_SOURCE_DIR}/include/)
add_executable(test test.cpp)
target_link_libraries(test math_lib)

# download glm
include(ExternalProject)
ExternalProject_Add(glm
        GIT_REPOSITORY  https://github.com/g-truc/glm.git
        GIT_TAG         0.9.9.8
        PREFIX          ${math_lib_SOURCE_DIR}/libs/glm
        BINARY_DIR      ${math_lib_BINARY_DIR}/glm
        GIT_SHALLOW     true
        GIT_PROGRESS    true
        UPDATE_COMMAND  ""
        BUILD_COMMAND   ""
        INSTALL_COMMAND ""
        )

ExternalProject_Get_Property(glm SOURCE_DIR)
target_include_directories(test PRIVATE ${SOURCE_DIR})
add_dependencies(test glm)