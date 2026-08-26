#include<iostream>
#include<math.h>

using namespace std;

class diem
{
protected:
	float x, y;
public:
	diem()
	{
		x = 0;
		y = 0;
	}
	diem(float x0,float y0)
	{
		x = x0;
		y = y0;
	}
	void input()
	{
		cout<<"Nhap x: ";
		cin>>x;
		cout<<"Nhap y: ";
		cin>>y;
	}
	float getterX(diem d)
	{
		return d.x;
	}
	float getterY(diem d)
	{
		return d.y;
	}
	bool ss0(diem d1,diem d2)
	{
		if(d1.x==d2.x) return true;
		else return false;
	}
	bool ss1(diem d1,diem d2)
	{
		if(d1.y!=d2.y) return true;
		else return false;
	}
	bool ss2(diem d1,diem d2,diem d3,diem d4)
	{
		if(abs(d1.x-d2.x)!=abs(d3.x-d4.x)) return true;
		else return false;
	}
	bool ss3(diem d1,diem d2,diem d3,diem d4)
	{
		if(abs(d1.x-d2.x)!=abs(d3.y-d4.y)) return true;
		else return false;
	}
	~diem() {}
};

class hinhthang: protected diem
{
public:
	hinhthang()
	{
		diem d1(0,0), d2(3,0), d3(1,1), d4(1,2);
	}
	void htinput(diem d[])
	{
		int i;
		do
		{
			for(i=1;i<3;i++)
			{
				cout<<"Toa do diem "<<i<<" (day duoi):\n";
				d[i-1].input();
			}
			if(ss0(d[0],d[1])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			else
				if(ss1(d[0],d[1])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
		} while(ss0(d[0],d[1])||ss1(d[0],d[1]));
		do
		{
			for(i=3;i<5;i++)
			{
				cout<<"Toa do diem "<<i<<" (day tren):\n";
				d[i-1].input();
			}
			if(ss0(d[2],d[3])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			else
			{
				if(ss1(d[2],d[3])&&ss1(d[2],d[0])&&ss1(d[0],d[3])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
				if(!ss1(d[0],d[2])||!ss1(d[0],d[3])) cout<<"Da^y khong phai hinh thang! Moi nhap lai:\n";
			}
		} while(ss0(d[2],d[3])||ss1(d[3],d[2])||!ss1(d[0],d[2])||!ss1(d[0],d[3]));
	}
	void output(diem d[])
	{
		
		cout<<"Hinh thang vua nhap: ";
		for(int i=0;i<4;i++) cout<<"d"<<i+1<<"("<<getterX(d[i])<<","<<getterY(d[i])<<") ";
	}
	~hinhthang() {}
};

class hinhbinhhanh: protected diem
{
public:
	hinhbinhhanh()
	{
		diem d1(0,0), d2(3,0), d3(1,1), d4(4,1);
	}
	void hbhinput(diem d[])
	{
		int i;
		do
		{
			for(i=1;i<3;i++)
			{
				cout<<"Toa do diem "<<i<<" (day duoi):\n";
				d[i-1].input();
			}
			if(ss0(d[0],d[1])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			if(ss1(d[0],d[1])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
		} while(ss0(d[0],d[1])||ss1(d[0],d[1]));
		do
		{
			for(i=3;i<5;i++)
			{
				cout<<"Toa do diem "<<i<<" (day tren):\n";
				d[i-1].input();
			}
			if(ss0(d[2],d[3])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			else
			{
				if(ss1(d[2],d[3])&&ss1(d[2],d[0])&&ss1(d[0],d[3])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
				if(!ss1(d[0],d[2])||!ss1(d[0],d[3])) cout<<"Da^y khong phai hinh binh hanh! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&ss2(d[0],d[1],d[2],d[3])) cout<<"Da^y khong phai hinh binh hanh! Moi nhap lai:\n";
			}
		} while(ss0(d[2],d[3])||ss1(d[3],d[2])||!ss1(d[0],d[2])||!ss1(d[0],d[3])||ss2(d[0],d[1],d[2],d[3]));
	}
	void output(diem d[])
	{
		
		cout<<"Hinh binh hanh vua nhap: ";
		for(int i=0;i<4;i++) cout<<"d"<<i+1<<"("<<getterX(d[i])<<","<<getterY(d[i])<<") ";
	}
	~hinhbinhhanh() {}
};

class hinhchunhat: protected diem
{
public:
	hinhchunhat()
	{
		diem d1(0,0), d2(2,0), d3(0,1), d4(2,1);
	}
	void hcninput(diem d[])
	{
		int i;
		do
		{
			for(i=1;i<3;i++)
			{
				cout<<"Toa do diem "<<i<<" (day duoi):\n";
				d[i-1].input();
			}
			if(ss0(d[0],d[1])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			if(ss1(d[0],d[1])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
		} while(ss0(d[0],d[1])||ss1(d[0],d[1]));
		do
		{
			for(i=3;i<5;i++)
				{
					cout<<"Toa do diem "<<i<<" (day tren):\n";
					d[i-1].input();
				}
			if(ss0(d[2],d[3])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			else
			{
				if(ss1(d[2],d[3])&&ss1(d[2],d[0])&&ss1(d[0],d[3])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
				if(!ss1(d[0],d[2])||!ss1(d[0],d[3])) cout<<"Da^y khong phai hinh chu nhat! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&ss2(d[0],d[1],d[2],d[3])) cout<<"Da^y khong phai hinh chu nhat! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&!ss2(d[0],d[1],d[2],d[3])&&(!ss0(d[2],d[1])||!ss0(d[0],d[3]))) cout<<"Canh ben phai song song voi truc tung! Moi nhap lai:\n";
			}
		} while(ss0(d[2],d[3])||ss1(d[3],d[2])||!ss1(d[0],d[2])||!ss1(d[0],d[3])||ss2(d[0],d[1],d[2],d[3])||!ss0(d[0],d[3])||!ss0(d[2],d[1]));
	}
	void output(diem d[])
	{
		
		cout<<"Hinh chu nhat vua nhap: ";
		for(int i=0;i<4;i++) cout<<"d"<<i+1<<"("<<getterX(d[i])<<","<<getterY(d[i])<<") ";
	}
	~hinhchunhat() {}
};

class hinhvuong: protected diem
{
public:
	hinhvuong()
	{
		diem d1(0,0), d2(1,0), d3(0,1), d4(1,1);
	}
	void hvinput(diem d[])
	{
		int i;
		do
		{
			for(i=1;i<3;i++)
			{
				cout<<"Toa do diem "<<i<<" (day duoi):\n";
				d[i-1].input();
			}
			if(ss0(d[0],d[1])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			if(ss1(d[0],d[1])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
		} while(ss0(d[0],d[1])||ss1(d[0],d[1]));
		do
		{
			for(i=3;i<5;i++)
				{
					cout<<"Toa do diem "<<i<<" (day tren):\n";
					d[i-1].input();
				}
			if(ss0(d[2],d[3])) cout<<"Hai hoanh do phai khac nhau! Moi nhap lai:\n";
			else
			{
				if(ss1(d[2],d[3])&&ss1(d[2],d[0])&&ss1(d[0],d[3])) cout<<"Canh day phai song song voi truc hoanh! Moi nhap lai:\n";
				if(!ss1(d[0],d[2])||!ss1(d[0],d[3])) cout<<"Da^y khong phai hinh vuong! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&ss2(d[0],d[1],d[2],d[3])) cout<<"Da^y khong phai hinh vuong! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&!ss2(d[0],d[1],d[2],d[3])&&(!ss0(d[2],d[1])||!ss0(d[0],d[3]))) cout<<"Canh ben phai song song voi truc tung! Moi nhap lai:\n";
				if(!ss1(d[2],d[3])&&ss1(d[0],d[2])&&ss1(d[0],d[3])&&!ss2(d[0],d[1],d[2],d[3])&&ss0(d[2],d[1])&&ss0(d[0],d[3])&&ss3(d[0],d[1],d[0],d[3])) cout<<"Da^y khong phai hinh vuong! Moi nhap lai:\n";
			}
		} while(ss0(d[2],d[3])||ss1(d[3],d[2])||!ss1(d[0],d[2])||!ss1(d[0],d[3])||ss2(d[0],d[1],d[2],d[3])||!ss0(d[0],d[3])||!ss0(d[2],d[1])||ss3(d[0],d[1],d[0],d[3]));
	}
	void output(diem d[])
	{
		
		cout<<"Hinh vuong vua nhap: ";
		for(int i=0;i<4;i++) cout<<"d"<<i+1<<"("<<getterX(d[i])<<","<<getterY(d[i])<<") ";
	}
	~hinhvuong() {}
};

int main()
{
	hinhthang ht;
	hinhbinhhanh hbh;
	hinhchunhat hcn;
	hinhvuong hv;
	diem d1[4], d2[4], d3[4], d4[4];
	cout<<"HINH THANG:\n";
	ht.htinput(d1);
	ht.output(d1);
	cout<<"\n\nHINH BINH HANH:\n";
	hbh.hbhinput(d2);
	hbh.output(d2);
	cout<<"\n\nHINH CHU NHAT:\n";
	hcn.hcninput(d3);
	hcn.output(d3);
	cout<<"\n\nHINH VUONG:\n";
	hv.hvinput(d4);
	hv.output(d4);
}