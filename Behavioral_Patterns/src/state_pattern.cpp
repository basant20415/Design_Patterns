// In software design, managing the behavior of an object according to its internal state is a common issue. 
// The state pattern addresses this issue by allowing an object to alter its behavior every time its internal state changes.

// This pattern encapsulates each state in a separate class, which makes it easier to add new states and modify existing states without altering the object's code directly. 
// This pattern is useful when an object transitions between different states, with each transition triggering specific actions.

#include<bits/stdc++.h>
using namespace std;

class trafficLightState{
public:
virtual void handle()=0;
};

class red_state:public trafficLightState{
public:
void handle(){
    cout<<"traffic light is red";
}
};

class yellow_state:public trafficLightState{
public:
void handle(){
    cout<<"traffic light is yellow";
}
};

class green_state:public trafficLightState{
public:
void handle(){
    cout<<"traffic light is green";
}
};

class trafficLight{
private:
trafficLightState* state;
public:

trafficLight():state(new red_state()){}

void set_state(trafficLightState* newState)
{
    delete state;
    state=newState;
}

void change(){
state->handle();
}
};
int main(){
trafficLight lights;
lights.change();
lights.set_state(new green_state());
lights.change();


}