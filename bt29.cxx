#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, j, n, dem;
	printf("Nhap so nguyen duong: ");
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		dem = 2;
		for(j=2;j<i;j++) if(i%j!=0) dem++;
		if(dem==i) printf("%d ",i);
	}
	getch();
}