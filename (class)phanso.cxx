#include<iostream>

using namespace std;

int ucln(int m, int n)
{
	while(n>0)
	{
		if(m>n) m -= n;
		else n -= m;
	}
	return m;
}

class phanso
{
	int tuso, mauso;
	public:
	void input()
	{
		cout<<"Nhap tu so: ";
		cin>>tuso;
		do
		{
			cout<<"Nhap mau so: ";
			cin>>mauso;
		} while(mauso<=0);
	}
	void cong(phanso &d1,phanso &d2)
	{
		mauso = d1.mauso*d2.mauso/ucln(d1.mauso,d2.mauso);
		tuso = d1.tuso*mauso/d1.mauso + d2.tuso*mauso/d2.mauso;
		x = ucln(tuso,mauso);
		tuso /= x;
		mauso /= x;
		cout<<"Ket qua cong: "<<tuso<<"/"<<mauso<<endl;
	}
};
		
int main()
{
	phanso d1, d2, d3;
	d1.input();
	d2.input();
	d3.cong(d1,d2);
}