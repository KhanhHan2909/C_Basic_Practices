#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strrev(char s[Max])
{
	int i;
	char s0[Max];
	for(i=0;i<strlen(s);i++)
		s0[i] = s[strlen(s)-1-i];
	for(i=0;i<strlen(s);i++)
		s[i] = s0[i];
}

int main(void)
{
	char s[Max];
	printf("Nhap xau ki tu: ");
	gets(s);
	strrev(s);
	printf("Xau da dao nguoc: %s",s);
}