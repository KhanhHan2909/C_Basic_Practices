#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, a, b, c;
	for(i=100;i<1000;i++)
	{
		a = i/100; 
		b = (i - a*100)/10; 
		c = i - a*100 - b*10;
		if(a*b*c==a+b+c) printf("%d ",i);
	}
	getch();
}