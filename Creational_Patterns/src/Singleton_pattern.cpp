#include<bits/stdc++.h>
using namespace std;

// The Singleton Pattern is a creational design pattern that ensures a class has only one instance throughout the entire program
//  and provides a global point of access to that instance.

class Singleton{
private:

static Singleton* instance;
Singleton(){}

public:

static Singleton* get_instance(){
    if(instance==nullptr){
        instance=new Singleton();
    }
    return instance;
}

void show_message(){
    cout<<"hello from singleton";
}

};

Singleton* Singleton::instance=nullptr;

int main(){
Singleton* s1=Singleton::get_instance();
s1->show_message();


}