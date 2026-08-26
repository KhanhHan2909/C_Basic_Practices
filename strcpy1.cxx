#include<stdio.h>
#include<string.h>

int main(void)
{
	char s1[30], s2[30];
	int i, x, n;
	printf("Nhap mot chuoi: ");
	gets(s1);
	x = strlen(s1);
	do
	{
		printf("Nhap so ki tu duoc chep: ");
		scanf("%d",&n);
	} while(n>x);
	for(i=0;i<n;i++) s2[i] = s1[i];
	s2[n] = '\0';
	printf("Chuoi duoc chep: %s",s2);
}