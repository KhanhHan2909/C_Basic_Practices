#include<stdio.h>
#include<math.h>

#define Max 100

int strlen(char s[Max])
{
	int l = 0;
	while(s[l]!='\0') l++;
	return l;
}
	
void itoa(int n,char s[Max])
{
	int i, l = 0, l0, x = n, d;
	if(n==0)
	{
		s[0] = 48; s[1] = '\0';
	}
	else
	{
		while(x)
		{
			l++;
			x /= 10;
		}
		if(n>0)
		{
			x = n; l0 = l;
			while(x)
			{
				d = x%10;
				s[l0-1] = d + 48;
				l0--;
				x/= 10;
			}
		}
		else
		{
			x = n; l0 = l;
			while(x)
			{
				d = abs(x)%10;
				s[l0] = d + 48;
				l0--;
				x/= 10;
			}
			s[0] = 45;
		}
	}
}
	
int main(void)
{
	char s[Max];
	int n;
	printf("Nhap so nguyen: ");
	scanf("%d",&n);
	itoa(n,s);
	printf("Xau ki tu duoc chuyen doi tu so nguyen tren: %s",s);
}