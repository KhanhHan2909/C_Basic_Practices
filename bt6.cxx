#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, n;
	int tong = 0;
	printf("Nhap mot so nguyen duong: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) if(i%2==1) tong += i*i;
	printf("Tong binh phuong cac so le tu 1 den %d bang %d",n,tong);
	getch();
}