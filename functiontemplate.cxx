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
	n1.a *= qdms(n1,n2)/n1.b;
	n2.a *= qdms(n1,n2)/n2.b;
	if(n1.a<n2.a) return true;
	else return false;
}

bool operator>(phanso &n1,phanso &n2)
{
	n1.a *= qdms(n1,n2)/n1.b;
	n2.a *= qdms(n1,n2)/n2.b;
	if(n1.a>n2.a) return true;
	else return false;
}

ostream& operator<<(ostream &os,phanso &ps)
{
	os<<ps.a<<"/"<<ps.b;
	return os;
}

template<typename val>
void min(val x1,val x2)
{
	if(x1<x2) cout<< x1;
	else cout<< x2;
}
void main()
{
	phanso n1, n2;
	n1.a = 3; n1.b = 4;
	n2.a = 2; n2.b = 3;
}