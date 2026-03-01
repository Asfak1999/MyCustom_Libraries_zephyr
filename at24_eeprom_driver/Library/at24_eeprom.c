/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "at24_eeprom.h"
#include <stdio.h>


/**
 * @breif eepromInit is initialise the device driver and I2c driver
 * @param i2c_dt_spec *dev pass the pointer to init the driver
 * @returns none
 */

void eepromInit(at24_eeprom_t *config, const struct i2c_dt_spec *dev){
	
	config->i2c = dev;

	if (!i2c_is_ready_dt(config->i2c)) {
		printk("I2C bus is not ready!\n\r");
	}
}


/**
 * @breif 	write 1-Byte of data to the specific address
 * @param	config	pointer to EEPROM configuration with device driver
 * @param	data		pointer to data to be written 
 * @param	memAddr	data memory address of EEPROM
 * @return	none
 * 
 * @note	keep delay 10ms for completion of write operion for EEPROM
 */

void eepromWrite8(at24_eeprom_t *config, uint8_t *data, uint16_t memAddr){

	uint8_t txBuffer[3];


	txBuffer[0] = (uint8_t)(memAddr >> 8);
	txBuffer[1] = (uint8_t)(memAddr & 0xFF);
	txBuffer[2] = (uint8_t)(*data);
	

	int ret = i2c_write_dt(config->i2c, txBuffer, 3);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}
	k_msleep(100);
}


/**
 * @breif	Read 1-Byte of data inside the specific address of EEPROM
 * @param	config	pointer to EEPROM configuration with device driver
 * @param	data	pointer to data to be read from EEPROM
 * @param	memAddr	data memory address of EEPROM
 * @return	none
 */

void eepromRead8(at24_eeprom_t *config, uint8_t *data, uint16_t memAddr){

	uint8_t txBuffer[2];
	txBuffer[0] = (uint8_t)(memAddr >> 8);
	txBuffer[1] = (uint8_t)(memAddr & 0xFF);

	int ret = i2c_write_read_dt(config->i2c, txBuffer, 2, data, 1);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}
	k_msleep(100);
}



/**
 * @breif 	write 2-Byte of data to the specific address
 * @param	config	pointer to EEPROM configuration with device driver
 * @param	data		pointer to data to be written 
 * @param	memAddr	data memory address of EEPROM
 * @return	none
 * 
 * @note	keep delay 10ms for completion of write operion for EEPROM
 */

void eepromWrite16(at24_eeprom_t *config, uint16_t *data, uint16_t memAddr){

	uint8_t txBuffer[4];


	txBuffer[0] = (uint8_t)(memAddr >> 8);
	txBuffer[1] = (uint8_t)(memAddr & 0xFF);
	txBuffer[2] = (uint8_t)(*data >> 8);
	txBuffer[3] = (uint8_t)(*data & 0xFF);
	

	int ret = i2c_write_dt(config->i2c, txBuffer, 4);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}
	k_msleep(100);
}


/**
 * @breif	Read 2-Byte of data inside the specific address of EEPROM
 * @param	config	pointer to EEPROM configuration with device driver
 * @param	data	pointer to data to be read from EEPROM
 * @param	memAddr	data memory address of EEPROM
 * @return	none
 */

void eepromRead16(at24_eeprom_t *config, uint16_t *data, uint16_t memAddr){

	uint8_t txBuffer[2];
	txBuffer[0] = (uint8_t)(memAddr >> 8);
	txBuffer[1] = (uint8_t)(memAddr & 0xFF);

	uint8_t rxBuffer[2];

	int ret = i2c_write_read_dt(config->i2c, txBuffer, 2, rxBuffer, 2);
	if(ret != 0){
		printk("Failed to write/read I2C device address \n\r");
	}

	*data = (rxBuffer[0] << 8) | (rxBuffer[1] & 0xFF);

	k_msleep(100);
}




void eepromFullErase(at24_eeprom_t *config)
{
	uint16_t pageAddr = 0;
	uint8_t pdata[64];

	memset(&pdata, 0xFF, sizeof(pdata));

	for(int pageIndex = 0; pageIndex < 512; pageIndex++)
	{
		pageAddr = (uint16_t)(pageIndex << 6);

		eepromWrite8(config, pdata, pageAddr);

		k_msleep(50);
	}
}