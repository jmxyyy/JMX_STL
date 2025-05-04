#ifndef _FWD_TUPLE_H
#define _FWD_TUPLE_H

#include "../cstddef/size_t.h"

namespace jmx {

    template <size_t, typename>
    struct tuple_element;

    template <typename...>
    class tuple;

    template <typename>
    struct tuple_size;

    template <size_t Ip, typename... Tp>
    constexpr typename tuple_element<Ip, Tp...>::type& _get(tuple<Tp...>&) noexcept;

    template <size_t Ip, typename... Tp>
    constexpr const typename tuple_element<Ip, Tp...>::type&& _get(const tuple<Tp...>&&) noexcept;

    template <size_t Ip, typename... Tp>
    constexpr typename tuple_element<Ip, Tp...>::type& _get(tuple<Tp...>&) noexcept;

    template <size_t Ip, typename... Tp>
    constexpr const typename tuple_element<Ip, Tp...>::type&& _get(const tuple<Tp...>&&) noexcept;
}

#endif