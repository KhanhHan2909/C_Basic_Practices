#include<stdio.h>
#include<math.h>

void minrange(int n,float a[100],float a0[2][4950],float a00[4950])
{
	int i, j, k = 0;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			a0[0][k] = a[i]; a0[1][k] = a[j];
			a00[k] = abs(a[i]-a[j]);
			k++;
		}
	float min = a00[0];
	for(i=1;i<k;i++) if(a00[i]<min) min = a00[i];
	printf("Khoang cach ngan nhat giua hai phan tu la %.2f",min);
	printf("\nCac cap phan tu co khoang cach ngan nhat la: ");
	for(i=0;i<k;i++)
		if(a00[i]==min) printf("(%.2f ; %.2f) ",a0[0][i],a0[1][i]);
}

//void minrange(int n,float a[2][4950],float a0[4950])
//{
//	int i;

//}

int main(void)
{
	int i, n;// fsize = n*(n-1)/2;
	float a[100], b[2][4950], c[4950];
	printf("Nhap kich thuoc mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%f",&a[i]);
	}
	minrange(n,a,b,c);
//	minrange(fsize,b,c);
}