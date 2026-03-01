/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AT24_EEPROM_H_
#define _AT24_EEPROM_H_

#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>


/**
 * @breif EEPROM I2c confuguration 
 */
typedef struct STRUCT_at24_eeprom
{
    const struct i2c_dt_spec *i2c; /* EEPROM i2c Driver struct */

}at24_eeprom_t;





/**
  * @brief EEPROM Error handle enum definition
  */
typedef enum
{
	EEPROM_OK = 0,			/*!< EEPROM Successful operation             */
	EEPROM_INIT_ERROR,		/*!< EEPROM Initialization error             */
	EEPROM_NOT_READY,		/*!< EEPROM Device status		             */
	EEPROM_WRITE_ERROR,		/*!< EEPROM Write Memory Error               */
	EEPROM_READ_ERROR,		/*!< EEPROM Read Memory Error                */
	EEPROM_NOT_ERASE		/*!< EEPROM Read Memory Error                */

}EEPROM_ErrorHandle_t;





void eepromInit(at24_eeprom_t *config, const struct i2c_dt_spec *dev);
void eepromRead8(at24_eeprom_t *config, uint8_t *data, uint16_t memAddr);
void eepromWrite8(at24_eeprom_t *config, uint8_t *data, uint16_t memAddr);
void eepromWrite16(at24_eeprom_t *config, uint16_t *data, uint16_t memAddr);
void eepromRead16(at24_eeprom_t *config, uint16_t *data, uint16_t memAddr);
void eepromFullErase(at24_eeprom_t *config);
#endif

