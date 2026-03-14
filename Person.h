#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int ID;

public:
    Person(string name = "", int ID = 0)
        : name(name), ID(ID) {}

    virtual string getName() const { return name; }
    virtual int getID() const { return ID; }

    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
    }
};

#endif

