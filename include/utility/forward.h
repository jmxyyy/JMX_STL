#ifndef _UTILITY_FORWARD_H
#define _UTILITY_FORWARD_H

#include <__type_traits/is_reference.h>
#include <__type_traits/remove_reference.h>

namespace jmx {

  template <typename Tp>
  [[__nodiscard__]] inline constexpr Tp&&
  _forward(std::__libcpp_remove_reference_t<Tp>& t) noexcept {
    return static_cast<Tp&&>(t);
  }

  template <typename Tp>
  [[__nodiscard__]] inline constexpr Tp&&
  _forward(std::__libcpp_remove_reference_t<Tp>&& t) noexcept {
    static_assert(!std::is_lvalue_reference_v<Tp>, "cannot forward an rvalue as an lvalue");
    return static_cast<Tp&&>(t);
  }

} // namespace jmx

#endif