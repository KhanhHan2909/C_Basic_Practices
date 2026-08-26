//Co the dung de tim so thanh phan lien thong
#include<stdio.h>
#include<stdlib.h>

void dfs(int a[100][100],int n,int v,bool *chuaxet)
{
	int i = 0;
	chuaxet[v] = false;
	printf("%d ",v+1);
	while(i<n)
	{
		if(a[v][i]>0&&chuaxet[i]) dfs(a,n,i,chuaxet);
		i++;
	}
}

int main()
{
	int i, j, a[100][100], n;
	bool *chuaxet = (bool*)malloc(100*sizeof(bool));
	do
	{
		printf("Nhap so dinh do thi: ");
		scanf("%d",&n);
	} while(n<1);
	printf("Nhap ma tran ke cua do thi:\n");
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			do
			{
				printf("a[%d][%d] = ",i,j);
				scanf("%d",&a[i][j]);
			} while(a[i][j]<0);
		}
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			a[i][j] = a[j][i];
	printf("\nMa tran ke vua nhap:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",a[i][j]);
		printf("\n");
		chuaxet[i] = true;
	}
	printf("Thu tu cac dinh duoc duyet theo thu tuc DFS:\n");
	for(i=0;i<n;i++)
		if(chuaxet[i]) dfs(a,n,i,chuaxet);
		free(chuaxet);
}