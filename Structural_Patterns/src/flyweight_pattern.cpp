//  flyweight design pattern can be applied to reduce the load on memory by sharing objects. 
/*
The program simulates a forest made up of many trees.
Instead of storing duplicate data for every tree (like type, color, texture),
we share that data among all trees of the same type.

👉 So instead of 1,000 trees each having its own "Oak, Green, Rough" data,
we only keep one shared object for "Oak, Green, Rough".The program simulates a forest made up of many trees.
Instead of storing duplicate data for every tree (like type, color, texture),
we share that data among all trees of the same type.

👉 So instead of 1,000 trees each having its own "Oak, Green, Rough" data,
we only keep one shared object for "Oak, Green, Rough".

*/

// Represents the shared part of a tree — these don’t change per tree.
#include<bits/stdc++.h>
using namespace std;
class treetype{
string name;
string color;
string texture;
public:
treetype(string n,string c,string t):name(n),color(c),texture(t){}
void display(int x, int y) {
        cout << "Drawing tree [" << name << ", " << color << ", " << texture 
             << "] at (" << x << ", " << y << ")\n";
    }
};
/*
Keeps a map (cache) of all created tree types.

Ensures that each type of tree ("Oak_Green_Rough")
is created only once and then reused.
*/
class treeFactory{
static unordered_map<string,treetype*>treetypes;
public:

static treetype* get_treetype(string name,string color,string texture){
    string key=name+"_"+color+"_"+texture;
    if(treetypes.find(key)==treetypes.end()){
        cout << "Creating new TreeType: " << key << endl;
        treetypes[key] = new treetype(name, color, texture);
    }
     return treetypes[key];
}

static void cleanup(){
    for(auto &t:treetypes){
        delete t.second;
    }
    treetypes.clear();
}
};

/*
Stores unique/extrinsic data → x, y position.

Holds a pointer to a shared TreeType object → type.
*/
class tree{
private:
int x,y;
treetype *type;
public:
tree(int x, int y, treetype* t) : x(x), y(y), type(t) {}
void draw(){
    type->display(x,y);
}
};

unordered_map <string,treetype*>treeFactory::treetypes;
/*
Manages all the trees in the forest.

When you call plantTree(), it:

Asks TreeFactory for the right TreeType.

Creates a Tree at (x, y) with that type.

When you call draw(), it loops through all trees and displays them.
*/
class forest{
vector<tree*>trees;
public:
void plant_tree(int x,int y, string name,string color,string texture){
    treetype* type=treeFactory::get_treetype(name,color,texture);
    trees.push_back(new tree(x,y,type));
}

void draw() {
        for (auto t : trees)
            t->draw();
    }

 ~forest() {
        for (auto t : trees)
            delete t;
        treeFactory::cleanup();
    }

};

int main(){

    forest fore;

    fore.plant_tree(1, 2, "Oak", "Green", "Rough");
    fore.plant_tree(3, 5, "Oak", "Green", "Rough");
    fore.plant_tree(7, 9, "Pine", "Dark Green", "Smooth");

    cout << "\nDrawing forest:\n";
    fore.draw();
}