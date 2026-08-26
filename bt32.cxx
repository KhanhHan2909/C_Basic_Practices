#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i = 1, x, n, demd = 0, dema = 0, demk = 0;
	printf("Co bn so nguyen? ");
	scanf("%d",&n);
	while(i<n+1)
	{
		printf("Nhap so nguyen thu %d: ",i);
		scanf("%d",&x);
		i++;
		if(x>0) demd++;
		if(x<0) dema++;
		if(x==0) demk++;
	}
	printf("Co %d so duong, %d so am, %d so 0.",demd,dema,demk);
	getch();
}