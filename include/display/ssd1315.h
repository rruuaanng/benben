#ifndef BENBEN_DISPLAY_SSD1315_H
#define BENBEN_DISPLAY_SSD1315_H

#include <stdint.h>

#define SSD1315_I2C_ADDR                    0x78
#define SSD1315_I2C_TIMEOUT                 0xFF
#define SSD1315_PAGE_SIZE                   8U
#define SSD1315_COLUMN_SIZE                 128U
#define SSD1315_COMMAND_MODE                0x00
#define SSD1315_DATA_MODE                   0x01

#define CMD_NOP                             0xE3
#define CMD_PAGE_LOW_ADDRESS                0x00
#define CMD_PAGE_HIGH_ADDRESS               0x10

#define COM_NORMAL_SCAN                     0xC0
#define COM_REMAP_SCAN                      0xC8
void ssd1315_set_com_scan(uint8_t mode);

#define DISPLAY_NORMAL                      0xA6
#define DISPLAY_REVERSE                     0xA7
void ssd1315_set_display_mode(uint8_t mode);

#define DISPLAY_ON                          0xAF
#define DISPLAY_OFF                         0xAE
void ssd1315_set_display_status(uint8_t status);

int ssd1315_set_contrast_ratio(uint8_t ratio);

#define COL0_MAP_TO_SEG0                    0xA0
#define COL127_MAP_TO_SEG0                  0xA1
void ssd1315_seg_map(uint8_t rule);

#define PAGE0_START_ADDRESS                 0xB0
#define PAGE1_START_ADDRESS                 0xB1
#define PAGE2_START_ADDRESS                 0xB2
#define PAGE3_START_ADDRESS                 0xB3
#define PAGE4_START_ADDRESS                 0xB4
#define PAGE5_START_ADDRESS                 0xB5
#define PAGE6_START_ADDRESS                 0xB6
#define PAGE7_START_ADDRESS                 0xB7
void ssd1315_set_page_start_addr(uint8_t addr);


void ssd1315_set_mux_rate(uint8_t rate);

void ssd1315_set_display_offset(uint8_t offset);

void ssd1315_set_display_clk(uint8_t osc);

void ssd1315_set_pre_charge_time(uint8_t dclk);

int ssd1315_send_cmd(uint8_t value);
int ssd1315_send_data(uint8_t value);
int ssd1315_init(void);



#endif // BENBEN_DISPLAY_SSD1315_H
