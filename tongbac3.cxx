#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, n, S = 0;
	printf("Nhap n: ");
	scanf("%d",&n);
	for(i=1;i<n+1;i++) S = S + i*i*i;
	printf("Tong bac 3: %d",S);
	getch();
}