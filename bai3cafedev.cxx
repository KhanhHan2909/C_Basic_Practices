#ifndef CANDIDATE_H_
#define CANDIDATE_H_
#include<string>
#include<iostream>
using namespace std;
struct DMY{
    int day;
    int month;
    int year;
    void setDMY(int d,int m,int y){
        day=d;
        month=m;
        year=y;
    }
    void Out(){
        cout<<day<<"/"<<month<<"/"<<year;
    }
    void In(){
        cout<<"Input day, month, year:";
        cin>>day>>month>>year;
    }
};
class Candidate
{
private:
    string Name;
    int ID;
    DMY Birth;
    double Math;
    double Liter;
    double Eng;
    bool IsGreaterThanOne;
public:
    string GetterName();
    int GetterID();
    DMY GetterBirth();
    double GetterMath();
    double GetterLiter();
    double GetterEng();
    double ShowAverage();
    bool GetterIsGreaterThanOne();
    void SetterName(string name);
    void SetterID(int id);
    void SetterBirth(DMY birth);
    void SetterMath(double math);
    void SetterLiter(double liter);
    void SetterEng(double eng);
    Candidate();
    Candidate(string name,int Id_Number,DMY day_of_birth,double math,double liter,double eng);
    void Input();
    void Print();
    ~Candidate();
};
#endif

#include<iostream>
#include "Candidate.h"
using namespace std;
Candidate::Candidate(){
    Name="";
    ID=0;
    Birth.setDMY(0,0,0);
    Math=Liter=Eng=0;
    IsGreaterThanOne=(Math+Liter+Eng>1)? true : false;
}
void Candidate::Print(){
    cout<<Name <<" "<<ID<<"--"<<"Birth: ";
    Birth.Out();
    cout<<"--score math-literature-english: "<<Math<<" "<<Liter<<" "<<Eng<<endl;
}
Candidate::Candidate(string name,int Id_Number,DMY day_of_birth,double math,double liter,double eng){
    Name=name;
    ID=Id_Number;
    Birth=day_of_birth;
    Math=math;
    Liter=liter;
    Eng=eng;
    IsGreaterThanOne=(Math+Liter+Eng>1)? true : false;
}
void Candidate::Input(){
    cout<<"Input Name: ";
    cin>>Name;
    cout<<"Input ID number: ";
    cin>>ID;
    cout<<"Birth day, ";
    Birth.In();
    cout<<"Input math score: ";
    cin>>Math;
    cout<<"Input literature score: ";
    cin>>Liter;
    cout<<"Input English score: ";
    cin>>Eng;
    IsGreaterThanOne=(Math+Liter+Eng>1)? true : false;
}
double Candidate::ShowAverage(){
    return (Math+Liter+Eng)/3;
}
Candidate::~Candidate(){
}
string Candidate::GetterName(){
    return Name;
}
int Candidate::GetterID(){
    return ID;
}
DMY Candidate::GetterBirth(){
    return Birth;
}
double Candidate::GetterMath(){
    return Math;
    }
double Candidate::GetterLiter(){
    return Liter;
}
double Candidate::GetterEng(){
    return Eng;
}
bool Candidate::GetterIsGreaterThanOne(){
    return IsGreaterThanOne;
}
 void Candidate::SetterName(string name){
    this->Name=name;
}
void Candidate::SetterID(int id){
    this->ID=id;
}
void Candidate::SetterBirth(DMY birth){
    this->Birth=birth;
}
void Candidate::SetterMath(double math){
    this->Math=math;
}
void Candidate::SetterLiter(double liter){
    this->Liter=liter;
}
void Candidate::SetterEng(double eng){
    this->Eng=eng;
}

#ifndef TESTCANDIDATE_H_
#define TESTCANDIDATE_H_
#include "Candidate.h"
class TestCandidate{
    private:
        int NumberOfStudent;
        Candidate *candidate =new Candidate[NumberOfStudent];
    public:
        int GetterNumberOfStudent();
        Candidate * GetterCandidate();
        void SetterNumberOfStudent(int n);
        TestCandidate();
        ~TestCandidate();
        void SetAllCandidate();
        void ShowCandidateGreaterThanOne();
};
#endif

#include<iostream>
#include"TestCandidate.h"
using namespace std;
    int TestCandidate::GetterNumberOfStudent(){
        return NumberOfStudent;
    }
    Candidate * TestCandidate::GetterCandidate(){
        return candidate;
    }
    void TestCandidate::SetterNumberOfStudent(int n){
        this->NumberOfStudent=n;
    }
    TestCandidate::TestCandidate(){
        this->NumberOfStudent=0;
    }
    TestCandidate::~TestCandidate(){
        delete[] candidate;
    }
    void TestCandidate::SetAllCandidate(){
        for(int i=0;i<GetterNumberOfStudent();i++){
            cout<<"Input infomation student "<<i+1<<": "<<endl;
            candidate[i].Input();
        }
    }
    void TestCandidate::ShowCandidateGreaterThanOne(){
        for(int i=0;i<GetterNumberOfStudent();i++){
            if(candidate[i].GetterIsGreaterThanOne()){
                candidate[i].Print();
            }
        }
    }