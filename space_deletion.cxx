#include<stdio.h>
#include<string.h>

void main(void)
{
	char s[50];
	int i, j, x;
	printf("Nhap chuoi: ");
	gets(s);
	x = strlen(s);
	for(i=0;i<x;i++)
		if(s[i]==' ')
			for(j=i;j<=x;j++) s[j] = s[j+1];
	puts(s);
}