#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<vector>
#include<fstream>

using namespace std;

void paragraph_out(string s)
{
	fstream prg;
	prg.open("paragraph.txt",ios::out);
	prg<<s;
	prg.close();
}

void paragraph_in()
{
	ifstream prg;
	prg.open("paragraph.txt");
	string data;
	while(!prg.eof())
	{
		prg>>data;
		cout<<data<<" ";
	}
	prg.close();
}

int sentence_count()
{
	ifstream prg;
	prg.open("paragraph.txt");
	string data;
	int count = 0;
	while(!prg.eof())
	{
		prg>>data;
		for(int i=0;i<data.size();i++)
			if(data[i]=='.'||data[i]=='!'||data[i]=='?')
			{
				count++;
				break;
			}
	}
	prg.close();
	return count;
}

void word_count()
{
	ifstream prg;
	fstream prg2;
	prg.open("paragraph.txt");
	prg2.open("processedparagraph.txt",ios::app);
	string data;
	int count1 = 0, count2 = 0;
	while(!prg.eof())
	{
		prg>>data;
		count1++;
		for(int i=0;i<data.size();i++)
			if(data[i]=='.'||data[i]=='!'||data[i]=='?')
			{
				count2++;
				cout<<endl<<"So tu trong cau thu "<<count2<<" la "<<count1;
				prg2<<endl<<"So tu trong cau thu "<<count2<<" la "<<count1;
				count1 = 0;
				break;
			}
	}
	prg.close();
	prg2.close();
}

void mostappearword()
{
	ifstream prg;
	fstream prg2;
	prg.open("paragraph.txt");
	prg2.open("processedparagraph.txt",ios::app);
	string data;
	vector<string> v1, v2;
	while(!prg.eof())
	{
		prg>>data;
		v1.push_back(data);
	}
	int i, j, k;
	for(i=0;i<v1.size();i++)
	{
		for(j=v1[i].size()-1;j>=0;j--)
			if(v1[i][j]=='.'||v1[i][j]==','||v1[i][j]=='!'||v1[i][j]=='?'||v1[i][j]==';') v1[i].pop_back();
		v1[i][0] = tolower(v1[i][0]);
	}
	for(i=0;i<v1.size();i++) v2.push_back(v1[i]);
	for(i=0;i<v2.size()-1;i++)
		for(j=i+1;j<v2.size();j++)
			if(v2[i]==v2[j])
			{
				for(k=j;k<v2.size()-1;k++)
					v2[k] = v2[k+1];
				v2.pop_back();
			}
	vector<int> v3(v2.size(),0);
	for(i=0;i<v2.size();i++)
		for(j=0;j<v1.size();j++)
			if(v2[i]==v1[j]) v3[i]++;
	int max = v3[0];
	for(i=1;i<v3.size();i++)
		if(v3[i]>max) max = v3[i];
	cout<<endl<<"Tu xuat hien nhieu nhat la "<<max<<" lan, (cac) tu xuat hien nhieu nhat: ";
	for(i=0;i<v3.size();i++)
		if(v3[i]==max) cout<<v2[i]<<" ";
	prg2<<endl<<"Tu xuat hien nhieu nhat la "<<max<<" lan, (cac) tu xuat hien nhieu nhat: ";
	for(i=0;i<v3.size();i++)
		if(v3[i]==max) prg2<<v2[i]<<" ";
		prg2<<endl;
	prg.close();
	prg2.close();
}

void alphabetsort()
{
	ifstream prg;
	fstream prg2;
	prg.open("paragraph.txt");
	prg2.open("processedparagraph.txt",ios::app);
	string data, temp, s;
	vector<string> word, sentence;
	while(!prg.eof())
	{
		prg>>data;
		word.push_back(data);
	}
	int i, j, k, dem = -1;
	char c;
	for(i=0;i<word.size();i++)
	{
		c = word[i][word[i].size()-1];
		if(c=='.'||c=='?'||c=='!')
		{
			for(j=dem+1;j<=i;j++) 
			{
				temp += word[j];
				temp.push_back(32);
			}
			temp.pop_back();
			sentence.push_back(temp);
			temp = '\0';
			dem = i;
		}
	}
	int lst[sentence.size()]; //longest sentence
	for(i=0;i<sentence.size();i++)
	{
		lst[i] = 0;
		stringstream ss(sentence[i]);
		while(ss>>s) lst[i]++;
	}
	int max = lst[0];
	for(i=1;i<sentence.size();i++) if(lst[i]>max) max = lst[i];
	int arrsize = sentence.size()*max;
	vector<string> sw(arrsize);
	for(i=0;i<sentence.size();i++)
	{
		j = 0;
		stringstream ss(sentence[i]);
		while(ss>>s)
		{
			sw[max*i+j] = s;
			j++;	
		}
	}
	for(i=0;i<sentence.size();i++)
		for(j=0;j<lst[i]-1;j++)
			for(k=lst[i]-1;k>j;k--)
				if(sw[max*i+k-1].compare(sw[max*i+k])>0)
				{
					temp = sw[max*i+k-1];
					sw[max*i+k-1] = sw[max*i+k];
					sw[max*i+k] = temp;
				}
	cout<<endl;
	for(i=0;i<sentence.size();i++)
		for(j=0;j<lst[i];j++)
			cout<<sw[max*i+j]<<" ";
	prg2<<"Doan van sau khi sap xep: "<<endl;
	for(i=0;i<sentence.size();i++)
	{
		for(j=0;j<lst[i];j++) prg2<<sw[max*i+j]<<" ";
		prg2<<endl;
	}
	prg.close();
	prg2.close();
}

int main()
{
	ofstream prg;
	string s = "Hello! My name is Han. Han is my name. Han's my name. I am 33 years old. I live in Hanoi, Vietnam. What's about you?";
	prg.open("processedparagraph.txt");
	prg<<"Doan van goc: "<<s<<endl;
	paragraph_out(s);
	cout<<"Doan van vua ghi ra file:\n";
	paragraph_in();
	cout<<endl<<"So cau trong doan la "<<sentence_count();
	prg<<"So luong cau: "<<sentence_count();
	prg.close();
	word_count();
	mostappearword();
	alphabetsort();
}