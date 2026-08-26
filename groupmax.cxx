#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, n, max, a[100];
	printf("Kich thuoc mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("So nguyen thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
	max = a[0];
	for(i=1;i<n;i++)
		if(a[i]>=max) max = a[i];
		printf("Max = %d",max);
	getch();
}