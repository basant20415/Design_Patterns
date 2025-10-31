#include<bits/stdc++.h>
using namespace std;

// The Factory Method Pattern is a creational design pattern that lets a class delegate the responsibility of creating objects to its subclasses.
// Instead of creating objects directly using new, you define a method (called a factory method) to create objects.
// This gives you flexibility and reduces tight coupling between code that uses the object and the code that creates it.

// abstract product_shape
class shape{
public:
virtual void draw()=0;
virtual ~shape(){}
};



// concrete product

class circle:public shape{
public:
void draw()override{
    cout<<"drawing circle";
}
};

class square:public shape{
public:
void draw()override{
    cout<<"drawing square";
}
};


// abstract creator_shape factory

class shape_factory{
public:
virtual shape* create_shape()=0;
~shape_factory(){}
};

// concrete_creator (circle factory and square factor)


// concrete_creator_circle creator ,square creator

class circle_factory:public shape_factory{

shape* create_shape(){
    return new circle();
}
};

class square_factory:public shape_factory{
shape* create_shape(){
    return new square();
}
};

int main(){
shape_factory *factory=new circle_factory();
shape * shape1=factory->create_shape();
shape1->draw();
delete shape1;
delete factory;


}