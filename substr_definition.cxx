#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void substr(char s[Max],int x,int n)
{
	int i = 0, l = strlen(s);
	for(i=x-1;i<l-n;i++)
		s[i] = s[i+n];
	s[l-n] = '\0';
}

int main(void)
{
	char s[Max];
	int x, n, l;
	printf("Nhap xau ki tu: ");
	gets(s);
	l = strlen(s);
	do
	{
		printf("Nhap vi tri can xoa: ");
		scanf("%d",&x);
	} while(x<1||x>l);
	do
	{
		printf("Nhap so ki tu bi xoa: ");
		scanf("%d",&n);
	} while(x+n>l+1||n<0);
	substr(s,x,n);
	printf("Xau sau khi xoa: ");
	puts(s);
}