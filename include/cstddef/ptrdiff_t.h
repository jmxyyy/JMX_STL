#ifndef _CSTDDEF_PRTDIFFF_T_H
#define _CSTDDEF_PRTDIFFF_T_H

namespace jmx {
    using ptrdiff_t = decltype(static_cast<int*>(nullptr) - static_cast<int*>(nullptr));
}

#endif