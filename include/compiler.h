#ifndef BENBEN_COMPILER_GCC_BUILTIN_H
#define BENBEN_COMPILER_GCC_BUILTIN_H


#ifdef __cplusplus
extern "C" {
#endif

#define GCC_C99_VERSION         199901L
#define GCC_C11_VERSION         201112L

#if __STDC_VERSION__ >= 201112L \
    && __STDC__

#define static_assert_nmsg(cond) _Static_assert(cond, "")
#define static_assert(cond, msg) _Static_assert(cond, msg)

#endif // 201112L

/* GCC extension */
#if __GNUC__

#define STRINGIFY(x)            #x
#define CONCAT(v1, v2)          v1 ## v2

#ifndef __typeof__
#define __typeof__
#define typeof(v)               typeof(v)
#endif // __typeof__

#define __weak                  __attribute__((__weak__))

#define __noreturn              __attribute__((__noreturn__))

#define __unused                __attribute__((__unused__))

#define __flatten			    __attribute__((flatten))

#define __malloc                __attribute__((__malloc__))

#define __cold                  __attribute__((__cold__))

#define __used                  __attribute__((__used__))

#define __pure                  __attribute__((__pure__))

#define __packed                __attribute__((__packed__))

#define __const                 __attribute__((__const__))

#define __cleanup(func)			__attribute__((__cleanup__(func)))

#define __always_inline         inline __attribute__((__always_inline__))

#define __alloc_size__(x, ...)  __attribute__((__alloc_size__(x, ## __VA_ARGS__)))

#define __printf(a, b)          __attribute__((__format__(printf, a, b)))

#define __scanf(a, b)           __attribute__((__format__(scanf, a, b)))

#define __alias(symbol)         __attribute__((__alias__(#symbol)))

#define __aligned(x)            __attribute__((__aligned__(x)))

#define __aligned_largest       __attribute__((__aligned__))

#define noinline              __attribute__((__noinline__))

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_COMPILER_GCC_BUILTIN_H