#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, j, k, l, m, n;
	printf("Nhap chieu dai day: ");
	scanf("%d",&n);
	if(n%2==1)
	{
		for(i=1;i<=(n+1)/2;i++)
		{
			for(j=1;j<=(n-1)/2-i+1;j++) printf(" ");
			for(k=1;k<=i-1;k++) printf("*");
			printf("*");
			for(l=1;l<=i-1;l++) printf("*");
			for(m=1;m<=(n-1)/2-i+1;m++) printf(" ");
			printf("\n");
		}
	}
	else
	{
		for(i=1;i<=n/2;i++)
		{
			for(j=1;j<=n/2-i;j++) printf(" ");
			for(k=0;k<=i-1;k++) printf("*");
			for(l=0;l<=i-1;l++) printf("*");
			for(m=1;m<=n/2-i;m++) printf(" ");
			printf("\n");
		}
	}
	getch();
}