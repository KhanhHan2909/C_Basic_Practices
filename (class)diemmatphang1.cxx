#ifndef COORDINATE_H_
#define COORDINATE_H_
#include<iostream>

using namespace std;

class Coordinate
{
private:
    int x; // abscissa 
    int y; // ordinate
public:
    Coordinate();
    Coordinate(int a,int b);
    int GetterX();
    int GetterY();
    void SetterX(int a);
    void SetterY(int b);
    void MoveCoordinate(int a,int b);
    //void DrawingCoordinate() -> library is not supported
    friend ostream & operator<<(ostream & os,Coordinate & Coor);
    friend istream & operator>>(istream & is,Coordinate & Coor);
    ~Coordinate();
};

Coordinate::Coordinate(){
    SetterX(1);
    SetterY(0);
}
Coordinate::Coordinate(int a,int b){
    SetterX(a);
    SetterY(b);
}
int Coordinate::GetterX(){
    return x;
}
int Coordinate::GetterY(){
    return y;
}
void Coordinate::SetterX(int a){
    x=a;
}
void Coordinate::SetterY(int b){
    y=b;
}
void Coordinate::MoveCoordinate(int a,int b){
    SetterX(GetterX()+a);
    SetterY(GetterY()+b);
}
//void DrawingCoordinate() -> library is not supported
ostream & operator<<(ostream & os,Coordinate & Coor){
    os<<"( "<<Coor.GetterX()<<" , "<<Coor.GetterY()<<" )";
    return os;
}
istream & operator>>(istream & is,Coordinate & Coor){
    is>>Coor.x>>Coor.y;
    return is;
}
Coordinate::~Coordinate(){
}

int main(){
    Coordinate Coor1[10]; //call default constuctor
    Coordinate Coor2(2,3); //Call constructor
    for(int i=0;i<10;i++)
    	cout<<"Show coordinate 1: "<<Coor1[i]<<endl;
    cout<<"Show coordinate 2:"<<Coor2<<endl;
  //  cout<<"Set value to coordinate 1 :";
   // cin>>Coor1;
    cout<<"Move coordinate 2 (-5,7): "<<endl;
    Coor2.MoveCoordinate(-5,7);
//    cout<<"Show coordinate 1: "<<Coor1<<endl;
    cout<<"Show coordinate 2:"<<Coor2<<endl;
    return 0;
}
#endif