#include<stdio.h>
#include<stdlib.h>

void ktlienthong(int b[100][99],int n,int *c,int *q,int r)
{
	int i = 0, j, test;
	while(i<n)
	{
		if(b[r][i]>-1) 
		{
			test = 0;
			for(j=0;j<=*q;j++) 
				if(c[j]==b[r][i]) 
				{
					test = 1;
					break;
				}
			if(!test)
			{
				c[*q] = b[r][i];
				(*q)++;
				ktlienthong(b,n,c,q,b[r][i]);
			}
			i++;
		}
		else
		{
			if(*q>0) break;
			else
			{
				(*q)++;
				c[0] = r;
				break;
			}
		}
	}
	return;
}

int stplt(int b[100][99],int n)
{
	int zero = 0;
	int ketqua = 0, dem = 0, *c = (int*)malloc(100*sizeof(int)), *q = &zero, d[100], dlength = n, e[99], dem2, ll, r = 0, i, j;
	for(i=0;i<n;i++)
	{
		c[i] = -1;
		d[i] = i;
		e[i] = -1;
	}
	while(dem<n)
	{
		ll = 0;
		ktlienthong(b,n,c,q,r);
		for(i=0;i<dlength;i++)
		{
			dem2 = 0;
			for(j=0;j<*q;j++)
				if(d[i]!=c[j]) dem2++;
			if(dem2==*q) 
			{
				e[ll] = d[i];
				ll++;
			}
		}
		for(i=0;i<ll;i++) 
		{
			d[i] = e[i];
		}
		dlength = ll;
		r = d[0];
		for(i=0;i<ll;i++) c[i] = -1;
		if(!*q) dem++;
		else dem += *q;
		*q = 0; //Nho ki cach gan gia tri hang so nay cho bien con tro!!
		ketqua++;
	}
	free(c);
	return ketqua;
}

int main()
{
	int i, j, n, a[100][100], b[100][99], f;
	printf("Chuong trinh kiem tra 1 do thi vo huong co bao nhieu thanh phan lien thong.\n**********\n");
	do
	{
		printf("Nhap so dinh do thi: ");
		scanf("%d",&n);
	} while(n<1);
	printf("Nhap ma tran ke cua do thi:\n");
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		{
			do
			{
				printf("a[%d][%d] = ",i,j);
				scanf("%d",&a[i][j]);
			} while(a[i][j]<0);
		}
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			a[i][j] = a[j][i];
	printf("\nMa tran ke vua nhap:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++) 
		for(j=0;j<n-1;j++) b[i][j] = -1;
	for(i=0;i<n;i++)
	{
		f = 0;
		for(j=0;j<i;j++)
		{
			if(a[j][i]!=0) 
			{
				b[i][f] = j;
				f++;
			}
		}
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]!=0) 
			{
				b[i][f] = j;
				f++;
			}
		}
	}
	printf("Do thi da cho co %d thanh phan lien thong.",stplt(b,n));
}