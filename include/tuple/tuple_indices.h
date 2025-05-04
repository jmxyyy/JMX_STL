#ifndef _TUPLE_TUPLE_INDICES_H
#define _TUPLE_TUPLE_INDICES_H

#include "../cstddef.h"

#include <__utility/integer_sequence.h>

namespace jmx {

    template <size_t...>
    struct _tuple_indices {};

    template <size_t Ep, size_t Sp = 0>
    struct _make_tuple_indices {
        static_assert(Sp <= Ep, "_make_tuple_indices input error");

        typedef _make_tuple_indices<Ep, Sp> type;
    };
    
}

#endif