#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strupr(char s[Max])
{
	int i = 0, l = strlen(s);
	for(i=0;i<l;i++)
		if(s[i]>96&&s[i]<123) s[i] -= 32;
}

int main(void)
{
	char s[Max];
	printf("Nhap xau ki tu: ");
	gets(s);
	strupr(s);
	printf("Xau sau khi UP: ");
	puts(s);
}