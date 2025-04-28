# JMX_STL

based on llvm:release/20.x libc++

-std=c++23

简化clang stl, 提高可读性

由于 type_trait, utility 等包含编译器开洞, 暂时使用std替代

一概不考虑对旧标准兼容, 以最新特性为基准

## TODO_LIST

- [] include
    - [] cstddef
        - [x] size_t
        - [x] ptrdiff_t
        - [x] nullptr_t
        - [] max_align_t
        - [] byte
    - [] concepts // cxx20 引入, 存在开洞, 搁置
    - [] iterator
        - [x] access
        - [x] readable_traits
    - [] fwd  // 向前声明
        - [x] array
        - [x] tuple
        - [x] pair
