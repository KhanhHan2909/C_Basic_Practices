#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct date
{
	int day, month, year;
};

void dateinput(date &D);

class doituong
{
protected:
	string hoten;
	date ngaysinh;
	string diachi;
public:
	doituong()
	{
		hoten = "Nguyen A";
		ngaysinh.day = 1;
		ngaysinh.month = 1;
		ngaysinh.year = 2000;
		diachi = "183 Nguyen Khang, Cau Giay, Ha Noi";
	}
	void input()
	{
		cin.ignore();
		cout<<"Nhap ho ten: ";
		getline(cin,hoten);
		dateinput(ngaysinh);
		cin.ignore();
		cout<<"Nhap dia chi: ";
		getline(cin,diachi);
	}
	~doituong() {}
};

class sinhvien: public doituong
{
	int hocki;
	float gpa;
public:
	sinhvien()
	{
		hocki = 8;
		gpa = 5;
	}
	void svinput()
	{
		cout<<"Nhap so hoc ki: ";
		cin>>hocki;
		cout<<"Nhap diem GPA: ";
		cin>>gpa;
	}
	void output()
	{
		cout<<hoten<<" "<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year<<" "<<diachi<<" "<<"So hoc ki: "<<hocki<<" "<<"GPA: "<<gpa<<endl;
	}
	~sinhvien() {}
};

class congnhan: public doituong
{
	int luongcb, sosp;
public:
	congnhan()
	{
		luongcb = 100000;
		sosp = 50;
	}
	void cninput()
	{
		cout<<"Nhap luong co ban: ";
		cin>>luongcb;
		cout<<"Nhap so san pham: ";
		cin>>sosp;
	}
	void output()
	{
		cout<<hoten<<" "<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year<<" "<<diachi<<"Thu nhap: "<<luongcb + sosp*50000<<endl;
	}
	~congnhan() {}
};

class casi: public doituong
{
	int snhd;
	vector<string> hits;
public:
	casi()
	{
		snhd = 1;
	}
	void csinput()
	{
		cout<<"Nhap so nam hoat dong: ";
		cin>>snhd;
		int n;
		cout<<"Co bao nhieu hit? ";
		cin>>n;
		cin.ignore();
		for(int i=0;i<n;i++)
		{
			string s;
			cout<<"Hit so "<<i+1<<": ";
			getline(cin,s);
			hits.push_back(s);
		}
	}
	void output()
	{
		cout<<hoten<<" "<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year<<" "<<diachi<<" Ds hit: ";
		for(int i=0;i<hits.size();i++)
			cout<<hits[i]<<" ";
		cout<<endl;
	}
	~casi() {}
};

void dateinput(date &D)
{
	do
	{
		printf("Nhap nam: ");
		scanf("%d",&D.year);
		if(D.year<1) printf("Nam phai lon hon 0! Xin nhap lai!\n");
	} while(D.year<1);
	do
	{
		printf("Nhap thang: ");
		scanf("%d",&D.month);
		if(D.month<1) printf("Thang phai lon hon 0! Xin nhap lai!\n");
		else if(D.month>12) printf("Thang phai nho hon 13! Xin nhap lai!\n");
	} while(D.month<1||D.month>12);
	do
	{
		printf("Nhap ngay: ");
		scanf("%d",&D.day);
		if(D.day<1) printf("Ngay phai lon hon 0! Xin nhap lai!\n");
		else if(D.day>31) printf("Ngay phai nho hon 32! Xin nhap lai!\n");
		else if((D.month==4||D.month==6||D.month==9||D.month==11)&&D.day>30) printf("Thang 4, 6, 9, 11 chi co 30 ngay! Xin nhap lai!\n");
		else if((D.year%4==0&&D.year%100!=0||D.year%400==0)&&D.month==2&&D.day>29) printf("Thang hai nam nhuan chi co 29 ngay! Xin nhap lai!\n");
		else if((D.year%4!=0||D.year%100==0&&D.year%400!=0)&&D.month==2&&D.day>28) printf("Thang hai nam khong nhuan chi co 28 ngay! Xin nhap lai!\n");
	} while(D.day>31||((D.month==4||D.month==6||D.month==9||D.month==11)&&D.day>30)||(D.month==2&&D.day>29)||((D.year%4!=0||D.year%100==0&&D.year%400!=0)&&D.month==2&&D.day>28)||D.day<1);
}

int main()
{
	vector<sinhvien> sv; vector<congnhan> cn; vector<casi> cs;
	int i, n;
	do
	{
		cout<<"\nMenu chuong trinh: \n";
		cout<<"1.Nhap tt sinh vien\n";
		cout<<"2.Nhap tt cong nhan\n";
		cout<<"3.Nhap tt ca si\n";
		cout<<"4.Thoat\n";
		cin>>n;
		if(n==1)
		{
			sinhvien sv0;
			sv0.input();
			sv0.svinput();
			sv.push_back(sv0);
			cout<<"Thong tin sinh vien: \n";
			for(i=0;i<sv.size();i++) sv[i].output();
		}
		if(n==2)
		{
			congnhan cn0;
			cn0.input();
			cn0.cninput();
			cn.push_back(cn0);
			cout<<"Thong tin cong nhan: \n";
			for(i=0;i<cn.size();i++) cn[i].output();
		}
		if(n==3)
		{
			casi cs0;
			cs0.input();
			cs0.csinput();
			cs.push_back(cs0);
			cout<<"Thong tin ca si: \n";
			for(i=0;i<cs.size();i++) cs[i].output();
		}
	} while(n!=4);
}