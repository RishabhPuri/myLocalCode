void main()
{
	signed int bit=512, mbit;
	mbit = ~bit; // one's complement
	bit = bit & ~bit;
	printf("%d -%d \n",bit, mbit);

}
