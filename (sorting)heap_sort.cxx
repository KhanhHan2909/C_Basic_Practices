#include<stdio.h>
#include<stdlib.h>

void swap(int *n1,int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void adjust(int *a, int n,int i)
{
	if(i>n/2-1) return;
	int adjustLeft = 0, adjustRight = 0;
	if(2*i+2<n)
	{
		if(a[2*i+1]>=a[2*i+2]&&a[2*i+1]>a[i]) {
			swap(&a[2*i+1],&a[i]);
			adjustLeft = 1;
		}
		else if(a[2*i+1]<=a[2*i+2]&&a[2*i+2]>a[i]) {
			swap(&a[2*i+2],&a[i]);
			adjustRight = 1;
		}
	}
	else
	{
		if(a[2*i+1]>a[i]) swap(&a[2*i+1],&a[i]);
	}
	if(adjustLeft) adjust(a,n,2*i+1);
	else if(adjustRight) adjust(a,n,2*i+2);
}

void heapify(int *a,int n)
{
	for(int i=n/2-1;i>=0;i--) adjust(a,n,i);
}

void heapsort(int *a,int n)
{
	int i;
	heapify(a,n);
	for(i=n;i>1;i--)
	{
		swap(&a[0],&a[i-1]);
		adjust(a,i-1,0);
	}
}

int main()
{
	int i, n, *a;
	printf("Co bn pt? ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printf("Mang da sap xep tang dan: ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	free(a);
}