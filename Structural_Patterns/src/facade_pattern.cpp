// Imagine you have a complex software system with numerous components, 
// each having its own set of methods and interactions. 
// Without the Facade Pattern, clients would need to interact with these components directly,
//  which could lead to a tangled mess of dependencies and make the system difficult to understand and maintain.
#include<bits/stdc++.h>
using namespace std;

class engine{
public:
void start(){

    cout<<"engine started";
}

void stop(){
    cout<<"engine stopped";
}

};

class lights{
public:
void turnOn(){
    cout<<"lights turned on";
}

void turnOff(){
    cout<<"lights turned off";
}

};

class car{
private:
engine eng;
lights ligh;

public:
void start_car(){
    eng.start();
    ligh.turnOn();
    cout<<"car started";
}

void stopCar(){
    eng.stop();
    ligh.turnOff();
    cout<<"car stopped";
}


};
int main(){

car c;
c.start_car();

c.stopCar();
}