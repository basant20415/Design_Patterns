#include<bits/stdc++.h>
using namespace std;
/*
🧠 2. Real-World Analogy

Imagine you’re visiting a secure building:

You can’t directly talk to the CEO (real object).

You must first talk to the receptionist (proxy), who:

Checks if you have permission.

Decides whether to connect you to the CEO.

So, the proxy controls access to the real subject.

*/
class image{
    public:
    virtual void display()=0;
    virtual ~image(){}
};

// RealSubject (Heavy Object)
class realimage:public image{
private:
string filename;
public:
realimage(string n):filename(n){
    cout<<"loading from disk...";
}
void display()override{
    cout << "Displaying image: " << filename << endl;
}
};


class proxyimage:public image{
private:
string name;
realimage *image;
public:
proxyimage(string n):name(n),image(nullptr){}
void display()override{
if(image==nullptr){
    image=new realimage(name);
}
image->display();
}
~proxyimage(){
delete image;
}



};
int main(){

proxyimage *image =new proxyimage("root");
image->display();

}