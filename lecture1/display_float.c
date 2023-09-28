#include <stdio.h>
void printfloats(float f)
{
	int i;
	int v = *(int *)(&f);
	for (i = 31; i >=0 ; i --)
	{
		if(v & (1 << i))
			printf("1");
		else
			printf("0");
		if( i == 31 || i == 23) printf(" ");
	}
	printf("\n");
}

void main(void)
{
	float f = 1.0;
	printf("%f = ", f);
	printfloats(f);
	f = 1.5;
	printf("%f = ", f);
	printfloats(f);
	f = 2.5;
	printf("%f = ", f);
	printfloats(f);
}
