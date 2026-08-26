#include<stdio.h>
#include<conio.h>

void main(void)
{
	int i, j, n, a0[100], a1[100], b;
	printf("Kich thuoc mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("So nguyen thu %d: ",i+1);
		scanf("%d",&a0[i]);
		a1[i] = a0[i];
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a0[i]>a0[j])
			{
				b = a0[i]; a0[i] = a0[j]; a0[j] = b;
			}
	for(j=0;j<n;j++) printf("%d ",a0[j]);
	printf("\n");
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a0[i]<a0[j])
			{
				b = a0[i]; a0[i] = a0[j]; a0[j] = b;
			}
	for(i=0;i<n;i++) printf("%d ",a0[i]);
	printf("\n");
	for(j=0;j<n;j++) printf("%d ",a1[j]);
	getch();
}