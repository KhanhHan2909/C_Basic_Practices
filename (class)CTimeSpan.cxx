#include<iostream>

using namespace std;

class Ctimespan
{
	int t;
public:
	Ctimespan()
	{
		t = 0;
	}
	Ctimespan(int t0)
	{
		timesetter(t0);
	}
	void timesetter(int t0)
	{
		t = t0;
	}
	Ctimespan cong(Ctimespan &ts1,Ctimespan &ts2)
	{
		return ts1 + ts2;
	}
	Ctimespan tru(Ctimespan &ts1,Ctimespan &ts2)
	{
		return ts1 - ts2;
	}
	void sosanh(Ctimespan ts1,Ctimespan ts2)
	{
		bool cmp;
		cmp = ts1==ts2;
		if(cmp) cout<<"ts1 = ts2: true\n";
		else cout<<"ts1 = ts2: false\n";
		cmp = ts1!=ts2;
		if(cmp) cout<<"ts1 != ts2: true\n";
		else cout<<"ts1 != ts2: false\n";
		cmp = ts1>ts2;
		if(cmp) cout<<"ts1 > ts2: true\n";
		else cout<<"ts1 > ts2: false\n";
		cmp = ts1>=ts2;
		if(cmp) cout<<"ts1 >= ts2: true\n";
		else cout<<"ts1 >= ts2: false\n";
		cmp = ts1<ts2;
		if(cmp) cout<<"ts1 < ts2: true\n";
		else cout<<"ts1 < ts2: false\n";
		cmp = ts1<=ts2;
		if(cmp) cout<<"ts1 <= ts2: true\n";
		else cout<<"ts1 <= ts2: false\n";
	}
	friend Ctimespan operator+(Ctimespan &ts1,Ctimespan &ts2);
	friend Ctimespan operator-(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator==(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator!=(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator>(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator>=(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator<(Ctimespan &ts1,Ctimespan &ts2);
	friend bool operator<=(Ctimespan &ts1,Ctimespan &ts2);
	friend ostream & operator<<(ostream & os,Ctimespan &ts);
	friend istream & operator>>(istream & is,Ctimespan &ts);
	~Ctimespan() {}
};

Ctimespan operator+(Ctimespan &ts1,Ctimespan &ts2)
{
	Ctimespan ts3;
	ts3.t = ts1.t + ts2.t;
	return ts3;
}

Ctimespan operator-(Ctimespan &ts1,Ctimespan &ts2)
{
	Ctimespan ts3;
	ts3.t = ts1.t - ts2.t;
	return ts3;
}

bool operator==(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t==ts2.t) return true;
	else return false;
}

bool operator!=(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t!=ts2.t) return true;
	else return false;
}

bool operator>(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t>ts2.t) return true;
	else return false;
}

bool operator>=(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t>=ts2.t) return true;
	else return false;
}

bool operator<(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t<ts2.t) return true;
	else return false;
}

bool operator<=(Ctimespan &ts1,Ctimespan &ts2)
{
	if(ts1.t<=ts2.t) return true;
	else return false;
}

ostream & operator<<(ostream & os,Ctimespan &ts)
{
	os<<ts.t;
	return os;
}

istream & operator>>(istream & is,Ctimespan &ts)
{
	is>>ts.t;
	return is;
}

int main()
{
	Ctimespan ts1(3), ts2(5), ts3, ts4;
/*	cout<<"Nhap khoang thoi gian thu nhat (giay): ";
	cin>>ts1;
	cout<<"Nhap khoang thoi gian thu hai (giay): ";
	cin>>ts2;	*/
	cout<<"Khoang thoi gian thu nhat (ts1) la "<<ts1<<" giay\n";
	cout<<"Khoang thoi gian thu hai (ts2) la "<<ts2<<" giay\n";
	ts3 = ts1 + ts2;
	cout<<"Khoang thoi gian thu ba (ts3 = ts1 + ts2) la "<<ts3<<" giay\n";
	ts4 = ts1 - ts2;
	cout<<"Khoang thoi gian thu tu (ts4 = ts1 - ts2) la "<<ts4<<" giay\n";
	ts3.sosanh(ts1,ts2);
}