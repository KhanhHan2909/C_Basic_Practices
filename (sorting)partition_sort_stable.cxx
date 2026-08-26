#include<stdio.h>
#include<stdlib.h>

void partitionsort(int *a,int L,int R)
{
	if(L>=R) return;
	int i, j, chot = L, k = chot + 1, a0[100];
	a0[L] = a[L];
	for(i=L+1;i<=R;i++) a0[i] = 0;
	for(i=L+1;i<=R;i++)
	{
		if(a[L]>a[i])
		{
			for(j=R;j>chot;j--) a0[j] = a0[j-1];
			a0[chot] = a[i];
			chot++;
			k++;
		}
		else
		{
			a0[k] = a[i];
			k++;
		}
	}
	for(i=L;i<=R;i++) a[i] = a0[i];
	partitionsort(a,L,chot-1);
	partitionsort(a,chot+1,R);
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