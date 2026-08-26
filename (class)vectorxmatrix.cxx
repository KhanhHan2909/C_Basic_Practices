#include<iostream>
#include<iomanip>

using namespace std;

class Vector
{
	unsigned int d;
	float *coor;
public:
	Vector()
	{
		d = 1;
		float x = 1;
		coor = &x;
	}
	Vector(float coor0)
	{
		d = 1;
		coor = &coor0;
	}
	void init()
	{
		cout<<"Nhap so chieu khong gian: ";
		cin>>d;
		coor = new float[d];
		for(int i=0;i<d;i++)
		{
			cout<<"Toa do thu "<<i+1<<": ";
			cin>>coor[i];
		}
		//delete []coor;
	}
	void output()
	{
		cout<<"So chieu khong gian la: "<<d<<endl;
		cout<<"Toa do vector trong kg: (";
		for(int i=0;i<d;i++) cout<<coor[i]<<" ";
		cout<<")\n";
	}
	/*void cong(Vector &v)
	{
		Vector v2;
		int i;
		if(d!=v.d) cout<<"Khong the cong!";
		else
		{
			v2 .coor = new float[d];
			for(i=0;i<d;i++) v2.coor[i] = coor[i] + v.coor[i];
			cout<<"Toa do v2: (";
			for(i=0;i<d;i++) cout<<v2.coor[i]<<" ";
			cout<<")\n";
			delete []v2.coor;
		}
	}*/
	Vector operator+(const Vector &v)
	{
		Vector v2, v3;
		v2.d = 0;
		v2.coor = NULL;
		if(d!=v.d) 
		{
			cout<<"Khong the cong!\n";
			return *this;
		}
		else
		{
			v3.d = d;
			v3.coor = new float[d];
			for(int i=0;i<d;i++) v3.coor[i] = coor[i] + v.coor[i];
			return v3;
		}
	}
	Vector operator-(const Vector &v)
	{
		Vector v2, v3;
		v2.d = 0;
		v2.coor = NULL;
		if(d!=v.d) 
		{
			cout<<"Khong the tru!\n";
			return *this;
		}
		else
		{
			v3.d = d;
			v3.coor = new float[d];
			for(int i=0;i<d;i++) v3.coor[i] = coor[i] - v.coor[i];
			return v3;
		}
	}
	float operator*(Vector &v)
	{
		float s = 0;
		if(d!=v.d) return 0;
		else
			for(int i=0;i<d;i++) s += coor[i]*v.coor[i];
		return s;
	}
	friend class Matrix;
	~Vector()
	{
		delete []coor;
	}
};

class Matrix
{
	int m, n;
	float *a;
public:
	Matrix()
	{
		m = 1;
		n = 1;
		float x = 0;
		a = &x;
	}
	Matrix(int m0,int n0)
	{
		m = m0;
		n = n0;
		a = new float[m*n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				a[n*i + j] = 1;
	}
	void init()
	{
		cout<<"So hang: ";
		cin>>m;
		cout<<"So cot: ";
		cin>>n;
		a = new float[m*n];
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cout<<"a["<<i<<"]["<<j<<"] = ";
				cin>>a[n*i + j];
			}
	}
	void output()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++) cout<<setw(8)<<fixed<<setprecision(2)<<a[n*i + j]<<" ";
			cout<<endl;
		}
	}
	void vectorxmatrix(Vector &v)
	{
		if(v.d!=n) cout<<"Khong the nhan!\n";
		else
		{
			float *v0 = new float[m];
			for(int i=0;i<m;i++)
			{
				v0[i] = 0;
				for(int j=0;j<n;j++)
					v0[i] += a[n*i + j]*v.coor[j];
			}
			cout<<"Ket qua phep nhan vector va ma tran: (";
			for(int i=0;i<m;i++) cout<<v0[i]<<" ";
			cout<<")\n";
			delete []v0;
		}
	}
	void matrixxmatrix(Matrix m0)
	{
		int i, j, k;
		if(n!=m0.m) cout<<"Khong the nhan!\n";
		else
		{
			float *m1 = new float[m*m0.n];
			for(i=0;i<m;i++)
				for(j=0;j<m0.n;j++)
				{
					m1[m0.n*i + j] = 0;
					for(k=0;k<n;k++)
						m1[m0.n*i + j] += a[n*i + k]*m0.a[m0.n*k + j];
				}
			cout<<"Ma tran ket qua phep nhan m1 x m2:\n";
			for(i=0;i<m;i++)
			{
				for(j=0;j<m0.n;j++) cout<<setw(8)<<fixed<<setprecision(2)<<m1[m0.n*i + j]<<" ";
				cout<<endl;
			}
			delete []m1;
		}
	}
	~Matrix()
	{
		delete []a;
	}
};

int main()
{
	Vector v1, v2(5), v3, v4, v5;
	cout<<"Vector v1:\n";
	v1.init();
	v1.output();
	cout<<" Vector v2:\n";
	v2.init();
	v2.output();
	//v1.cong(v2);
	v3 = v1 + v2;
	cout<<"Vector v3 = v1 + v2:\n";
	v3.output();
	v4 = v1 - v2;
	cout<<"Vector v4 = v1 - v2:\n";
	v4.output();
	float x = v1*v2;
	cout<<"v1*v2 = "<<x<<endl;
	Matrix a1, a2(2,3);
	cout<<"Ma tran so mot:\n";
	a1.init();
	cout<<"Ma tran vua nhap:\n";
	a1.output();
	cout<<"Nhap vector can nhan:\n";
	v5.init();
	a1.vectorxmatrix(v5);
	cout<<"Ma tran so hai:\n";
	a2.init();
	cout<<"Ma tran vua nhap:\n";
	a2.output();
	a1.matrixxmatrix(a2);
}