#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int i, n;
	cout<<"Nhap so luong pt: ";
	cin>>n;
	vector<int> v(n);
	for(i=0;i<v.size();i++)
	{
		cout<<"Pt thu "<<i+1<<" : ";
		cin>>v[i];
	}
	for(i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}