/*
 * Copyright (c) 2021-2022 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>


#define EEPROM_NODE DT_NODELABEL(at24_eeprom)
static const struct i2c_dt_spec i2c_dev = I2C_DT_SPEC_GET(EEPROM_NODE);

int ret;


uint8_t writeData = 100;
uint8_t readData;

void eepromWrite8(uint8_t *data){

	uint16_t reg_addr = 0x0000;
	uint8_t txBuffer[3];


	txBuffer[0] = (uint8_t)(reg_addr >> 8);
	txBuffer[1] = (uint8_t)(reg_addr & 0xFF);
	txBuffer[2] = (uint8_t)(*data);
	

	int ret = i2c_write_dt(&i2c_dev, txBuffer, 3);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}
	k_msleep(100);
}

void eepromRead8(uint8_t *data){

	uint16_t reg_addr = 0x0000;
	uint8_t txBuffer[2];


	txBuffer[0] = (uint8_t)(reg_addr >> 8);
	txBuffer[1] = (uint8_t)(reg_addr & 0xFF);
	
	

	int ret = i2c_write_read_dt(&i2c_dev, txBuffer, 2, data, 1);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}
	k_msleep(100);
}



int main(void)
{
	if (!i2c_is_ready_dt(&i2c_dev)) {
		printk("I2C bus is not ready!\n\r");
		return -1;
	}

	
	eepromWrite8(&writeData);

	eepromRead8(&readData);

	while(1){
		k_msleep(1000);
	}



	return 0;
}
