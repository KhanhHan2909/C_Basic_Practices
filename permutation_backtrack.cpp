#include<stdio.h>
#include<stdlib.h>

void permutation(int *a,int n,int i)
{
	int j, k;
	bool duplicated;
	for(j=1;j<=n;j++)
	{
		duplicated = false;
		for(k=0;k<i;k++)
			if(a[k]==j)
			{
				duplicated = true;
				break;
			} 
		if(!duplicated) a[i] = j;
		else continue;
		if(i==n-1)
		{
			for(k=0;k<n;k++) printf("%d",a[k]);
			printf("\n");
		}
		else permutation(a,n,i+1); 
	}
}

int main()
{
	int i, n, k, *a;
	printf("Nhap kich thuoc tap hop X: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	printf("Cac hoan vi cua X la:\n",n);
	permutation(a,n,0);
	free(a);
}