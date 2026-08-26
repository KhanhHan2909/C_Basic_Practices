#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max(int *a,int n)
{
	int max = *(a);
	for(int i=1;i<n;i++)
		if(max<*(a+i)) max = *(a+i);
		return max;
}

int min(int *a,int n)
{
	int min = *(a);
	for(int i=1;i<n;i++)
		if(min>*(a+i)) min = *(a+i);
		return min;
}

void tangdan(int *a,int n)
{
	int i, j, temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(a+i)>*(a+j))
			{
				temp = *(a+i);
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
}

void giamdan(int *a,int n)
{
	int i, j, temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]<a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}

void xuatmang(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void lancanchan(int *a,int n)
{
	int c = 0, i, j, k, *a2;
	a2 = (int*)malloc(n*sizeof(int));
	if(n==1) printf("Khong co gia tri thoa man!");
	else
	{
		if(a[0]%2==0&&a[1]%2==0)
		{
			a2[c] = a[0];
			c++;
		}
		for(i=1;i<n-1;i++)
			if(a[i]%2==0&&a[i-1]%2==0||a[i+1]%2==0&&a[i]%2==0)
			{
				a2[c] = a[i];
				c++;
			}
		if(a[n-1]%2==0&&a[n-2]%2==0)
		{
			a2[c] = a[n-1];
			c++;
		}
		if(c==0) printf("Khong co gia tri thoa man!");
		else
		{
			for(i=0;i<c-1;i++)
				for(j=i+1;j<c;j++)
					if(a2[i]==a2[j])
					{
						for(k=j;k<c;k++) a2[k] = a2[k+1];
						c--; j--;
					}
			printf("GTTM: ");
			for(i=0;i<c;i++) printf("%d ",a2[i]);
		}
	}
	free(a2);
}

int chanlienke(int *a,int n)
{
	int i, c = 0;
	if(a[0]%2==0&&a[1]%2==0) c+=2;
	for(i=1;i<n-1;i++)
	{
		if(a[i]%2==0&&a[i+1]%2==0&&a[i-1]%2==1) c+=2;
		if(a[i]%2==0&&a[i+1]%2==0&&a[i-1]%2==0) c++;
	}
	return c;
}

void lkts(int *a,int n)
{
	int i, j, k, m, *a2, *a3;
	a2 = (int*)malloc(n*sizeof(int));
	a3 = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) 
	{
		a2[i] = a[i];
		a3[i] = 0;
	}
	m = n;
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
			if(a2[i]==a2[j])
			{
				for(k=j;k<m;k++) a2[k] = a2[k+1];
				m--; j--;
			}
	for(i=0;i<m;i++) 
		for(j=0;j<n;j++)
			if(a2[i]==a[j]) a3[i]++;
	printf("\nCac gia tri phan biet: ");
	for(i=0;i<m;i++) printf("%d ",a2[i]);
	printf("\nTan suat xuat hien lan luot la: ");
	for(i=0;i<m;i++) printf("%d ",a3[i]);
	free(a2); free(a3);
}

int ucln(int *a,int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=a[0];j>=1;j--)
			if(a[0]%j==0&&a[i]%j==0) 
			{
				a[0] = j;
				break;
			}
	}
	return a[0];
}
	
int bcnn(int *a,int n)
{
	int i, j, x;
	for(i=0;i<n;i++)
		for(j=1;j<=a[0];j++)
			if(a[0]%j==0)
			{
				x = a[i]*j;
				if(x%a[0]==0)
				{
					a[0] = x;
					break;
				}
			}
	return a[0];
}

int solanxuathien(int *a,int *a2,int n,int m)
{
	int i, j, c1, c2= 0;
	for(i=0;i<=m-n;i++)
	{
		c1 = 0;
		for(j=0;j<n;j++)
			if(a[j]==a2[i+j]) c1++;
		if(c1==n) c2++;
	}
	return c2;
}

void wavy(int *a,int n)
{
	int i, c1 = 0, c2 = 0;
	if(n==1||n==2) printf("\nMang khong phai so'ng!");
	else if(n==3)
	{
		if(a[1]>a[0]&&a[1]>a[2]) printf("\nMang dang so'ng!");
		else if(a[1]<a[0]&&a[1]<a[2]) printf("\nMang dang so'ng!");
		else printf("\nMang khong phai so'ng!");
	}
	else
	{
		if(n%2==0)
		{
			for(i=2;i<n-1;i+=2)
			{
				if(a[0]>a[1]) c1++;
				if(a[i]>a[i-1]&&a[i]>a[i+1]) c1++;
			}
			for(i=2;i<n-1;i+=2)
			{
				if(a[0]<a[1]) c2++;
				if(a[i]<a[i-1]&&a[i]<a[i+1]) c2++;
			}
			if(c1==n/2||c2==n/2) printf("\nMang dang so'ng!");
			else printf("\nMang khong phai so'ng!");
		}
		else
		{
			for(i=2;i<n-2;i+=2)
			{
				if(a[0]>a[1]) c1++;
				if(a[i]>a[i-1]&&a[i]>a[i+1]) c1++;
				if(a[n-1]>a[n-2]) c1++;
			}
			for(i=2;i<n-2;i+=2)
			{
				if(a[0]<a[1]) c2++;
				if(a[i]<a[i-1]&&a[i]<a[i+1]) c2++;
				if(a[n-1]<a[n-2]) c2++;
			}
			if(c1==(n+1)/2||c2==(n+1)/2) printf("\nMang dang so'ng!");
			else printf("\nMang khong phai so'ng!");
		}
	}
}

void thaykhang253(int *a,int *a2,int n,int m)
{
	int i, j, c1, c2 = 0;
	for(i=0;i<n;i++)
	{
		c1 = 0;
		for(j=0;j<m;j++)
			if(a[i]==a2[j]) c1++;
		if(c1>0) c2++;
	}
	if(c2==n) printf("Tat ca phan tu mang 1 nam trong mang 3!");
	else printf("Khong thoa man yeu cau!");
}

int main(void)
{
	int *a, i, n, m, p, *b, *a2, *c;
	printf("Co bn pt?");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	b = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) b[i] = abs(a[i]);
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",a+i);
	}
	printf("So ln: %d\n",max(a,n));
	printf("So nn: %d\n",min(a,n));
	lancanchan(a,n);
	printf("\nSo phan tu chan lien ke la %d",chanlienke(a,n));
	lkts(a,n);
	wavy(a,n);
//	printf("\nUCLN = %d",ucln(b,n));
//	printf("\nBCNN = %d",bcnn(b,n));
	do
	{
		printf("\nMang thu 2 co bn pt?(m>=n)");
		scanf("%d",&m);
	} while(m<n);
	a2 = (int*)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
	{
		printf("a2[%d] = ",i);
		scanf("%d",a2+i);
	}
	printf("So lan xuat hien cua mang 1 trong mang 2 la %d",solanxuathien(a,a2,n,m));
	printf("\nMang thu 3 co bn pt?");
	scanf("%d",&p);
	c = (int*)malloc(p*sizeof(int));
	for(i=0;i<p;i++)
	{
		printf("a3[%d] = ",i);
		scanf("%d",c+i);
	}
	thaykhang253(a,c,n,p);
	free(a);
	free(b);
	free(c);
	free(a2);
}