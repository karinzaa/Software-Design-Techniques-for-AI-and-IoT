#include <stdio.h>
int sum_up(int n)
{
	int i, c =0;
	for (i=1; i<n ; i++)
	{
		c = c +i;
	}
	return(c);
}

void main(void)
{
	int output = sum_up(100);
	printf("Sum = %d \n",output);

}
