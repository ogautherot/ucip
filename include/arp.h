/** ARP packet support
 * Encapsulated in Ethernet frames
 * Protocol field in Ethernet packet should be 0x0806
 */

#ifndef __UCIPLIB_ARP_H__
#define __UCIPLIB_ARP_H__

#include <stdint.h>

#include "ip.h"

enum ArpHardwareType
{
    Ethernet = 1,
    Ieee802 = 6,
    Arcnet = 7,
    FrameRelay = 15,
    AsyncTransferMode = 16,
    Hdlc = 17,
    FibreChannel = 18,
    AsyncTransferMode2 = 19,
    SerialLine = 20
};

/**
 * MAC addresses should be shared with the IP driver
 */
typedef struct __attribute__((__packed__)) ArpFrameStruct
{
    uint16_t MacType;      // 0x0001 for Ethernet
    uint16_t NetworkType;  // 0x800 for IP
    uint8_t MacLength;     // 6 for Ethernet
    uint8_t NetworkLength; // 4 for IPv4
    uint8_t operation;     // 1 for request, 2 for response

    uint8_t MacAddrSrc[6];      // Source MAC address
    uint8_t NetworkAddrSrc[4];  // Source IP address
    uint8_t MacAddrDest[6];     // Source MAC address
    uint8_t NetworkAddrDest[4]; // Source IP address
} ArpFrameStruct;

#endif // __UCIPLIB_ARP_H__
