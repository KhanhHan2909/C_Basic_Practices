#include<stdio.h>
#include<stdlib.h>

void dfs(int a[100][100],int n,int *prev,int v,bool *chuaxet)
{
	int i = 0;
	chuaxet[v] = false;
	while(i<n)
	{
		if(a[v][i]>0&&chuaxet[i])
		{
			prev[i] = v;
			dfs(a,n,prev,i,chuaxet);
		}
		i++;
	}
}

void result(int *prev,int v1,int v2)
{
	int i;
	if(prev[v1]==-1) printf("Khong co duong di tu dinh %d den dinh %d.",v1,v2);
	else
	{
		printf("Duong di tu dinh %d den dinh %d la: ",v1,v2);
		i = v1;
		while(i!=v2)
		{
			printf("%d ",i);
			i = prev[i];
		}
		printf("%d ",v2);
	}
}
	
int main()
{
	int i, j, a[100][100], n, *prev = (int*)malloc(100*sizeof(int)), v1, v2;
	bool *chuaxet = (bool*)malloc(100*sizeof(bool));
	do
	{
		printf("Nhap so dinh do thi: ");
		scanf("%d",&n);
	} while(n<1);
	printf("Nhap ma tran ke cua do thi:\n");
	for(i=0;i<n;i++)
	{
		prev[i] = -1;
		chuaxet[i] = true;
		for(j=i;j<n;j++)
		{
			do
			{
				printf("a[%d][%d] = ",i,j);
				scanf("%d",&a[i][j]);
			} while(a[i][j]<0);
		}
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
	}
	printf("\nNhap dinh di va dinh den: ");
	scanf("%d %d",&v1,&v2);
	dfs(a,n,prev,v2,chuaxet);
//	for(i=0;i<n;i++) printf("%d ",prev[i]);
	result(prev,v1,v2);
	free(prev);
	free(chuaxet);
}