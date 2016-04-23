#include <stdio.h>
#include <stdlib.h>

int magicNumber (int n)
{
	int pow = 1, result = 0;
	while (n)
	{
		pow *= 5;
		
		if (n&1)
			result += pow;
	
		n = n >> 1;
	}
	return result;
}


int nthMagicNo(int n)
{
    int pow = 1, answer = 0;
 
    // Go through every bit of n
    while (n)
    {
       pow = pow*5;
 
       // If last bit of n is set
       if (n & 1)
         answer += pow;
 
       // proceed to next bit
       n >>= 1;  // or n = n/2
    }
    return answer;
}

void main ()
{
	int n;
	scanf ("%d",&n);
	printf ("%d",magicNumber(n));
	//printf ("%d",nthMagicNo(n));
}
