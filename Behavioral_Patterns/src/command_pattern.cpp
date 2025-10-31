#include<bits/stdc++.h>
using namespace std;

class Electronic_device{
private:
string name;

public:
Electronic_device(string s):name(s){}
void turn_on(){
    cout<< name <<" turning on...";
}

void turn_off(){
    cout<< name<<" turn off...";
}

};

class command{
    public:
virtual void execute()=0;

};

class turn_on_command:public command{
private:
Electronic_device& device; 

public:
turn_on_command(Electronic_device& dev):device(dev){}
void execute(){
    device.turn_on();
}
};

class turn_off_command:public command{
private:
Electronic_device& device; 

public:
turn_off_command(Electronic_device& dev):device(dev){}
void execute(){
    device.turn_off();
}
};

class remote_control{
private:
vector<command*>commands;
public:
void add_command(command *cmd){
commands.push_back(cmd);
}

void press_button(int slot){

    if(slot>=0&&slot<commands.size())
commands[slot]->execute();

}
};

int main(){
Electronic_device TV("TV");
Electronic_device lights("LIGHTs");

turn_on_command turnontv(TV);
turn_off_command turnofftv(TV);

turn_on_command turnonlight(lights);
turn_off_command turnofflight(lights);

remote_control remote;

remote.add_command(&turnontv);
remote.add_command(&turnofftv);
remote.add_command(&turnonlight);
remote.add_command(&turnofflight);

remote.press_button(0);
remote.press_button(1);
remote.press_button(2);
remote.press_button(3);
}