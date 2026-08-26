#include<iostream>
#include<utility>

using namespace std;

void dsmd(int a,int b = 1)
{
	cout<<a<<" "<<b<<endl;
}

/*Error khai bao: void dsmd2(int a,int b = 1,int c)
{
	}
	Vi sau dsmd deu phai la dsmd*/
int main()
{
	int a = 2, c = 3;
	dsmd(a);
	dsmd(a,c);
}