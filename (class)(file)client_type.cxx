#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class khachhang
{
protected:
	string hoten;
	int soluong, dongia;
public:
	khachhang()
	{
		hoten = "";
		soluong = 1;
		dongia = 1000;
	}
	virtual void fileoutput(int i)
	{
		fstream kh;
		kh.open("khoitaokhachhang.txt",ios::app);
		cin.ignore();
		cout<<"Ho ten khach hang: ";
		getline(cin,hoten);
		int k, j;
		for(j=0;j<hoten.size();j++) hoten[j] = tolower(hoten[j]);
		for(j=0;j<hoten.size();j++)
			if(hoten[j]==32&&hoten[j+1]!=32) hoten[j+1] = toupper(hoten[j+1]);
		for(j=0;j<hoten.size();j++)
			while(hoten[j]==32)
				for(k=j;k<hoten.size();k++) hoten[k] = hoten[k+1];
		hoten[0] = toupper(hoten[0]);
		do
		{
			cout<<"So luong hang: ";
			cin>>soluong;
		} while(soluong<1);
		do
		{
			cout<<"Don gia (VND): ";
			cin>>dongia;
		} while(dongia<1);
		kh<<i+1<<". "<<hoten<<" So luong hang: "<<soluong<<" Don gia: "<<dongia<<" VND ";
		kh.close();
	}
	virtual void output()
	{
		cout<<hoten<<" "<<soluong<<" "<<dongia;
	}
	virtual void *thanhtoan() = 0;
	~khachhang() {}
};

class binhthuong: public khachhang
{
public:
	binhthuong(): khachhang() {}
	binhthuong(string s,int sl,int dg)
	{
		hoten = s;
		soluong = sl;
		dongia = dg;
	}
	void fileoutput(int i)
	{
		khachhang::fileoutput(i);
		fstream bt;
		bt.open("khoitaokhachhang.txt",ios::app);
		bt<<"So nam than thiet: 0 VIP: Khong"<<endl;
		bt.close();
	}
/*	void output()
	{
		khachhang::output();
	}	*/
	void *thanhtoan()
	{
		ifstream bt1;
		bt1.open("khoitaokhachhang.txt");
		fstream bt2;
		bt2.open("xyzout.txt",ios::app);
		string data;
		vector<string> v;
		int i = -1, j, xsl, xdg;
		while(!bt1.eof())
		{
			xsl = 0; xdg = 0;
			i++;
			bt1>>data;
			v.push_back(data);
			if(data=="0")
			{
				for(j=v[i-9].size()-1;j>=0;j--)
					xsl += (v[i-9][j] - 48)*pow(10,v[i-9].size()-1-j);
				for(j=v[i-6].size()-1;j>=0;j--)
					xdg += (v[i-6][j] - 48)*pow(10,v[i-6].size()-1-j);
				bt2<<v[i-14]<<" "<<v[i-13]<<" So luong hang: "<<v[i-9]<<" Don gia: "<<v[i-6]<<" VND So nam than thiet: 0 VIP: Khong Thanh tien: "<<xsl*xdg*11/10<<" VND"<<endl;
			}
		}
		bt1.close();
		bt2.close();
	}
	~binhthuong() {}
};

class thanthiet: public khachhang
{
	int sonamtt;
public:
	thanthiet(): khachhang()
	{
		sonamtt = 0;
	}
	thanthiet(string s,int sl,int dg,int sntt)
	{
		hoten = s;
		soluong = sl;
		dongia = dg;
		sonamtt = sntt;
	}
	void fileoutput(int i)
	{
		khachhang::fileoutput(i);
		do
		{
			cout<<"So nam than thiet(tren 0 nam va duoi 11 nam): ";
			cin>>sonamtt;
		} while(sonamtt<1||sonamtt>10);
		fstream tt;
		tt.open("khoitaokhachhang.txt",ios::app);
		tt<<"So nam than thiet: "<<sonamtt<<" VIP: Khong"<<endl;
		tt.close();
	}
	void *thanhtoan()
	{
		ifstream bt1;
		bt1.open("khoitaokhachhang.txt");
		fstream bt2;
		bt2.open("xyzout.txt",ios::app);
		string data;
		vector<string> v;
		int i = -1, j, xsl, xdg, xtt;
		float km;
		while(!bt1.eof())
		{
			xsl = 0; xdg = 0;
			i++;
			bt1>>data;
			v.push_back(data);
			if(i%17==14&&data!="N/A"&&data!="0")
			{
				for(j=v[i-9].size()-1;j>=0;j--)
					xsl += (v[i-9][j] - 48)*pow(10,v[i-9].size()-1-j);
				for(j=v[i-6].size()-1;j>=0;j--)
					xdg += (v[i-6][j] - 48)*pow(10,v[i-6].size()-1-j);
				if(v[i].size()==1) xtt = v[i][0] - 48;
				else xtt = v[i][0] - 39;
				km = 1 - (float)xtt/20;
				bt2<<v[i-14]<<" "<<v[i-13]<<" So luong hang: "<<v[i-9]<<" Don gia: "<<v[i-6]<<" VND So nam than thiet: "<<v[i]<<" VIP: Khong Thanh tien: "<<xsl*xdg*km+xsl*xdg/10<<" VND"<<endl;
			}
		}
		bt1.close();
		bt2.close();
	}
	~thanthiet() {}
};

