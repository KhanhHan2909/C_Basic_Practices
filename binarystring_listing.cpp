#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, n, *a, count;
	do
	{
		printf("Nhap do dai toi da cua xau nhi phan (>=0): ");
		scanf("%d",&n);
	} while(n<0);
	a = (int*)malloc(n*sizeof(int));
	printf("Cac xau nhi phan co do dai %d la:\n",n);
	for(i=0;i<n;i++) 
	{
		a[i] = 0;
		printf("%d",a[i]);
	}
	printf("\n");
	bool stop = false;
	while(!stop)
	{
		for(i=n-1;i>=0;i--)
			if(!a[i])
			{
				a[i] = 1;
				for(j=i+1;j<n;j++) a[j] = 0;
				break;
			}
		for(i=0;i<n;i++) printf("%d",a[i]);
		printf("\n");
		count = 0;
		for(i=0;i<n;i++) if(a[i]) count++;
		if(count==n) stop = true;
	}
	free(a);
}