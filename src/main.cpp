// ReSharper disable once CppUnusedIncludeDirective
#include "linmath_fmt.h"

#include <spdlog/spdlog.h>
#include <linmath.h>

int main() {
    spdlog::info("Hello, World!");
    constexpr vec2 v = { 1.0f, 2.0f };
    spdlog::info(v);
}
