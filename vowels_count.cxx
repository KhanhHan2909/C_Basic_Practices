#include<stdio.h>
#include<string.h>

int main(void)
{
	char s[100];
	int i, x, dem = 0;
	printf("Nhap chuoi: ");
	gets(s);
	x = strlen(s);
	for(i=0;i<x;i++)
  if(s[i]==65||s[i]==69||s[i]==73||s[i]==79||s[i]==85||s[i]==97||s[i]==101||s[i]==105||s[i]==111||s[i]==117) dem++;
	printf("Co %d nguyen am.",dem);
}