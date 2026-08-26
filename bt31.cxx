#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(void)
{
	int i, x, n;
	float p = 0, q = 0;
	printf("Nhap x va so dau can: ");
	scanf("%d %d",&x,&n);
	for(i=1;i<=n;i++) p = sqrt(x + p);
	printf("Gia tri bt: %.2f\n",p);
	printf("Nhap x va n: ");
	scanf("%d %d",&x,&n);
	for(i=0;i<=n;i++) q += pow(x,i)/(i + 1);
	printf("Gia tri bt: %.2f",q);
	getch();
}