class dacbiet: public khachhang
{
public:
	dacbiet(): khachhang() {}
	dacbiet(string s,int sl,int dg)
	{
		hoten = s;
		soluong = sl;
		dongia = dg;
	}
	void fileoutput(int i)
	{
		khachhang::fileoutput(i);
		fstream db;
		db.open("khoitaokhachhang.txt",ios::app);
		db<<"So nam than thiet: N/A VIP: Co"<<endl;
		db.close();
	}
	void output() {}
	void *thanhtoan()
	{
		ifstream bt1;
		bt1.open("khoitaokhachhang.txt");
		fstream bt2;
		bt2.open("xyzout.txt",ios::app);
		string data;
		vector<string> v;
		int i = -1, j, xsl, xdg;
		while(!bt1.eof())
		{
			xsl = 0; xdg = 0;
			i++;
			bt1>>data;
			v.push_back(data);
			if(data=="N/A")
			{
				for(j=v[i-9].size()-1;j>=0;j--)
					xsl += (v[i-9][j] - 48)*pow(10,v[i-9].size()-1-j);
				for(j=v[i-6].size()-1;j>=0;j--)
					xdg += (v[i-6][j] - 48)*pow(10,v[i-6].size()-1-j);
				bt2<<v[i-14]<<" "<<v[i-13]<<" So luong hang: "<<v[i-9]<<" Don gia: "<<v[i-6]<<" VND So nam than thiet: 0 VIP: Khong Thanh tien: "<<xsl*xdg*3/5<<" VND"<<endl;
			}
		}
		bt1.close();
		bt2.close();
	}
	~dacbiet() {}
};

class congty
{
	int tt;
public:
	int tongtien()
	{
		tt = 0;
		ifstream ct;
		ct.open("xyzout.txt");
		string data;
		vector<string> v;
		int i = -1, j, x;
		while(!ct.eof())
		{
			i++;
			ct>>data;
			v.push_back(data);
			x = 0;
			if(i%21==19)
			{
				for(j=v[i].size()-1;j>=0;j--)
					x += (v[i][j] - 48)*pow(10,v[i].size()-1-j);
				tt += x;
			}
		}
		ct.close();
		return tt;
	}
};

int main()
{
	binhthuong bt; thanthiet tt; dacbiet db;
	int i, x, y, z;
	ofstream null;
	null.open("khoitaokhachhang.txt");
	null<<"";
	null.close();
	null.open("xyzout.txt");
	null<<"";
	null.close();
	do
	{
		cout<<"Co bao nhieu khach hang binh thuong(khong vuot qua 1000)? ";
		cin>>x;
	} while(x<1||x>1000);
	for(i=0;i<x;i++) bt.fileoutput(i);
	bt.thanhtoan();
	do
	{
		cout<<"Co bao nhieu khach hang than thiet(khong vuot qua 1000)? ";
		cin>>y;
	} while(y<1||y>1000);
	for(i=0;i<y;i++) tt.fileoutput(i+x);
	tt.thanhtoan();
	do
	{
		cout<<"Co bao nhieu khach hang dac biet(khong vuot qua 1000)? ";
		cin>>z;
	} while(z<1||z>1000);
	for(i=0;i<z;i++) db.fileoutput(i+x+y);
	db.thanhtoan();
	congty ct;
	fstream ds;
	ds.open("xyzout.txt",ios::app);
	ds<<endl<<"Tong tien cong ty thu duoc: "<<ct.tongtien();
	ds.close();
}