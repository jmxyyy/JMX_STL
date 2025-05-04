#ifndef _ITERATOR_INCREMENTABLE_H
#define _ITERATOR_INCREMENTABLE_H

#include "../cstddef.h"

#include <concepts>
#include <type_traits>
#include <utility>

namespace jmx {

  template <typename>
  struct incrementable_traits {};

  template <typename Tp>
    requires std::is_object_v<Tp>
  struct incrementable_traits<Tp*> {
    using difference_type = ptrdiff_t;
  };

  template <typename Ip>
  struct incrementable_traits<const Ip> : incrementable_traits<Ip> {};

  template <typename Tp>
  concept has_member_difference_type =
      requires { typename Tp::difference_type; };

  template <has_member_difference_type Tp>
  struct incrementable_traits<Tp> {
    using difference_type = typename Tp::difference_type;
  };

  template <typename Tp>
  concept has_integral_minus = requires(const Tp& x, const Tp& y) {
    { x - y } -> std::integral;
  };

  template <has_integral_minus Tp>
    requires(!has_member_difference_type<Tp>)
  struct incrementable_traits<Tp> {
    using difference_type =
        std::make_signed_t<decltype(std::declval<Tp>() - std::declval<Tp>())>;
  };

  template <typename>
  struct iterator_traits;

  template <typename Ip>
  using iter_difference_t = typename std::conditional_t<
      bool Bp, incrementable_traits<std::remove_cvref_t<Ip>>,
      iterator_traits<std::remove_cvref_t<Ip>>>::difference_type;

} // namespace jmx

#endif
