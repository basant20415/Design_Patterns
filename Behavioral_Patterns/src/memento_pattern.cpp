// behavioral design pattern used to save and restore an object’s state — without exposing its internal details.
/*
The Originator creates a Memento (snapshot of its state).

The Caretaker stores this Memento.

When needed, the Caretaker tells the Originator to restore the state from a Memento.
*/

#include<bits/stdc++.h>
using namespace std;
class memento{
private:
string state;
public:

memento(string s):state(s){}

string get_state()const{
    return state;
}
};


class text_editor{

string text;

public:
void type(const string newtext){
    text+=newtext;
}

string get_text()const {
    retur text;
}

memento* save(){
    return new memento(text);
}

void restore(memento *m){
    text=m->get_state();
}
};

class Caretaker{
vectir<memento*>history;
public:
void save (memento *m){
   history.push_back(m);
}

memento *undo()
{
if (history.empty()) return nullptr;
memento* last=history.back();
history.pop_back();
return last;
}

 ~caretaker() {
        for (auto m : history) delete m;
    }
};

int main(){
    texteditor edit;
    caretaker care;

    edit.type("Hello ");
    care.save(edit.save()); // Save state 1

    edit.type("World!");
    care.save(edit.save()); // Save state 2

    cout << "Current text: " << edit.getText() << endl;

    // Undo
    edit.restore(care.undo());
    cout << "After undo: " << edit.getText() << endl;

    // Undo again
    edit.restore(caretaker.undo());
    cout << "After second undo: " << edit.getText() << endl;




}