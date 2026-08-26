#include<stdio.h>
#include<string.h>

int main(void)
{
	char s1[30], s2[30];
	int i, x, l, n;
	printf("Nhap mot chuoi: ");
	gets(s1);
	x = strlen(s1);
	do
	{
		printf("Nhap vi tri bat dau chep: ");
		scanf("%d",&l);
	} while(l>x);
	do
	{
		printf("Nhap so ki tu duoc chep: ");
		scanf("%d",&n);
	} while((l+n-1)>x);
	for(i=l-1;i<l+n-1;i++) s2[i-l+1] = s1[i];
	printf("Chuoi duoc chep (ca khoang trang): %s",s2);
}