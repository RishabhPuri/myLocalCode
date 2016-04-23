#include <stdio.h>

/** decode is a pre-processor directive 
 * s,t,u,m,p,e,d are tokens, could have been anything for that matter , like numbers 
 * what decode does is uses ## operator to join 4,1,3,2 argument, and then we passed
 * animate -- m(4),a(1),i(3),n(2)*/

#define decode(s,t,u,m,p,e,d) m##s##u##t
#define begin decode(a,n,i,m,a,t,e)

begin()
{
    printf ("HELLO WORLD \n");
}
