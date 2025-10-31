#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class AirTrafficControlTower;

// Abstract Colleague
class Airplane {
public:
    virtual void requestTakeoff() = 0;
    virtual void requestLanding() = 0;
    virtual void notifyAirTrafficControl(const string& message) = 0;
    virtual ~Airplane() = default;
};

// Mediator interface
class AirTrafficControlTower {
public:
    virtual void requestTakeoff(Airplane* airplane) = 0;
    virtual void requestLanding(Airplane* airplane) = 0;
    virtual ~AirTrafficControlTower() = default;
};

// Concrete Colleague
class CommercialAirplane : public Airplane {
private:
    AirTrafficControlTower* mediator;
public:
    CommercialAirplane(AirTrafficControlTower* m) : mediator(m) {}

    void requestTakeoff() override {
        mediator->requestTakeoff(this);
    }

    void requestLanding() override {
        mediator->requestLanding(this);
    }

    void notifyAirTrafficControl(const string& message) override {
        cout << "Commercial Airplane: " << message << endl;
    }
};

// Concrete Mediator
class AirportControlTower : public AirTrafficControlTower {
public:
    void requestTakeoff(Airplane* airplane) override {
        airplane->notifyAirTrafficControl("Requesting takeoff clearance.");
    }

    void requestLanding(Airplane* airplane) override {
        airplane->notifyAirTrafficControl("Requesting landing clearance.");
    }
};

// Client
int main() {
    // Instantiate the Mediator (Airport Control Tower)
    AirTrafficControlTower* controlTower = new AirportControlTower();

    // Instantiate Concrete Colleagues (Commercial Airplanes)
    Airplane* airplane1 = new CommercialAirplane(controlTower);
    Airplane* airplane2 = new CommercialAirplane(controlTower);

    // Interactions via Mediator
    airplane1->requestTakeoff();
    airplane2->requestLanding();

    // Expected Output:
    // Commercial Airplane: Requesting takeoff clearance.
    // Commercial Airplane: Requesting landing clearance.

    delete controlTower;
    delete airplane1;
    delete airplane2;
    return 0;
}
