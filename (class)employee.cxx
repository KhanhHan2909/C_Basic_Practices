#include<iostream>
#include<string>

using namespace std;

struct date
{
	int day, month, year;
};

void dateinput(date &D);

class nhanvien
{
protected:
	string hoten;
	date ngaysinh;
public:
	nhanvien()
	{
		hoten =  "Nguyen Thi A";
		ngaysinh.day = 1;
		ngaysinh.month = 1;
		ngaysinh.year = 2000;
	}
	void input()
	{
		cin.ignore();
		cout<<"Nhap ho ten: ";
		getline(cin,hoten);
		dateinput(ngaysinh);
	}
	~nhanvien() {}
};

class sanxuat: public nhanvien
{
	int luongcb, sosp;
public:
	sanxuat()
	{
		luongcb = 1000;
		sosp = 1;
	}
	void sxinput()
	{
		cout<<"Nhap luong can ban: ";
		cin>>luongcb;
		cout<<"Nhap so san pham: ";
		cin>>sosp;
	}
	void output(int i)
	{
		cout<<i+1<<". "<<hoten<<" "<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year<<" "<<luongcb + sosp*5000<<endl;
	}
	~sanxuat() {}
};

class vanphong: public nhanvien
{
	int snlv;
public:
	vanphong()
	{
		snlv = 25;
	}
	void vpinput()
	{
		do
		{
			cout<<"Nhap so ngay lam viec: ";
			cin>>snlv;
		} while(snlv>30);
	}
	void output(int i)
	{
		cout<<i+1<<". "<<hoten<<" "<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year<<" "<<snlv*100000<<endl;
	}
	~vanphong() {}
};

void dateinput(date &D)
{
	do
	{
		printf("Nhap nam: ");
		scanf("%d",&D.year);
		if(D.year<1) printf("Nam phai lon hon 1! Xin nhap lai!");
	} while(D.year<1);
	do
	{
		printf("Nhap thang:");
		scanf("%d",&D.month);
		if(D.month<1) printf("Thang phai lon hon 1! Xin nhap lai!");
		else if(D.month>12) printf("Thang phai nho hon 12! Xin nhap lai!");
	} while(D.month<1||D.month>12);
	do
	{
		printf("Nhap ngay: ");
		scanf("%d",&D.day);
		if(D.day<1) printf("Ngay phai lon hon 1! Xin nhap lai!");
		else if(D.day>31) printf("Ngay phai nho hon 32! Xin nhap lai!\n");
		else if((D.month==4||D.month==6||D.month==9||D.month==11)&&D.day>30) printf("Thang 4, 6, 9, 11 chi co 30 ngay! Xin nhap lai!\n");
		else if((D.year%4==0&&D.year%100!=0||D.year%400==0)&&D.month==2&&D.day>29) printf("Thang hai nam nhuan chi co 29 ngay! Xin nhap lai!\n");
		else if((D.year%4!=0||D.year%100==0&&D.year%400!=0)&&D.month==2&&D.day>28) printf("Thang hai nam khong nhuan chi co 28 ngay! Xin nhap lai!\n");
	} while(D.day>31||((D.month==4||D.month==6||D.month==9||D.month==11)&&D.day>30)||(D.month==2&&D.day>29)||((D.year%4!=0||D.year%100==0&&D.year%400!=0)&&D.month==2&&D.day>28)||D.day<1);
}

int main()
{
	int i, n1, n2;
	cout<<"Nhap so nhan vien san xuat: ";
	cin>>n1;
	cout<<"Nhap so nhan vien van phong: ";
	cin>>n2;
	sanxuat nvsx[n1];
	for(i=0;i<n1;i++)
	{
		nvsx[i].input();
		nvsx[i].sxinput();
	}
	vanphong nvvp[n2];
	for(i=0;i<n2;i++)
	{
		nvvp[i].input();
		nvvp[i].vpinput();
	}
	cout<<endl<<"Thong ke nhan vien (Stt Ho_ten Ngay_sinh Luong): "<<endl;
	for(i=0;i<n1;i++) nvsx[i].output(i);
	for(i=n1;i<n1+n2;i++) nvvp[i-n1].output(i);
}