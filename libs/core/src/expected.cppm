module;

#include <expected>

export module qubiz.core:expected;

namespace qubiz {
    struct ok_default {
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() const // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_default_constructible_v<T> || std::is_void_v<T>)
            requires(std::is_void_v<T> || std::default_initializable<T>) {
            return std::expected<T, E>{};
        }
    };

    template<class V>
    struct ok_value {
        V v;

        // rvalue path
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() && // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_constructible_v<T, V &&>)
            requires std::constructible_from<T, V &&> {
            return std::expected<T, E>{std::move(v)};
        }

        // lvalue/const path
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() const & // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_constructible_v<T, const V &>)
            requires std::constructible_from<T, const V &> {
            return std::expected<T, E>{v};
        }
    };

    struct err_default {
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() const // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_default_constructible_v<E>)
            requires std::default_initializable<E> {
            return std::unexpected<E>{E{}};
        }
    };

    template<class EV>
    struct err_value {
        EV e;

        // rvalue path
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() && // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_constructible_v<E, EV &&>)
            requires std::constructible_from<E, EV &&> {
            return std::unexpected<E>{std::move(e)};
        }

        // lvalue/const path
        template<class T, class E>
        // ReSharper disable once CppNonExplicitConversionOperator
        constexpr operator std::expected<T, E>() const & // NOLINT(*-explicit-constructor, *-explicit-conversions)
            noexcept(std::is_nothrow_constructible_v<E, const EV &>)
            requires std::constructible_from<E, const EV &> {
            return std::unexpected<E>{e};
        }
    };
}

export namespace qubiz {
    [[nodiscard]] constexpr auto ok() noexcept {
        return ok_default{};
    }

    template<class V>
    [[nodiscard]] constexpr auto ok(V &&v) noexcept {
        return ok_value<std::decay_t<V> >{std::forward<V>(v)};
    }

    [[nodiscard]] constexpr auto err() noexcept {
        return err_default{};
    }
    template<class E>
    [[nodiscard]] constexpr auto err(E &&e) noexcept {
        return err_value<std::decay_t<E> >{std::forward<E>(e)};
    }

    template<typename T, typename E>
    constexpr auto get_expected_value(std::expected<T, E> &&e) noexcept -> T {
        if constexpr (std::is_void_v<T>) {
            return;
        } else {
            return std::move(e).value();
        }
    }
}
