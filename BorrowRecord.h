#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <iostream>
#include <ctime>
#include "Member.h"
#include "Book.h"
using namespace std;

class BorrowRecord
{
    int recordID;
    time_t borrowDate;
    time_t dueDate;
    time_t returnedDate;
    bool isReturned;
    Member *borrower;
    Book *borrowedBook;

public:
    BorrowRecord(int recordID = 0, time_t borrowDate = 0,
                 time_t dueDate = 0, Member *borrower = nullptr,
                 Book *borrowedBook = nullptr)
        : recordID(recordID), borrowDate(borrowDate), dueDate(dueDate),
          returnedDate(0), isReturned(false),
          borrower(borrower), borrowedBook(borrowedBook) {}

    int getRecordID() const
    {
        return recordID;
    }

    bool getReturnedStatus() const
    {
        return isReturned;
    }

    bool isOverDuration() const
    {
        return (!isReturned && time(nullptr) > dueDate);
    }

    void returnBook()
    {
        if (isReturned)
            return;

        isReturned = true;
        returnedDate = time(nullptr);
        if (borrowedBook)
            borrowedBook->setAvailability(true);
    }

    void displayInfo()
    {
        cout << "Record ID: " << recordID << endl;
        cout << "Borrow Date: " << ctime(&borrowDate);
        cout << "Due Date: " << ctime(&dueDate);
        cout << "Returned: " << (isReturned ? "Yes" : "No") << endl;

        if (borrower)
            cout << "Borrower: " << borrower->getName() << " (ID " << borrower->getID() << ")" << endl;

        if (borrowedBook)
            cout << "Book: " << borrowedBook->getTitle()
                 << " | ISBN: " << borrowedBook->getISBN() << endl;
    }
};

#endif
