#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

/** whois client 
 *  whois service allows a client on one machine to obtain information 
 *  about a user on remote machine */

/** input argument has to be remote machine host name and user-name */
int main (int argc, char **argv)
{
    char *remHostName, *userName = NULL;
	struct hostent *hp = NULL;
	struct servent *sp = NULL;
	struct sockaddr_in sa;
	int fd = 0;
	int len = 0;
	char buf[100];

	if (argc != 3)
	{
		fprintf (stderr," Incorrect input values \n");
		exit(1);
	}

	remHostName = argv[1];
	userName    = argv[2];

	/** get the ip address for the remote host name */
	if ((hp = gethostbyname (remHostName)) == NULL )
	{
		fprintf (stderr, "No such host name exists \n");
		exit(1);
	}
	
	strcpy ((char *)hp->h_addr, (char *)&sa.sin_addr) ;
	sa.sin_family = hp->h_addrtype; 
	
    /** check the whois service port number */
	if ((sp = getservbyname ("whois","tcp")) == NULL)
	{
		fprintf (stderr, "No such service name exists \n");
		exit(1);
	}
   
	sa.sin_port = htons (sp->s_port);

	/** open a tcp socket */
	if (( fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		fprintf (stderr, "Error: unable to open socket \n");
		exit(1);
	}

	if (connect (fd, &sa, sizeof(sa)) < 0)
	{
		fprintf (stderr, "Error: unable to connect to server \n");
		exit(1);
	}

	if (write (fd, userName, strlen (userName)) != strlen (userName))
	{
		fprintf (stderr, "Error: unable to connect to server \n");
		exit(1);
	}

	/** wait for resp, read it and close */
	while (1)
	{
	 	if (read (fd, buf, 100) > 0 )
		{
			printf ("server: %s", buf);
			break;
		}
	}
	close (fd);
	exit(0);
	
}
