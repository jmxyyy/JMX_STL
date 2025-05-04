#ifndef _TUPLE_IGNORE_H
#define _TUPLE_IGNORE_H

namespace jmx {

  // cxx11
  struct _ignore_type {
    template <typename Tp>
    constexpr const _ignore_type& operator=(const Tp&) const noexcept {
      return *this;
    }
  };

  inline constexpr _ignore_type ignore;

} // namespace jmx

#endif