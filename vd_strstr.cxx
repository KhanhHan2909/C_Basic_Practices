#include<stdio.h>
#include<string.h>

int main()
{
	char s[10] = "blogger", t[10] = "g", *res = strstr(s,t);
	if(res==NULL) printf("0");
	else printf("Vi tri xuat hien cua t trong s: %d",res-s);
//	printf("%d\n%d",res,s);
	printf("\n%s",res);
}
	