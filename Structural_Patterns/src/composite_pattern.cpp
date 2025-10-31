#include<bits/stdc++.h>
using namespace std;

class fileSystem{
public:
virtual void show_details(int indent=0)=0;
virtual ~fileSystem(){}
};


class file:public fileSystem{
private:
string name;
public:
file(string n):name(n){}
void show_details(int indent=0)override{
    cout<<string(indent,' ')<<"- file: "<<name<<endl;
}
};

class folder:public fileSystem{
private:
string name;
vector<fileSystem*>children;
public:
folder(string n) : name(n) {}
void add (fileSystem *item){
    children.push_back(item);
}

void show_details(int indent=0)override{
    cout<<string(indent,' ')<<"+ folder :"<<name<<endl;
    for(auto child:children){
       child->show_details(indent+2);
    }
}

~folder() {
        for (auto child : children) delete child;
    }
};
 
int main(){

folder *root=new folder("root");
file *f1=new file("resume.pdf");
file *f2=new file("cv.pdf");
folder *subfolder=new folder("Documents");
subfolder->add(new file("report"));
subfolder->add(new file("notes"));
root->add (f1);
root->add(f2);
root ->add(subfolder);

root->show_details();



}