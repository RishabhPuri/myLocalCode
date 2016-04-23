#include <stdio.h>
#include <string.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    unsigned int tc, len;
    char str[100001] ;
	memset (str, '\0', 100001);
    int i, count; unsigned long long ans;
    scanf ("%d\n", &tc);
    while (tc > 0)
    {
        ans = 0; count = 1;
        printf ("TC %d \n", tc);
        
        if (NULL != fgets (str, 100000, stdin))
        {
            if (str[0] == '\n') {printf ("Enter any input \n"); continue;}

			len = strlen (str);
            
            for (i=1; i<=len; i++)
            {
                if (str[i]!=str[i-1])
                {
                    count++;
                }
                else 
                {
                    ans = ans + ((count * (count+1))/2);
                    count = 1;
                }
            } 
            ans = ans + ((count * (count+1))/2);
            printf ("%llu \n", ans);
        }
        tc--;
    }
    return 0;
}

