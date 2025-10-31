#include<bits/stdc++.h>
using namespace std;

// Abstract Factory Pattern is a creational design pattern used in object-oriented programming. 
// It provides an interface for creating families of related or dependent objects without specifying their concrete classes. 
// This pattern is a way to encapsulate the creation of objects and ensure that they are compatible and properly configured

// Abstract Product Interface
class pizza{
public:
virtual void bake()=0;
virtual void box()=0;
~pizza(){}
};

// Concrete New York Cheese Pizza
class newyorkcheesepizza:public pizza{
public:
void bake(){
    cout<<"baking new_york cheese  pizza";
}

void box(){
    cout<<"boxing new_york cheese  pizza";
}

};

// Concrete Chicago Cheese Pizza
class chicagocheesepizza:public pizza{
public:
void bake(){
    cout<<"baking chicago cheese  pizza";
}

void box(){
    cout<<"boxing chicago cheese  pizza";
}

};

// Concrete New York Pepperoni Pizza
class newyorkpeperonipizza:public pizza{
     public:
void bake(){
    cout<<"baking new_york peperoni  pizza";
}

void box(){
    cout<<"boxing new_york peperoni  pizza";
}
};

// Concrete Chicago Pepperoni Pizza
class chicagopeperonipizza:public pizza{
     public:
void bake(){
    cout<<"baking chicago peperoni  pizza";
}

void box(){
    cout<<"boxing chicago peperoni  pizza";
}

};

// Abstract Factory Interface
class pizzafactory{
 public:
 virtual pizza* create_cheese_pizza()=0;
  virtual pizza* create_peperoni_pizza()=0;
 ~pizzafactory(){}
};

// Concrete newyork Pizza Factory
class newyorkpizzafactory:public pizzafactory{
public:
pizza* create_cheese_pizza(){
    return new newyorkcheesepizza();
}

pizza* create_peperoni_pizza(){
    return new newyorkpeperonipizza();
}

};

// Concrete Chicago Pizza Factory
class chicagopizzafactory:public pizzafactory{
public:
pizza* create_cheese_pizza(){
    return new chicagocheesepizza();
}

pizza* create_peperoni_pizza(){
    return new chicagopeperonipizza();
}

};

int main(){
pizzafactory * factory=new newyorkpizzafactory();
pizza* new_pizza=factory->create_cheese_pizza();
new_pizza->bake();
new_pizza->box();


}