#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, j, a, b;
	printf("Chieu ngang: ");
	scanf("%d",&a);
	printf("Chieu doc: ");
	scanf("%d",&b);
	for(i=1;i<=a;i++) printf("*");
	printf("\n");
	for(j=2;j<b;j++)
	{
		printf("*");
		for(i=2;i<a;i++) printf(" ");
		printf("*");
		printf("\n");
	}
	for(i=1;i<=a;i++) printf("*");
	getch();
}