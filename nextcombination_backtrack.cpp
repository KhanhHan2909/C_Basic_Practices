#include<stdio.h>
#include<stdlib.h>

void combination(int *a,int n,int k,int i)
{
	int j, ii;
	for(j=i;j<=n-k+i;j++)
	{
		if(j>a[i-1]) a[i] = j;
		else continue;
		if(i==k)
		{
			for(ii=1;ii<=k;ii++) printf("%d",a[ii]);
			printf("\n");
		}
		else combination(a,n,k,i+1); 
	}
}

int main()
{
	int i, n, k, *a;
	printf("Nhap kich thuoc tap hop X: ");
	scanf("%d",&n);
	printf("Nhap kich thuoc tap con cua X: ");
	scanf("%d",&k);
	a = (int*)malloc(k+1*sizeof(int));
	a[0] = 0;
	printf("Cac tap con chap %d phan tu cua X la:\n",k);
	combination(a,n,k,1);
	free(a);
}