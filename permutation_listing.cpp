#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, n, *a, localmin, temp, count;
	do
	{
		printf("Nhap kich thuoc n cua tap hop co dang X = {1, 2, ..., n}: ");
		scanf("%d",&n);
	} while(n<1);
	a = (int*)malloc(n*sizeof(int));
	printf("Cac hoan vi cua X duoc liet ke duoi day:\n");
	for(i=1;i<=n;i++)
	{
		a[i] = i;
		printf("%d ",i);
	}
	printf("\n");
	bool stop = false;
	while(!stop)
	{
		for(i=n-1;i>0;i--) 
			if(a[i]<a[i+1])
			{
				localmin = a[i+1];
				break;
			}
		for(j=i+1;j<=n;j++) if(a[j]>a[i]&&a[j]<localmin) localmin = a[j];
		for(j=i+1;j<=n;j++) if(a[j]==localmin) break;
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
		for(j=i+1;j<=i+(n-i)/2;j++)
		{
			temp = a[j];
			a[j] = a[n-j+i+1];
			a[n-j+i+1] = temp;	
		}
		for(i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		count = 0;
		for(i=n;i>0;i--) if(a[i]==n-i+1) count++;
		if(count==n) stop = true;
	}
	free(a);
}