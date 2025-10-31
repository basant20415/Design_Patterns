#include<bits/stdc++.h>
using namespace std;
// The Decorator Pattern is a structural design pattern in software engineering that enables the dynamic addition of new behaviors or responsibilities to individual objects without altering their underlying class structure.
// It achieves this by creating a set of decorator classes that are used to wrap concrete components, which represent the core functionality.

class IceCream{
public:
virtual string get_describtion() const =0;
virtual double cost() const=0;
};

class VanillaIcecream:public IceCream{
public:
string get_describtion() const{
   return "vanilla ice cream...";
}
   
double cost() const{
    return 101.6;
}
};

class IceCreamDecorator: public IceCream{
protected:
    IceCream *icecream;
public:
IceCreamDecorator(IceCream *ic):icecream(ic){}
string get_describtion() const{
    return icecream->get_describtion();
}

double cost()const{
    return icecream->cost();
}

};

class chocolateDecorator:public IceCreamDecorator{

public:

chocolateDecorator( IceCream *ic):IceCreamDecorator(ic){}

string get_describtion()const{
    return icecream->get_describtion()+" with chocolate";
}

double cost() const{
    return icecream->cost()+100;
}
};
int main(){
IceCream *ice=new VanillaIcecream ();

cout<<ice->get_describtion()<<" "<<ice->cost();
chocolateDecorator ch(ice);
cout<<ch.get_describtion()<<" "<<ch.cost();

}