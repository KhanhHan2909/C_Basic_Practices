#include<iostream>

using namespace std;

void merge(int *a,int l,int m,int r)
{
	int i, j, k = l, x, a1[m-l+1], a2[r-m];
	for(i=l;i<=m;i++) a1[i-l] = a[i];
	for(i=m+1;i<=r;i++) a2[i-m-1] = a[i];
	i= 0; j = 0;
	while(i<m-l+1&&j<r-m)
	{
		if(a1[i]<=a2[j])
		{
			a[k] = a1[i];
			i++;
		}
		else
		{
			a[k] = a2[j];
			j++;
		}
		k++;
	}
	while(i<m-l+1)
	{
		a[k] = a1[i];
		k++;
		i++;
	}
	while(j<r-m)
	{
		a[k] = a2[j];
		k++;
		j++;
	}
}

void mergesort(int *a,int l,int r)
{
	if(l>=r) return;
	int m = l + (r - l)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);
}

int main()
{
	int *a, i, n;
	cout<<"Nhap so phan tu: ";
	cin>>n;
	a = new int[n];
	for(i=0;i<n;i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	int l = 0, r = n - 1;
	mergesort(a,l,r);
	cout<<"Mang da sap xep: ";
	for(i=0;i<n;i++) cout<<a[i]<<" ";
	delete []a;
}