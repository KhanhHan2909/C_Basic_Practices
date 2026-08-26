#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, j;
	for(j=1;j<11;j++)
	{
		for(i=1;i<11;i++) 
		{
			printf("%dx%d=%d ",j,i,i*j);
		}
		printf("\n");
	}
	getch();
}