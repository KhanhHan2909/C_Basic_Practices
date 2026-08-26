#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

struct diem_vector
{
	float x, y;
};
		
bool test(diem_vector d1,diem_vector d2);
bool test2(diem_vector d1,diem_vector d2);

class dagiac
{
protected:
	diem_vector *d;
public:
	dagiac()
	{
		d = new diem_vector;
		d->x = 0;
		d->y = 0;
	}
	virtual void input(int n)
	{
		d = new diem_vector[n];
		for(int i=0;i<n;i++)
		{
			cout<<"Toa do dinh "<<i+1<<":\n";
			cout<<"x = ";
			cin>>d[i].x;
			cout<<"y = ";
			cin>>d[i].y;
		}
	}
		virtual void output(int n) 
		{
			for(int i=0;i<n;i++) cout<<"("<<d[i].x<<","<<d[i].y<<") ";
			cout<<endl;
		}
		virtual void tinhtien(int n,diem_vector d0)
		{
			for(int i=0;i<n;i++) 
			{
				d[i].x += d0.x;
				d[i].y += d0.y;
			}
		}
	~dagiac()
	{
		delete []d;
	}
};

class tamgiac: public dagiac
{
public:
	tamgiac(): dagiac()
	{
		d = new diem_vector[3];
		d[0].x = 0; d[0].y = 0;
		d[1].x = 0; d[1].y = 1;
		d[2].x = 1; d[2].y = 0;
	}
	void input(int n)
	{
		diem_vector v1, v2, v3;
		int t;
		do
		{
			t = 1;
			dagiac::input(3);
			v1.x = d[0].x - d[1].x;
			v1.y = d[0].y - d[1].y;
			v2.x = d[1].x - d[2].x;
			v2.y = d[1].y - d[2].y;
			if(test(v1,v2)) 
			{
				t = 0;
				cout<<"3 diem vua nhap khong phai tam giac! Moi nhap lai:\n";
			}
		} while(t==0);
	}
	void output(int n)
	{
		cout<<"Tam giac: ";
		dagiac::output(3);
	}
	void tinhtien(int n,diem_vector d0)
	{
		dagiac::tinhtien(3,d0);
	}
	~tamgiac()
	{
		delete []d;
	}
};

class tugiac: public dagiac
{
public:
	tugiac(): dagiac()
	{
		d = new diem_vector[4];
		d[0].x = 0; d[0].y = 0;
		d[1].x = 0; d[1].y = 1;
		d[2].x = 2; d[2].y = 2;
		d[3].x = 1; d[3].y = 0;
	}
	void input(int n)
	{
		diem_vector v1, v2, v3, v4;
		int t;
		do
		{
			t = 1;
			dagiac::input(4);
			v1.x = d[0].x - d[1].x;
			v1.y = d[0].y - d[1].y;
			v2.x = d[1].x - d[2].x;
			v2.y = d[1].y - d[2].y;
			v3.x = d[2].x - d[3].x;
			v3.y = d[2].y - d[3].y;
			v4.x = d[3].x - d[0].x;
			v4.y = d[3].y - d[0].y;
			if(test(v1,v2)||test(v2,v3)||test(v3,v4)||test(v4,v1)) 
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai tu giac! Moi nhap lai:\n";
			}
		} while(t==0);
	}
	void output(int n)
	{
		cout<<"Tu giac: ";
		dagiac::output(4);
	}
	void tinhtien(int n,diem_vector d0)
	{
		dagiac::tinhtien(4,d0);
	}
	~tugiac()
	{
		delete []d;
	}
};

class hinhbinhhanh: public dagiac
{
public:
	hinhbinhhanh(): dagiac()
	{
		d = new diem_vector[4];
		d[0].x = 0; d[0].y = 0;
		d[1].x = 0; d[1].y = 1;
		d[2].x = 1; d[2].y = 1.5;
		d[3].x = 1; d[3].y = 0.5;
	}
	void input(int n)
	{
		diem_vector v1, v2, v3, v4;
		int t;
		do
		{
			t = 1;
			dagiac::input(4);
			v1.x = d[0].x - d[1].x;
			v1.y = d[0].y - d[1].y;
			v2.x = d[1].x - d[2].x;
			v2.y = d[1].y - d[2].y;
			v3.x = d[2].x - d[3].x;
			v3.y = d[2].y - d[3].y;
			v4.x = d[3].x - d[0].x;
			v4.y = d[3].y - d[0].y;
			if(test(v1,v2)||test(v2,v3)||test(v3,v4)||test(v4,v1)) 
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh binh hanh! Moi nhap lai:\n";
			}
			if(!test(v1,v3)||!test(v2,v4))
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh binh hanh! Moi nhap lai:\n";
			}
		} while(t==0);
	}
	void output(int n)
	{
		cout<<"Hinh binh hanh: ";
		dagiac::output(4);
	}
	void tinhtien(int n,diem_vector d0)
	{
		dagiac::tinhtien(4,d0);
	}
	~hinhbinhhanh()
	{
		delete []d;
	}
};

