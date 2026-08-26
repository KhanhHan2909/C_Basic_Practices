#include<iostream>

using namespace std;

int tohop(int n,int k)
{
	if(k==0||n==k) return 1;
	return tohop(n-1,k-1) + tohop(n-1,k);
}

int main()
{
	int n, k;
	
	cout<<"Nhap n: ";
	cin>>n;
	do
	{
		cout<<"Nhap k: ";
		cin>>k;
	} while(k>n);
	cout<<"To hop chap "<<k<<" cua "<<n<<": "<<tohop(n,k);
}