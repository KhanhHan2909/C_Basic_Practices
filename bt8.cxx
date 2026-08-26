#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, n, gt = 1;
	printf("Nhap mot so nguyen duong: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) gt *= i;
	printf("Giai thua so vua nhap: %d",gt);
	getch();
}