#ifndef _ITERATOR_READABLE_TRAITS_H
#define _ITERATOR_READABLE_TRAITS_H

#include <concepts>
#include <type_traits>

namespace jmx {

  // 辅助空模板
  template <typename>
  struct cond_value_type {};

  // cond_value_type对object偏特化
  template <typename Tp>
    requires std::is_object_v<Tp> // Tp约束
  struct cond_value_type<Tp> {
    using value_type = std::remove_cv_t<Tp>;
  };

  // concept判断Tp存在value_type类型成员
  template <typename Tp>
  concept has_member_value_type = requires { typename Tp::value_type; };

  // concept判断Tp存在element_type类型成员
  template <typename Tp>
  concept has_member_element_type = requires { typename Tp::element_type; };

  // 主模板, 用于萃取类型间接可读的类型
  template <typename>
  struct indirectly_readable_traits {};

  // 对array特化
  template <typename Ip>
    requires std::is_array_v<Ip>
  struct indirectly_readable_traits<Ip> {
    using value_type = std::remove_cv_t<std::remove_extent_t<Ip>>;
  };

  // const类型特化, 直接继承no const
  template <typename Ip>
  struct indirectly_readable_traits<const Ip> : indirectly_readable_traits<Ip> {
  };

  // 指针特化, 利用cond_value_type, value_type为Tp去除限定符
  template <typename Tp>
  struct indirectly_readable_traits<Tp*> : cond_value_type<Tp> {};

  // 萃取Tp成员value_type
  template <has_member_value_type Tp>
  struct indirectly_readable_traits<Tp>
      : cond_value_type<typename Tp::value_type> {};

  template <has_member_element_type Tp>
  struct indirectly_readable_traits<Tp>
      : cond_value_type<typename Tp::element_type> {};

  template <has_member_value_type Tp>
    requires has_member_value_type<Tp>
  struct indirectly_readable_traits<Tp> {};

  // 针对同时具有element,value,且为相同类型
  // 消除上面萃取成员的歧义
  template <has_member_value_type Tp>
    requires has_member_element_type<Tp> &&
             std::same_as<std::remove_cv_t<typename Tp::element_type>,
                          std::remove_cv_t<typename Tp::value_type>>
  struct indirectly_readable_traits<Tp>
      : cond_value_type<typename Tp::value_type> {};

} // namespace jmx

#endif