#include<bits/stdc++.h>
using namespace std;

class expression{
public:
virtual void interpret()=0;
virtual ~expression(){}
};

class helloexpression:public expression{
public:
void interpret()override{

cout<<"you said hello";
}

};

class byeexpression:public expression{
public:
void interpret()override{
    cout<<"you said bye";
}
};

class interpretercontext{
public:

void interpret_command(string command){
    unique_ptr<expression>expr;
    if(command=="hello")
    expr=make_unique<helloexpression>();
    else if(command=="bye")expr=make_unique<byeexpression>();
    else cout<<"unkown command";
    if(expr)expr->interpret();
}

};

int main(){

interpretercontext context;
context.interpret_command("hello");
context.interpret_command("bye");
context.interpret_command("hi");

}