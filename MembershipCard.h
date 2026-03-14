#ifndef MEMBERSHIPCARD_H
#define MEMBERSHIPCARD_H

#include <iostream>
#include <ctime>
using namespace std;

class MembershipCard
{
    string cardNumber;
    time_t issueDate;
    time_t expiryDate;

public:
    MembershipCard(string cardNumber = "", time_t issue = 0, time_t expiry = 0)
        : cardNumber(cardNumber), issueDate(issue), expiryDate(expiry) {}

    string getCardNumber() const
    {
        return cardNumber;
    }

    bool isValid() const
    {
        return time(nullptr) <= expiryDate;
    }
};

#endif
