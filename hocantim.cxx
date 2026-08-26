#include<stdio.h>
#include<string.h>

int main(void)
{
	char hoten[50][100], ho[60], hct[60];
	int i, j, x, count = 0, n;
	printf("Nhap ho can tim: ");
	gets(hct);
	printf("So nguoi trong ds? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Nhap ho ten thu %d: ",i+1);
		scanf("%s",&hoten[i]);
		x = strlen(hoten[i]);
		for(j=0;j<x;j++)
		{
			if(hoten[i][j]!=32) ho[j] = hoten[i][j];
			else break;
		}
		if(strcmp(ho,hct)==0) count++;
	}
	if(count>0) printf("So nguoi co ho %s trong danh sách la %d.",hct,count);
	else printf("Khong co ai ho %s trong danh sach.",hct);
}