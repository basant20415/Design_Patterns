#include<bits/stdc++.h>
using namespace std;

class shape{
public:
virtual shape*clone()=0;
virtual void draw()=0;
virtual ~shape(){}
};

class circle:public shape
{
public:
double radius;
circle(double r):radius(r){}
shape* clone(){
    return new circle(*this);
}
void draw() override{
    cout<<"drawing circle";

}
};

class rectangle:public shape
{
public:
int length,width;
rectangle(int l,int w):length(l),width(w){}
shape* clone(){
    return new rectangle(*this);
}
void draw() override{
    cout<<"drawing rectangle";

}
};


int main(){
circle *c1=new circle(5.0);
shape *s1=c1->clone();

s1->draw();

}