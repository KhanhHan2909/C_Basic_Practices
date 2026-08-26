#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, n, k, *a, count;
	do
	{
		printf("Nhap do lon n cua tap hop X = {1, 2, ..., n}: ");
		scanf("%d",&n);
	} while(n<1);
	do
	{
		printf("Nhap do lon k cua tap con cua X: ");
		scanf("%d",&k);
	} while(k<1||k>n);
	printf("Cac tap con %d phan tu cua X la:\n");
	a = (int*)malloc(k*sizeof(int));
	for(i=1;i<=k;i++)
	{
		a[i] = i;
		printf("%d ",a[i]);
	}
	printf("\n");
	bool stop = false;
	while(!stop)
	{
		if(a[2]==n-k+2&&a[1]<n-k+1) a[1]++;
		for(i=2;i<k;i++)
		{
			if(a[i+1]==n-k+i+1)
			{
				if(a[i]<n-k+i) a[i]++;
				else if(a[i-1]<n-k+i-1) a[i] = a[i-1] + 1;
			}
		}
		if(a[k]<n) a[k]++;
		else if(a[k-1]<n-1) a[k] = a[k-1] + 1;
		count = 0;
		for(i=1;i<=k;i++)
		{
			printf("%d ",a[i]);
			if(a[i]==n-k+i) count++;
		}
		printf("\n");
		if(count==k) stop = true;
	}
}