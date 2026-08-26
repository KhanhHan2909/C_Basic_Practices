#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[100];
	int i, l, p, e;
	printf("Nhap xau ki tu: ");
	gets(s);
	l = strlen(s);
	do
	{
		printf("Nhap vi tri can xoa: ");
		scanf("%d",&p);
	} while(p>l);
	do
	{
		printf("Nhap so ki tu can xoa: ");
		scanf("%d",&e);
	} while(p+e-1>l);
	for(i=p-1;i<l-e;i++) s[i] = s[i+e];
	for(i=l-e;i<l+1;i++) s[i] = '\0';
	printf("Xau da xoa: %s",s);
}