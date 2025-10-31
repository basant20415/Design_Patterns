#include<bits/stdc++.h>
using namespace std;

// The Observer Pattern is a behavioral design pattern where:
// 1.One object (Subject) holds the main data.
// 2.Many other objects (Observers) want to be notified whenever that data changes.
// This is called a "one-to-many" relationship.

// Example: Weather Station & Displays
// Let’s say we have a Weather Station that collects temperature, humidity, and pressure.
// We also have Displays that need to show this information whenever it changes.

class Observer{
public:
virtual void update(float temp,float humidity,float pressure)=0;
virtual ~Observer(){}
};

class subject{
public:
virtual void register_observer(Observer *observer)=0;
virtual void detach_observer(Observer *observer)=0;
virtual void notify_observer()=0;
virtual ~subject(){}
};

class weather_station:public subject{
public:
vector<Observer*>observers;
float temperature,humidity,pressure;

void register_observer(Observer * observer)override{
observers.push_back(observer);
}

void detach_observer(Observer * observer)override{
    observers.erase(remove(observers.begin(),observers.end(),observer),observers.end());
}

void notify_observer()override{
for(Observer* obs:observers){
    obs->update(temperature,humidity,pressure);
}
}

void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notify_observer(); // Notify all observers of the new data
    }
};

class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Display: Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa\n";
    }
};


int main(){
weather_station station;

Display display1;
Display display2;

station.register_observer(&display1);
station.register_observer(&display2);

station.setMeasurements(10.0,20.0,30.0);
station.setMeasurements(50.0,60.0,70.0);
}