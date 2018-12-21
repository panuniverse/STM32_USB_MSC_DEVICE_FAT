#include "FAT16.h"


uint8_t fat_buffer[FAT_SIZE];

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
  memcpy(fat_buffer + blk_addr,buf,blk_len);
  return 0;
}
