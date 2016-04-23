#include <stdio.h>

int main (int argc, char **argv)
{
  char *name = argv[0];
  int child_pid = fork ();
  if (child_pid == 0)
  {
     printf ("Child running %s pid %d \n",name, child_pid);
     return 0;
  } 
  else 
  {
     printf ("Parent running %s ppid %d \n",name, child_pid);
     return 0;
  }

}
