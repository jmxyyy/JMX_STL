#ifndef _FWD_PAIR_H
#define _FWD_PAIR_H

#include "../cstddef/size_t.h"
#include "./tuple.h"

namespace jmx {
    template <typename, typename>
    struct pair;

    template <size_t Ip, typename T1, typename T2>
    constexpr typename tuple_element<Ip, pair<T1, T2>>::type& get(pair<T1, T2>&) noexcept;

    template <size_t Ip, typename T1, typename T2>
    constexpr const typename tuple_element<Ip, pair<T1, T2>>::type& get(const pair<T1, T2>&) noexcept;

    template <size_t Ip, typename T1, typename T2>
    constexpr typename tuple_element<Ip, pair<T1, T2>>::type&& get(pair<T1, T2>&&) noexcept;

    template <size_t Ip, typename T1, typename T2>
    constexpr const typename tuple_element<Ip, pair<T1, T2>>::type&& get(const pair<T1, T2>&&) noexcept;
}

#endif