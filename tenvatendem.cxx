#include<stdio.h>
#include<string.h>

void main(void)
{
	char hoten[50], tdvt[50];
	int i, j, x;
	printf("Nhap ho ten: ");
	gets(hoten);
	x = strlen(hoten);
	for(i=0;i<x;i++)
		if(hoten[i]==' ')
		{
			for(j=i+1;j<x;j++) tdvt[j-i-1] = hoten[j];
			break;
		}
	puts(tdvt);
}