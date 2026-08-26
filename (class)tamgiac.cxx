#include<iostream>
#include<math.h>

using namespace std;

class TamGiac;

class Diem
{
	float x, y;
public:
	Diem()
	{
		x = 0;
		y = 0;
	}
	Diem(int a, int b)
	{
		x = a;
		y = b;
	}
	float getterx()
	{
		return x;
	}
	float gettery()
	{
		return y;
	}
	void setterx(float a)
	{
		x = a;
	}
	void settery(float b)
	{
		y = b;
	}
	void move1(float a,float b)
	{
    setterx(getterx()+a);
    settery(gettery()+b);
	}
    friend class TamGiac;
    friend ostream & operator<<(ostream & os,TamGiac &tg);
    friend istream & operator>>(istream & is,TamGiac &tg);
    friend void sizeup(TamGiac t);
    friend void sizedown(TamGiac t);
    friend void rotate(TamGiac t);
    ~Diem() {}
};

class TamGiac
{
	Diem a, b, c;
public:
	TamGiac()
	{
		a.x = 0;
		a.y = 0;
		b.x = 1;
		b.y = 0;
		c.x = 0;
		c.y = 1;
	}
	TamGiac(Diem a0,Diem b0,Diem c0)
	{
		settera0(a0);
		setterb0(b0);
		setterc0(c0);
	}
	void settera0(Diem a0)
	{
		a.x = a0.x;
		a.y = a0.y;
	}
	void setterb0(Diem b0)
	{
		b.x = b0.x;
		b.y = b0.y;
	}
	void setterc0(Diem c0)
	{
		c.x = c0.x;
		c.y = c0.y;
	}
	float length(Diem a0,Diem b0)
	{
		return sqrt(pow(a0.x-b0.x,2) + pow(a0.y-b0.y,2));
	}
	int test()
	{
		float ab = length(a,b), bc = length(b,c), ca = length(c,a);
		if(ab+bc<=ca||bc+ca<=ab||ca+ab<=bc)
			return 0;
		else return 1;
	}
	void move2(float m,float n)
	{
		a.move1(m,n);
		b.move1(m,n);
		c.move1(m,n);
	}
	friend ostream & operator<<(ostream & os,TamGiac &tg);
    friend istream & operator>>(istream & is,TamGiac &tg);
    friend void sizeup(TamGiac t);
    friend void sizedown(TamGiac t);
    friend void rotate(TamGiac t);
    ~TamGiac() {}
};

ostream & operator<<(ostream & os,TamGiac &tg)
{
	os<<"("<<tg.a.getterx()<<","<<tg.a.gettery()<<")"<<" ; "<<"("<<tg.b.getterx()<<","<<tg.b.gettery()<<")"<<" ; "<<"("<<tg.c.getterx()<<","<<tg.c.gettery()<<")";
	return os;
}
istream & operator>>(istream & is,TamGiac &tg)
{
	is>>tg.a.x>>tg.a.y>>tg.b.x>>tg.b.y>>tg.c.x>>tg.c.y;
	return is;
}

int doisonguyen(float a)
{
	while(a-floor(a)!=0) a *= 10;
	return (int)a;
}

int ucln(int a,int b)
{
	if(b==0) return a;
	while(a>0)
	{
		if(a>=b) a -= b;
		else b -= a;
	}
	return b;
}

void toadotoigian(float &a,float &b)
{
	int m = doisonguyen(a);
	int n = doisonguyen(b);
	int p = ucln(abs(m),abs(n));
	m /= p;
	n /= p;
	a = (float)m;
	b = (float)n;
}
	
void vtpt(float &a,float &b)
{
	toadotoigian(a,b);
	float c = a*-1;
	a = b;
	b = c;
}

