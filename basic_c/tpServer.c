#include <stdio.h>

void main ()
{
  int fd;
  int opt = 1;
  /*create socket */
  if (fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP) == -1 )
  {
    perror ("socket creation error \n");
    exit (1);
  }
  /* set socket option
   * opt: is a flag which tells is the third arg 
   * is enabled or disabled
   * SO_REUSEADDR = sys/socket.h
   * many other options are there too */
  if (-1 == setsockopt (fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)))
  {
    perror ("setSockeOpt error \n");
    /* causes the shell executing this program
     * to exit with status 1, if 1 is not specified 
     * it can exit with the status of the last command executed
     * */
    exit (1);
  }
   
  fcntl (fd, F_SETFL, O_NONBLOCK);
  struct sockaddr_in s;
  s.sin_family = AF_INET;
  s.sin_addr = inet_addr ("127.0.0.1");
  s.sin_port = htons (75);
  memset(&s.sin_zero, 0, 8);

  if (bind (fd, &s, sizeof(s)) < 0)
    perror ("ERROR: bind");

  listen (fd, 5);
 
  accept ();





}