class hinhchunhat: public dagiac
{
public:
	hinhchunhat(): dagiac()
	{
		d = new diem_vector[4];
		d[0].x = 0; d[0].y = 0;
		d[1].x = 0; d[1].y = 2;
		d[2].x = 1; d[2].y = 2;
		d[3].x = 1; d[3].y = 0;
	}
	void input(int n)
	{
		diem_vector v1, v2, v3, v4;
		int t;
		do
		{
			t = 1;
			dagiac::input(4);
			v1.x = d[0].x - d[1].x;
			v1.y = d[0].y - d[1].y;
			v2.x = d[1].x - d[2].x;
			v2.y = d[1].y - d[2].y;
			v3.x = d[2].x - d[3].x;
			v3.y = d[2].y - d[3].y;
			v4.x = d[3].x - d[0].x;
			v4.y = d[3].y - d[0].y;
			if(test(v1,v2)||test(v2,v3)||test(v3,v4)||test(v4,v1)) 
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh chu nhat! Moi nhap lai:\n";
			}
			if(!test(v1,v3)||!test(v2,v4))
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh chu nhat! Moi nhap lai:\n";
			}
			if(!test2(v1,v2))
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh chu nhat! Moi nhap lai:\n";
			}
		} while(t==0);
	}
	void output(int n)
	{
		cout<<"Hinh chu nhat: ";
		dagiac::output(4);
	}
	void tinhtien(int n,diem_vector d0)
	{
		dagiac::tinhtien(4,d0);
	}
	~hinhchunhat()
	{
		delete []d;
	}
};

class hinhvuong: public dagiac
{
public:
	hinhvuong(): dagiac()
	{
		d = new diem_vector[4];
		d[0].x = 0; d[0].y = 0;
		d[1].x = 0; d[1].y = 1;
		d[2].x = 1; d[2].y = 1;
		d[3].x = 1; d[3].y = 0;
	}
	void input(int n)
	{
		diem_vector v1, v2, v3, v4;
		int t;
		do
		{
			t = 1;
			dagiac::input(n);
			v1.x = d[0].x - d[1].x;
			v1.y = d[0].y - d[1].y;
			v2.x = d[1].x - d[2].x;
			v2.y = d[1].y - d[2].y;
			v3.x = d[2].x - d[3].x;
			v3.y = d[2].y - d[3].y;
			v4.x = d[3].x - d[0].x;
			v4.y = d[3].y - d[0].y;
			if(test(v1,v2)||test(v2,v3)||test(v3,v4)||test(v4,v1)) 
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh vuong! Moi nhap lai:\n";
			}
			if(!test(v1,v3)||!test(v2,v4))
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh vuong! Moi nhap lai:\n";
			}
			if(!test2(v1,v2))
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh vuong! Moi nhap lai:\n";
			}
			float a = v1.x*v1.x + v1.y*v1.y, b = v2.x*v2.x + v2.y*v2.y;
			if(a!=b)
			{
				t = 0;
				cout<<"4 diem vua nhap khong phai hinh vuong! Moi nhap lai:\n";
			}
		} while(t==0);
	}
	void output(int n)
	{
		cout<<"Hinh vuong: ";
		dagiac::output(4);
	}
	void tinhtien(int n,diem_vector d0)
	{
		dagiac::tinhtien(4,d0);
	}
	~hinhvuong()
	{
		delete []d;
	}
};

class hinhhoc
{
	vector<dagiac*> DG;
public:
	void input()
	{
		int h, k, n;
		cout<<"Nhap so luong da giac: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			do
			{
				cout<<"Tam giac(1), Tu giac(2), Hinh binh hanh(3), Hinh chu nhat(4), Hinh vuong(5): ";
				cin>>k;
			} while(k<1||k>5);
			dagiac *dg;
			if(k==1) 
			{
				dg = new tamgiac;
			}
			else if(k==2) dg = new tugiac;
			else if(k==3) dg = new hinhbinhhanh;
			else if(k==4) dg = new hinhchunhat;
			else dg = new hinhvuong;
			dg->input(h);
			DG.push_back(dg);
		}
	}
	void output()
	{
		int h;
		cout<<endl;
		for(int i=0;i<DG.size();i++)
		{
			cout<<i+1<<". ";
			DG.at(i)->output(h);
		}
	}
	void tinhtien()
	{
		int h;
		cout<<endl;
		for(int i=0;i<DG.size();i++)
		{
			diem_vector d;
			cout<<"Nhap vector tinh tien voi hinh thu "<<i+1<<": ";
			cin>>d.x>>d.y;
			DG.at(i)->tinhtien(h,d);
		}
	}
};

bool test(diem_vector d1, diem_vector d2)
{
	if(d1.x==0&&d1.y==0) return true;
	if(d2.x==0&&d2.y==0) return true;
	if(d1.x==0&&d2.x==0) return true;
	if(d1.y==0&&d2.y==0) return true;
	if(d2.x==0) return false;
	if(d2.y==0) return false;
	if((d1.x/d2.x)==(d1.y/d2.y)) return true;
	else return false;
}

bool test2(diem_vector d1,diem_vector d2)
{
	if((d1.x*d2.x+d1.y*d2.y)==0) return true;
	else return false;
}

void main()
{
	hinhhoc hh;
	hh.input();
	hh.output();
	hh.tinhtien();
	hh.output();
}