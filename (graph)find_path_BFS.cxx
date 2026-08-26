//Luon tim ra duong di ngan nhat

#include<stdio.h>
#include<stdlib.h>

void bfs(int a[100][100],int n,int v,int *prev,bool *chuaxet)
{
	int i, l = 0, queue[100], v0 = v;
	for(i=0;i<n;i++) queue[i] = -1;
	chuaxet[v] = false;
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
				prev[i] = v0;
			}
		}
		v0 = queue[0];
	} while(l!=0);
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
	int i, j, a[100][100], n, v1, v2, *prev = (int*)malloc(100*sizeof(int));
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
		prev[i] = -1;
	}
	printf("\nNhap dinh di va dinh den: ");
	scanf("%d %d",&v1,&v2);
    bfs(a,n,v2,prev,chuaxet);
    //for(i=0;i<n;i++) printf("%d ",prev[i]);
    result(prev,v1,v2);
	free(chuaxet);
	free(prev);
}