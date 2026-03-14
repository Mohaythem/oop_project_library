#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <string>
#include "Chapter.h"
using namespace std;

class Book
{
    string title;
    string author;
    string ISBN;
    int totalPages;
    bool isAvailable;
    vector<Chapter> chapters;

public:
    Book(string title = "", string author = "", string ISBN = "", int totalPages = 0,
         bool available = true, vector<Chapter> chapters = {})
        : title(title), author(author), ISBN(ISBN), totalPages(totalPages),
          isAvailable(available), chapters(chapters) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool v) { isAvailable = v; }

    void displayInfo()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Total Pages: " << totalPages << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;

        if (!chapters.empty())
        {
            cout << "Chapters: " << endl;
            for (auto &c : chapters)
                c.displayInfo();
        }
    }
};

#endif
