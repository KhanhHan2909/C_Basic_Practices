#include<stdio.h>
#include<string.h>

void main(void)
{
	char s[50], ss[50];
	int i, x;
	printf("Nhap chuoi ki tu: ");
	gets(s);
	x = strlen(s);
	for(i=0;i<x;i++)
		if(s[i]>96&&s[i]<123) s[i] -= 32;
	puts(s);
	printf("Nhap chuoi ki tu: ");
	gets(ss);
	x = strlen(ss);
	for(i=0;i<x;i++)
		if(ss[i]>64&&ss[i]<91) ss[i] += 32;
	puts(ss);
}