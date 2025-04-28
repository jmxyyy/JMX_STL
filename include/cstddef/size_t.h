#ifndef _CSTDDEF_SIZE_T_H
#define _CSTDDEF_SIZE_T_H

namespace jmx {
    using size_t = decltype(sizeof(int));
}

#endif