#include<iostream>

using namespace std;

struct phanso
{
	int a, b;
};

 int ucln(int x,int y)
 {
 	int x0 = abs(x); int y0 = abs(y);
 	while(y0!=0)
 	{
 		if(x0>y0) x0 -= y0;
 		else y0 -= x0;
 	}
 	return x0;
 }
 
int qdms(phanso n1,phanso n2)
{
	return n1.b*n2.b/ucln(n1.b,n2.b);
}

bool operator<(phanso &n1,phanso &n2)
{
	int x = n1.a, y = n2.a;
	x *= qdms(n1,n2)/n1.b;
	y *= qdms(n1,n2)/n2.b;
	if(x<y) return true;
	else return false;
}

bool operator>(phanso &n1,phanso &n2)
{
	int x = n1.a, y = n2.a;
	x *= qdms(n1,n2)/n1.b;
	y *= qdms(n1,n2)/n2.b;
	if(x>y) return true;
	else return false;
}

/*phanso abs(phanso ps)
{
	if(ps.a<0) ps.a = ps.a*-1;
	if(ps.b<0) ps.b = ps.b*-1;
	return ps;
}*/

phanso operator*(phanso &ps,int x)
{
	 phanso ps0;
	 ps0.a = ps.a*x;
	 ps0.b = ps.b;
	return ps0;
}

bool operator<(phanso &ps,const int x)
{
	if(ps.a<0&&ps.b>=0) return true;
	else if(ps.a>=0&&ps.b<0) return true;
	else return false;
}

ostream& operator<<(ostream &os,phanso &ps)
{
	os<<ps.a<<"/"<<ps.b;
	return os;
}

istream& operator>>(istream &is,phanso &ps)
{
	is>>ps.a>>ps.b;
	return is;
}

template<typename T>
class dayso
{
	T *a;
public:
	dayso()
	{
		a = new T;
		*a = 0;
	}
	dayso(const T &v,int n)
	{
		a = new T[n];
		for(int i=0;i<n;i++) a[i] = v;
	}
	dayso(T *a0,int n)
	{
		a = new T[n];
		for(int i=0;i<n;i++) a[i] = a0[i];
	}
	void output(int n)
	{
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
	}
	void tangdan(int n)
	{
		T x;
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				if(a[i]>a[j])
				{
					x = a[i];
					a[i] = a[j];
					a[j] = x;
				}
	}
	void gttdgiamdan(int n)
	{
		T x, x1, x2;
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				if(a[i]<0) x1 = a[i]*-1;
				else x1 = a[i];
				if(a[j]<0) x2 = a[j]*-1;
				else x2 = a[j];
				if(x1<x2)
				{
					x = a[i];
					a[i] = a[j];
					a[j] = x;
				}
			}
	}
	~dayso()
	{
		delete []a;
	}
};

void main()
{
	int n, v = 5;
	phanso *arr;
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	arr = new phanso[n];
	for(int i=0;i<n;i++)
	{
		do
		{
			cout<<"a["<<i<<"] = ";
			cin>>arr[i];
		} while(arr[i].b==0);
	}
	dayso ds(arr,n);
	ds.output(n);
	ds.tangdan(n);
	cout<<endl;
	ds.output(n);
	ds.gttdgiamdan(n);
	cout<<endl;
	ds.output(n);
	delete []arr;
}