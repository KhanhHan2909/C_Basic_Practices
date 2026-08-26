#include<stdio.h>
#include<string.h>

int main(void)
{
	char s1[100], s2[50];
	int i, j, x, y, c;
	printf("Nhap xau ki tu goc: ");
	gets(s1);
	printf("Nhap xau can do vi tri: ");
	scanf("%s",&s2);
	x = strlen(s1);
	y = strlen(s2);
	for(i=0;i<x;i++)
		if(s1[i]==s2[0])
		{
			c = 0;
			for(j=i;j<i+y;j++)
				if(s1[j]==s2[j-i]) c++;
			if(c==y)
			{
				printf("\n\nXau nguon la: %s",s1);
				printf("\nXau con la: %s",s2);
				printf("\nVi tri bat dau cua xau con la: %d",i+1);
			}
		}
}