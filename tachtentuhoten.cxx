#include<stdio.h>
#include<string.h>

int main(void)
{
	char name[30], *np, *np0;
	int i, j, l;
	printf("Nhap ten: ");
	gets(name);
	np = name;
	np0 = np;
	l = strlen(np);
	//if(l>=3) printf("%c",*(np+2));
	for(i=l-1;i>=0;i--) 
		if(*(np+i)==32) break;
	for(j=0;j<l-i-1;j++) *(np0+j) = *(np+i+1+j);
	*(np0+j) = '\0';
	//for(j=l-i;j<l;j++) *(np0+j) = 32;
	//*(np0) = *(np+l-1);
	puts(np0);
	//puts(np0);
}