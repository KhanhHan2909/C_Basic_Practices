#include<iostream>

using namespace std;
int main()
{
	int a = 20000000;
	short b;
	b = a; //implicit
	//b = (short)a; //explicit
	cout<<b;
}