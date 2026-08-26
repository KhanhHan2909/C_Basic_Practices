#include<iostream>

using namespace std;

class dathuc
{
	int n;
	float *a;
public:
	dathuc()
	{
		n = 0;
		a = new float[1];
		a[0] = 0;
	}
	//Correct Code Python
	/*def xuat(dt):
	    if dt.n==0: print(dt.hs[0],end=" ")
	    elif dt.n==1:
	        print("{0}*x".format(dt.hs[0]),end=" ")
	        if dt.hs[1]!=0: print("+",dt.hs[1],end=" ")
	    else:
	        print("{0}*x^{1}".format(dt.hs[0],dt.n),end=" ")
	        for i in range(dt.n-1,1,-1):
	            if dt.hs[dt.n-i]!=0:
	                print("+ {0}*x^{1}".format(dt.hs[dt.n-i],i),end=" ")
	        if dt.hs[dt.n-1]==0:
	            if dt.hs[dt.n]!=0: print("+",dt.hs[dt.n],end=" ")
	        else:
	            print("+ {0}*x".format(dt.hs[dt.n-1]),end=" ")
	            if dt.hs[dt.n]!=0: print("+",dt.hs[dt.n],end=" ")
	def nhap(dt):
	    dt.n = -1
	    while dt.n<0:
	        dt.n = int(input("Nhap bac da thuc (lon hon hoac bang 0): "))
	    dt.hs = []
	    if dt.n==0:
	        x = float(input("Nhap he so: "))
	        dt.hs.append(x)
	    else:
	        x = float(input("Nhap he so thu 1: "))
	        while x==0:
	            print("He so thu 1 phai khac 0!")
	            x = float(input("Nhap he so thu 1: "))
	        dt.hs.append(x)
	        for i in range(1,dt.n+1):
	            x = float(input("Nhap he so thu {0}: ".format(i+1)))
	            dt.hs.append(x)*/
	void output()
	{
		cout<<"f(x) = ";
		if(n==0) cout<<a[0];
		else
			for(int i=0;i<n-1;i++) cout<<a[i]<<"*x^"<<n-i<<" + ";
			cout<<a[n-1]<<"*x"<<" + "<<a[n];
	}
	void input()
{
	do
	{
		cout<<"Nhap bac da thuc: ";
		cin>>n;
	} while(n<0);
	a = new float[n+1];
	for(int i=0;i<n+1;i++)
	{
		cout<<"Nhap he so thu "<<i+1<<": ";
		cin>>a[i];
	}
}
	~dathuc()
	{
		delete []a;
	}
};

int main()
{
	dathuc dt;
	dt.input();
	dt.output();
}