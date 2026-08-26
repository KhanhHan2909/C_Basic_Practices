#include<stdio.h>

int main()
{
	int i, j, k, n, a[100], temp;
	bool swapped;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(a[i]<a[j])
			{
				temp = a[i];
				for(k=i;k>j;k--) a[k] = a[k-1];
				a[j] = temp;
//				break;
			}
	}
	printf("\nMang da sap xep theo thu tu tang dan: ");
	for(i=0;i<n;i++) printf("%d ",a[i]);
}