#ifndef FAT16_H
#define FAT16_H

#include "main.h"
#include "stm32l4xx_hal.h"

#define STORAGE_LUN_NBR                  1

#define DEVICE_FLASH_SECTOR_COUNT        256 // set secrot count.
#define DEVICE_SPI_FLASH_SECTOR_SIZE     512 //define sector size.

#define STORAGE_BLK_NBR                  DEVICE_FLASH_SECTOR_COUNT
#define STORAGE_BLK_SIZ                  DEVICE_SPI_FLASH_SECTOR_SIZE


#define FAT_SIZE (DEVICE_FLASH_SECTOR_COUNT * DEVICE_SPI_FLASH_SECTOR_SIZE)
extern uint8_t fat_buffer[FAT_SIZE];

uint32_t Device_Init();


uint32_t _ReadSector(uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);



uint32_t _WriteSector(const uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);


#endif