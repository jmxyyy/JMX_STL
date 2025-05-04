#ifndef _FWD_ARRAY_H
#define _FWD_ARRAY_H

#include "../cstddef/size_t.h"

#include <type_traits>

namespace jmx {

    template <typename Tp, size_t Size>
    struct array;

    template <typename Tp>
    inline const bool is_std_array_v = false;

    template <typename Tp, size_t Size>
    inline const bool is_std_array_v<array<Tp, Size>> = true;

    template <size_t Ip, typename Tp, size_t Size>
    constexpr Tp& get(array<Tp, Size>&) noexcept;

    template <size_t Ip, typename Tp, size_t Size>
    constexpr const Tp& get(const array<Tp, Size>&) noexcept;

    template <size_t Ip, typename Tp, size_t Size>
    constexpr Tp&& get(array<Tp, Size>&&) noexcept;

    template <size_t Ip, typename Tp, size_t Size>
    constexpr const Tp&& get(const array<Tp, Size>&&) noexcept;

}

#endif