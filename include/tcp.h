/**
 *
 */

#ifndef __UCIPLIB_TCP_H__
#define __UCIPLIB_TCP_H__

#include <stdint.h>

typedef struct __attribute__((__packed__)) TcpStruct
{
    uint16_t SourcePort;
    uint16_t DestPort;
    uint32_t SequenceNumber;  // Sequence number of the first byte of the segment (in bytes)
    uint32_t Acknowledgement; // Sequence number of the next byte expected (acknowledgement for all the previous bytes)
    uint8_t HeaderLength;     // Bits 4 to 7 are reserved and must be null
    struct
    {
        uint8_t : 2;
        uint8_t urg : 1;
        uint8_t ack : 1;
        uint8_t psh : 1;
        uint8_t rst : 1;
        uint8_t syn : 1;
        uint8_t fin : 1;
    } Flags;
    uint16_t Window; // For sliding windows
    uint16_t HeaderChecksum;
    uint16_t Urgent; // Not supported, should be null
    uint8_t Payload[];
} TcpStruct;

#endif // __UCIPLIB_TCP_H__
