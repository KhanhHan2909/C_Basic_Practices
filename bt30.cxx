#include<stdio.h>
#include<conio.h>

void main(void)
{
	char c;
	do
	{
		printf("Nhap mot ki tu: ");
		scanf("%c",&c);
		if(c>96&&c<123) printf("%c %c\n",c,c-32);
		if(c>64&&c<91) printf("%c %c\n",c,c+32);
		if(c>47&&c<58) printf("%c\n",c);
	} while((c>47&&c<58)||(c>64&&c<91)||(c>96&&c<123));
	getch();
}