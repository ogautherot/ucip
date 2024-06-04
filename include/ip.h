/** IP packets support
 * Encapsulated in Ethernet frames
 * Protocol field in Ethernet packet should be 0x800
 */

#include <stdint.h>

/** Local variable store
 *
 */
typedef struct __attribute__((__packed__)) LocalIpVarStruct
{
    uint8_t IpAddr[4]; // Local IP address
    uint8_t Mac[6];    // Ethernet MAC addres, may be removed in the future
} LocalIpVarStruct;

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
} IpHeaderStruct;

extern uint8_t NullIpAddr[4];
