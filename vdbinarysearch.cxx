#include<iostream>
#include<algorithm>

using namespace std;

void nhapmang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
}

void xuatmang(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

bool binarysearch(int a[],int n,int x)
{
	int l = 0, r = n - 1;
	while(l<=r)
	{
		int m = (l + r)/2;
		if(a[m]==x) return true;
		else if(a[m]<x) l = m + 1;
		else r = m - 1;
	}
	return false;
}

int firstpos(int a[],int n, int x)
{
	int m, l = 0, r = n - 1;
	while(l<=r)
	{
		m = (l + r)/2;
		if(a[m]==x) break;
		else if(a[m]<x) l = m + 1;
		else r = m - 1;
	}
	if(l>r) return -1;
	else while(a[m]==a[m-1]&&m>0) m--;
	return m;
}
int firstpos2(int a[],int n,int x)
{
	int l = 0, r = n - 1, p = -1;
	while(l<=r)
	{
		int m = (l + r)/2;
		if(a[m]>=x)
		{
			p = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return p;
}

int main()
{
	int a[1000], x, n;
	cout<<" Ktm: "; cin>>n;
	nhapmang(a,n);
	xuatmang(a,n);
	cout<<"Nhap gia tri can tim kiem: ";
	cin>>x;
	stable_sort(a,a+n);
	if(binarysearch(a,n,x)==true) 
	{
		cout<<"Gia tri "<<x<<" ton tai trong mang!";
		cout<<endl<<"Vi tri dau tien cua "<<x<<": "<<firstpos(a,n,x);
	}
	else cout<<"Gia tri "<<x<<" khong ton tai trong mang!";
	cout<<endl;
//	cout<<a[-2]<<endl;
	int f = firstpos2(a,n,x);
	if(f==-1) cout<<"Khong co vi tri lon hon hoac bang "<<x<<"!";
	else cout<<"Vi tri dau tien lon hon hoac bang "<<x<<" la "<<f<<", gia tri bang "<<a[f];
}
	