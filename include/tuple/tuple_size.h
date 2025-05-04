#ifndef _TUPLE_TUPLE_SIZE_H
#define _TUPLE_TUPLE_SIZE_H

#include <__type_traits/is_const.h>
#include <__type_traits/is_volatile.h>

#include "../cstddef.h"
#include "../fwd/tuple.h"
#include "../type_traits/enable_if.h"
#include "../type_traits/integral_constant.h"
#include "./tuple_types.h"

namespace jmx {

  template <typename Tp> struct tuple_size;

  // cxx11
  template <typename Tp, typename...> using _enable_if_tuple_size_imp = Tp;

  template <typename Tp>
  struct tuple_size<_enable_if_tuple_size_imp<
      const Tp, enable_if_t<!std::is_volatile_v<Tp>>,
      integral_constant<size_t, sizeof(tuple_size<Tp>)>>>
      : public integral_constant<size_t, tuple_size<Tp>::value> {};

  template <typename Tp>
  struct tuple_size<_enable_if_tuple_size_imp<
      volatile Tp, enable_if_t<!std::is_const_v<Tp>>,
      integral_constant<size_t, sizeof(tuple_size<Tp>)>>>
      : public integral_constant<size_t, tuple_size<Tp>::value> {};

  template <typename Tp>
  struct tuple_size<_enable_if_tuple_size_imp<
      const volatile Tp, integral_constant<size_t, sizeof(tuple_size<Tp>)>>>
      : public integral_constant<size_t, tuple_size<Tp>::value> {};

  template <typename... Tp>
  struct tuple_size<tuple<Tp...>>
      : public integral_constant<size_t, sizeof...(Tp)> {};

  template <typename... Tp>
  struct tuple_size<_tuple_types<Tp...>>
      : public integral_constant<size_t, sizeof...(Tp)> {};

  // cxx17
  template <typename Tp>
  inline constexpr size_t tuple_size_v = tuple_size<Tp>::value;

} // namespace jmx

#endif