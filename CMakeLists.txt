cmake_minimum_required(VERSION 3.31)
project(NBody_Simulation)

set(CMAKE_CXX_STANDARD 20)
set(SPDLOG_COMPILE_LIB ON)
set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/glad)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw)
add_subdirectory(external/spdlog)
add_subdirectory(external/linmath)

add_library(glad ${GLAD_DIR}/src/gl.c)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/linmath
        ${GLAD_DIR}/include
)

target_precompile_headers(${PROJECT_NAME} PRIVATE <linmath.h>)

target_link_libraries(${PROJECT_NAME} PRIVATE
        OpenGL::GL
        glfw
        glad
        spdlog::spdlog
        linmath
)