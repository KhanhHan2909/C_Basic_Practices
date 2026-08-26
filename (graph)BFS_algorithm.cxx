//Co the dung de tim so thanh phan lien thong
#include<stdio.h>
#include<stdlib.h>

void bfs(int a[100][100],int n,int v,bool *chuaxet)
{
	int i, l = 0, queue[100], v0 = v;
	for(i=0;i<n;i++) queue[i] = -1;
	chuaxet[v] = false;
	printf("%d ",v+1);
	do
	{
		for(i=0;i<l;i++) queue[i] = queue[i+1];
		if(l>0) l--;
		for(i=0;i<n;i++)
		{
			if(a[v0][i]>0&&chuaxet[i])
			{
				queue[l] = i;
				l++;
				chuaxet[i] = false;
				printf("%d ",i+1);
			}
		}
		v0 = queue[0];
	} while(l!=0);
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
	printf("Thu tu cac dinh duoc duyet theo thu tuc BFS:\n");
	for(i=0;i<n;i++)
		if(chuaxet[i]) bfs(a,n,i,chuaxet);
}