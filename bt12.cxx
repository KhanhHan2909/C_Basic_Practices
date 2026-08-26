#include<stdio.h>
#include<conio.h>

void main(void)
{
	unsigned int i, n;
	int dem = 1;
	printf("Nhap mot so nguyen duong: ");
	scanf("%d",&n);
	if(n==1) printf("So ban vua nhap khong phai so nguyen to.");
	else
	{	
		for(i=2;i<n;i++) if(n%i!=0) dem++;
		if(dem==n-1) printf("So ban vua nhap la so nguyen to.");
		else printf("So ban vua nhap khong phai so nguyen to");
	}
	getch();
}