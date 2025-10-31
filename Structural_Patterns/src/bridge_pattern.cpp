#include <bits/stdc++.h>
using namespace std;

// Abstraction interface
class device {
public:
    virtual void turn_on() = 0;
    virtual void turn_off() = 0;
    virtual ~device() {}
};

// Concrete Implementor 1
class tv : public device {
public:
    void turn_on() override {
        cout << "TV is turned on.\n";
    }
    void turn_off() override {
        cout << "TV is turned off.\n";
    }
};

// Concrete Implementor 2
class radio : public device {
public:
    void turn_on() override {
        cout << "Radio is turned on.\n";
    }
    void turn_off() override {
        cout << "Radio is turned off.\n";
    }
};

// Abstraction (Bridge)
class remote_control {
protected:
    device* dev;  // reference to Implementor
public:
    remote_control(device* d) : dev(d) {}
    virtual void press_on() {
        dev->turn_on();
    }
    virtual void press_off() {
        dev->turn_off();
    }
    virtual ~remote_control() {}
};

// Refined Abstraction
class advanced_remote : public remote_control {
public:
    advanced_remote(device* d) : remote_control(d) {}
    void mute() {
        cout << "Device muted!\n";
    }
};

// Client code
int main() {
    device* tvDevice = new tv();
    device* radioDevice = new radio();

    remote_control* remote1 = new remote_control(tvDevice);
    remote1->press_on();
    remote1->press_off();

    cout << "----\n";

    advanced_remote* remote2 = new advanced_remote(radioDevice);
    remote2->press_on();
    remote2->mute();
    remote2->press_off();

    delete tvDevice;
    delete radioDevice;
    delete remote1;
    delete remote2;
}
