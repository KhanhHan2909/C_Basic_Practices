#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	float s1, s2, s3, a, b, c;
	cout<<"Dien tich s1: ";
	cin>>s1;
	cout<<"Dien tich s2: ";
	cin>>s2;
	cout<<"Dien tich s3: ";
	cin>>s3;
	a = sqrt(s1*s3/s2);
	b = sqrt(s1*s2/s3);
	c = sqrt(s2*s3/s1);
	cout<<"Chu vi hinh hop: "<<(a+b+c)*4;
}