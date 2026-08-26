#include<iostream>
#include<iomanip>

using namespace std;

void xuatmt(int m,int n,int a[50][50])
{
	int i, j;
	cout<<"Ma tran vua nhap:\n";
	for(i=0;i<m;i++)
	{	
		for(j=0;j<n;j++)
	cout<<setw(6)<<a[i][j]<<" ";
		cout<<endl;
	}
}

void xoayoc(int m,int n,int a[50][50])
{
	int i, j, k = 1;
	if(m<n)
	{
		for(i=0;i<m/2;i++)
		{
			for(j=i;j<n-i-1;j++) 
			{
				a[i][j] = k;
				k++;
			}
			for(j=i;j<m-i-1;j++)
			{
				a[j][n-i-1] = k;
				k++;
			}
			for(j=n-i-1;j>i;j--)
			{
				a[m-i-1][j] = k;
				k++;
			}
			for(j=m-i-1;j>i;j--)
			{
				a[j][i] = k;
				k++;
			}
		}
		if(m%2==1)
			for(i=m/2;i<n-m/2;i++)
			{
				a[m/2][i] = k;
				k++;
			}
	}
	else
	{
		for(i=0;i<n/2;i++)
		{
			for(j=i;j<n-i-1;j++) 
			{
				a[i][j] = k;
				k++;
			}
			for(j=i;j<m-i-1;j++)
			{
				a[j][n-i-1] = k;
				k++;
			}
			for(j=n-i-1;j>i;j--)
			{
				a[m-i-1][j] = k;
				k++;
			}
			for(j=m-i-1;j>i;j--)
			{
				a[j][i] = k;
				k++;
			}
		}
		if(n%2==1)
			for(i=n/2;i<m-n/2;i++)
			{
				a[i][n/2] = k;
				k++;
			}
	}
}

int main()
{
	int a[50][50], m, n;
	cout<<"So hang:  ";
	cin>>m;
	cout<<"So cot: ";
	cin>>n;
	xoayoc(m,n,a);
	xuatmt(m,n,a);
}