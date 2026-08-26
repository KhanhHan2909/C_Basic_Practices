#include<stdio.h>
#include<string.h>

void main(void)
{
	char s[50];
	int i, x;
	printf("Nhap chuoi ki tu: ");
	gets(s);
	x = strlen(s);
	for(i=0;i<x;i++)
		if(s[i]==32)
			if(s[i+1]>96&&s[i+1]<123) s[i+1] -= 32;
	if(s[0]>96&&s[0]<123) s[0] -= 32;
	puts(s);
}