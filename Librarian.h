#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <iostream>
#include <string>
using namespace std;

class Librarian
{
    string name;
    int ID;

public:
    Librarian(string name = "", int ID = 0)
        : name(name), ID(ID) {}

    int get_id() const
    {
        return ID;
    }

    string get_name() const
    {
        return name;
    }

    void displayInfo() const
    {
        cout << "Librarian Name: " << name << endl;
        cout << "Librarian ID: " << ID << endl;
    }
};

#endif
