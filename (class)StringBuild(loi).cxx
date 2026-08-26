#include<iostream>

using namespace std;

class String
{
	char *s;
public:
	String()
	{
		s = new char[1];
		s[0] = '#';
	}
	void input(int length)
	{
		s = new char[length];
		cin>>s;
	}
	int strlen()
	{
		int i = 0;
		while(s[i]!='\0') i++;
		return i;
	}
	void ReverseString(){
		int Len = ::strlen(s);
	    char * TempStr=new char[Len+1];
	    int j=0;
	    for(int i=Len-1;i>=0;i--){
	        TempStr[j++]=this->s[i];
	    }
	    delete [] s;
	    this->s=TempStr;
	    cout<<s;
	}
	friend void strcat(String str1,String str2);
	friend void strrev(String str);
	friend ostream& operator<<(ostream &os,String &str);
	~String()
	{
		delete []s;
	}
};

void strcat(String str1,String str2)
{
	int i, l1 = str1.strlen(), l2 = str2.strlen();
	String str3;
	str3.s = new char[l1+l2];
	for(i=0;i<l1;i++) str3.s[i] = str1.s[i];
	for(i=l1;i<l1+l2;i++) str3.s[i] = str2.s[i-l1];
	cout<<str3<<endl;
}
void strrev(String str)
{
	int i, l = str.strlen();
	String str0;
	str0.s = new char[l+1];
	for(i=0;i<l;i++) str0.s[i] = str.s[l-1-i];
	cout<<str0<<endl;
}
ostream& operator<<(ostream &os,String &str)
{
	os<<str.s;
	return os;
}
int main()
{
	String str1, str2, str3, str4;
	int l1, l2;
	cout<<"Nhap do dai toi da xau 1: ";
	cin>>l1;
	cout<<"Nhap xau 1: ";
	str1.input(l1);
	cout<<"Xau 1: "<<str1<<endl;
	cout<<"Nhap do dai toi da xau 2: ";
	cin>>l2;
	cout<<"Nhap xau 2: ";
	str2.input(l2);
	cout<<"Xau 2: "<<str2<<endl;
	cout<<"Ket qua noi xau 2 vao xau 1: ";
	strcat(str1,str2);
	cout<<"Xau dao nguoc cua xau 1: ";
	//strrev(str1);
	str1.ReverseString();
}