#include <ssd1315.h>
#include "stm32h7b0xx.h"
#include "i2c.h"

// ssd1315 frame buffer
static uint8_t GDDRAM[SSD1315_COLUMN_SIZE + 16][SSD1315_PAGE_SIZE];

int ssd1315_init()
{
    HAL_Delay(100);
    ssd1315_send_cmd(CMD_NOP);
    ssd1315_set_display_status(DISPLAY_OFF);

    ssd1315_send_cmd(CMD_PAGE_LOW_ADDRESS);
    ssd1315_send_cmd(CMD_PAGE_HIGH_ADDRESS);
    ssd1315_send_cmd(0x00);
    ssd1315_set_page_start_addr(PAGE0_START_ADDRESS);
    ssd1315_set_contrast_ratio(0xF0);
    ssd1315_send_cmd(0xA1);
    ssd1315_set_display_mode(DISPLAY_NORMAL);

    ssd1315_set_com_scan(COM_REMAP_SCAN);
    ssd1315_set_display_offset(0x00);
    ssd1315_set_display_clk(0x80);
    ssd1315_set_pre_charge_time(0x1F);

    ssd1315_set_mux_rate(0x3F);
    // set COM pins
    ssd1315_send_cmd(0xDA);
    ssd1315_send_cmd(0x12);

    // set Vcom
    ssd1315_send_cmd(0xDB);
    ssd1315_send_cmd(0x40);
    // set charge pump enable
	ssd1315_send_cmd(0x8d);
	ssd1315_send_cmd(0x14);
    ssd1315_set_display_status(DISPLAY_ON);
    return 0;
}

void ssd1315_set_mux_rate(uint8_t rate)
{
    ssd1315_send_cmd(0xA8);
    ssd1315_send_cmd(rate);
}

void ssd1315_seg_map(uint8_t rule)
{
    switch (rule) {
    case COL0_MAP_TO_SEG0: ssd1315_send_cmd(rule);
    case COL127_MAP_TO_SEG0: ssd1315_send_cmd(rule);
    }
}

int ssd1315_send_cmd(uint8_t value)
{
    uint8_t msg[2];

    msg[0] = SSD1315_COMMAND_MODE;
    msg[1] = value;

    HAL_I2C_Master_Transmit(&hi2c1,SSD1315_I2C_ADDR , 
                    msg, sizeof(msg), SSD1315_I2C_TIMEOUT);
	
		return 0;
}

int ssd1315_send_data(uint8_t value)
{
    return 0;
}

void ssd1315_set_com_scan(uint8_t mode)
{
    switch (mode) {
    case COM_NORMAL_SCAN: ssd1315_send_cmd(mode);
    case COM_REMAP_SCAN: ssd1315_send_cmd(mode);
    }
}

void ssd1315_set_display_mode(uint8_t mode)
{
    switch (mode) {
    case DISPLAY_NORMAL: ssd1315_send_cmd(mode);
    case DISPLAY_REVERSE: ssd1315_send_cmd(mode);
    }
}

void ssd1315_set_display_offset(uint8_t offset)
{
    ssd1315_send_cmd(0xD3);
    ssd1315_send_cmd(offset);
}

void ssd1315_set_display_status(uint8_t status)
{
    switch (status) {
    case DISPLAY_ON: ssd1315_send_cmd(status);
    case DISPLAY_OFF: ssd1315_send_cmd(status);
    }
}

int ssd1315_set_contrast_ratio(uint8_t ratio)
{
    if (ratio > 0xFF || ratio < 0x01)
        return 1;

    ssd1315_send_cmd(0x81);
    ssd1315_send_cmd(ratio);

    return 0;
}

void ssd1315_set_page_start_addr(uint8_t addr)
{
    switch (addr) {
    case PAGE0_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE1_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE2_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE3_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE4_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE5_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE6_START_ADDRESS: ssd1315_send_cmd(addr);
    case PAGE7_START_ADDRESS: ssd1315_send_cmd(addr);
    }
}

void ssd1315_set_display_clk(uint8_t osc)
{
    ssd1315_send_cmd(0xD5);
    ssd1315_send_cmd(osc);
}

void ssd1315_set_pre_charge_time(uint8_t dclk)
{
    ssd1315_send_cmd(0xD9);
    ssd1315_send_cmd(dclk);
}
