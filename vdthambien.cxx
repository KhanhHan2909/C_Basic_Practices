#include<stdio.h>

void time(int &ig, int &ip)
{
	ig = ip/60;
	ip %= 60;
}

int main(void)
{
	int ig, ip;
	printf("Nhap vao sp: ");
	scanf("%d",&ip);
	time(ig,ip);
	printf("%d:%d",ig,ip);
}