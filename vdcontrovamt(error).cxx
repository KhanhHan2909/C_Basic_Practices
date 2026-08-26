#include<stdio.h>
#include<stdlib.h>

void nhapmt(int **a,int m, int n)
{
	int i, j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			printf("a[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
}

int main(void)
{
	int **ap = NULL, i, j, m, n;
	printf("So dong: "); scanf("%d",&m);
	printf("So cot: "); scanf("%d",&n);
	ap = (int**)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
		ap[i] = (int*)malloc(n*sizeof(int));
	nhapmt(ap,m,n);
		for(i=0;i<m;i++)
		{
			free(ap[i]);
		}
		free(ap);
}