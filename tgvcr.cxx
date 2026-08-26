#include<stdio.h>

int main(void)
{
	int i, j, n;
	printf("Nhap do dai canh vuong can: ");
	scanf("%d",&n);
	printf("*");
	for(i=2;i<=n;i++) printf(" ");
	printf("\n");
	for(i=2;i<n;i++)
	{
		printf("*");
		for(j=1;j<i-1;j++) printf(" ");
		printf("*");
		for(j=1;j<=n-i;j++) printf(" ");
		printf("\n");
	}
	for(i=1;i<=n;i++) printf("*");
}