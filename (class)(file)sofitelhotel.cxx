#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class hotel
{
protected:
	string maphong;
	int sodem;
public:
	hotel()
	{
		maphong = "";
		sodem = 0;
	}
	void foutput()
	{
		fstream f;
		fstream f1;
		f.open("sofitel.inp",ios::app);
		f1.open("sofitel_prevmonth.inp",ios::app);
		cin.ignore();
		cout<<"Nhap ma phong: ";
		getline(cin,maphong);
		do
		{
			cout<<"Nhap so dem thang nay: ";
			cin>>sodem;
		} while(sodem<0);
		f<<"Ma phong: "<<maphong<<" So dem: "<<sodem;
		do
		{
			cout<<"Nhap so dem thang truoc: ";
			cin>>sodem;
		} while(sodem<0);
		f1<<"Ma phong: "<<maphong<<" So dem: "<<sodem;
		f.close();
		f1.close();
	}
	~hotel() {}
};

class business: protected hotel
{
public:
	business(): hotel() {}
	void foutput(int n)
	{
		fstream f;
		fstream f1;
		f.open("sofitel.inp",ios::app);
		f1.open("sofitel_prevmonth.inp",ios::app);
		for(int i=0;i<n;i++)
		{
			hotel::foutput();
			f<<" Phi dich vu: 0 VND Phi phuc vu: 0 VND\n";
			f1<<" Phi dich vu: 0 VND Phi phuc vu: 0 VND\n";
		}
		f.close();
		f1.close();
	}
	void finput1(int i0)
	{
		ifstream f;
		f.open("sofitel.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0;
		for(int i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		f.close();
	}
	void finput2(int i0)
	{
		ifstream f;
		f.open("sofitel_prevmonth.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0;
		for(int i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		f.close();
	}
	int doanhthu()
	{
		return sodem*300000;
	}
	string gettermp()
	{
		return maphong;
	}
	~business() {}
};

class premium: protected hotel
{
	int dichvu;
public:
	premium(): hotel()
	{
		dichvu = 0;
	}
	void foutput(int n)
	{
		fstream f;
		fstream f1;
		f.open("sofitel.inp",ios::app);
		f1.open("sofitel_prevmonth.inp",ios::app);
		for(int i=0;i<n;i++)
		{
			hotel::foutput();
			if(sodem==0) dichvu = 0;
			else
				do
				{
					cout<<"Nhap phi dich vu (VND): ";
					cin>>dichvu;
				} while(dichvu<=0);
			f<<" Phi dich vu: "<<dichvu<<" VND Phi phuc vu: 0 VND\n";
			f1<<" Phi dich vu: "<<dichvu<<" VND Phi phuc vu: 0 VND\n";
		}
		f.close();
		f1.close();
	}
	void finput1(int i0)
	{
		ifstream f;
		f.open("sofitel.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0, i;
		for(i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		s = 0;
		for(i=v[i0+7].size()-1;i>=0;i--) s += (v[i0+7][i]-48)*pow(10,v[i0+7].size()-1-i);
		dichvu = s;
		f.close();
	}
	void finput2(int i0)
	{
		ifstream f;
		f.open("sofitel_prevmonth.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0, i;
		for(i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		s = 0;
		for(i=v[i0+7].size()-1;i>=0;i--) s += (v[i0+7][i]-48)*pow(10,v[i0+7].size()-1-i);
		dichvu = s;
		f.close();
	}
	int doanhthu()
	{
		if(sodem==0) return 0;
		else return sodem*(500000 + dichvu)*1.05;
	}
	string gettermp()
	{
		return maphong;
	}
	~premium() {}
};

class deluxe: protected hotel
{
	int dichvu, phucvu;
public:
	deluxe(): hotel()
	{
		dichvu = 0;
		phucvu = 0;
	}
	void foutput(int n)
	{
		fstream f;
		fstream f1;
		f.open("sofitel.inp",ios::app);
		f1.open("sofitel_prevmonth.inp",ios::app);
		for(int i=0;i<n;i++)
		{
			hotel::foutput();
			if(sodem==0)
			{
				dichvu = 0;
				phucvu = 0;
			}
			else
				do
				{
					cout<<"Nhap phi dich vu (VND): ";
					cin>>dichvu;
				} while(dichvu<=0);
				do
				{
					cout<<"Nhap phi phuc vu thang nay (VND): ";
					cin>>phucvu;
				} while(phucvu<=0);
			f<<" Phi dich vu: "<<dichvu<<" VND Phi phuc vu: "<<phucvu<<" VND\n";
			do
				{
					cout<<"Nhap phi phuc vu thang truoc (VND): ";
					cin>>phucvu;
				} while(phucvu<=0);
			f1<<" Phi dich vu: "<<dichvu<<" VND Phi phuc vu: "<<phucvu<<" VND\n";
		}
		f.close();
		f1.close();
	}
	void finput1(int i0)
	{
		ifstream f;
		f.open("sofitel.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0, i;
		for(i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		s = 0;
		for(i=v[i0+7].size()-1;i>=0;i--) s += (v[i0+7][i]-48)*pow(10,v[i0+7].size()-1-i);
		dichvu = s;
		s = 0;
		for(i=v[i0+12].size()-1;i>=0;i--) s += (v[i0+12][i]-48)*pow(10,v[i0+12].size()-1-i);
		phucvu = s;
		f.close();
	}
	void finput2(int i0)
	{
		ifstream f;
		f.open("sofitel_prevmonth.inp");
		string data;
		vector<string> v;
		while(!f.eof())
		{
			f>>data;
			v.push_back(data);
		}
		maphong = v[i0];
		int s = 0, i;
		for(i=v[i0+3].size()-1;i>=0;i--) s += (v[i0+3][i]-48)*pow(10,v[i0+3].size()-1-i);
		sodem = s;
		s = 0;
		for(i=v[i0+7].size()-1;i>=0;i--) s += (v[i0+7][i]-48)*pow(10,v[i0+7].size()-1-i);
		dichvu = s;
		s = 0;
		for(i=v[i0+12].size()-1;i>=0;i--) s += (v[i0+12][i]-48)*pow(10,v[i0+12].size()-1-i);
		phucvu = s;
		f.close();
	}
	int doanhthu()
	{
		if(sodem==0) return 0;
		else return sodem*(750000 + dichvu)*1.03 + phucvu;
	}
	string gettermp()
	{
		return maphong;
	}
	~deluxe() {}
};

void main()
{
	business bs1, bs2; premium pm1, pm2; deluxe dl1, dl2;
	int b, p, d;
	do
	{
		cout<<"Co bn phong business, premium, deluxe? ";
		cin>>b>>p>>d;
	} while(b<1||d<1||p<1);
	ofstream f;
	f.open("sofitel.inp");
	f<<b<<" "<<p<<" "<<d<<endl;
	f.close();
	ofstream f1;
	f1.open("sofitel_prevmonth.inp");
	f1<<b<<" "<<p<<" "<<d<<endl;
	f1.close();
	cout<<"Business:\n";
	bs1.foutput(b);
	cout<<"Premium:\n";
	pm1.foutput(p);
	cout<<"Deluxe:\n";
	dl1.foutput(d);
	ifstream f2;
	f2.open("sofitel.inp");
	ofstream f3;
	f3.open("doanhthu.out");
	string data;
	vector<string> v;
	while(!f2.eof())
	{
		f2>>data;
		v.push_back(data);
	}
	int dt1, dt2;
	for(int i=0;i<v.size();i++)
		if((i-5)%16==0)
		{
			if(v[i+7]=="0") 
			{
				bs1.finput1(i);
				dt1 = bs1.doanhthu();
				f3<<"Ma phong: "<<bs1.gettermp()<<" Doanh thu: "<<dt1<<" Vuot troi: ";
				bs2.finput2(i);
				dt2 = bs2.doanhthu();
			}
			else
			{
				if(v[i+12]=="0") 
				{
					pm1.finput1(i);
					dt1 = pm1.doanhthu();
					f3<<"Ma phong: "<<pm1.gettermp()<<" Doanh thu: "<<pm1.doanhthu()<<" Vuot troi: ";
					pm2.finput2(i);
					dt2 = pm2.doanhthu();
				}
				else 
				{
					dl1.finput1(i);
					dt1 = dl1.doanhthu();
					f3<<"Ma phong: "<<dl1.gettermp()<<" Doanh thu: "<<dl1.doanhthu()<<" Vuot troi: ";
					dl2.finput2(i);
					dt2 = dl2.doanhthu();
				}
			}
			if(dt1>=dt2*1.25) f3<<"Co"<<endl;
			else f3<<"Khong"<<endl;
		}
		f2.close();
		f3.close();
}