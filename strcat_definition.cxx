#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strcat(char s1[Max],char s2[Max])
{
	int i = 0, l1 = strlen(s1), l2 = strlen(s2);
	for(i=l1;i<l1+l2+1;i++) s1[i] = s2[i-l1];
}

int main(void)
{
	char s1[Max], s2[Max];
	printf("Nhap xau ki tu thu nhat: ");
	gets(s1);
	printf("Nhap xau ki tu thu hai: ");
	gets(s2);
	strcat(s1,s2);
	printf("Xau ki tu thu nhat sau khi ghep: ");
	puts(s1);
}