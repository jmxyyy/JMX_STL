#ifndef _ITERATOR_ACCESS_H
#define _ITERATOR_ACCESS_H

// NOTE: 提供对iterator的首尾迭代器获取

#include "../cstddef/size_t.h"

namespace jmx {

    template <typename Tp, size_t Np>
    constexpr Tp* begin(Tp(&array)[Np]) noexcept {
        return array; // 底层内存使用数组
    }

    template <typename Tp, size_t Np>
    constexpr Tp* end(Tp(&array)[Np]) noexcept {
        return array + Np;
    }

    // cxx11 自动推导
    template <typename Cp>
    constexpr auto begin(Cp& c) -> decltype(c.begin()) {
        return c.begin();
    }

    template <typename Cp>
    constexpr auto begin(const Cp& c) -> decltype(c.begin()) {
        return c.begin();
    }

    template <typename Cp>
    constexpr auto end(Cp& c) -> decltype(c.end()) {
        return c.end();
    }

    template <typename Cp>
    constexpr auto end(const Cp& c) -> decltype(c.end()) {
        return c.end();
    }

    // cxx14 提供std::begin通用迭代器函数
    template <typename Cp>
    constexpr auto cbegin(const Cp& c) noexcept(noexcept(begin(c))) -> decltype(begin(c)) {
        return begin(c);
    }

    template <typename Cp>
    constexpr auto cend(const Cp& c) noexcept(noexcept(end(c))) -> decltype(end(c)) {
        return end(c);
    }

}

#endif