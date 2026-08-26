#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int stop = 0, c = 1;

void init(int *a,int k)
{
	int i;
	for(i=1;i<=k;i++) a[i] = i;
}

void nc(int *a,int n,int k)
{
	int i = k, j;
	while(a[i]==n-k+i) i--;
	if(i==0) stop = 1;
	else
	{
		a[i]++;
		for(j=i+1;j<=k;j++) a[j] = a[i] + j - i;
	}
}

void printnc(int * a,int k)
{
	int i;
	printf("\nTo hop thu %d: ",c);
	for(i=1;i<=k;i++) printf("%d ",a[i]);
	c++;
}

void generate(int *a,int n,int k)
{
	while(stop!=1)
	{
		printnc(a,k); nc(a,n,k);
	}
}

int main(void)
{
	int k, n, *a;
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Nhap k: ");
	scanf("%d",&k);
	a = (int *) malloc(n*sizeof(int));
	init(a,k); generate(a,n,k);
	getch();
}