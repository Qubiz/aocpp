module;

export module qubiz.core:optional;

import std;

export namespace qubiz {
    /**
     * @brief Engage an optional with a default-constructed value.
     * @tparam T The value type.
     * @return An optional engaged with a default value of T.
     */
    template<typename T>
    [[nodiscard]] constexpr auto some() noexcept(std::is_nothrow_default_constructible_v<T>) -> std::optional<T>
        requires std::default_initializable<T> {
        return std::optional<T>{std::in_place};
    }

    /**
     * @brief Engage an `optional` with a specific value.
     * @tparam V The value type.
     * @param v The value to store in the optional.
     * @return An optional engaged with the given value.
     */
    template<typename V>
    [[nodiscard]] constexpr auto some(V &&v) noexcept(std::is_nothrow_constructible_v<std::decay_t<V>, V &&>)
        -> std::optional<std::decay_t<V> > {
        using T = std::decay_t<V>;
        return std::optional<T>{std::in_place, std::forward<V>(v)};
    }

    /**
     * Represents an absent value.
     */
    inline constexpr auto none = std::nullopt;
}
