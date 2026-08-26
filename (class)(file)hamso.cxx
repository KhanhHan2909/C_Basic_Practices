#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

class Function
{
protected:
	float min, step, max;
public:
	Function()
	{
		min = 0;
		step = 1;
		max = 1;
	}
	Function(float min0,float max0,float step0)
	{
		min = min0;
		max = max0;
		step = step0;
	}
	void foutput()
	{
		fstream f;
		f.open("khaosat.inp",ios::app);
		f<<min<<" "<<max<<" "<<step;
		f.close();
	}
	void foutput2()
	{
		ofstream f;
		f.open("khaosat.out");
		for(float i=min;i<=max;i+=step) f<<i<<" ";
		f<<endl;
		f.close();
	}
	~Function() {}
};

class fx: public Function
{
	float k;
public:
	fx()
	{
		k = 1;
	}
	fx(float k0)
	{
		k = k0;
	}
	void input(float min0,float max0,float step0)
	{
		min = min0;
		max = max0;
		step = step0;
		cout<<"k1 = ";
		cin>>k;
	}
	void foutput0()
	{
		ofstream f;
		f.open("khaosat.inp");
		f<<k<<" ";
		f.close();
	}
	void *value()
	{
		float val;
		fstream f0;
		f0.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = k*i - 3;
			f0<<val<<" ";
		}
		f0<<endl;
		f0.close();
	}
	void derivative()
	{
		float val;
		fstream f0;
		f0.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = k;
			f0<<val<<" ";
		}
		f0<<endl;
		f0.close();
	}
	~fx() {}
};

class gx: public Function
{
	float k;
public:
	gx()
	{
		k = 1;
	}
	gx(float k0)
	{
		k = k0;
	}
	void input(float min0,float max0,float step0)
	{
		min = min0;
		max = max0;
		step = step0;
		cout<<"k2 = ";
		cin>>k;
	}
	void foutput0()
	{
		fstream f;
		f.open("khaosat.inp",ios::app);
		f<<k<<" ";
		f.close();
	}
	void *value()
	{
		float val;
		fstream g;
		g.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = -3*i*i + k*i;
			g<<val<<" ";
		}
		g<<endl;
		g.close();
	}
	void derivative()
	{
		float val;
		fstream g;
		g.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = -6*i + k;
			g<<val<<" ";
		}
		g<<endl;
		g.close();
	}
	~gx() {}
};

class hx: public Function
{
	float k;
public:
	hx()
	{
		k = 1;
	}
	hx(float k0)
	{
		k = k0;
	}
	void input(float min0,float max0,float step0)
	{
		min = min0;
		max = max0;
		step = step0;
		cout<<"k3 = ";
		cin>>k;
	}
	void foutput0()
	{
		fstream f;
		f.open("khaosat.inp",ios::app);
		f<<k<<" ";
		f.close();
	}
	void *value()
	{
		float val;
		fstream h;
		h.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = 7*i*i*i + k*i*i - 5;
			h<<val<<" ";
		}
		h<<endl;
		h.close();
	}
	void derivative()
	{
		float val;
		fstream h;
		h.open("khaosat.out",ios::app);
		for(float i=min;i<=max;i+=step)
		{
			val = 21*i*i + 2*k*i;
			h<<val<<" ";
		}
		h<<endl;
		h.close();
	}
	~hx() {}
};

int main()
{
	float a, min, max, step;
	cout<<"min = ";
	cin>>min;
	do
	{
		cout<<"max = ";
		cin>>max;
	} while(max<=min);
	do
	{
		cout<<"step = ";
		cin>>step;
		a = (max - min)/step;
	} while(a!=round(a)||step<=0);
	fx f; gx g; hx h; Function F(min,max,step);
	f.input(min,max,step); g.input(min,max,step); h.input(min,max,step);
	f.foutput0(); g.foutput0(); h.foutput0(); F.foutput();
	F.foutput2();
	f.value(); g.value(); h.value();
	f.derivative(); g.derivative(); h.derivative();
}