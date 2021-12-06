#include "libraryBuilder.h"

using namespace std;

LibraryBuilder::LibraryBuilder() { }
LibraryBuilder::~LibraryBuilder() { }

Library* LibraryBuilder::createLibrary(ifstream& books, ifstream& patrons)
{
    BookDatabase* bookDB = new BookDatabase();
    PatronDatabase* patronDB = new PatronDatabase();
    string readString;

    while (!books.eof()) {
        getline(books, readString);
        if (readString.length() == 0)
            break;

        cout << "vvv" << endl;
        cout << readString << endl;
        cout << "^^^" << endl;

        bookDB->insertBook(readString);
    }

    while (!patrons.eof()) {
        getline(patrons, readString);
        if (readString.length() == 0)
            break;

        cout << "vvv" << endl;
        cout << readString << endl;
        cout << "^^^" << endl;

        patronDB->insertPatron(readString);
    }

    return new Library(bookDB, patronDB);
}