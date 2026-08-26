#include<stdio.h>
#include<stdlib.h>

void popback(int *a,int *q)
{
	(*q)--;
	a[*q] = -1;
}

void findpath(int b[100][99],int n,int *c,int *q,int v1, int v2,bool *done)
{
	int i = 0, j, test;
	while(i<n)
	{
		if(*done) return;
		if(b[v1][i]>-1) 
		{
			if(b[v1][i]!=v2)
			{
				test = 0;
				for(j=0;j<*q;j++) 
					if(b[v1][i]==c[j]) 
					{
						test = 1;
						break;
					}
				if(!test)
				{
					c[*q] = b[v1][i];
					(*q)++;
					findpath(b,n,c,q,b[v1][i],v2,done);
				}
				i++;
			}
			else
			{
				c[*q] = v2;
				(*q)++;
				*done = true;
				return;
			}
		}
		else break;
	}
	if(!*done) popback(c,q);
	return;
}

int main()
{
	int one = 1;
	int i, j, n, a[100][100], b[100][99], *c = (int*)malloc(100*sizeof(int)), f, *q = &one, v1, v2;
	bool init = false, *done = &init;
	printf("Chuong trinh tim duong di giua 2 dinh trong do thi.\n**********\n");
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
	printf("\nMa tran ke vua nhap(hang tren cung va cot ngoai cung ben trai la ten dinh):\n");
	printf("    ");
	for(i=0;i<n;i++) printf("%3d ", i+1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%3d ",i+1);
		for(j=0;j<n;j++)
			printf("%3d ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++) 
	{
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
	do
	{
		printf("\nNhap dinh di (v1) va dinh den (v2): ");
		scanf("%d %d",&v1,&v2);
	} while(v1<1||v1>n||v2<1||v2>n);
	c[0] = v1 - 1;
	findpath(b,n,c,q,v1-1,v2-1,done);
	if(*done)
	{
		printf("\nDuong di tu v1 den v2 la: ");
		for(i=0;i<*q;i++) printf("%d ",c[i]+1);
	}
	else printf("\nKhong co duong di tu v1 den v2.");
	free(c);
}