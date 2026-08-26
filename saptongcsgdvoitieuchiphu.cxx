#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int tong(int n)
{
	int s = 0;
	while(n>0)
	{
		s += n%10;
		n /= 10;
	}
	return s;
}

bool cmp(int a,int b)
{
	if(tong(a)!=tong(b)) return tong(a)>tong(b);
	else return a>b;
}

int main()
{
	int a[] = {111,9,3000,20001}, i;
	sort(a,a+4,cmp);
	cout<<"Mang sau khi sap xep: ";
	for(i=0;i<4;i++) cout<<a[i]<<" ";
}