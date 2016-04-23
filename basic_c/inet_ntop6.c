#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdlib.h>


char hex[]="0123456789abcdef";

// assuming only ipv6 address 
char *inet_ntop6 (struct in6_addr *addr, char *dst, socklen_t len)
{
	char tmpBuf[INET6_ADDRSTRLEN] = {0};
	unsigned char nib[2] = {0};
	unsigned int i = 0, j = 0, k = 0;
	bool bColon = 0;
	for (i=0; i < 16; i++)
	{
		nib[0] = addr->s6_addr[i] & 0x0f;
		nib[1] = addr->s6_addr[i] >> 4 ;// & 0xf0;
		tmpBuf[k++] = hex[nib[1]];
		tmpBuf[k++] = hex[nib[0]];
		j = 0;
		bColon = !((k)%4) ? 1 : 0;
		if (bColon)
		{
			tmpBuf[k++] = ':';
			bColon = 0;
		}	
	}
	k++;
	tmpBuf[k] = '\0';
	strcpy (dst, tmpBuf);
	return dst;
}

void main (int argc, char **argv)
{
	if (argc !=2)		
	{
		fprintf (stderr,  "Enter IPv6 address ... \n");
		return 0;
	}
	
	char buf[INET6_ADDRSTRLEN];
	struct in6_addr addr ;
	inet_pton (AF_INET6, argv[1], &addr);
	inet_ntop6 (&addr, buf, INET6_ADDRSTRLEN);
	printf ("IPv6 address entered was : %s\n", buf);
	return 0;	
}
