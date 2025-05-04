#ifndef _TUPLE_TUPLE_ELEMENT_H
#define _TUPLE_TUPLE_ELEMENT_H

#include "../cstddef.h"
#include "./tuple_indices.h"
#include "./tuple_types.h"

namespace jmx {

  template <size_t Ip, typename Tp>
  struct tuple_element;

  template <size_t Ip, typename Tp>
  struct tuple_element<Ip, const Tp> {
    typedef const typename tuple_element<Ip, Tp>::type type;
  };

  template <size_t Ip, typename Tp>
  struct tuple_element<Ip, volatile Tp> {
    typedef volatile typename tuple_element<Ip, Tp>::type type;
  };

  template <size_t Ip, typename Tp>
  struct tuple_element<Ip, const volatile Tp> {
    typedef const volatile typename tuple_element<Ip, Tp>::type type;
  };

  // cxx11
  template <size_t Ip, typename... Types>
  struct tuple_element<Ip, _tuple_types<Types...>> {
    static_assert(Ip < sizeof...(Types), "tuple_element index out of range");

    // BUILD_IN
    typedef __type_pack_element<Ip, Types...> type;
  };

  // cxx14
  template <size_t Ip, typename... Tp>
  using tuple_element_t = typename tuple_element<Ip, Tp...>::type;

} // namespace jmx

#endif