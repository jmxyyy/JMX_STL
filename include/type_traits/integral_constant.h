#ifndef _TYPE_TRAITS_INTEGRAL_CONSTANT_H
#define _TYPE_TRAITS_INTEGRAL_CONSTANT_H

// NOTE: 编译期常量容器

namespace jmx {

  // Tp: type, v: value
  template <typename Tp, Tp v>
  struct integral_constant {
    static constexpr const Tp value = v; // 存储值
    using value_type = Tp;               // 暴露类型
    using type = integral_constant;

    // 隐式转换
    constexpr operator value_type() const noexcept { return value; }
    // cxx14 函数式访问
    constexpr value_type operator()() const noexcept { return value; }
  };

  template <typename Tp, Tp v>
  constexpr const Tp integral_constant<Tp, v>::value;

  // bool特化
  using true_type = integral_constant<bool, true>;
  using false_type = integral_constant<bool, false>;

  // cxx17
  template <bool b>
  using bool_constant = integral_constant<bool, b>;

} // namespace jmx

#endif