#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin,s);
	if(s.size()<26) cout<<"No";
	else
	{
		int mark[256] = {0}, dem = 0, i;
		for(i=0;i<s.size();i++)
			if(s[i]>64&&s[i]<91||s[i]>96&&s[i]<123){
				s[i] = toupper(s[i]);
				mark[s[i]]++;
			}
		for(i=65;i<91;i++) if(mark[i]>0) dem++;
		if(dem==26) cout<<"Yes";
		else cout<<"No"<<" "<<dem;
	}
}