void sizeup(TamGiac t)
{
	Diem a0, b0, c0;
	a0.x = t.a.x;
	a0.y = t.a.y;
	int sizeup;
	float delta, m1 = t.a.x - t.b.x, n1 = t.a.y - t.b.y, m2 = t.c.x - t.a.x, n2 = t.c.y - t.a.y;
	vtpt(m1,n1);
	vtpt(m2,n2);
	do
	{
		cout<<"Nhap so lan muon phong to tam giac: ";
		cin>>sizeup;
	} while(sizeup<=0);
	float d1 = sqrt(pow(t.a.x-t.b.x,2)+pow(t.a.y-t.b.y,2));
	float d2 = sqrt(pow(t.c.x-t.a.x,2)+pow(t.c.y-t.a.y,2));
	d1 *= sizeup;
	d2 *= sizeup;
	if(n1==0)
	{
		b0.x = t.a.x;
		if(t.b.y>t.a.y) b0.y = t.a.y + d1;
		else b0.y = t.a.y - d1;
		delta = pow((m2/n2 + 1)*t.a.x,2) - (m2*m2/(n2*n2) + 1)*((m2*m2/(n2*n2) + 1)*t.a.x*t.a.x - d2*d2);
		if(t.c.x>t.a.x) c0.x = ((m2/n2 + 1)*t.a.x + sqrt(delta))/(m2*m2/(n2*n2) + 1);
		else c0.x = ((m2/n2 + 1)*t.a.x - sqrt(delta))/(m2*m2/(n2*n2) + 1);
		c0.y = (m2*t.a.x + n2*t.a.y - m2*c0.x)/n2;
		TamGiac tg(a0,b0,c0);
		cout<<"3 diem tam giac sau khi phong to lay A lam goc la: "<<tg<<endl;
		return;
	}
	if(n2==0)
	{
		delta = pow((m1/n1 + 1)*t.a.x,2) - (m1*m1/(n1*n1) + 1)*((m1*m1/(n1*n1) + 1)*t.a.x*t.a.x - d1*d1);
		if(t.b.x>t.a.x) b0.x = ((m1/n1 + 1)*t.a.x + sqrt(delta))/(m1*m1/(n1*n1) + 1);
		else b0.x = ((m1/n1 + 1)*t.a.x - sqrt(delta))/(m1*m1/(n1*n1) + 1);
		b0.y = (m1*t.a.x + n1*t.a.y - m1*b0.x)/n1;
		c0.x = t.a.x;
		if(t.c.y>t.a.y) c0.y = t.a.y + d2;
		else c0.y = t.a.y - d2;
		TamGiac tg(a0,b0,c0);
		cout<<"3 diem tam giac sau khi phong to lay A lam goc la: "<<tg<<endl;
		return;
	}
	delta = pow((m1/n1 + 1)*t.a.x,2) - (m1*m1/(n1*n1) + 1)*((m1*m1/(n1*n1) + 1)*t.a.x*t.a.x - d1*d1);
	if(t.b.x>t.a.x) b0.x = ((m1/n1 + 1)*t.a.x + sqrt(delta))/(m1*m1/(n1*n1) + 1);
	else b0.x = ((m1/n1 + 1)*t.a.x - sqrt(delta))/(m1*m1/(n1*n1) + 1);
	b0.y = (m1*t.a.x + n1*t.a.y - m1*b0.x)/n1;
	delta = pow((m2/n2 + 1)*t.a.x,2) - (m2*m2/(n2*n2) + 1)*((m2*m2/(n2*n2) + 1)*t.a.x*t.a.x - d2*d2);
	if(t.c.x>t.a.x) c0.x = ((m2/n2 + 1)*t.a.x + sqrt(delta))/(m2*m2/(n2*n2) + 1);
	else c0.x = ((m2/n2 + 1)*t.a.x - sqrt(delta))/(m2*m2/(n2*n2) + 1);
	c0.y = (m2*t.a.x + n2*t.a.y - m2*c0.x)/n2;
	TamGiac tg(a0,b0,c0);
	cout<<"3 diem tam giac sau khi phong to lay A lam goc la: "<<tg<<endl;
	return;
}

