#include<iostream>
#include<utility>

using namespace std;

int main()
{
	int b = 1, c = 2, d = 3, e = 4;
	pair<int, int> a(b,c);
	cout<<a.first<<" "<<a.second<<endl;
	pair<int,int> a2(d,e);
	cout<<a2.first<<" "<<a2.second<<endl;
	a.swap(a2);
	cout<<a.first<<" "<<a.second<<endl;
	cout<<a2.first<<" "<<a2.second<<endl;
	cout<<boolalpha<<(a==a2)<<endl;
	cout<<boolalpha<<(a!=a2)<<endl;
	cout<<boolalpha<<(a<a2)<<endl;
	cout<<boolalpha<<(a>a2)<<endl;
}