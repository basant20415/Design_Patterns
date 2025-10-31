# 🎯 Design Patterns in C++ – Complete Guide

A practical and detailed overview of the most important Design Patterns in software engineering, explained through analogies, real-world use cases, C++ examples, and diagrams (conceptually).

## 🧩 What Are Design Patterns?

Design Patterns are proven, reusable solutions to common problems in software design.
They are blueprints for how to structure your code, not rigid frameworks.

Why Use Design Patterns?

✅ Improve code reusability and readability

✅ Simplify maintenance and testing

✅ Encourage scalable and flexible design

✅ Provide a shared vocabulary for developers

## ⚙️ Types of Design Patterns

![alt text](image.png)

## 🏗️ Creational Patterns
### 1. Singleton Pattern

Purpose: Ensure that only one instance of a class exists globally.

Analogy:
A printer spooler — all print jobs go through a single manager.

C++ Example:

```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

```
Pros:

Saves memory (only one instance)

Centralized access to shared resource

Cons:

Harder to test (global state)

May hide dependencies

Use When:

Logging, configuration managers, hardware interfaces

### 2. Factory Method Pattern

Purpose: Define an interface for creating an object but allow subclasses to decide which class to instantiate.

Analogy:
A pizza restaurant where each branch decides what type of pizza to serve.

C++ Example:

