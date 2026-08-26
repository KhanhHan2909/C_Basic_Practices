#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, n;
	printf("Nhap n: ");
	scanf("%d",&n);
	for(i=1;i<n;i++) 
		if(n%i==0)
			printf("%d ",i);
	getch();
}