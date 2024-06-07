/**
 *
 */

#include "icmp.h"
#include "ip.h"

int parse_icmp(void *p, int len)
{
    IcmpStruct *icmp = (IcmpStruct *)p;

    if (0 != get_ip_checksum(p, len))
    {
        return -1;
    }

    switch (icmp->Type)
    {
    case IcmpEchoRequest:
        break;
    case IcmpUnreachable:
        break;
    case IcmpCongestion:
        break;
    case IcmpRedirection:
        break;
    case IcmpEchoResponse:
        break;
    case IcmpTimeExceeded:
        break;
    case IcmpBadIpHeadr:
        break;
    default:
        break;
    }
}
