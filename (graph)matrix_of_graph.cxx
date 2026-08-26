#include<stdio.h>
#include<stdlib.h>

void ktlienthong(int b[100][99],int n,int *c,int *q,int r)
{
	int i = 0, j, e;
	while(i<n)
	{
		if(b[r][i]>-1) 
		{
			e = 0;
			for(j=0;j<=*q;j++) 
				if(c[j]==b[r][i]) 
				{
					e = 1;
					break;
				}
			if(e==0)
			{
				c[*q] = b[r][i];
				(*q)++;
				ktlienthong(b,n,c,q,b[r][i]);
			}
			i++;
		}
		else break;
	}
	return;
}

int main()
{
	int zero = 0;
	int i, j, n, a[100][100], b[100][99], *c = (int*)malloc(100*sizeof(int)), f, *q = &zero;
	printf("Chuong trinh kiem tra 1 do thi vo huong co lien thong hay khong.\n**********\n");
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
	}
	for(i=0;i<n;i++) 
	{
		c[i] = -1;
		for(j=0;j<n-1;j++) b[i][j] = -1;
	}
	for(i=0;i<n;i++)
	{
		f = 0;
		for(j=0;j<i;j++)
		{
			if(a[j][i]!=0) 
			{
				b[i][f] = j;
				f++;
			}
		}
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]!=0) 
			{
				b[i][f] = j;
				f++;
			}
		}
	}
	ktlienthong(b,n,c,q,0);
	if(*q==n) printf("Do thi da cho la lien thong.");
	else printf("Do thi da cho khong lien thong.");
	free(c);
}