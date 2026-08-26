#include<stdio.h>
#include<conio.h>

void main(void)
{
	char c; int n;
	do
	{
		printf("Nhap mot ki tu ASCII: ");
		scanf("%c",&c);
		printf("Ma ki tu vua nhap: %d\n",c);
	} while(c!='0');
	getch();
}