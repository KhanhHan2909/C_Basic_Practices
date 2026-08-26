#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[100];
	int a[100], i, j = 0, l, c = 0;
	printf("Nhap xau bat ki: ");
	gets(s);
	l = strlen(s);
	for(i=0;i<l;i++) a[i] = 0;
	for(i=0;i<l;i++)
	{
		if(s[i]>64&&s[i]<91||s[i]>96&&s[i]<123) a[j]++;
		else j++;
	}
	for(i=0;i<l;i++) if(a[i]>0) c++;
	printf("Co %d tu!",c);
}