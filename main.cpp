#include <iostream>
#include <ctime>
#include "Library.h"
using namespace std;

int main()
{

    Address adrr("Hay Elrahman", "Sohag/Idfa", "565656");
    Library lib("Hay Elrahman", adrr);

    int mainChoise, subChoise;

    while (true)
    {

        cout << endl
             << "*************_MAIN MENU_***********" << endl;
        cout << "1) Book Management" << endl;
        cout << "2) Member Management" << endl;
        cout << "3) Staff Management" << endl;
        cout << "4) Borrowing Operations" << endl;
        cout << "5) Library Information" << endl;
        cout << "0) Exit System" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoise;

        if (mainChoise == 0)
        {
            cout << "Exiting System " << endl;
            return 0;
        }

        switch (mainChoise)
        {

            // -------------------------------- BOOK MANAGEMENT --------------------------------

        case 1:
            while (true)
            {
                cout << "**************_Book Management_***********" << endl;
                cout << "1) Add New Book" << endl;
                cout << "2) View All Books" << endl;
                cout << "3) View Available Books" << endl;
                cout << "0) Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoise;

                if (subChoise == 0)
                    break;

                if (subChoise == 1)
                {
                    string title, author, isbn;
                    int page;

                    cout << "Enter Book Title: ";
                    cin.ignore();
                    getline(cin, title);

                    cout << "Enter Book Author: ";
                    getline(cin, author);

                    cout << "Enter Book ISBN: ";
                    getline(cin, isbn);

                    cout << "Enter Book Pages: ";
                    cin >> page;

                    Book newBook(title, author, isbn, page);
                    lib.addBook(newBook);

                    cout << "Book Added Successfully" << endl;
                }

                else if (subChoise == 2)
                {
                    lib.listAllBooks();
                }

                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
            break;


        case 2:
            while (true)
            {
                cout << "**************_Member Management_***********" << endl;
                cout << "1) Register New Member" << endl;
                cout << "2) View All Members" << endl;
                cout << "0) Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoise;

                if (subChoise == 0)
                    break;

                if (subChoise == 1)
                {

                    string name, email, phone, cardnumber;
                    int id;

                    cout << "Enter Member ID : ";
                    cin >> id;

                    cin.ignore();

                    cout << "Enter Member Name : ";
                    getline(cin, name);

                    cout << "Enter Member Email : ";
                    getline(cin, email);

                    cout << "Enter Member Phone Number : ";
                    getline(cin, phone);

                    cout << "Enter Member Card Number : ";
                    getline(cin, cardnumber);

                    Member *newMember = new Member(name, id, email, phone, cardnumber);
                    lib.addMember(newMember);

                    cout << "Member Added Successfully" << endl;
                }

                else if (subChoise == 2)
                {
                    lib.listAllMembers();
                }

                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
            break;


        case 3:
            while (true)
            {
                cout << "**************__Staff Management__************" << endl;
                cout << "1) Hire New Librarian" << endl;
                cout << "2) View All Staff" << endl;
                cout << "0) Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoise;

                if (subChoise == 0)
                    break;

                if (subChoise == 1)
                {

                    string name;
                    int id;

                    cout << "Enter Librarian ID : ";
                    cin >> id;

                    cin.ignore();

                    cout << "Enter Librarian Name : ";
                    getline(cin, name);

                    Librarian *newLib = new Librarian(name, id);
                    lib.addLibrarian(newLib);

                    cout << "Librarian Added Successfully" << endl;
                }

                else if (subChoise == 2)
                {

                    vector<Librarian *> staff = lib.getStaff();

                    if (staff.empty())
                    {
                        cout << "NO Staff Found" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < staff.size(); i++)
                        {
                            cout << "Librarian ID : " << staff[i]->get_id() << endl;
                            cout << "Librarian Name : " << staff[i]->get_name() << endl;
                        }
                    }
                }

                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
            break;


        case 4:
            while (true)
            {

                cout << "**************_Borrowing Operations_***********" << endl;
                cout << "1) Borrow Book" << endl;
                cout << "2) Return Book" << endl;
                cout << "3) View All Borrow Records" << endl;
                cout << "0) Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> subChoise;

                if (subChoise == 0)
                    break;

                // Borrow
                if (subChoise == 1)
                {

                    int memberID;
                    string BookTitle;

                    cout << "Enter Member ID: ";
                    cin >> memberID;

                    cin.ignore();

                    cout << "Enter Book Title: ";
                    getline(cin, BookTitle);

                    Member *borrower = nullptr;
                    vector<Member *> members = lib.getMembers();

                    for (int i = 0; i < members.size(); i++)
                    {
                        if (members[i]->getID() == memberID)
                        {
                            borrower = members[i];
                            break;
                        }
                    }

                    if (!borrower)
                    {
                        cout << "Member not found!" << endl;
                        continue;
                    }

                    Book *bookToBorrow = nullptr;
                    vector<Book> allBooks = lib.getBooks();

                    for (int i = 0; i < allBooks.size(); i++)
                    {
                        if (allBooks[i].getTitle() == BookTitle)
                        {
                            bookToBorrow = &allBooks[i];
                            break;
                        }
                    }

                    if (!bookToBorrow)
                    {
                        cout << "Book not found!" << endl;
                        continue;
                    }

                    BorrowRecord record(
                        lib.getBorrowRecords().size(),
                        time(0),
                        time(0),
                        borrower,
                        bookToBorrow);

                    lib.addBorrowRecord(record);

                    cout << "Book borrowed successfully!" << endl;
                }

                
                else if (subChoise == 2)
                {

                    int recordID;
                    cout << "Enter Record ID: ";
                    cin >> recordID;

                    vector<BorrowRecord> rec = lib.getBorrowRecords();
                    bool f = false;

                    for (int i = 0; i < rec.size(); i++)
                    {

                        if (rec[i].getRecordID() == recordID)
                        {

                            if (rec[i].getReturnedStatus())
                            {
                                cout << "This record is already returned!" << endl;
                            }
                            else
                            {
                                rec[i].returnBook();
                                cout << "Book Returned Successfully!" << endl;
                            }

                            f = true;
                            break;
                        }
                    }

                    if (!f)
                    {
                        cout << "Record not found!" << endl;
                    }
                }

                
                else if (subChoise == 3)
                {

                    vector<BorrowRecord> rec = lib.getBorrowRecords();

                    if (rec.empty())
                    {
                        cout << "NO Record Found" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < rec.size(); i++)
                        {
                            rec[i].displayInfo();
                        }
                    }
                }

                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
            break;


        case 5:
            lib.displayInfo();
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}
