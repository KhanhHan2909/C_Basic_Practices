#include<iostream>
#include<iomanip>

using namespace std;

void xuatmt(int n,float a[50][50])
{
	int i, j;
	cout<<"Ma tran vua nhap:\n";
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
	cout<<setw(6)<<fixed<<setprecision(1)<<a[i][j]<<" ";
		cout<<endl;
	}
}

void xoayoc(int n,float a[50][50])
{
	int i, j;
	float dem = 1;
	for(i=0;i<n/2;i++)
	{
		for(j=i;j<n-i-1;j++) 
		{
			a[i][j] = dem;
			dem++;
		}
		for(j=i;j<n-i-1;j++)
		{
			a[j][n-i-1] = dem;
			dem++;
		}
		for(j=n-i-1;j>i;j--)
		{
			a[n-i-1][j] = dem;
			dem++;
		}
		for(j=n-i-1;j>i;j--)
		{
			a[j][i] = dem;
			dem++;
		}
	}
	if(n%2==1) a[n/2][n/2] = dem;
}

int main()
{
	float a[50][50], dem = 1;
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	xoayoc(n,a);
	xuatmt(n,a);
}