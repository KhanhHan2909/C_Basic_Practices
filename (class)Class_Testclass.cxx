#include<iostream>
#include<string>

using namespace std;

struct date
{
	int day, month, year;
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

class thisinh
{
	char mats[5];
	string hoten;
	date ngaysinh;
	float toan, van, anh;
	public:
	void input()
	{
		cout<<"Nhap ma thi sinh: ";
		cin>>mats;
		cin.ignore();
		cout<<"Nhap ho ten: ";
		getline(cin,hoten);
		dateinput(ngaysinh);
		do
		{
			cout<<"Diem Toan - Van - Anh: ";
			cin>>toan>>van>>anh;
		} while(toan<0||toan>10||van<0||van>10||anh<0||anh>10);
	}
/*	void output()
	{
		
	}*/
	friend class testthisinh;
};

class testthisinh
{
	int n;
	public:
	void testinput(thisinh *ts,int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"Thi sinh thu "<<i+1<<": \n";
			ts[i].input();
		}
	}
	void tongdiem(thisinh *ts,int n)
	{
		int i;
		cout<<endl<<"Danh sach thi sinh co tong diem lob hon 1:"<<endl;
		for(i=0;i<n;i++) 
			if(ts[i].toan+ts[i].van+ts[i].anh>1) 		 
				cout<<ts[i].mats<<" "<<ts[i].hoten<<" "<<ts[i].ngaysinh.day<<"/"<<ts[i].ngaysinh.month<<"/"<<ts[i].ngaysinh.year<<" "<<ts[i].toan<<" "<<ts[i].van<<" "<<ts[i].anh<<" "<<endl;
	}
};

int main()
{
	int n;
	thisinh *ts;
	testthisinh tts;
	cout<<"Nhap so thi sinh: ";
	cin>>n;
	ts = new thisinh[n];
	tts.testinput(ts,n);
	tts.tongdiem(ts,n);
	delete []ts;
}