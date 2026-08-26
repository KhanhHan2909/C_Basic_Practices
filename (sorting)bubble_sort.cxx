//Sap xep noi bot duoc cai tien ve thoi gian thuat toan
#include<stdio.h>

int main()
{
	int i, j, n, a[100], temp;
	bool swapped;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		swapped = false;
		for(j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				swapped = true;
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
		if(!swapped) break;
	}
	printf("\nMang da sap xep theo thu tu tang dan: ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
}