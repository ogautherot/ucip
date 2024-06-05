/** ICMP support
 * Encapsulated in IP frames
 *
 */

#ifndef __UCIPLIB_ICMP_H__
#define __UCIPLIB_ICMP_H__

#include <stdint.h>

enum IcmpCodeType
{
    IcmpEchoRequest = 0,
    IcmpUnreachable = 3,
    IcmpCongestion = 4,
    IcmpRedirection = 5,
    IcmpEchoResponse = 8,
    IcmpTimeExceeded = 11,
    IcmpBadIpHeadr = 12
};

typedef struct __attribute__((__packed__)) IcmpStruct
{
    uint8_t Type;
    uint8_t Code;
    uint16_t CheckSum;
} IcmpStruct;

#endif // __UCIPLIB_ICMP_H__
