#include<stdio.h>
#include<stdlib.h>

void binary(int *a,int n,int i)
{
	int j, k;
	for(j=0;j<=1;j++)
	{
		a[i] = j;
		if(i==n-1)
		{
			for(k=0;k<n;k++) printf("%d",a[k]);
			printf("\n");
		}
		else binary(a,n,i+1); 
	}
}

int main()
{
	int i, n, k, *a;
	printf("Nhap kich thuoc xau nhi phan: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	printf("Cac xau nhi phan co kich thuoc %d la:\n",n);
	binary(a,n,0);
	free(a);
}