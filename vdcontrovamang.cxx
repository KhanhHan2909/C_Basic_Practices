#include<stdio.h>

void add(int *ptr, int n, int a)
{
	int i;
	for(i=0;i<n;i++)
		*(ptr + i) += a;
}

int main(void)
{
	int array[] = {2, 5, 4, 3};
	int i, a = 10;
	add(array,4,a);
	for(i=0;i<4;i++)
		printf("%d ",*(array + i));
}