```cpp
class Product {
public:
    virtual void show() = 0;
};

class ConcreteProductA : public Product {
public:
    void show() override { cout << "Product A\n"; }
};

class Factory {
public:
    virtual Product* createProduct() = 0;
};

class FactoryA : public Factory {
public:
    Product* createProduct() override { return new ConcreteProductA(); }
};


Use When:

The creation logic must vary depending on the subclass.

### 3. Builder Pattern

Purpose: Construct complex objects step-by-step.

Analogy:
Building a house — first walls, then roof, then finishing touches.

C++ Example:

class House {
public:
    string walls, roof;
    void show() { cout << "Walls: " << walls << ", Roof: " << roof << endl; }
};

class Builder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual House* getHouse() = 0;
};

class WoodenHouseBuilder : public Builder {
    House* house = new House();
public:
    void buildWalls() override { house->walls = "Wood"; }
    void buildRoof() override { house->roof = "Wooden Roof"; }
    House* getHouse() override { return house; }
};


Use When:

Constructing objects with many optional parts (e.g., report generators, UI builders).

### 4. Prototype Pattern

Purpose: Clone existing objects instead of creating from scratch.

Analogy:
Duplicating a document rather than writing it again.

C++ Example:

class Shape {
public:
    virtual Shape* clone() = 0;
};

class Circle : public Shape {
public:
    Circle* clone() override { return new Circle(*this); }
};


Use When:

Object creation is costly or complex.

You need to create duplicates dynamically.

### 5. Abstract Factory Pattern

Purpose: Create families of related objects without specifying their concrete classes.

Analogy:
A furniture factory producing either Victorian or Modern chairs and tables.

Use When:

You need to ensure product families are compatible (e.g., UI themes or cross-platform widgets).

## 🧱 Structural Patterns
### 6. Adapter Pattern

Purpose: Make incompatible interfaces work together.

Analogy:
A travel adapter connects a European plug to a US socket.

C++ Example:

class OldPrinter { public: void printOld() { cout << "Old printer\n"; } };
class Printer { public: virtual void print() = 0; };

class Adapter : public Printer {
    OldPrinter* old;
public:
    Adapter(OldPrinter* o): old(o) {}
    void print() override { old->printOld(); }
};


Use When:

Integrating legacy code with modern systems.

### 7. Bridge Pattern

Purpose: Separate abstraction from implementation.

Analogy:
A remote control works for different devices (TV, Radio).

C++ Example:

class Device { public: virtual void turnOn()=0; };
class TV : public Device { public: void turnOn(){ cout<<"TV on\n"; } };

class Remote {
protected:
    Device* device;
public:
    Remote(Device* d): device(d) {}
    void pressOn() { device->turnOn(); }
};


Use When:

You have multiple abstractions and implementations that should vary independently.

### 8. Composite Pattern

Purpose: Treat individual objects and compositions uniformly.

Analogy:
A folder can contain files and other folders.

C++ Example:

class FileSystemItem {
public:
    virtual void showDetails() = 0;
};

class File : public FileSystemItem {
    string name;
public:
    File(string n): name(n) {}
    void showDetails() { cout << "File: " << name << endl; }
};

class Folder : public FileSystemItem {
    string name;
    vector<FileSystemItem*> children;
public:
    Folder(string n): name(n) {}
    void add(FileSystemItem* item){ children.push_back(item); }
    void showDetails(){
        cout << "Folder: " << name << endl;
        for(auto c: children) c->showDetails();
    }
};


Use When:

You want to represent tree-like hierarchies.

### 9. Decorator Pattern

Purpose: Add new behavior dynamically without altering the class.

Analogy:
Adding toppings to an ice cream 🍦 — base flavor remains, toppings add extra features.

Use When:

You need flexible extensions (e.g., I/O streams, UI components).

### 10. Proxy Pattern

Purpose: Control access to another object (lazy loading, logging, or access control).

Analogy:
A receptionist controls who can meet the CEO.

C++ Example:

class Image { public: virtual void display()=0; };

class RealImage : public Image {
    string filename;
public:
    RealImage(string f): filename(f){ cout << "Loading " << f << endl; }
    void display(){ cout << "Displaying " << filename << endl; }
};

class ProxyImage : public Image {
    string filename; RealImage* real = nullptr;
public:
    ProxyImage(string f): filename(f) {}
    void display() {
        if(!real) real = new RealImage(filename);
        real->display();
    }
};


Use When:

You need to defer expensive object creation or add access control.

### 11. Flyweight Pattern

Purpose: Minimize memory by sharing common data among many similar objects.

Analogy:
A forest shares tree models; only positions differ.

Use When:

Large numbers of similar objects (e.g., game sprites, characters, icons).

## 🧠 Behavioral Patterns
### 12. Observer Pattern

Purpose: Notify multiple objects when one object changes state.

Analogy:
YouTube notifications for subscribers when a new video is posted.

Use When:

Event-driven systems, GUIs, or pub-sub models.

### 13. Strategy Pattern

Purpose: Define a family of algorithms and make them interchangeable.

Analogy:
A GPS navigator choosing between shortest route, fastest route, or scenic route.

Use When:

Multiple algorithms or modes of operation.

### 14. Command Pattern

Purpose: Encapsulate a request as an object.

Analogy:
A remote control stores actions as commands (turn on TV, turn off light).

Use When:

You need to queue, undo, or log operations.

### 15. Memento Pattern

Purpose: Save and restore object state without violating encapsulation.

Analogy:
Undo feature in a text editor.

C++ Example:

class Memento {
    string state;
public:
    Memento(string s): state(s) {}
    string getState(){ return state; }
};

class Editor {
    string content;
public:
    void type(string words){ content += words; }
    Memento save(){ return Memento(content); }
    void restore(Memento m){ content = m.getState(); }
    void show(){ cout << content << endl; }
};


Use When:

Implementing undo/redo, checkpoints, or snapshots.

### 16. State Pattern

Purpose: Allow an object to change its behavior when its internal state changes.

Analogy:
Traffic light changes behavior (color) based on current state.

Use When:

You have objects with behavior dependent on internal conditions.

### 17. Chain of Responsibility Pattern

Purpose: Pass a request through a chain of handlers until one handles it.

Analogy:
Customer support escalation — Level 1 → Level 2 → Manager.

Use When:

You want to decouple senders and receivers of requests.

### 18. Visitor Pattern

Purpose: Add new operations to existing class hierarchies without modifying them.

Analogy:
A tax auditor visits departments to perform checks.

Use When:

You want to add operations to complex object structures dynamically.