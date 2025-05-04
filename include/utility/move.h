#ifndef _UTILITY_MOVE_H
#define _UTILITY_MOVE_H

#include <__type_traits/conditional.h>
#include <__type_traits/is_constructible.h>
#include <__type_traits/is_nothrow_constructible.h>
#include <__type_traits/remove_reference.h>

namespace jmx {

  template <class Tp>
  [[__nodiscard__]] inline constexpr std::__libcpp_remove_reference_t<Tp>&&
  move(Tp&& t) noexcept {
    using Up = std::__libcpp_remove_reference_t<Tp>;
    return static_cast<Up&&>(t);
  }

  template <class Tp>
  using _move_if_noexcept_result_t =
      std::__conditional_t<!std::is_nothrow_move_constructible_v<Tp> &&
                               std::is_copy_constructible_v<Tp>,
                           const Tp&, Tp&&>;

  template <class Tp>
  [[__nodiscard__]] inline constexpr _move_if_noexcept_result_t<Tp>
  move_if_noexcept(_LIBCPP_LIFETIMEBOUND Tp& x) noexcept {
    return move(x);
  }

} // namespace jmx

#endif