#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, j, k, l, m, n;
	printf("Nhap chieu dai day: ");
	scanf("%d",&n);
	if(n%2==1)
	{
		for(i=1;i<(n+1)/2;i++) printf(" ");
		printf("*");
		for(j=(n+1)/2+1;j<=n;j++) printf(" ");
		printf("\n");
		for(i=2;i<=(n+1)/2-1;i++)
		{
			for(j=1;j<=(n-1)/2-i+1;j++) printf(" ");
			printf("*");
			for(k=2;k<=i-1;k++) printf(" ");
			printf(" ");
			for(l=2;l<=i-1;l++) printf(" ");
			printf("*");
			for(m=1;m<=(n-1)/2-i+1;m++) printf(" ");
			printf("\n");
		}
		for(j=1;j<=n;j++) printf("*");
	}
	else
	{
		for(i=1;i<n/2;i++) printf(" ");
		printf("**");
		for(j=n/2+2;j<=n;j++) printf(" ");
		printf("\n");
		for(i=2;i<=n/2-1;i++)
		{
			for(j=1;j<=n/2-i;j++) printf(" ");
			printf("*");
			for(k=1;k<=i-1;k++) printf(" ");
			for(l=1;l<=i-1;l++) printf(" ");
			printf("*");
			for(m=1;m<=n/2-i;m++) printf(" ");
			printf("\n");
		}
		if(n>2) for(j=1;j<=n;j++) printf("*");
	}
	getch();
}