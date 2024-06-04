/**
 *
 */

#include "ip.h"

uint8_t NullIpAddr[4] = {0, 0, 0, 0};

int get_ip_checksum(void *ptr, int len_in_bytes)
{
    uint16_t *hdr;
    uint16_t sum = 0;

    while (len_in_bytes > 0)
    {
        sum += *hdr;
        hdr++;
        len_in_bytes -= 2;
    }
    return sum;
}

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
            break;
        case 6: // TCP
            break;
        case 17: // UDP
            break;
        }
    }
    return ret;
}
