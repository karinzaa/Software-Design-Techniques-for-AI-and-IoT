#include <stdio.h>
void printbits(int v)
{
	int i;
	for (i = 31; i >=0 ; i --)
	{
		if(v & (1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

void main(void)
{
	int c = 100;
	printf("%5d = ", c);
	printbits(c);
	c = -100;
	printf("%5d = ", c);
	printbits(c);

}
