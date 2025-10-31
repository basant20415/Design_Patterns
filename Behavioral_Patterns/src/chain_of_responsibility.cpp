// Chain of responsibility Pattern or Chain of Responsibility Method is a behavioral pattern, 
// which allows an object to send a request to other objects without knowing who is going to handle it. 
// This pattern is frequently used in the chain of multiple objects, 
// where each object either handles the request or passes it on to the next object in the chain if it is unable to handle that request. 
// This pattern encourages loose coupling between sender and receiver, 
// providing freedom in how the request is handled.

// Suppose we have to handle authentication requests with a chain of handlers. 
// Depending on the type of authentication request, the appropriate handler in the chain handles it, 
// or it is passed along the chain until a handler can process it or until the end of the chain is reached.

#include<bits/stdc++.h>
using namespace std;

class authentication_handler{
public:
virtual void set_next_handler(authentication_handler *handler)=0;
virtual void handle_request(string request)=0;
};


class usernamepasswordhandler:public authentication_handler{
private:
authentication_handler *next_handler;
public:

void set_next_handler(authentication_handler *handler)override{
    next_handler=handler;
}

void handle_request(string request)override{
if(request=="user_password"){
    cout<<"user_password handling...";
}else if(next_handler!=nullptr){
next_handler->handle_request(request);
}else{
    cout<<"invalid request";
}
}

};


class Oauthhandler:public authentication_handler{
private:
authentication_handler *next_handler;
public:
void set_next_handler(authentication_handler *handler)override{
    next_handler=handler;
}

void handle_request(string request)override{
if(request=="Oauth"){
    cout<<"Oauth handling...";
}else if(next_handler!=nullptr){
next_handler->handle_request(request);
}else{
    cout<<"invalid request";
}
}

};
int main(){
authentication_handler* ushandler=new usernamepasswordhandler();
authentication_handler* oauthhand2=new Oauthhandler();

ushandler->set_next_handler(oauthhand2);
ushandler->handle_request("user_password");
ushandler->handle_request("Oauth");
ushandler->handle_request("invalid request");

}