#include<stdio.h>
#include<string.h>

void main(void)
{
	char s1[50], s2[50];
	int i, x;
	printf("Nhap chuoi: ");
	gets(s1);
	x = strlen(s1);
	for(i=0;i<x;i++) if(s1[i]<65||(s1[i]>90&&s1[i]<97)||s1[i]>122)
}