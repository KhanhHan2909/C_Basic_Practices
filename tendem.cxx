#include<stdio.h>
#include<string.h>

void main(void)
{
	char hoten[70], tdvt[70], td[70];
	int i, j, x, y;
	printf("Nhap ho ten: ");
	gets(hoten);
	x = strlen(hoten);
	for(i=0;i<x;i++)
		if(hoten[i]==' ')
		{
			for(j=i+1;j<x;j++) tdvt[j-i-1] = hoten[j];
			tdvt[x-i-1] = '\0';
			break;
		}
	y = strlen(tdvt);
	for(i=y-1;i>=0;i--)
		if(tdvt[i]==' ')
		{
			for(j=i-1;j>=0;j--) td[j] = tdvt[j];
			td[i] = '\0';
			break;
		}
	puts(td);
}