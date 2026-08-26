#include<stdio.h>
#include<conio.h>

int fibonacci(int i)
{
	if(i==1||i==2) return 1;
	else return fibonacci(i-2) + fibonacci(i-1);
}

void main(void)
{
	int n;
	printf("Nhap so hang can tim trong day Fibonacci: ");
	scanf("%d",&n);
	printf("%d",fibonacci(n));
	getch();
}