#include <stdio.h>
#include <stdlib.h>

int find_subsets(int start, int end, int subsetsum)
{
	int total_no = (end - start + 1);
	int mask = 0;
	char buf[256];
	int i = start;
	int *num = malloc (sizeof(int) * total_no);

	if (!num) {
		printf ("Memory failed ...\n");
		return -1;
	}
/*populate data*/
	while (i <= end) {
		num[i - start] = i;
		i++;
	}

	for (mask = 1 ; mask < (0x1 << total_no); ++mask) {
		int sum = 0;
		int len = 0;
		for (i = 0; i < total_no; ++i) {
			if ( (mask >> i) & 0x01 ) {
				sum += num [total_no-1-i];
				len += snprintf (buf + len, sizeof(buf) - 1, "%d ", 
						 num[total_no-1-i]);
			}
		}
		if (sum == subsetsum)
			printf ("%s = %d\n", buf, sum);
		sum = 0;
	}
	return 0;
}

int main (int c, char **v)
{
	int start_range;
	int end_rage;
	int sum;

	if (c != 4) {
		fprintf (stderr, "usage: %s <start_no> <end_no> <sum>\n", v[0]);
		fprintf (stderr, "     example : %s 1 23 23\n", v[0]);
		return -1;	
	}

	start_range = atoi (v[1]);
	end_rage = atoi (v[2]);

	if (start_range > end_rage) {
		fprintf (stderr, "Error: start number must be less than or equal to end\n");
		return -1; 
	}
	sum = atoi(v[3]);

	return find_subsets (start_range, end_rage, sum);
}
