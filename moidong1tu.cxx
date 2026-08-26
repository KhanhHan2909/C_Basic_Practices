#include<stdio.h>
#include<string.h>

void main(void)
{
	char s[100];
	int i, x;
	printf("Nhap chuoi ki tu: ");
	gets(s);
	x =strlen(s);
	for(i=0;i<x;i++)
		if(s[i]==32)
			s[i] = '\n';
	puts(s);
}