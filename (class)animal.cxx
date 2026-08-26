#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class animal
{
protected:
	int babies, quantity;
	float milk;
public:
	animal()
	{
		quantity = 1;
		babies = 0;
		milk = 1;
	}
	void input()
	{
		cout<<"Nhap so luong ca the: ";
		cin>>quantity;
		/*cout<<"Nhap so con moi sinh: ";
		cin>>babies;
		cout<<"Nhap so lit sua: ";
		cin>>milk;*/
	}
	void output()
	{
		babies = (rand()%100)*quantity;
		cout<<"So luong ca the: "<<quantity<<endl;
		cout<<"So luong con moi sinh: "<<babies<<endl;
	}
	~animal() {}
};

class cow: public animal
{
public:
	float cowmilk()
	{
		milk = (rand()%20+1)*quantity;
		return milk;
	}
};

class sheep: public animal
{
public:
	float sheepmilk()
	{
		milk = (rand()%5+1)*quantity;
		return milk;
	}
};

class goat: public animal
{
public:
	float goatmilk()
	{
		milk = (rand()%10+1)*quantity;
		return milk;
	}
};
		
int main()
{
	srand(time(0));
	cow c1;
	sheep s1;
	goat g1;
	cout<<"Thong ke dan bo:\n";
	c1.input();
	c1.output();
	float cm = c1.cowmilk();
	cout<<"So lit sua: "<<cm<<endl;
	cout<<"Thong ke dan cuu:\n";
	s1.input();
	s1.output();
	float sm = s1.sheepmilk();
	cout<<"So lit sua: "<<sm<<endl;
	cout<<"Thong ke dan de:\n";
	g1.input();
	g1.output();
	float gm = g1.goatmilk();
	cout<<"So lit sua: "<<gm<<endl;
	cout<<"\nTong so lit sua gia suc la "<<cm+sm+gm;
}