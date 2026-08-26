#include<stdio.h>
#include<stdlib.h>

void swap(int &n1,int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void partitionsort(int *a,int L,int R)
{
	if(L>=R) return;
	int i = L + 1, j = R;
	while(i<=j)
	{
		while(a[i]<a[L]) i++;
		while(a[j]>a[L]) j--;
		if(i<j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	swap(a[L],a[j]);
	partitionsort(a,L,j-1);
	partitionsort(a,j+1,R);
}

int main()
{
	int i, n, *a = (int*)malloc(100*sizeof(int));
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	partitionsort(a,0,n-1);
	printf("\nMang da sap xep theo thu tu tang dan: ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	free(a);
}