void sizedown(TamGiac t)
{
	Diem a0, b0, c0;
	a0.x = t.a.x;
	a0.y = t.a.y;
	int sizedown;
	float delta, m1 = t.a.x - t.b.x, n1 = t.a.y - t.b.y, m2 = t.c.x - t.a.x, n2 = t.c.y - t.a.y;
	vtpt(m1,n1);
	vtpt(m2,n2);
	do
	{
		cout<<"Nhap so lan muon thu nho tam giac: ";
		cin>>sizedown;
	} while(sizedown<=0);
	float d1 = sqrt(pow(t.a.x-t.b.x,2)+pow(t.a.y-t.b.y,2));
	float d2 = sqrt(pow(t.c.x-t.a.x,2)+pow(t.c.y-t.a.y,2));
	d1 /= sizedown;
	d2 /= sizedown;
	if(n1==0)
	{
		b0.x = t.a.x;
		if(t.b.y>t.a.y) b0.y = t.a.y + d1;
		else b0.y = t.a.y - d1;
		delta = pow((m2/n2 + 1)*t.a.x,2) - (m2*m2/(n2*n2) + 1)*((m2*m2/(n2*n2) + 1)*t.a.x*t.a.x - d2*d2);
		if(t.c.x>t.a.x) c0.x = ((m2/n2 + 1)*t.a.x + sqrt(delta))/(m2*m2/(n2*n2) + 1);
		else c0.x = ((m2/n2 + 1)*t.a.x - sqrt(delta))/(m2*m2/(n2*n2) + 1);
		c0.y = (m2*t.a.x + n2*t.a.y - m2*c0.x)/n2;
		TamGiac tg(a0,b0,c0);
		cout<<"3 diem tam giac sau khi thu nho lay A lam goc la: "<<tg<<endl;
		return;
	}
	if(n2==0)
	{
		delta = pow((m1/n1 + 1)*t.a.x,2) - (m1*m1/(n1*n1) + 1)*((m1*m1/(n1*n1) + 1)*t.a.x*t.a.x - d1*d1);
		if(t.b.x>t.a.x) b0.x = ((m1/n1 + 1)*t.a.x + sqrt(delta))/(m1*m1/(n1*n1) + 1);
		else b0.x = ((m1/n1 + 1)*t.a.x - sqrt(delta))/(m1*m1/(n1*n1) + 1);
		b0.y = (m1*t.a.x + n1*t.a.y - m1*b0.x)/n1;
		c0.x = t.a.x;
		if(t.c.y>t.a.y) c0.y = t.a.y + d2;
		else c0.y = t.a.y - d2;
		TamGiac tg(a0,b0,c0);
		cout<<"3 diem tam giac sau khi thu nho lay A lam goc la: "<<tg<<endl;
		return;
	}
	delta = pow((m1/n1 + 1)*t.a.x,2) - (m1*m1/(n1*n1) + 1)*((m1*m1/(n1*n1) + 1)*t.a.x*t.a.x - d1*d1);
	if(t.b.x>t.a.x) b0.x = ((m1/n1 + 1)*t.a.x + sqrt(delta))/(m1*m1/(n1*n1) + 1);
	else b0.x = ((m1/n1 + 1)*t.a.x - sqrt(delta))/(m1*m1/(n1*n1) + 1);
	b0.y = (m1*t.a.x + n1*t.a.y - m1*b0.x)/n1;
	delta = pow((m2/n2 + 1)*t.a.x,2) - (m2*m2/(n2*n2) + 1)*((m2*m2/(n2*n2) + 1)*t.a.x*t.a.x - d2*d2);
	if(t.c.x>t.a.x) c0.x = ((m2/n2 + 1)*t.a.x + sqrt(delta))/(m2*m2/(n2*n2) + 1);
	else c0.x = ((m2/n2 + 1)*t.a.x - sqrt(delta))/(m2*m2/(n2*n2) + 1);
	c0.y = (m2*t.a.x + n2*t.a.y - m2*c0.x)/n2;
	TamGiac tg(a0,b0,c0);
	cout<<"3 diem tam giac sau khi thu nho lay A lam goc la: "<<tg<<endl;
	return;
}

void rotate(TamGiac t)
{
	float alpha;
	cout<<"Nhap goc quay (radiant): ";
	cin>>alpha;
	Diem a0, b0, c0;
	a0.x = t.a.x*cos(alpha) - t.a.y*sin(alpha);
	a0.y = t.a.x*sin(alpha) + t.a.y*cos(alpha);
	b0.x = t.b.x*cos(alpha) - t.b.y*sin(alpha);
	b0.y = t.b.x*sin(alpha) + t.b.y*cos(alpha);
	c0.x = t.c.x*cos(alpha) - t.c.y*sin(alpha);
	c0.y = t.c.x*sin(alpha) + t.c.y*cos(alpha);
	TamGiac tg(a0,b0,c0);
	cout<<"3 diem tam giac sau khi quay tam O goc alpha la "<<tg<<endl;
}

int main()
{
	Diem a;
	Diem b(0,5);
	Diem c(3,4);
	TamGiac number1;
	TamGiac number2(a,b,c);
	cout<<"3 diem a1; b1; c1: "<<number1<<endl;
	if(number1.test()) cout<<"3 diem tren tao thanh mot tam giac!\n";
	else cout<<"3 diem tren KHONG tao thanh mot tam giac!\n";
	cout<<"Dat lai 3 diem a1; b1; c1: ";
	cin>>number1;
	if(number1.test()) cout<<"3 diem "<<number1<<" tao thanh mot tam giac!\n";
	else cout<<"3 diem "<<number1<<" KHONG tao thanh mot tam giac!\n";
	cout<<"3 diem a2; b2; c2: "<<number2<<endl;
	if(number2.test()) 
	{
		cout<<"3 diem tren tao thanh mot tam giac!\n";
		cout<<"Di chuyen tam giac 2 theo vector (-6,7): ";
		number2.move2(-6,7);
		cout<<number2<<endl;
	}
	else cout<<"3 diem tren KHONG tao thanh mot tam giac!\n";
	TamGiac number3;
	cout<<"Nhap toa do tam giac so 3: ";
	cin>>number3;
	if(number3.test())
	{
		cout<<"Tam giac vua nhap: "<<number3<<endl;
		sizeup(number3);
		sizedown(number3);
	}
	else cout<<"3 diem tren KHONG tao thanh mot tam giac!\n";
	rotate(number3);
}