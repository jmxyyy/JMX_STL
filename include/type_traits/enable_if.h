#ifndef _TYPE_TRAITS_ENABLE_IF_H
#define _TYPE_TRAITS_ENABLE_IF_H

// NOTE: 条件编译

namespace jmx {
  // 主模板, 默认无type成员
  template <bool, typename Tp = void>
  struct enable_if {};

  // true特化
  template <typename Tp>
  struct enable_if<true, Tp> {
    using type = Tp;
  };

  // cxx14
  template <bool Bp, typename Tp = void>
  using enable_if_t = typename enable_if<Bp, Tp>::type;

} // namespace jmx

#endif