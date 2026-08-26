#include<stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
	int x = 1, *p = &x;
	cout << *p << "\n";
	*p = 2;
	cout << x;
}