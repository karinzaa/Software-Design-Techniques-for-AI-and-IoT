#include <stdlib.h> 
#include <stdio.h>

int comp_count = 0;

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
#define N 10
#define RSEED 3

void swap(int * a0, int * a1)
{
	int t = *a0;
	*a0 = *a1;
	*a1 = t;
}
void create_array (int a[], int n, int rand_seed)
{
	int i;
	for(i = 0; i < n; i ++)
		a[i] = i;
	srand(rand_seed);
	for(i = 0; i < 2 * n; i ++){
		int j0 = rand() % n;
		int j1 = rand() % n;
		swap(&a[j0], &a[j1]);
	}
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
		if(i < k) swap(&a[i], &a[k]);
	}
	if(right > k) swap(&a[right], &a[k]);
	print_pivot(pivot, a, left, right);
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


void main()
{
	int a[N];
	create_array(a, N, RSEED);
	print_array2(a, 0, N-1);
	quick_sort(a, 0, N-1);
	print_array2(a, 0, N-1);
}
