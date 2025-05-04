#ifndef _UTILITY_INTEGER_SEQUENCE_H
#define _UTILITY_INTEGER_SEQUENCE_H

#include "../cstddef.h"

#include <__type_traits/is_integral.h>

namespace jmx {

    template <size_t...>
    struct _tuple_indices;

    template <typename IdxType, IdxType... Values>
    struct _integer_sequence {
        template <template <typename OIdxType, OIdxType...> typename ToIdxSeq, typename ToIdxType>
        using _convert = ToIdxSeq<ToIdxType, Values...>;

        template <size_t Sp>
        using _to_tuple_indices = _tuple_indices<(Values + Sp)...>;
    };

    // TODO: has_builtin

    // cxx14
    template <typename Tp, Tp... Ip>
    struct integer_sequence {
        typedef Tp value_type;
        static_assert(std::is_integral_v<Tp>, "integer_sequence can only be instantiated with an integral type");
        
        static constexpr size_t _size() noexcept {
            return sizeof...(Ip);
        }
    };
}

#endif