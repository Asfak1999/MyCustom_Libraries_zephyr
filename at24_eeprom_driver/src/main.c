/*
 * Copyright (c) 2025-2026 Mohamed Ashfak
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <at24_eeprom.h>


#define EEPROM_NODE DT_NODELABEL(at24_eeprom)
static const struct i2c_dt_spec i2c_dev = I2C_DT_SPEC_GET(EEPROM_NODE);

at24_eeprom_t eeprom;

uint8_t writeData;
uint8_t readData;

int main(void)
{


	eepromInit(&eeprom , &i2c_dev);

	writeData = 45;
	eepromWrite8(&eeprom, &writeData, 0x0000);
	eepromRead8(&eeprom, &readData, 0x0000);


	while(1){
		k_msleep(1000);
	}



	return 0;
}
