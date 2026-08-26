#include<stdio.h>
#include<conio.h>

void main(void)
{
	int itien[5] = {50, 25, 10, 5, 1}, ito, isotien, i;
	printf("Nhap so tien: ");
	scanf("%d",&isotien);
	for(i=0;i<5;i++)
	{
		ito = isotien/itien[i];
		printf("So tien loai %d la %d\n",itien[i],ito);
		isotien = isotien%itien[i];
	}
	getch();
}