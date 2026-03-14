#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include "Person.h"
#include "MembershipCard.h"
using namespace std;

class Member : public Person
{
    string email;
    string phone;
    MembershipCard card;

public:
    Member(string name = "", int ID = 0, string email = "",
           string phone = "", MembershipCard card = MembershipCard())
        : Person(name, ID), email(email), phone(phone), card(card) {}

    string getName() const override { return name; }
    int getID() const override { return ID; }
    string getCardNumber() const { return card.getCardNumber(); }
    MembershipCard getCard() const { return card; }

    void displayInfo() override
    {
        cout << "Member Name: " << name << endl;
        cout << "Member ID: " << ID << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "Card Number: " << card.getCardNumber() << endl;
        cout << "Valid: " << (card.isValid() ? "Yes" : "No") << endl;
    }
};

#endif
