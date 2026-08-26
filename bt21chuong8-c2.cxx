#include<stdio.h>
#include<string.h>

int main(void)
{
	char s1[100], s2[100];
	int i, l, p, e;
	printf("Nhap xau nguon: ");
	gets(s1);
	l = strlen(s1);
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
	for(i=0;i<p-1;i++) s2[i] = s1[i];
	for(i=p+e-1;i<l;i++) s2[i-e] = s1[i];
	s2[l-e] = '\0';
	printf("\nXau nguon la: %s\nXau sau khi xoa: %s",s1,s2);
}