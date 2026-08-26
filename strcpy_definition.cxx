#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strcpy(char s2[Max],char s1[Max])
{
	int i, l = strlen(s1);
	for(i=0;i<l;i++) s2[i] = s1[i];
	s2[l] = '\0';
}

int main(void)
{
	char s1[Max], s2[Max];
	printf("Nhap xau ki tu thu nhat: ");
	gets(s1);
	printf("Nhap xau ki tu thu hai: ");
	gets(s2);
	strcpy(s2,s1);
	printf("Xau thu hai sau khi sao tu xau thu nhat: ");
	puts(s2);
}