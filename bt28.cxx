#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(void)
{
	float x, n;
	printf("Nhap do day to giay (mm): ");
	scanf("%f",&x);
	n = log(1000/x)/log(2);
	printf("So lan gap: %.2f",n);
	getch();
}