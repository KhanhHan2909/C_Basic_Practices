#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	float d;
	cout << "Nhap toa do A: ";
	cin >> x1 >> y1;
	cout << "Nhap toa do B: ";
	cin >> x2 >> y2;
	d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	cout << fixed << setprecision(2) << d;
}