#include<stdio.h>

int acker(int m,int n)
{
	if(m==0) return n + 1;
	if(n==0) return acker(m - 1,1);
	return acker(m - 1,acker(m,n - 1));
}

int main()
{
	printf("%d",acker(1,2));
}