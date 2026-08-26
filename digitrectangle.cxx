#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, j, a, b;
	printf("Chieu ngang: ");
	scanf("%d",&a);
	printf("Chieu doc: ");
	scanf("%d",&b);
	for(j=1;j<=b;j++)
	{
		for(i=1;i<=a;i++) printf("%d",j-1);
		printf("\n");
	}
	getch();
}