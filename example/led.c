#include <io/bit.h>
#include <io/regmap.h>

#define STM32H7_GPIOE_BASE (0x58020000 + 0x1000)
#define GPIO_PIN3          BIT(3)

int main()
{
    __mem u32 *bsrr, *mode, *speed;

	bsrr = regmap32(STM32H7_GPIOE_BASE, 0x18);
	mode = regmap32(STM32H7_GPIOE_BASE, 0x00);
	speed = regmap32(STM32H7_GPIOE_BASE, 0x08);
	
    /* user implement */
	rcc_gpioe_enable();
	
	writel(mode, MASK(1, 6));
	writel(speed, MASK(1, 6));
	writel(bsrr, GPIO_PIN3);
    return 0;
}
