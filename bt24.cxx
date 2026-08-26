#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, k, n;
	float t = 1;
	printf("To hop chap k cua N.\n");
	do
	{
		printf("Nhap k: ");
		scanf("%d",&k);
		printf("Nhap N: ");
		scanf("%d",&n);
	} while(k>n);
	for(i=1;i<=k;i++) t *= (n - k + i)/i;
	printf("T = %.0f",t);
	getch();
}