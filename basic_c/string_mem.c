#include <stdio.h>
#include <assert.h>

/* To include bzero declaration, we include the header  */
/* To include strxxx declaration, we include the header */
#include <string.h>

/* To include calloc declaration, we include the header */
#include <stdlib.h>

void main (int argc, char**argv)
{
char a[100], *b;
char **mystr = NULL;
bzero((void*)a,100); //first argument is a void *
b = NULL;
if (argc>1)
 puts("you have entered something \n");

//b  = *argv[1]; 
//OR can use strcpy();
// gonna comment assert from here, as if b is null it simply terminates 
// the whole program and leaves me nothing ... :( 
// assert(b);

while (argc--) {
if (!b) {
puts("something is wrong ! \n");
assert(argv[1]);
b = (char *)(calloc (sizeof(char), strlen(argv[1])));
}
assert(b);
strcpy(b, argv[1]); 

printf("hoplazooh %s \n",b);

mystr[argc] = b;
}

}
