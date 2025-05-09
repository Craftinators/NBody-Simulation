cmake_minimum_required(VERSION 3.20)
project(NBody_Simulation VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SPDLOG_COMPILE_LIB ON)
set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/glad)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw)
add_subdirectory(external/spdlog)
add_subdirectory(external/linmath)

add_library(glad ${GLAD_DIR}/src/gl.c)
target_include_directories(glad PUBLIC ${GLAD_DIR}/include)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external/linmath)
target_precompile_headers(${PROJECT_NAME} PRIVATE <linmath.h>)

target_link_libraries(${PROJECT_NAME} PRIVATE
        OpenGL::GL
        glfw
        glad
        spdlog::spdlog
        linmath
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()