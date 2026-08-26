#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;
struct diem_vector
{
	int x, y;
};

class hinhhoc
{
protected:
	diem_vector *p;
	int *d;
public:
	hinhhoc()
	{
		p = new diem_vector;
		p->x = 0; p->y = 0;
		d = new int;
		*d = 5;
	}
	virtual void foutput() = 0;
	virtual void finput(int i0) = 0;
	virtual int gttx() = 0;
	virtual int gtty() = 0;
	virtual int dai() = 0;
	virtual int rong() = 0;
	~hinhhoc()
	{
		delete p;
		delete d;
	}
};

class tamgiac: public hinhhoc
{
public:
	tamgiac()
	{
		p = new diem_vector[3];
		p[0].x = 0; p[0].y = 0;
		p[1].x = 0; p[1].y = 1;
		p[2].x = 1; p[2].y = 0;
		d = new int;
		d = 0;
	}
	void foutput()
	{
		fstream f;
		f.open("hinhhoc.inp",ios::app);
		p = new diem_vector[3];
		for(int i=0;i<3;i++)
		{
			cout<<"Toa do goc "<<i+1<<": ";
			cin>>p[i].x>>p[i].y;
		}
		f<<"G "<<p[0].x<<" "<<p[0].y<<" "<<p[1].x<<" "<<p[1].y<<" "<<p[2].x<<" "<<p[2].y<<" "<<endl;
		f.close();
	}
	void finput(int i0)
	{
		ifstream f;
		f.open("hinhhoc.inp");
		string data;
		vector<string> sv;
		int i, s;
		while(!f.eof())
		{
			f>>data;
			sv.push_back(data);
		}
		s = 0;
		if(sv[i0+1][0]!=45)
		{
			for(i=sv[i0+1].size()-1;i>=0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p[0].x = s;
		}
		else
		{
			for(i=sv[i0+1].size()-1;i>0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p[0].x = -1*s;
		}
		s = 0;
		if(sv[i0+2][0]!=45)
		{
			for(i=sv[i0+2].size()-1;i>=0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p[0].y = s;
		}
		else
		{
			for(i=sv[i0+2].size()-1;i>0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p[0].y = -1*s;
		}
		s = 0;
		if(sv[i0+3][0]!=45)
		{
			for(i=sv[i0+3].size()-1;i>=0;i--) s += (sv[i0+3][i]-48)*pow(10,sv[i0+3].size()-1-i);
			p[1].x = s;
		}
		else
		{
			for(i=sv[i0+3].size()-1;i>0;i--) s += (sv[i0+3][i]-48)*pow(10,sv[i0+3].size()-1-i);
			p[1].x = -1*s;
		}
		s = 0;
		if(sv[i0+4][0]!=45)
		{
			for(i=sv[i0+4].size()-1;i>=0;i--) s += (sv[i0+4][i]-48)*pow(10,sv[i0+4].size()-1-i);
			p[1].y = s;
		}
		else
		{
			for(i=sv[i0+4].size()-1;i>0;i--) s += (sv[i0+4][i]-48)*pow(10,sv[i0+4].size()-1-i);
			p[1].y = -1*s;
		}
		s = 0;
		if(sv[i0+5][0]!=45)
		{
			for(i=sv[i0+5].size()-1;i>=0;i--) s += (sv[i0+5][i]-48)*pow(10,sv[i0+5].size()-1-i);
			p[2].x = s;
		}
		else
		{
			for(i=sv[i0+5].size()-1;i>0;i--) s += (sv[i0+5][i]-48)*pow(10,sv[i0+5].size()-1-i);
			p[2].x = -1*s;
		}
		s = 0;
		if(sv[i0+6][0]!=45)
		{
			for(i=sv[i0+6].size()-1;i>=0;i--) s += (sv[i0+6][i]-48)*pow(10,sv[i0+6].size()-1-i);
			p[2].y = s;
		}
		else
		{
			for(i=sv[i0+6].size()-1;i>0;i--) s += (sv[i0+6][i]-48)*pow(10,sv[i0+6].size()-1-i);
			p[2].y = -1*s;
		}
		f.close();
	}
	int gttx() //Hoanh do goc trai tren
	{
		if(p[0].x<=p[1].x&&p[0].x<=p[2].x) return p[0].x;
		if(p[1].x<=p[2].x&&p[1].x<=p[0].x) return p[1].x;
		if(p[2].x<=p[0].x&&p[2].x<=p[1].x) return p[2].x;
	}
	int gtty() //Tung do goc trai tren
	{
		if(p[0].y>=p[1].y&&p[0].y>=p[2].y) return p[0].y;
		if(p[1].y>=p[2].y&&p[1].y>=p[0].y) return p[1].y;
		if(p[2].y>=p[0].y&&p[2].y>=p[1].y) return p[2].y;
	}
	int gptx() //Hoanh do goc phai tren
	{
		if(p[0].x>=p[1].x&&p[0].x>=p[2].x) return p[0].x;
		if(p[1].x>=p[2].x&&p[1].x>=p[0].x) return p[1].x;
		if(p[2].x>=p[0].x&&p[2].x>=p[1].x) return p[2].x;
	}
	int gtdy() //Tung do goc trai duoi
	{
		if(p[0].y<=p[1].y&&p[0].y<=p[2].y) return p[0].y;
		if(p[1].y<=p[2].y&&p[1].y<=p[0].y) return p[1].y;
		if(p[2].y<=p[0].y&&p[2].y<=p[1].y) return p[2].y;
	}
	int dai()
	{
		return gptx() - gttx();
	}
	int rong()
	{
		return gtty() - gtdy();
	}
	~tamgiac()
	{
		delete []p;
		delete []d;
	}
};

class hinhchunhat: public hinhhoc
{
public:
	hinhchunhat()
	{
		p = new diem_vector;
		p->x = 0; p->y = 0;
		d = new int[2];
		d[0] = 1; d[1] = 1;
	}
	void foutput()
	{
		fstream f;
		f.open("hinhhoc.inp",ios::app);
		p = new diem_vector;
		cout<<"Toa do goc trai tren: ";
		cin>>p->x>>p->y;
		do
		{
			cout<<"Chieu dai(Ox): ";
			cin>>d[0];
		} while(d[0]<1);
		do
		{
			cout<<"Chieu rong(Oy): ";
			cin>>d[1];
		} while(d[1]<1);
		f<<"C "<<p->x<<" "<<p->y<<" "<<d[0]<<" "<<d[1]<<endl;
		f.close();
	}
	void finput(int i0)
	{
		ifstream f;
		f.open("hinhhoc.inp");
		string data;
		vector<string> sv;
		int i, s;
		while(!f.eof())
		{
			f>>data;
			sv.push_back(data);
		}
		s = 0;
		if(sv[i0+1][0]!=45)
		{
			for(i=sv[i0+1].size()-1;i>=0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = s;
		}
		else
		{
			for(i=sv[i0+1].size()-1;i>0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = -1*s;
		}
		s = 0;
		if(sv[i0+2][0]!=45)
		{
			for(i=sv[i0+2].size()-1;i>=0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = s;
		}
		else
		{
			for(i=sv[i0+2].size()-1;i>0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = -1*s;
		}
		s =0;
		for(i=sv[i0+3].size()-1;i>=0;i--) s += (sv[i0+3][i]-48)*pow(10,sv[i0+3].size()-1-i);
		d[0] = s;
		s =0;
		for(i=sv[i0+4].size()-1;i>=0;i--) s += (sv[i0+4][i]-48)*pow(10,sv[i0+4].size()-1-i);
		d[1] = s;
		f.close();
	}
	int gttx()
	{
		return p->x;
	}
	int gtty()
	{
		return p->y;
	}
	int dai()
	{
		return d[0];
	}
	int rong()
	{
		return d[1];
	}
	~hinhchunhat()
	{
		delete p;
		delete []d;
	}
};

class hinhvuong: public hinhhoc
{
public:
	hinhvuong()
	{
		p = new diem_vector;
		p->x = 0; p->y = 0;
		d = new int;
		*d = 1;
	}
	void foutput()
	{
		fstream f;
		f.open("hinhhoc.inp",ios::app);
		p = new diem_vector;
		cout<<"Toa do goc trai tren: ";
		cin>>p->x>>p->y;
		//d = new int;
		do
		{
			cout<<"Do dai canh: ";
			cin>>*d;
		} while(*d<1);
		f<<"V "<<p->x<<" "<<p->y<<" "<<*d<<endl;
		f.close();
	}
	void finput(int i0)
	{
		ifstream f;
		f.open("hinhhoc.inp");
		string data;
		vector<string> sv;
		int i, s;
		while(!f.eof())
		{
			f>>data;
			sv.push_back(data);
		}
		s = 0;
		if(sv[i0+1][0]!=45)
		{
			for(i=sv[i0+1].size()-1;i>=0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = s;
		}
		else
		{
			for(i=sv[i0+1].size()-1;i>0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = -1*s;
		}
		s = 0;
		if(sv[i0+2][0]!=45)
		{
			for(i=sv[i0+2].size()-1;i>=0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = s;
		}
		else
		{
			for(i=sv[i0+2].size()-1;i>0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = -1*s;
		}
		s = 0;
		for(i=sv[i0+3].size()-1;i>=0;i--) s += (sv[i0+3][i]-48)*pow(10,sv[i0+3].size()-1-i);
		*d = s;
		f.close();
	}
	int gttx()
	{
		return p->x;
	}
	int gtty()
	{
		return p->y;
	}
	int dai()
	{
		return *d;
	}
	int rong()
	{
		return *d;
	}
	~hinhvuong()
	{
		delete p;
		delete d;
	}
};

class hinhtron: public hinhhoc
{
public:
	hinhtron()
	{
		p = new diem_vector;
		p->x = 0; p->y = 0;
		d = new int;
		*d = 1;
	}
	void foutput()
	{
		fstream f;
		f.open("hinhhoc.inp",ios::app);
		p = new diem_vector;
		cout<<"Toa do tam: ";
		cin>>p->x>>p->y;
		d = new int;
		do
		{
			cout<<"Ban kinh: ";
			cin>>*d;
		} while(*d<1);
		f<<"T "<<p->x<<" "<<p->y<<" "<<*d<<endl;
		f.close();
	}
	void finput(int i0)
	{
		ifstream f;
		f.open("hinhhoc.inp");
		string data;
		vector<string> sv;
		int i, s;
		while(!f.eof())
		{
			f>>data;
			sv.push_back(data);
		}
		s = 0;
		if(sv[i0+1][0]!=45)
		{
			for(i=sv[i0+1].size()-1;i>=0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = s;
		}
		else
		{
			for(i=sv[i0+1].size()-1;i>0;i--) s += (sv[i0+1][i]-48)*pow(10,sv[i0+1].size()-1-i);
			p->x = -1*s;
		}
		s = 0;
		if(sv[i0+2][0]!=45)
		{
			for(i=sv[i0+2].size()-1;i>=0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = s;
		}
		else
		{
			for(i=sv[i0+2].size()-1;i>0;i--) s += (sv[i0+2][i]-48)*pow(10,sv[i0+2].size()-1-i);
			p->y = -1*s;
		}
		s = 0;
		for(i=sv[i0+3].size()-1;i>=0;i--) s += (sv[i0+3][i]-48)*pow(10,sv[i0+3].size()-1-i);
		*d = s;
		f.close();
	}
	int gttx()
	{
		return p->x-*d;
	}
	int gtty()
	{
		return p->y+*d;
	}
	int dai()
	{
		return 2*(*d);
	}
	int rong()
	{
		return 2*(*d);
	}
	~hinhtron()
	{
		delete p;
		delete d;
	}
};

class dshh
{
	int *a;
public:
	void foutput()
	{
		ofstream f;
		f.open("hinhhoc.inp");
		int n, k;
		cout<<"Co bao nhieu hinh? ";
		cin>>n;
		f<<n<<endl;
		f.close();
		for(int i=0;i<n;i++)
		{
			do
			{
				cout<<"Tam giac(1), Hinh chu nhat(2), Hinh vuong(3), Hinh tron(4): ";
				cin>>k;
			} while(k<1||k>4);
			hinhhoc *hh;
			if(k==1) hh = new tamgiac;
			else if(k==2) hh = new hinhchunhat;
			else if(k==3) hh = new hinhvuong;
			else hh = new hinhtron;
			hh->foutput();
		}
	}
	void bd_rectangle()
	{
		ifstream f;
		f.open("hinhhoc.inp");
		string data;
		vector<string> sv;
		tamgiac tg; hinhchunhat hcn; hinhvuong hv; hinhtron ht;
		int i, j = -1, rectx, recty, rectw, recth;
		while(!f.eof())
		{
			f>>data;
			sv.push_back(data);
		}
		f.close();
		a = new int[sv.size()];
		hinhhoc *hh;
		for(i=0;i<sv.size();i++)
		{
			if(sv[i]=="G") 
			{
				j++;
				hh = new tamgiac;
				hh->finput(i);
				a[4*j] = hh->gttx();
				a[4*j+1] = hh->gtty();
				a[4*j+2] = hh->dai();
				a[4*j+3] = hh->rong();
			}
			if(sv[i]=="C")
			{
				j++;
				hh = new hinhchunhat;
				hh->finput(i);
				a[4*j] = hh->gttx();
				a[4*j+1] = hh->gtty();
				a[4*j+2] = hh->dai();
				a[4*j+3] = hh->rong();
			}
			if(sv[i]=="V")
			{
				j++;
				hh = new hinhvuong;
				hh->finput(i);
				a[4*j] = hh->gttx();
				a[4*j+1] = hh->gtty();
				a[4*j+2] = hh->dai();
				a[4*j+3] = hh->rong();
			}
			if(sv[i]=="T")
			{
				j++;
				hh = new hinhvuong;
				hh->finput(i);
				a[4*j] = hh->gttx();
				a[4*j+1] = hh->gtty();
				a[4*j+2] = hh->dai();
				a[4*j+3] = hh->rong();
			}
		}
		rectx = a[0];
		for(i=0;i<=j;i++)
			if(a[4*i]<rectx) rectx = a[4*i];
		recty = a[1];
		for(i=0;i<=j;i++)
			if(a[4*i+1]>recty) recty = a[4*i+1];
		rectw = a[2];
		for(i=0;i<=j;i++)
			if(a[4*i]-rectx+a[4*i+2]>rectw) rectw = a[4*i]-rectx+a[4*i+2];
		recth = a[3];
		for(i=0;i<=j;i++)
			if(recty-a[4*i+1]+a[4*i+3]>recth) recth = recty-a[4*i+1]+a[4*i+3];
		ofstream f1;
		f1.open("ketqua.out");
		f1<<rectx<<" "<<recty<<" "<<rectw<<" "<<recth;
		f1.close();
	}
	~dshh()
	{
		delete []a;
	}
};

int main()
{
	dshh hh;
	hh.foutput();
	hh.bd_rectangle();
}