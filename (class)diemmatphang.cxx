#include<iostream>

using namespace std;

class diem
{
	float hd, td;
public:
	void input()
	{
		cout<<"Nhap hoanh do - tung do: ";
		cin>>hd>>td;
	}
	void output()
	{
		cout<<"("<<hd<<","<<td<<")"<<endl;
	}
	void change()
	{
		cout<<"Hooanh do moi: ";
		cin>>hd;
		cout<<"Tung do moi: ";
		cin>>td;
	}
};

int main()
{
	int i, x;
	diem d[3];
	for(i=0;i<3;i++)
		d[i].input();
	for(i=0;i<3;i++)
		d[i].output();
	cout<<"Nhap diem can thay doi: ";
	cin>>x;
	d[x-1].change();
	for(i=0;i<3;i++)
		d[i].output();
}