#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
	string hoten, w;
	int i;
	cout<<"Nhap ho ten: ";//Mac dinh  ten da duoc chuan hoa Title Case
	getline(cin,hoten);
	stringstream ss(hoten);
	vector<string> v;
	while(ss>>w) v.push_back(w);
	cout<<"Ho ten theo thu tu ten den ho dem la ";
	cout<<v[v.size()-1]<<" ";
	for(i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
	v[v.size()-2].pop_back();
}