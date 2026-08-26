#include<stdio.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}

int stricmp(char s1[Max],char s2[Max])
{
	int i = 0, l1 = strlen(s1), l2 = strlen(s2);
	while(i<l1||i<l2)
	{
		if(s1[i]>64&&s1[i]<91)
		{
			if(s2[i]>96&&s2[i]<123)
			{
				if(s1[i]+32>s2[i]) return 1;
				else if(s1[i]+32<s2[i]) return -1;
				else i++;
			}
			else
			{
				if(s1[i]>s2[i]) return 1;
				else if(s1[i]<s2[i]) return -1;
				else i++;
			}
		}
		else if(s1[i]>96&&s1[i]<123)
		{
			if(s2[i]>64&&s2[i]<91)
			{
				if(s1[i]-32>s2[i]) return 1;
				else if(s1[i]-32<s2[i]) return -1;
				else i++;
			}
			else
			{
				if(s1[i]>s2[i]) return 1;
				else if(s1[i]<s2[i]) return -1;
				else i++;
			}
		}
		else
		{
			if(s1[i]>s2[i]) return 1;
			else if(s1[i]<s2[i]) return -1;
			else i++;
		}
	}
	return 0;
}

int main(void)
{
	char s1[Max], s2[Max];
	int cmp;
	printf("Nhap xau ki tu thu nhat: ");
	gets(s1);
	printf("Nhap xau ki tu thu hai: ");
	gets(s2);
	cmp = stricmp(s1,s2);
	if(cmp==1) printf("Xau thu hai nho hon xau thu nhat!");
		else if(cmp==0) printf("Hai xau bang nhau!");
		else printf("Xau thu nhat nho hon xau thu hai!");
}