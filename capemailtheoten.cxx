#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
	string hoten, w;
	int i;
	cout<<"Nhap ho ten: ";//Mac dinh  ten chi toan chu cai thuong
	getline(cin,hoten);
	stringstream ss(hoten);
	vector<string> v;
	while(ss>>w) v.push_back(w);
	string email = {v[v.size()-1]};
	for(i=0;i<v.size()-1;i++) email += v[i][0];
	email += "@gmail.com";
	cout<<"Email: "<<email;
}