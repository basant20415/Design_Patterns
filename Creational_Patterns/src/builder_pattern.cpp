#include <bits/stdc++.h>
using namespace std;

class House {
public:
    string walls;
    string roof;
    string doors;

    void show() {
        cout << "House with " << walls << " walls, "
             << roof << " roof, and " << doors << " doors.\n";
    }
};

class HouseBuilder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildDoors() = 0;
    virtual House* getHouse() = 0;
    virtual ~HouseBuilder() {}
};

class WoodenHouseBuilder : public HouseBuilder {
    House* house;
public:
    WoodenHouseBuilder() { house = new House(); }

    void buildWalls() override { house->walls = "Wooden"; }
    void buildRoof() override { house->roof = "Wooden"; }
    void buildDoors() override { house->doors = "Wooden"; }

    House* getHouse() override { return house; }
};

class Director {
    HouseBuilder* builder;
public:
    Director(HouseBuilder* b) : builder(b) {}
    House* construct() {
        builder->buildWalls();
        builder->buildRoof();
        builder->buildDoors();
        return builder->getHouse();
    }
};

int main() {
    HouseBuilder* builder = new WoodenHouseBuilder();
    Director director(builder);

    House* house = director.construct();
    house->show();

    delete builder;
    delete house;
}
