#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int ucln, bcnn, tich, i, a, b;
	do 
	{
		printf("Nhap hai so nguyen duong a, b (a<=b): ");
		scanf("%d %d",&a,&b);
	} while(a>b);
	for(i=a;i>0;i--)
		if(a%i==0&&b%i==0)
		{
			ucln = i;
			break;
		}
	printf("UCLN = %d, ",ucln);
	tich = a*b;
	for(i=b;i<=tich;i++)
		if(i%a==0&&i%b==0)
		{
			bcnn = i;
			break;
		}
	printf("BCNN = %d",bcnn);
	getch();
}