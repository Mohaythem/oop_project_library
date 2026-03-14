#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "Address.h"
#include "Book.h"
#include "BorrowRecord.h"
#include "Member.h"
#include "Librarian.h"

using namespace std;

class Library
{
    string libraryName;
    Address libraryAddress;
    vector<Book> books;
    vector<Member *> members;
    vector<Librarian *> staff;
    vector<BorrowRecord> records;

public:
    Library(string name = "", Address addr = Address())
        : libraryName(name), libraryAddress(addr) {}

    void addBook(const Book &b) { books.push_back(b); }
    void addMember(Member *m) { members.push_back(m); }
    void addLibrarian(Librarian *l) { staff.push_back(l); }
    void addBorrowRecord(const BorrowRecord &r) { records.push_back(r); }

    vector<Book> getBooks() { return books; }
    vector<Member *> getMembers() { return members; }
    vector<Librarian *> getStaff() { return staff; }
    vector<BorrowRecord> getBorrowRecords() { return records; }

    void listAllBooks()
    {
        if (books.empty())
        {
            cout << "NO Books Found\n";
            return;
        }
        for (auto &b : books)
            b.displayInfo();
    }

    void listAllMembers()
    {
        if (members.empty())
        {
            cout << "NO Members Found\n";
            return;
        }
        for (auto *m : members)
            m->displayInfo();
    }

    Book *findBookByISBN(string isbn)
    {
        for (auto &b : books)
            if (b.getISBN() == isbn)
                return &b;
        return nullptr;
    }

    Member *findMemberByID(int id)
    {
        for (auto *m : members)
            if (m->getID() == id)
                return m;
        return nullptr;
    }

    void displayInfo()
    {
        cout << "\n--- Library Info ---\n";
        cout << "Name: " << libraryName << endl;
        libraryAddress.displayInfo();
        cout << "Books: " << books.size() << endl;
        cout << "Members: " << members.size() << endl;
        cout << "Staff: " << staff.size() << endl;
        cout << "Borrow Records: " << records.size() << endl;
    }
};

#endif
