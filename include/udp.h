/**
 *
 */

#include <stdint.h>

typedef struct __attribute__((__packed__)) UdpStruct
{
    uint16_t SrcPort;
    uint16_t DestPort;
    uint16_t Length;
    uint16_t Checksum;
} UdpStruct;
