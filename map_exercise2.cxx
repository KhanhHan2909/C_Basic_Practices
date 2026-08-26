#include<iostream>
#include<map>

using namespace std;

void main()
{
	int a[1000], b[1000], i, m, n;
	map<int,int> mp1, mp2;
	cout<<"Nhap so pt mang 1: ";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
		mp1[a[i]]++;
	}
	cout<<"Nhap so pt mang 2: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"b["<<i<<"] = ";
		cin>>b[i];
		mp2[b[i]]++;
	}
	for(auto it:mp1) 
		if(mp2.find(it.first)!=mp2.end())
			cout<<"("<<it.first<<","<<it.second+mp2[it.first]<<") ";
}