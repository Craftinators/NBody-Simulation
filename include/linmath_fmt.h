#pragma once

#include <spdlog/fmt/fmt.h>
#include <linmath.h>

namespace fmt {
template<>
struct formatter<vec2> {
    static constexpr auto parse(const format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const vec2& v, FormatContext& ctx) const -> decltype(ctx.out()) {
        return format_to(ctx.out(), "[{:.3f}, {:.3f}]", v[0], v[1]);
    }
};

template<>
struct formatter<vec3> {
    static constexpr auto parse(const format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const vec3& v, FormatContext& ctx) const -> decltype(ctx.out()) {
        return format_to(ctx.out(), "[{:.3f}, {:.3f}, {:.3f}]", v[0], v[1], v[2]);
    }
};

template<>
struct formatter<vec4> {
    static constexpr auto parse(const format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const vec4& v, FormatContext& ctx) const -> decltype(ctx.out()) {
        return format_to(ctx.out(), "[{:.3f}, {:.3f}, {:.3f}, {:.3f}]", v[0], v[1], v[2], v[3]);
    }
};
}