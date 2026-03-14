#ifndef CHAPTER_H
#define CHAPTER_H

#include <iostream>
#include <string>
using namespace std;

class Chapter
{
    int chapterNumber;
    string title;
    int pageStart;
    int pageEnd;

public:
    Chapter(int num = 0, string t = "", int ps = 0, int pe = 0)
        : chapterNumber(num), title(t), pageStart(ps), pageEnd(pe) {}

    void displayInfo()
    {
        cout << "Chapter " << chapterNumber << ": " << title << endl;
        cout << "Pages: " << pageStart << " - " << pageEnd << endl;
    }
};

#endif
