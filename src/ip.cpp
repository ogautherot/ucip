/**
 *
 */

#include "ip.h"
#include "icmp.h"
#include "tcp.h"
#include "udp.h"

uint8_t NullIpAddr[4] = {0, 0, 0, 0};

/**
 *
 */
int get_ip_checksum(void *ptr, int len_in_bytes)
{
    uint16_t *hdr = (uint16_t *)ptr;
    uint32_t sum = 0;

    while (len_in_bytes > 1)
    {
        sum += *hdr;
        hdr++;
        len_in_bytes -= 2;
    }

    if (1 >= len_in_bytes)
    {
        if (1 == htons(1))
        {
            sum += *hdr & 0xff00;
        }
        else
        {
            sum += (*hdr & 0xff) << 8;
        }
    }

    return ~((sum & 0xffff) + (sum >> 16));
}

/**
 *
 */
int parse_ip_frame(void *ptr)
{
    int ret = 0;
    int len;

    IpHeaderStruct *hdr = (IpHeaderStruct *)ptr;
    if (4 != hdr->Version)
    {
        ret = -1;
    }
    else if (5 != hdr->InternetHeaderLength)
    {
        ret = -1;
    }
    else if (0 != get_ip_checksum(hdr, 4 * hdr->InternetHeaderLength))
    {
        ret = -1;
    }
    else
    {
        len = hdr->TotalLength - sizeof(IpHeaderStruct);
        switch (hdr->Protocol)
        {
        case 1: // ICMP
            return parse_icmp(hdr->Payload, len);
        case 6: // TCP
            return parse_tcp(hdr->Payload, len);
        case 17: // UDP
            return parse_udp(hdr->Payload, len);
        }
    }
    return ret;
}
