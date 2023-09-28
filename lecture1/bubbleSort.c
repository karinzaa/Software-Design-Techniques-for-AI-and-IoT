#include <stdio.h>

void printArray(int array[], int n)
{
	int j;
	printf("array[%d] = {", n );
	for (j = 0 ; j< n; j++)
	{
		if( j >0) printf(", ");
		printf("%d", array[j]);
	}
	printf("} \n");

}

void swap(int  *a0, int *a1)
{
	int t = *a0;
	*a0 = *a1;
	*a1 = t;

}

void bbsort(int a[], int n)
{
	
	int i,j;
	printf("Start Sorting \n");	
	for (i=0; i<n; i = i +1)
	{

		for (j =1; j < n-i ; j = j+1)
		{
			printf("n = %d : i = %d : j =%d : n-i = %d \n",n,i,j ,(n-i));

			if( a[j-1] > a[j] )  
			{	
				swap(&a[j-1],&a[j]);
			}
		}
	}

}

void main()
{
	int a[10] = {10,5,3,4,2,16,9,8,1,0};
	printf("Before Sorting: ");
	printArray(a,10);
	bbsort(a,10);
	printf("After Sorted: ");
	printArray(a,10);

}



