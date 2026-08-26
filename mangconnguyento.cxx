#include<stdio.h>
#include<stdlib.h>

int prime(int n)
{
	int i, dem = 0;
	for(i=2;i<=n;i++)
		if(n%i==0) dem++;
	if(dem==1) return 1;
	else return 0;
}

void nhapmang(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}

void xuatmang(int *a,int n)
{
	int i;
	for(i=0;i<n;i++) printf("%d ",a[i]);
}

void longestprimearr(int *a,int n)
{
	int i, j, k, dem1 = 0, dem2, dem3 = 0, *b, m, maxsize, maxval = 0;
	for(i=1;i<=n;i++) m += n - i + 1;
	b = (int*)calloc((n+2)*m,sizeof(int));
	for(i=1;i<=n;i++)
		for(j=i-1;j<n;j++)
		{
			dem2 = 0;
			for(k=j+1-i;k<=j;k++)
				if(prime(a[k])) dem2++;
			if(dem2==i)
			{
				for(k=j+1-i;k<=j;k++) b[(n+2)*dem1+k-j-1+i] = a[k];
				b[(n+2)*dem1+n] = i;
				for(k=0;k<i;k++) b[(n+2)*dem1+n+1] += b[(n+2)*dem1+k];
				dem1++;
			}
		}
	if(dem1==0) printf("\nKhong co so nguyen to!");
	else
	{
		printf("\nCac mang con nguyen to dai nhat (voi tong lon nhat trong cac mang cung do dai): ");
		maxsize = b[n];
		for(i=0;i<dem1;i++)
			if(maxsize<b[(n+2)*i+n]) 
				maxsize = b[(n+2)*i+n];
		for(i=0;i<dem1;i++)
			if(b[(n+2)*i+n]==maxsize) dem3++;	
		if(dem3>1)
		{
			for(i=0;i<dem1;i++)
				if(b[(n+2)*i+n]==maxsize)
					if(b[(n+2)*i+n+1]>maxval) maxval = b[(n+2)*i+n+1];
			for(i=0;i<dem1;i++)
				if(b[(n+2)*i+n]==maxsize)
					if(b[(n+2)*i+n+1]==maxval)
					{
						printf("{");
						for(j=0;j<maxsize;j++) printf("%d ",b[(n+2)*i+j]);
						printf("} ");
					}
		}
		else
		{
			for(i=0;i<dem1;i++)
				if(b[(n+2)*i+n]==maxsize)
				{
					printf("{");
					for(j=0;j<maxsize;j++) printf("%d ",b[(n+2)*i+j]);
					printf("} ");
				}
		}
	}
	printf("\n");
	for(i=0;i<dem1;i++)
	{
			for(j=0;j<n+2;j++) printf("%d ",b[(n+2)*i+j]);
			printf("\n");
	}
			
	free(b);
}

int main()
{
	int *a, n;
	printf("Mang co bn pt? ");
	scanf("%d",&n);
	a = (int*)calloc(n,sizeof(int));
	nhapmang(a,n);
	xuatmang(a,n);
	longestprimearr(a,n);
	free(a);
}