#ifndef BENBEN_MATH_H
#define BENBEN_MATH_H


float sin(int deg);

float cos(int deg);

static uint16_t to_q15(float n)
{
    return (uint16_t)(n * (1 << 15))
}

static float q15_to_float(uint16_t n)
{
    return n / 32768.0f;
}

#endif // BENBEN_MATH_H