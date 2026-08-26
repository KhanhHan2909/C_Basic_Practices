#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i = 1, n, dem;
	do
	{
		printf("Nhap so nguyen duong: ");
		scanf("%d",&n);
	} while(n<1);
	printf("%d = ",n);
	if(n==1) printf("1");
	else
		while(n!=1)
		{
			i++;
			while(n%i==0)
			{
				if(n>i) printf("%d*",i);
				else printf("%d",i);
				n /= i;
			}
		}
	getch();
}