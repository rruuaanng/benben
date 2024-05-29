#ifndef BENBEN_BIT_H
#define BENBEN_BIT_H

#ifdef __cplusplus
extern "C" {
#endif

#define MASK(v, pos)           ((v) << (pos))
#define BIT(pos)               (1U << (pos))

#define WRITE_ONCE(var, v)     ((var) = (v))

#define SET_BIT(addr, mask)    ((addr) |= (mask))
#define RESET_BIT(addr, mask)  ((addr) &= ~(mask))
#define READ_BIT(addr, mask)   ((addr) & (mask))

#define IS_BIT(addr, bit)      READ_BIT(addr, MASK(1, bit))

#define BIT8_FULL_SET_MASK     0x11U
#define BIT16_FULL_SET_MASK    0x1111U
#define BIT32_FULL_SET_MASK    0x11111111U

#define BIT8_FULL_RESET_MASK   0x00U
#define BIT16_FULL_RESET_MASK  0x0000U
#define BIT32_FULL_RESET_MASK  0x00000000U

#define BIT8_LOW(v)            ((v) & 0xFF)
#define BIT16_LOW(V)           ((V) & 0XFFFF)
#define BIT32_LOW(V)           ((V) & 0XFFFFFFFF)

#define BIT8_HIGH(V)           ((V) >> 8)
#define BIT16_HIGH(V)          ((V) >> 16)
#define BIT32_HIGH(V)          ((V) >> 32)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BENBEN_BIT_H
