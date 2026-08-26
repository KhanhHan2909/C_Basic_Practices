//Chi chay dung khi ma tran input la cua do thi khong chua khuyen

#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

int deg(int a[100][100],int n,int v)
{
	int i, result = 0;
	for(i=0;i<n;i++) if(a[v][i]>0) result++;
	return result;
}

void edgereturn(int a[100][100],int n,int *v,int *t)
{
	a[v[*t]][v[*t-1]] = 1;
	a[v[*t-1]][v[*t]] = 1;
	(*t)--;
	if(deg(a,n,v[*t])<2) edgereturn(a,n,v,t);
}

void eulercycle(int a[100][100],int n,int *v,int *t,bool *done)
{
	int i, j, count = 0, marked = -1, current_v = v[*t], current_d = deg(a,n,current_v);
	bool isconnected = false;
	while(true)
	{
		for(i=0;i<n;i++)
		{
			if(a[current_v][i]>0&&i>marked)
			{
				a[current_v][i] = 0;
				a[i][current_v] = 0;
				(*t)++;
				v[*t] = i;
				marked = i;
				count++;
				break;
			}
		}
		for(i=0;i<n;i++)
			if(a[v[*t]][i]>0)
			{
				isconnected = true;
				break;
			}
		if(isconnected) eulercycle(a,n,v,t,done);
		else
		{
			int donetest = 0;
			for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(!a[i][j]) donetest++;
			if(donetest==(n*(n-1)/2)) *done = true;
			if(!*done) edgereturn(a,n,v,t);
			else break;
		}
		if(current_d<3||*done) break;
		if(current_d>2&&count==current_d)
		{                                                           
			edgereturn(a,n,v,t);
			break;
		}
	}
}

void print(int *v,int *t)
{
	printf("\nChu trinh Euler cua do thi da cho la: ");
	for(int i=0;i<=*t;i++) printf("%d ",v[i]);
}

int main()
{
	int zero = 0, i, j, a[100][100], n, count = 0, *v, *t = &zero;
	bool falsestate = false, *done = &falsestate;
	do
	{
		printf("Nhap so dinh do thi: ");
		scanf("%d",&n);
	} while(n<1);
	v = (int*)malloc(n*sizeof(int));
	v[*t] = 0;
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
		{
			printf("%3d ",a[i][j]);
		}
		printf("\n");
		if(deg(a,n,i)>0&&!(deg(a,n,i)%2)) count++;
	}
	if(count<n) printf("\nDo thi da cho khong co chu trinh Euler.");
	else
	{
		eulercycle(a,n,v,t,done);
		print(v,t);
	}
	free(v);
}