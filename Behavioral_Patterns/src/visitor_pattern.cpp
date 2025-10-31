#include <bits/stdc++.h>
using namespace std;

// Forward declarations
class Circle;
class Rectangle;

// ---------------- Visitor Interface ----------------
class Visitor {
public:
    virtual void visit(Circle &circle) = 0;
    virtual void visit(Rectangle &rectangle) = 0;
    virtual ~Visitor() = default;
};

// ---------------- Shape Base Class ----------------
class Shape {
public:
    virtual void accept(Visitor &visitor) = 0;
    virtual ~Shape() = default;
};

// ---------------- Concrete Shape: Circle ----------------
class Circle : public Shape {
public:
    double radius;
    Circle(double r) : radius(r) {}

    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

// ---------------- Concrete Shape: Rectangle ----------------
class Rectangle : public Shape {
public:
    int length, width;
    Rectangle(int l, int w) : length(l), width(w) {}

    void accept(Visitor &visitor) override {
        visitor.visit(*this);
    }
};

// ---------------- Concrete Visitor: AreaCalculator ----------------
class AreaCalculator : public Visitor {
public:
    void visit(Circle &circle) override {
        cout << "Area of circle: " << (3.14159 * circle.radius * circle.radius) << endl;
    }

    void visit(Rectangle &rectangle) override {
        cout << "Area of rectangle: " << (rectangle.length * rectangle.width) << endl;
    }
};

// ---------------- Another Concrete Visitor: ShapeDrawer ----------------
class ShapeDrawer : public Visitor {
public:
    void visit(Circle &circle) override {
        cout << "Drawing a circle with radius: " << circle.radius << endl;
    }

    void visit(Rectangle &rectangle) override {
        cout << "Drawing a rectangle (" << rectangle.length << " x " << rectangle.width << ")" << endl;
    }
};

// ---------------- Main (Client Code) ----------------
int main() {
    vector<Shape*> shapes = {
        new Circle(5),
        new Rectangle(3, 4)
    };

    AreaCalculator areaVisitor;
    ShapeDrawer drawVisitor;

    for (auto shape : shapes) {
        shape->accept(areaVisitor);
        shape->accept(drawVisitor);
    }

    for (auto shape : shapes) delete shape;

    return 0;
}
