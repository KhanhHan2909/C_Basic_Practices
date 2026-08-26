#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>

using namespace std;

void main()
{
	string s, w;
	int i, n;
	cout<<"Nhap doan van: ";
	getline(cin,s);
	map<string,int> mp;
	stringstream ss(s);
	while(ss>>w) mp[w]++;
	for(auto it:mp)
		cout<<"Tu '"<<it.first<<"' xuat hien "<<it.second<<" lan\n";
}