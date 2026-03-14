#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address
{
    string street;
    string city;
    string zipcode;

public:
    Address(string street = "", string city = "", string zipcode = "")
        : street(street), city(city), zipcode(zipcode) {}

    void displayInfo()
    {
        cout << "Street: " << street << "\nCity: " << city << "\nZipcode: " << zipcode << endl;
    }
};

#endif
