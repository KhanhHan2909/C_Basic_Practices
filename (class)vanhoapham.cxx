#include<iostream>
#include<string>
#include<vector>

using namespace std;

class vanhoapham
{
protected:
	string ten, nhaxb;
	int namxb, sotrang, dongia;
public:
	vanhoapham()
	{
		ten ="DMPLK"; nhaxb = "NxbTre";
		namxb = 2000;
		sotrang = 100;
		dongia = 30000;
	}
	virtual void input()
	{
		cin.ignore();
		cout<<"Ten: ";
		getline(cin,ten);
		cout<<"Nha xuat ban: ";
		getline(cin,nhaxb);
		do
		{
			cout<<"Nam xuat ban: ";
			cin>>namxb;
		} while(namxb<1);
		do
		{
			cout<<"So trang: ";
			cin>>sotrang;
		} while(sotrang<1);
		do
		{
			cout<<"Don gia: ";
			cin>>dongia;
		} while(dongia<1);
	}
	virtual void output()
	{
		cout<<ten<<"_"<<nhaxb<<"_"<<"Nam "<<namxb<<"_"<<sotrang<<" trang"<<"_"<<dongia<<" VND"<<"_";
	}
	~vanhoapham() {}
};

class sgk: public vanhoapham
{
	int khoilop;
public:
	sgk(): vanhoapham()
	{
		khoilop = 1;
	}
	void input()
	{
		vanhoapham::input();
		do
		{
			cout<<"Khoi lop: ";
			cin>>khoilop;
		} while(khoilop<1||khoilop>12);
	}
	void output()
	{
		vanhoapham::output();
		cout<<"Lop "<<khoilop<<endl;
	}
	~sgk() {}
};

class tieuthuyet: public vanhoapham
{
	string theloai;
public:
	tieuthuyet(): vanhoapham()
	{
		theloai = "Thieu nhi";
	}
	void input()
	{
		vanhoapham::input();
		cin.ignore();
		cout<<"The loai: ";
		getline(cin,theloai);
	}
	void output()
	{
		vanhoapham::output();
		cout<<"The loai "<<theloai<<endl;
	}
	~tieuthuyet() {}
};

class tapchi: public vanhoapham
{
	string dinhki;
public:
	tapchi(): vanhoapham()
	{
		dinhki = "hang ngay";
	}
	void input()
	{
		vanhoapham::input();
		int n;
		do
		{
			cout<<"Dinh ki xuat ban: hang ngay(1), tuan san(2), nguyet san(3), quy san(4), hang nam(5) ";
			cin>>n;
		} while(n<1||n>5);
		if(n==1) dinhki = "hang ngay";
		if(n==2) dinhki = "tuan san";
		if(n==3) dinhki = "nguyet san";
		if(n==4) dinhki = "quy san";
		if(n==5) dinhki = "hang nam";	
	}
	void output()
	{
		vanhoapham::output();
		cout<<"Dinh ki: "<<dinhki<<endl;
	}
	~tapchi() {}
};
	
void main()
{
	vector<vanhoapham*> Vhp;
	int k, n;
	cout<<"Nhap so luong van hoa pham: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Quyen "<<i+1<<":\n";
		do
		{
			cout<<"Sach giao khoa(1), tieu thuyet(2), tap chi(3): ";
			cin>>k;
		} while(k<1||k>3);
		vanhoapham *vhp;
		if(k==1) vhp = new sgk;
		if(k==2) vhp = new tieuthuyet;
		if(k==3) vhp = new tapchi;
		vhp->input();
		Vhp.push_back(vhp);
	}
	cout<<endl<<"Danh sach van hoa pham vua nhap:\n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". ";
		Vhp.at(i)->output();
	}
}