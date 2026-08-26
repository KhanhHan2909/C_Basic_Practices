#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strlwr(char s[Max])
{
	int i = 0, l = strlen(s);
	for(i=0;i<l;i++)
		if(s[i]>64&&s[i]<91) s[i] += 32;
}

int main(void)
{
	char s[Max];
	printf("Nhap xau ki tu: ");
	gets(s);
	strlwr(s);
	printf("Xau sau khi LOW: ");
	puts(s);
}