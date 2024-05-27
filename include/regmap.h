#ifndef BENBEN_REGMAP_H
#define BENBEN_REGMAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <types.h>

#ifndef NULL
#define NULL                   ((void *)0)
#endif // NULL

#ifndef __mem
#define __mem                  volatile
#endif // __mem

#if __GNUC__ && !defined(__write_once__)
#define __write_once__
#define WRITE_ONCE(var ,v) do { \
        typeof(var) __val = v;  \
        __atomic_store_n(&var, __val, __ATOMIC_RELAXED) }
#else
#define WRITE_ONCE(var, v)     ((var) = (v))
#endif // __GNUC__

#define __REGMAP(bit) \
static inline __mem u##bit \
*regmap##bit(unsigned long addr, int offset) \
{ \
    __mem u##bit *reg; \
    reg = (u##bit *)(addr + offset); \
    return reg; \
}
__REGMAP(8)
__REGMAP(16)
__REGMAP(32)

// 怎么会有这种无语的函数！！！
// 你冒昧吗
// 怎么读不上来
#define __READ(bit, type) \
static inline u##bit \
read##type(__mem u##bit *addr) \
{ \
    return *addr; \
}
__READ(8, b)
__READ(16, w)
__READ(32, l)

#define __WRITE(bit, type) \
static inline void \
write##type(__mem u##bit *addr, u##bit value) \
{ \
    WRITE_ONCE(*addr, value); \
}
__WRITE(8, b)
__WRITE(16, w)
__WRITE(32, l)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_REGMAP_H
