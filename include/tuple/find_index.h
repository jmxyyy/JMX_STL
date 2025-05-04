#ifndef _TUPLE_FIND_INDEX_H
#define _TUPLE_FIND_INDEX_H

#include "../cstddef.h"

#include <__type_traits/is_same.h>

namespace jmx {

    namespace _find_detail {

        static constexpr size_t not_find = static_cast<size_t>(-1); // 利用下溢转化为最大无符号数
        static constexpr size_t ambiguous = not_find - 1;

        inline constexpr size_t _find_idx_return(size_t curr_i, size_t res, bool matches) {
            return !matches? res: (res == not_find? curr_i: ambiguous);
        }

        template <size_t Nx>
        inline constexpr size_t _find_idx(size_t i, const bool (&matches)[Nx]) {
            return i == Nx? not_find: _find_idx_return(i, _find_idx(i + 1, matches), matches[i]);
        }

        template <typename T1, typename... Args>
        struct find_exactly_one_checked {
            static constexpr bool matches[sizeof...(Args)] = {std::is_same_v<T1, Args>...};
            static constexpr size_t value = _find_idx(0, matches);

            static_assert(value != not_find, "type not find");
            static_assert(value != ambiguous, "type occurs more than once");
        };

        template <typename T1>
        struct find_exactly_one_checked<T1> {
            static_assert(!std::is_same_v<T1, T1>, "type not in empty type list");
        };

    }

    template <typename T1, typename... Args>
    struct find_exactly_one_t: public _find_detail::find_exactly_one_checked<T1, Args...> {};

}

#endif