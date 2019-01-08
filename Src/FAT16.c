#include "FAT16.h"


uint8_t fat_buffer[FAT_SIZE];

#define SPI_REAL_FLASH_SIZE 4096

__weak uint32_t Device_Init()
{
  //init device SPI_DEVICE device.
}

__weak uint32_t _ReadSector(uint8_t *buf, uint32_t blk_addr, uint16_t blk_len)
{
    memcpy(buf,fat_buffer + blk_addr,blk_len);
    return 0;
}

__weak uint32_t _WriteSector(const uint8_t *buf, uint32_t blk_addr, uint16_t blk_len)
{
  uint32_t spi_real_sector = 0;
  uint32_t offset_sector = 0;
  spi_real_sector = blk_addr / SPI_REAL_FLASH_SIZE;
  offset_sector = (blk_addr % SPI_REAL_FLASH_SIZE) / DEVICE_SPI_FLASH_SECTOR_SIZE;
  _ReadSector(fat_buffer,spi_real_sector * SPI_REAL_FLASH_SIZE,SPI_REAL_FLASH_SIZE);
  memcpy(fat_buffer + offset_sector * DEVICE_SPI_FLASH_SECTOR_SIZE,buf,blk_len);
  memcpy(fat_buffer + blk_addr,buf,blk_len);
  return 0;
}
