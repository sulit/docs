#include <stdio.h>
#include <stdlib.h>

// the code from libGeoIP

int GeoIP_is_private_ipnum_v4(unsigned long ipnum) {
    return ((ipnum >= 167772160U && ipnum <= 184549375U) ||
            (ipnum >= 2851995648U && ipnum <= 2852061183U) ||
            (ipnum >= 2886729728U && ipnum <= 2887778303U) ||
            (ipnum >= 3232235520U && ipnum <= 3232301055U) ||
            (ipnum >= 2130706432U && ipnum <= 2147483647U))
               ? 1
               : 0;
}

unsigned long GeoIP_addr_to_num(const char *addr) {
    unsigned int c, octet, t;
    unsigned long ipnum;
    int i = 3;

    octet = ipnum = 0;
    while ((c = *addr++)) {
        if (c == '.') {
            if (octet > 255) {
                return 0;
            }
            ipnum <<= 8;
            ipnum += octet;
            i--;
            octet = 0;
        } else {
            t = octet;
	    // 下面三行是乘10操作
            octet <<= 3;
            octet += t;
            octet += t;
            c -= '0';
            if (c > 9) {
                return 0;
            }
            octet += c;
        }
    }
    if ((octet > 255) || (i != 0)) {
        return 0;
    }
    ipnum <<= 8;
    return ipnum + octet;
}

int GeoIP_is_private_v4(const char *addr) {
    unsigned long ipnum = GeoIP_addr_to_num(addr);
    return GeoIP_is_private_ipnum_v4(ipnum);
}

int main (int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s [ipaddr]\n", argv[0]);
		exit(1);
	}

	if(GeoIP_is_private_v4(argv[1]))
		printf("%s is IPv4 private address\n", argv[1]);
	else
		printf("%s is not IPv4 private address\n", argv[1]);

	return 0;
}
