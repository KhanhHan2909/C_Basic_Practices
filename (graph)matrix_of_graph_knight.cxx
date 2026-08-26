#include<stdio.h>

int main()
{
	int i, j, n, a[100][100];
	printf("Chuong trinh in ra ma tran ke cua do thi ban co nxn dinh voi quy tac lien ket quan ma giua cac dinh.\n**********\n");
	do
	{
		printf("Nhap so o ban co: ");
		scanf("%d",&n);
	} while(n<1);
	for(i=0;i<n*n;i++)
		for(j=i+1;j<n*n;j++)
		{
			if(i%n==0&&i<n*n-2*n)
			{
				if(j==i+n+2||j==i+2*n+1) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i%n==1&&i<n*n-2*n)
			{
				if(j==i+n+2||j==i+2*n+1||j==i+2*n-1) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i%n>1&&i%n<n-2&&i<n*n-2*n)
			{
				if(j==i+n+2||j==i+2*n+1||j==i+2*n-1||j==i+n-2) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i%n==n-2&&i<n*n-2*n)
			{
				if(j==i+n-2||j==i+2*n+1||j==i+2*n-1) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i%n==n-1&&i<n*n-2*n)
			{
				if(j==i+n-2||j==i+2*n-1) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i==n*n-2*n||i==n*n-2*n+1)
			{
				if(j==i+n+2) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i>n*n-2*n+1&&i<n*n-n-2)
			{
				if(j==i+n+2||j==i+n-2) a[i][j] = 1;
				else a[i][j] = 0;
			}
			if(i==n*n-n-2||i==n*n-n-1)
			{
				if(j==i+n-2) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
	for(i=0;i<n*n;i++) a[i][i] = 0;
	for(i=0;i<n*n;i++)
		for(j=0;j<i;j++)
			a[i][j] = a[j][i];
	printf("\nMa tran ke cua do thi ban co nxn o tuong duong nxn dinh vua nhap:\n");
	for(i=0;i<n*n;i++)
	{
		for(j=0;j<n*n;j++)
			printf("%3d ",a[i][j]);
		printf("\n");
	}
}