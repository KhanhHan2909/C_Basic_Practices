#include<stdio.h>
#include<string.h>

void main(void)
{
	char chi[12][10] = {"Than","Dau","Tuat","Hoi","Ty","Suu","Dan","Mao","Thin","Ti","Ngo","Mui"}, can[10][10] = {"Canh","Tan","Nham","Quy","Giap","At","Binh","Dinh","Mau","Ky"};
	int e, f, n;
	printf("Nhap nam duong lich: ");
	scanf("%d",&n);
	e = n%12;
	f = n%10;
	printf("%s %s",can[f],chi[e]);
}