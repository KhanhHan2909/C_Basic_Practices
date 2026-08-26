#include<stdio.h>
#include<string.h>

void main(void)
{
	char s[100];
	int i, x, dem = 0;
	printf("Nhap chuoi: ");
	gets(s);
	x = strlen(s);
	if(x%2==0)
	{
		for(i=0;i<x/2;i++)
			if(s[i]==s[x-1-i]) dem++;
		if(dem==x/2) printf("Chuoi doi xung.");
		else printf("Chuoi khong doi xung.");
	}
	else
	{
		for(i=0;i<(x-1)/2;i++)
			if(s[i]==s[x-1-i]) dem++;
		if(dem==(x-1)/2) printf("Chuoi doi xung.");
		else printf("Chuoi khong doi xung.");
	}
}