#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[30], s2[30], *cptr, *ctemp;
	int i, l;
	printf("Nhap xau: ");
	gets(s); l = strlen(s);
	strcpy(s2,s);
	cptr = s2;
	for(i=0;i<l;i++) *(cptr+l-i-1) = s[i];
	puts(cptr);
}