#ifndef BENBEN_ARM_IO_H
#define BENBEN_ARM_IO_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__write_once__)
#define __write_once__
#define WRITE_ONCE(var ,v) do { \
        typeof(var) __val = v;  \
        __atomic_store_n(&var, __val, __ATOMIC_RELAXED) }
#else
#define WRITE_ONCE(var, v)     ((var) = (v))
#endif // __GNUC__


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_ARM_IO_H