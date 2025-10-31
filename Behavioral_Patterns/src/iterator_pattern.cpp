#include<bits/stdc++.h>
using namespace std;

class iterrator{
public:
virtual bool has_next()=0;
virtual int next()=0;
};

class list_iterator:public iterrator{
private:
vector<int>collections;
size_t index;
public:
list_iterator(vector<int>&coll):collections(coll),index(0){}
bool has_next(){
return index<collections.size();
}

int next(){
return has_next()?collections[index++]:-1;
}
};

class iterable{
    public:
    virtual iterrator* create_iterator()=0;
};

class customList:public iterable{
private:
vector<int>items;
public:
customList(vector<int>data):items(data){}

iterrator* create_iterator(){
    return new list_iterator(items);
}

};

int main(){

customList mylist({1,2,3,4,5});
iterrator* it=mylist.create_iterator();
while(it->has_next()){
    cout<<it->next()<<" ";
}

}