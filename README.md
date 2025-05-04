# JMX_STL

based on llvm:release/20.x libc++

-std=c++23

简化clang stl, 提高可读性

由于 type_trait, utility 等包含编译器开洞, 暂时使用std替代

一概不考虑对旧标准兼容, 以最新特性为基准

对于隐藏abi, 为简洁性不添加宏, 变量名使用下划线开头修饰

## TODO_LIST
- [] include
    - [] cstddef
        - [x] size_t
        - [x] ptrdiff_t
        - [x] nullptr_t
        - [] max_align_t
        - [] byte
    - [] type_traits
        - [x] integral_constant
        - [x] enable_if
    - [] fwd
        - [x] memory
        - [x] array
        - [x] tuple
        - [x] pair
    - [] utility
        - [x] move
        - [x] forward
    - [] iterator
        - [x] access
        - [x] readable_traits

## 已知需build in
- type_traits
    - is_xxx
- memory
    - addressof