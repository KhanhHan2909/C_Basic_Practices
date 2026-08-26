#include<stdio.h>
#include<math.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}
	
int atoi(char s[Max])
{
	int i, l, n = 0;
	l = strlen(s);
	if(s[0]==45)
	{
		for(i=1;i<l;i++) 
			if(s[i]<48||s[i]>57) 
				return 0;
		for(i=l-1;i>0;i--) n += (s[i]-48)*pow(10,l-1-i);
		n *= -1;
		return n;
	}
	else
	{
		for(i=0;i<l;i++) 
			if(s[i]<48||s[i]>57) 
				return 0;
		for(i=l-1;i>-1;i--) n += (s[i]-48)*pow(10,l-1-i);
		return n;
	}
}
	
int main(void)
{
	char s[Max];
	printf("Nhap xau ki tu: ");
	gets(s);
	printf("So nguyen duoc chuyen doi tu xau tren: %d",atoi(s));
}