#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}
	
int main(void)
{
	char s[Max];
	int l;
	printf("Nhap xau ki tu: ");
	gets(s);
	l = strlen(s);
	printf("Do dai xau: %d",l);
}