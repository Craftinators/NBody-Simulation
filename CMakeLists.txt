cmake_minimum_required(VERSION 3.31)
project(NBody_Simulation)

set(CMAKE_CXX_STANDARD 20)
set(SPDLOG_COMPILE_LIB ON)

add_subdirectory(external/spdlog)
add_subdirectory(external/linmath)

add_executable(NBody_Simulation src/main.cpp)

target_include_directories(NBody_Simulation PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/linmath
)

target_precompile_headers(NBody_Simulation PRIVATE <linmath.h>)

target_link_libraries(NBody_Simulation PRIVATE spdlog::spdlog linmath)