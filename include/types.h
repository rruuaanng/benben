#ifndef BENBEN_TYPES_H
#define BENBEN_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t                u8;
typedef uint16_t               u16;
typedef uint32_t               u32;
typedef uint64_t               u64;

typedef int8_t                 s8;
typedef int16_t                s16;
typedef int32_t                s32;
typedef int64_t                s64;

typedef float                  float32_t;
typedef double                 float64_t;

#ifndef NULL
#define NULL                   ((void *)0)   /* NULL alias val */
#endif // NULL


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_TYPES_H
