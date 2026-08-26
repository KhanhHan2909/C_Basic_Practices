#include<stdio.h>
#include<string.h>

#define MAX 1000

void main(void)
{
	char s[MAX];
	int i, k = 0, x, a[MAX], dem1 = 0, dem2 = 0;
	printf("Nhap van ban: ");
	gets(s);
	for(i=0;i<MAX;i++) a[i] = 0;
	x = strlen(s);
	for(i=0;i<x;i++)
	{
		if(s[i]!=32) a[k]++;
		else k++;
	}
	for(i=0;i<k+1;i++)
	{
		if(a[i]<=8) dem1++;
		else dem2++;
	}
	printf("So tu: %d.",k+1);
	printf("\nSo tu co kich thuoc binh thuong: %d x 100 = %d dong.",dem1,dem1*100);
	printf("\nSo tu co kich thuoc > 8 ki tu: %d x 150 = %d dong.",dem2,dem2*150);
}