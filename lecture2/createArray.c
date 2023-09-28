#include <stdio.h>
#include <stdlib.h>



void swap(int  *a0, int *a1)
{
	int t = *a0;
	*a0 = *a1;
	*a1 = t;

}

void createArray(int a[], int n, int rand_seed)
{
	int i;
	for (i =0; i < n ; i++)
		a[i] = i;
	srand(rand_seed);
	for (i =0; i< 2*n ; i++)
	{
		int j0 = rand() %n; 
		int j1 = rand() %n; 	
		swap(&a[j0],&a[j1]);	
	}

}


void printArray2(int a[], int l, int r)
{
	int j;
	printf("a[%d:%d] = {", l,r);
	for ( j = 0 ; j <= r; j++)
	{
		if(j>l) printf(", ");
		printf("%d", a[j]);
	}
	printf(" }\n");

}

#define N 10
#define RSEED 123456

void main()
{
	int a[N];
	createArray(a, N , RSEED);

	printArray2(a, 0 , N-1);


}



