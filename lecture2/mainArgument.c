
#include <stdlib.h> 
#include <stdio.h>

#define RSEED 3
#define N 1000000  /* this is the maximum array size */
#include <time.h> /* for using clock() and CLOCKS_PER_SEC */
int a[N]; /* declare array a as global because the array size is HUGE! */
int comp_count = 0;
int swap_count = 0;

void print_array2(int a[], int l, int r)
{
	int j;
	printf("a[%d:%d] = {", l, r);
	for(j = l; j <= r; j ++){
		if(j > l) printf(", "); 
		printf("%d", a[j]);
	}
	printf("}\n");
}


void swap(int * a0, int * a1)
{
	int t = *a0;
	*a0 = *a1;
	*a1 = t;
}


void create_array(int a[], int n, int rand_seed)
{
	int i;
	for(i = 0; i < n; i ++)
		a[i] = i;
	srand(rand_seed);
	for(i = 0; i < 2 * n; i ++){
		int j0 = ((rand() << 15) | rand()) % n;
		int j1 = ((rand() << 15) | rand()) % n;
		swap(&a[j0], &a[j1]);
	}
}


void bubble_sort(int a[], int n)
{
	
	int i,j;
		
	for (i=0; i<n; i = i +1)
	{

		for (j =1; j < n-i ; j = j+1)
		{

			comp_count++;
			if( a[j-1] > a[j] )  
			{	
				swap(&a[j-1],&a[j]);
				swap_count++;
			}
		}
	}
	printf("Swap = %d \n", swap_count);
}


void print_pivot(int pivot, int a[], int l, int r)
{
	printf("pivot(%d): ", pivot);
	print_array2(a, l, r);
}
int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int i = left, k = right;
	while(i < k){
		while(i < k && a[i] < pivot) i ++;
		while(i < k && a[k] >= pivot) k --;
		if(i < k) 
		{
			swap(&a[i], &a[k]);
			swap_count++;
		}
	}
	if(right > k) 
	{
		swap(&a[right], &a[k]);
		swap_count++;
	}

	comp_count += right - left - 1;
	return k;
}

void quick_sort(int a[], int left, int right)
{
		
	if(left < right){
		int pivot_pos = partition(a, left, right);
		quick_sort(a, left, pivot_pos - 1);
		quick_sort(a, pivot_pos + 1, right);
	}
}


int main(int argc, char * argv[])
{
	int n, rand_seed = 1, sort_type = 1, clk; 
	if(argc < 2 || argc > 4){ /* # of command arguments must be 2, 3 or 4 */
		printf("Invalid command!\n");
		printf("usage: %s <array_size> <rand_seed> <sort-type>\n", argv[0]);
		printf("<rand_seed>, <sort-type> : optional\n");
		printf("sort-type = 0:bubble-sort, 1:quick-sort\n");
		return 0;
	}
	sscanf(argv[1], "%d", &n); /* read array size n */
	if(n <= 0 || n > N){ /* check that array size n is valid */
		printf("Invalid array size!\n");
		printf("Array size must be between %d and %d\n", 1, N);
		return 0;
	}
	if(argc >= 3){ /* read sort_type if 3rd argument is present */
		sscanf(argv[2], "%d", &sort_type);
	}
	if(argc >= 4){ /* read rand_seed if 4th argument is present */
		sscanf(argv[3], "%d", &rand_seed);
	}

	if(sort_type < 0 || sort_type > 1){
		printf("Invalid sort type!\n");
		printf("sort-type = 0:bubble-sort, 1:quick-sort\n");
		return 0;
	}
	create_array(a, n, rand_seed); /* use n and rand_seed from command argument */
	//print_array2(a, 0, n - 1);
	clk = clock(); /* get the current clock value : start timer from here */
	switch(sort_type){
		case 0: /* call bubble_sort */
			printf("Start Bubble Sorting \n");
			bubble_sort(a, n);
			break;
		case 1: /* call quick_sort */
			printf("Start Quick Sorting \n");
			quick_sort(a, 0, n - 1);
			break;
	}
	clk = clock() - clk; /* get the current clock value : clk is the elapse time */
	//print_array2(a, 0, n - 1);
	printf("comp_count = %d\nswap_count = %d\n", comp_count, swap_count);
	/* CLOCKS_PER_SEC : # of clock ticks per second (usually 1000 ticks/sec) */
	printf("elapse time = %.9f sec\n", (double) clk / (double) CLOCKS_PER_SEC);
	return 0;
}
