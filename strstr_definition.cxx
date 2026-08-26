#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

void strstr(char s1[Max],char s2[Max],char s3[Max])
{
	int i = 0, j, l1 = strlen(s1), l2 = strlen(s2), count;
	while(i<l1)
	{
		count = 0;
		for(j=0;j<l2;j++) 
			if(s2[j]==s1[i+j]) count++;
		if(count==l2)
		{
			for(j=i;j<l1;j++) s3[j-i] = s1[j];
			s3[l1-i] = '\0';
			break;
		}
		i++;
	}
}

int main(void)
{
	char s1[Max], s2[Max], s3[Max];
	printf("Nhap xau ki tu thu nhat: ");
	gets(s1);
	printf("Nhap xau ki tu thu hai: ");
	gets(s2);
	strstr(s1,s2,s3);
//	if(l==0) printf("Xau thu hai khong ton tai trong xau thu nhat!");
//	else
//	{
		printf("Xau duoc cat tu xau thu nhat voi xau thu hai o dau (lay vi tri dau tien cua xau hai) la: ");
		puts(s3);
//	}
}