/** IP packets support
 * Encapsulated in Ethernet frames
 * Protocol field in Ethernet packet should be 0x800
 */

#ifndef __UCIPLIB_IP_H__
#define __UCIPLIB_IP_H__

#include <stdint.h>

#include "defs.h"

/** Local variable store
 *
 */
typedef struct __attribute__((__packed__)) ArpCacheStruct
{
    uint32_t IpAddr;
    uint8_t Mac[6];
    uint8_t reserved[2]; // Padding
} ArpCacheStruct;

typedef struct __attribute__((__packed__)) LocalIpVarStruct
{
    uint8_t IpAddr[4]; // Local IP address
    uint8_t Mac[6];    // Ethernet MAC addres, may be removed in the future
} LocalIpVarStruct;

/* ******** Protocol structure ******** */

static inline CopyMac(void *dest, void *src)
{
    *RAW_POINTER(uint32_t, dest, 0) = *RAW_POINTER(uint32_t, src, 0);
    *RAW_POINTER(uint16_t, dest, 4) = *RAW_POINTER(uint16_t, src, 4);
}

/** IP packet header
 *
 */
typedef struct __attribute__((packed)) IpHeaderStruct
{
    uint8_t Version : 4;              // 4 for IPv4
    uint8_t InternetHeaderLength : 4; // Typically 5 for IPv4
    uint8_t TypeOfService;            // Deprecated
    uint16_t TotalLength;             // Length of IP packet
    uint16_t Identification;          // Kind of random number
    uint8_t flags : 3;                // Fragmentation not supported
    uint16_t FragmentOffset : 13;     // Offset in packet, should be 0
    uint8_t TimeToLive;               // Default to 64
    uint8_t Protocol;                 // 1 for ICMP, 6 for TCP, 17 for UDP
    uint16_t HeaderChecksum;          // Relatively simple sum
    uint8_t SourceAddress[4];         // IP address
    uint8_t DestinationAddress[4];    // IP address
    uint8_t Payload[];
} IpHeaderStruct;

extern uint8_t NullIpAddr[4];

int parse_ip_frame(void *ptr);
int get_ip_checksum(void *hdr, int len_in_bytes);

#endif // __UCIPLIB_IP_H__
