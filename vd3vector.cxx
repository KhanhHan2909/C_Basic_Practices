#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int i, j, m, n;
	cout<<"So hang, so cot: ";
	cin>>m>>n;
	vector<vector<int>> v(m,vector<int>(m));
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			cout<<"Pt hang "<<i+1<<" cot "<<j+1<<" : ";
			cin>>v[i][j];
		}
	for(i=0;i<m;i++)
	{
			for(j=0;j<n;j++) cout<<v[i][j]<<" ";
			cout<<endl;
	}
}