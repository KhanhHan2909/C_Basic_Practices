#include<stdio.h>
#include<stdlib.h>

void nhapmang(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",a+i);
	}
}

void xuatmang(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void lkmc(int *a,int n)
{
	int i, j, k, ktmc;
	printf("Liet ke mang con: ");
	for(ktmc=1;ktmc<=n;ktmc++)
		for(i=ktmc-1;i<n;i++)
		{
			printf("{");
			for(j=i+1-ktmc;j<=i;j++) 
				printf("%d ",a[j]);
			printf("} ");
		}
}

void lkmctdvt(int *a,int n)
{
	int i, j, k, ktmc, dem, tong;
	printf("Liet ke mang con tang dan kem tong: ");
	for(ktmc=1;ktmc<=n;ktmc++)
		for(i=ktmc-1;i<n;i++)
		{
			dem = 1;
			for(j=i+1-ktmc;j<i;j++)
				if(a[j]<a[j+1]) dem++;
			if(dem==ktmc)
			{
				tong = 0;
				printf("{");
				for(j=i+1-ktmc;j<=i;j++) 
					printf("%d ",a[j]);
				printf("}");
				for(j=i+1-ktmc;j<=i;j++) tong += a[j];
				printf("--(%d)  ",tong);
			}
		}
}

void mctln(int *a,int n)
{
	int i, j, ktmc, m = 0, *a2, *tong, k = 0, l, max;
	for(ktmc=1;ktmc<n+1;ktmc++) m += (n - ktmc + 1);
	a2 = (int*)calloc(m*(n+1),sizeof(int));
	tong = (int*)calloc(m,sizeof(int));
	printf("Liet ke mang con co tong lon nhat: ");
	for(ktmc=1;ktmc<n+1;ktmc++)
		for(i=ktmc-1;i<n;i++)
		{
			tong[k] = 0;
			l = 0;
			for(j=i+1-ktmc;j<=i;j++)
			{
				a2[(n+1)*k+l] = a[j];
				tong[k] += a[j];
				l++;
			}
			a2[(n+1)*k+n] = l;
			k++;
		}
	max = tong[0];
	for(i=0;i<m;i++) if(tong[i]>max) max = tong[i];
	for(i=0;i<m;i++)
	{
		if(tong[i]==max)
		{
			printf("{");
			for(j=0;j<a2[(n+1)*i+n];j++) 
				printf("%d ",a2[(n+1)*i+j]);
			printf("} ");
		}
	}
	/*printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n+1;j++) printf("%3d ",a2[(n+1)*i+j]);
		printf("\n");
	}*/
	free(a2);
	free(tong);
}

void mctddn(int *a,int n)
{
	int i, j, ktmc, dem1, dem2 = 0;
	printf("Liet ke cac mang con toan duong dai nhat: ");
	for(ktmc=n;ktmc>0;ktmc--)
	{
		for(i=ktmc-1;i<n;i++)
		{
			dem1 = 0;
			for(j=i+1-ktmc;j<=i;j++)
				if(a[j]>0) dem1++;
			if(dem1==ktmc)
			{
				dem2++;
				printf("{");
				for(j=i+1-ktmc;j<=i;j++) printf("%d ",a[j]);
				printf("} ");
			}
		}
		if(dem2>0) break;
	}
}

int main(void)
{
	int *a, n;
	printf("Co bn pt?");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	nhapmang(a,n);
	printf("\n");
	xuatmang(a,n);
	printf("\n");
	lkmc(a,n);
	printf("\n");
	lkmctdvt(a,n);
	printf("\n");
	mctln(a,n);
	printf("\n");
	mctddn(a,n);
	free(a);
}