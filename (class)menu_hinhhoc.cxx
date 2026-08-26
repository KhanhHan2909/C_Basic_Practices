#include<iostream>
#include<math.h>
#include<vector>

#define pi 3.1412159

using namespace std;

class canh_bankinh
{
protected:
	float *x;
public:
	canh_bankinh()
	{
		x = new float;
		*x = 0;
	}
	virtual void input(int k)
	{
		cin>>x[k];
	}
	virtual void output() {}
	virtual float dientich() {}
	virtual float chuvi() {}
	~canh_bankinh()
	{
		delete []x;
	}
};
	
class hinhchunhat: public canh_bankinh
{
public:
	hinhchunhat(): canh_bankinh()
	{
		x = new float[2];
		x[1] = 1;
		x[2] = 1;
	}
	void input(int k)
	{
		x = new float[2];
		for(k=0;k<2;k++)
		{
			cout<<"Do dai canh thu "<<k+1<<": ";
			canh_bankinh::input(k);
		}
	}
	void output()
	{
		cout<<"Hinh chu nhat ("<<x[0]<<" "<<x[1]<<")";
	}
	float dientich()
	{
		return x[0]*x[1];
	}
	float chuvi()
	{
		return (x[0]+x[1])*2;
	}
	~hinhchunhat()
	{
		delete []x;
	}
};

class tamgiac: public canh_bankinh
{
public:
	tamgiac(): canh_bankinh()
	{
		x = new float[3];
		x[0] = 1;
		x[1] = 1;
		x[2] = 1;
	}
	void input(int k)
	{
		x = new float[3];
		for(k=0;k<3;k++)
		{
			cout<<"Do dai canh thu "<<k+1<<": ";
			canh_bankinh::input(k);
		}
	}
	void output()
	{
		cout<<"Tam giac ("<<x[0]<<" "<<x[1]<<" "<<x[2]<<")";
	}
	float dientich()
	{
		float p = (x[0] + x[1] + x[2])/2;
		return sqrt(p*(p-x[0])*(p-x[1])*(p-x[2]));
	}
	float chuvi()
	{
		return x[0] + x[1] + x[2];
	}
	~tamgiac()
	{
		delete []x;
	}
};

class hinhtron: public canh_bankinh
{
public:
	hinhtron(): canh_bankinh()
	{
		x = new float;
		*x = 1;
	}
	void input(int k)
	{
		x = new float;
		cout<<"Do dai ban kinh: ";
		canh_bankinh::input(0);
	}
	float dientich()
	{
		return (*x)*(*x)*pi;
	}
	float chuvi()
	{
		return 2*(*x)*pi;
	}
	void output()
	{
		cout<<"Hinh tron ("<<*x<<")";
	}
	~hinhtron()
	{
		delete x;
	}
};

void main()
{
	vector<canh_bankinh*> hh;
	int n;
	do
	{
		cout<<endl;
		cout<<"1. Nhap kich thuoc cac hinh\n";
		cout<<"2. Hien thi dien tich va chu vi\n";
		cout<<"3. Ket thuc\n";
		cin>>n;
		if(n==1)
		{
			int k;
			do
			{
				cout<<"Hinh chu nhat(1), tam giac(2), hinh tron(3): ";
				cin>>k;
			} while(k<1||k>3);
			canh_bankinh *NEW;
			if(k==1) NEW = new hinhchunhat;
			else if(k==2) NEW = new tamgiac;
			else NEW = new hinhtron;
			NEW->input(k);
			hh.push_back(NEW);
		}
		if(n==2)
		{
			for(int i=0;i<hh.size();i++)
			{
				cout<<i+1<<". ";
				hh.at(i)->output();
				cout<<"    Chu vi: "<<hh.at(i)->chuvi()<<" Dien tich: "<<hh.at(i)->dientich()<<endl;
			}
		}
	} while(n!=3);
}