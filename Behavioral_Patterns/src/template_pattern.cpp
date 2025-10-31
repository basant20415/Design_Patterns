#include<bits/stdc++.h>
using namespace std;

class vehicleTemplate{
public:
void buildVehicle(){
    assembleBody();
    installEngine();
    addWheels();
    cout<<"vehicle is ready.";
}

virtual void assembleBody()=0;
virtual void installEngine()=0;
virtual void addWheels()=0;
};

class Car : public vehicleTemplate {
public:
    void assembleBody() override {
        std::cout << "Assembling car body.\n";
    }

    void installEngine() override {
        std::cout << "Installing car engine.\n";
    }

    void addWheels() override {
        std::cout << "Adding 4 wheels to the car.\n";
    }
};

class Motorcycle : public vehicleTemplate {
public:
    void assembleBody() override {
        std::cout << "Assembling motorcycle frame.\n";
    }

    void installEngine() override {
        std::cout << "Installing motorcycle engine.\n";
    }

    void addWheels() override {
        std::cout << "Adding 2 wheels to the motorcycle.\n";
    }
};
int main(){

Car car;
car.buildVehicle();

}