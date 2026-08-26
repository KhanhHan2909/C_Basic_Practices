#include<stdio.h>
#include<math.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}
	
float atoi(char s[Max])
{
	int i, j, l, c = 0, c0 = 2;
	float n = 0;
	l = strlen(s);
	if(s[0]==45)
	{
		for(i=1;i<l;i++) 
			if((s[i]<48&&s[i]!=46)||s[i]>57) 
				return 0;
		if(s[1]==46) return 0;
		if(s[l-1]==46) return 0;
		for(i=2;i<l-1;i++) if(s[i]==46) c++;
		if(c>1) return 0;
		for(i=2;i<l-1;i++)
			if(s[i]!=46) c0++;
		if(c0==l-1)
		{
			for(i=l-1;i>0;i--) 
				n += (s[i]-48)*pow(10,l-1-i);
			n *= -1;
			return n;
		}
		else
		{
			for(i=2;i<l-1;i++) if(s[i]==46) break;
			for(j=i-1;j>0;j--) 
				n += (s[j]-48)*pow(10,i-1-j);
			for(j=i+1;j<l;j++)
				n += (s[j]-48)*pow(10,-(j-i));
			n *= -1;
				return n;
		}
	}
	else
	{
		for(i=0;i<l;i++) 
			if((s[i]<48&&s[i]!=46)||s[i]>57) 
				return 0;
		if(s[0]==46) return 0;
		if(s[l-1]==46) return 0;
		for(i=1;i<l-1;i++) if(s[i]==46) c++;
		if(c>1) return 0;
		for(i=1;i<l-1;i++)
			if(s[i]!=46) c0++;
		if(c0==l)
		{
			for(i=l-1;i>-1;i--) 
				n += (s[i]-48)*pow(10,l-1-i);
			return n;
		}
		else
		{
			for(i=1;i<l-1;i++) if(s[i]==46) break;
			for(j=i-1;j>-1;j--) 
				n += (s[j]-48)*pow(10,i-1-j);
			for(j=i+1;j<l;j++)
				n += (s[j]-48)*pow(10,-(j-i));
			return n;
		}
	}
}
	
int main(void)
{
	char s[Max];
	printf("Nhap xau ki tu (so thap phan dang xau): ");
	gets(s);
	printf("So thap phan duoc chuyen doi tu xau tren: %f",atoi(s));
}