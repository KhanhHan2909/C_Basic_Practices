#include<iostream>

using namespace std;

class sophuc
{
	float a, b;
public:
	sophuc()
	{
		a = 1;
		b = 1;
	}
	sophuc(float a0,float b0)
	{
		a = a0;
		b = b0;
	}
	sophuc operator+(const sophuc &sp)
	{
		sophuc res;
		res.a = this->a + sp.a;
		res.b = this->b + sp.b;
		return res;
	}
	sophuc operator-(const sophuc &sp)
	{
		sophuc res;
		res.a = this->a - sp.a;
		res.b = this->b - sp.b;
		return res;
	}
	sophuc operator*(const sophuc &sp)
	{
		sophuc res;
		res.a = this->a*sp.a - this->b*sp.b;
		res.b = this->a*sp.b + sp.a*this->b;
		return res;
	}
	sophuc operator/(const sophuc &sp)
	{
		sophuc res;
		float c = sp.a*sp.a + sp.b*sp.b;
		res.a = (this->a*sp.a + this->b*sp.b)/c;
		res.b = (sp.a*this->b - this->a*sp.b)/c;
		return res;
	}
	bool operator==(const sophuc &sp)
	{
		if(this->a==sp.a&&this->b==sp.b) return true;
		else return false;
	}
	bool operator!=(const sophuc &sp)
	{
		if(this->a!=sp.a||this->b!=sp.b) return true;
		else return false;
	}
	bool operator>(const sophuc &sp)
	{
		float c1 = this->a*this->a + this->b*this->b, c2 = sp.a*sp.a + sp.b*sp.b;
		if(c1>c2) return true;
		else return false;
	}
	bool operator<(const sophuc &sp)
	{
		float c1 = this->a*this->a + this->b*this->b, c2 = sp.a*sp.a + sp.b*sp.b;
		if(c1<c2) return true;
		else return false;
	}
	friend ostream& operator<<(ostream &os,const sophuc &sp);
	friend istream& operator>>(istream &is,sophuc &sp);
	~sophuc() {}
};
ostream& operator<<(ostream &os,const sophuc &sp)
{
	os<<sp.a<<" + "<<sp.b<<"*i";
	return os;
}
istream& operator>>(istream &is,sophuc &sp)
{
	is>>sp.a>>sp.b;
	return is;
}

int main()
{
	sophuc sp1(3,6), sp2, sp7(0,0);
	cout<<"So phuc thu nhat: "<<sp1;
	cout<<"\nNhap so phuc thu hai: ";
	cin>>sp2;
	sophuc sp3 = sp1 + sp2, sp4 = sp1 - sp2, sp5 = sp1*sp2, sp6 = sp1/sp2;
	if(sp2!=sp7)
		cout<<"Add: "<<sp3<<", "<<"Sub: "<<sp4<<", "<<"Multi: "<<sp5<<", "<<"Div: "<<sp6<<endl;	
	else
		cout<<"Add: "<<sp3<<", "<<"Sub: "<<sp4<<", "<<"Multi: "<<sp5<<", phep chia khong co ket qua!\n";
	cout<<"sp1 = sp2: "<<(sp1==sp2)<<endl;
	cout<<"sp1 >< sp2: "<<(sp1!=sp2)<<endl;
	cout<<"sp1 > sp2: "<<(sp1>sp2)<<endl;
	cout<<"sp1 < sp2: "<<(sp1<sp2)<<endl;
}