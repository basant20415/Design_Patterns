#include<bits/stdc++.h>
using namespace std;

// Suppose you have a legacy printer class that only understands commands in uppercase, 
// and a modern computer class that sends commands in lowercase. 
// You need to make the modern computer work with the legacy printer without modifying the existing printer class.

class legacyPrinter{
public:
void printInUpper(string &commands){
    cout<<"Sending command: "<<commands<<endl;
}
};

class ModernComputer {
public:
    void send_command(const std::string& command) {
        std::cout << "Sending command: " << command << std::endl;
    }
};

class printerAdabter{
private:
legacyPrinter printer;
public:
void send_command(const string &command )
{//since command is const -->we need to copy it in another variable
//for sending "hello" direct without creating string c="hello ,comp.send_command(s)"
string uppercaseCommand = command;
for(auto &c:uppercaseCommand)c=toupper(c);
printer.printInUpper(uppercaseCommand);
}
};

int main(){
ModernComputer comp;
comp.send_command("hello");
printerAdabter print;
print.send_command("hello");
}