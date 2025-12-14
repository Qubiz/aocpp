module;

#include <algorithm>
#include <cstdint>

export module qubiz.core:types;

export namespace qubiz {
    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using usize = std::size_t;

    using i8 = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;
    using isize = std::size_t;

    using f32 = float;
    using f64 = double;

    using byte = u8;

    template<typename T, typename Tag>
    struct StrongType {
        using tag = Tag;

        T value;

        StrongType() = default;
        explicit constexpr StrongType(const T& v) : value(v) {}
        explicit constexpr StrongType(T&& v) : value(std::move(v)) {}

        // Allow explicit access to the underlying value
        [[nodiscard]] constexpr T& get() noexcept { return value; }
        [[nodiscard]] constexpr const T& get() const noexcept { return value; }

        // Comparison operators
        auto operator<=>(const StrongType&) const = default;
    };
}