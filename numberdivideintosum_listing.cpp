#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	int i, j, n, *a, minisum;
	do
	{
		printf("Nhap so nguyen duong can phan chia: ");
		scanf("%d",&n);
	} while(n<1);
	a = (int*)malloc(n*sizeof(int));
	a[0] = n;
	for(i=1;i<n;i++) a[i] = 0;
	printf("Sau day la cac cach phan chia so tren thanh tong cac so nguyen duong khong lon hon no:\n");
	printf("%d\n",n);
	bool stop = false;
	while(!stop)
	{
		for(i=n-1;i>=0;i--) if(a[i]>0) break;
		if(a[i]>1)
		{
			a[i]--;
			a[++i] = 1;
		}
		else
		{
			j = i;
			while(a[j]==1) j--;
			a[j]--;
			minisum = i - j + 1;
			while(minisum>0)
			{
				if(minisum>=a[j]) a[j+1] = a[j];
				else a[j+1] = minisum;
				minisum -= a[j];
				j++;
			}
			if(j>=i) i = j;
			else
                while(i>j)
                {
                    a[i] = 0;
                    i--;
                }
		}
		for(j=0;j<i;j++) printf("%d + ",a[j]);
		printf("%d\n",a[i]);
		if(a[n-1]==1) stop = true;
	}
	free(a);
}
