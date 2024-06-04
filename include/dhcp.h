/** DHCP support
 * Encapsulated in UDP frames
 *
 */

#include <stdint.h>

#include "ip.h"

enum DhcpMessageType
{
    DhcpDiscover = 1,
    DhcpOffer = 2,
    DhcpRequest = 3,
    DhcpDecline = 4,
    DhcpAck = 5,
    DhcpNak = 6,
    DhcpRelease = 7,
    DhcpInform = 8,
    DhcpForceRenew = 9,
    DhcpLeaseQuery = 10,
    DhcpLeaseUnassigned = 11,
    DhcpLeaseUnknown = 12,
    DhcpLeaseActive = 13,
    DhcpBulkLeaseQuery = 14,
    DhcpLeaseQueryDone = 15,
    DhcpActiveLeaseQuery = 16,
    DhcpLeaseQueryStatus = 17,
    DhcpTls = 18
};

/**
 *
 */
typedef struct __attribute__((__packed__)) DhcpStruct
{
    uint8_t op;           // 1 for request, 2 for response
    uint8_t htype;        // See ArpHardwareType in ip.h
    uint8_t hlen;         // Length of hardware address
    uint8_t hops;         // Number of relay agents between host and client
    uint32_t xid;         // Transaction ID, random number
    uint16_t secs;        // Reserved
    uint16_t flags;       // 0x8000 if broadcast
    uint8_t ciaddr[4];    // Client IP address (0.0.0.0 if not known)
    uint8_t yiaddr[4];    // 'Your' IP address, sent by server
    uint8_t siaddr[4];    // Server IP address
    uint8_t giaddr[4];    // First relay agent IP address
    uint8_t chaddr[16];   // Client hardware address (MAC)
    uint8_t sname[64];    // Server host name
    uint8_t file[128];    // Boot file name
    uint8_t options[340]; // Optional
} DhcpStruct;
