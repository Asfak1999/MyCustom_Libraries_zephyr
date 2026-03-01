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

uint16_t writeData;
uint16_t readData;

int main(void)
{


	eepromInit(&eeprom , &i2c_dev);

	writeData = 1200;
	
	eepromWrite16(&eeprom, &writeData, 0x0002);
	eepromRead16(&eeprom, &readData, 0x0002);
	eepromFullErase(&eeprom);
	eepromRead16(&eeprom, &readData, 0x0002);


	while(1){
		k_msleep(1000);
	}



	return 0;
}
