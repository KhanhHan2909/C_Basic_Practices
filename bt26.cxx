#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, j, dem1, dem2, s1, s2;
	printf("Nhap s1: ");
	scanf("%d",&s1);
	printf("Nhap s2: ");
	scanf("%d",&s2);
	for(i=1;i<=s1;i++)
	{
		for(j=i+1;j<=s1;j++) 
			if((2i+4j)==s2)
			{
				dem1 = i;
				dem2 = j;
				break;
			}
		break;
	}
	printf("cho = %d, ",dem1);
	printf("ga = %d",dem2);
	getch();
}