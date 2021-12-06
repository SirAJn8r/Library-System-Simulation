#include "returnBook.h"

using namespace std;

ReturnBook::ReturnBook(BookDatabase* bookDB, PatronDatabase* patronDB)
{

    this->bookDB = bookDB;
    this->patronDB = patronDB;
}

ReturnBook::~ReturnBook()
{
    bookDB = nullptr;
    patronDB = nullptr;
}

void ReturnBook::execute()
{
    Book* book = bookDB->getBook(bookID);
    Patron* patron = patronDB->getPatron(patronID);

    if (!book || !patron) {
        cout << "Couldn't find Book or Patron for Return" << endl;
        return;
    }

    if (book->receiveBook(patron))
        patron->returnBook(book);
}

LibraryCommand* ReturnBook::create(ifstream& parameters) const
{
    ReturnBook* toReturn = new ReturnBook(bookDB, patronDB);
    parameters >> toReturn->patronID;

    if (toReturn->patronID.compare("9999") == 0) {
        delete toReturn;
        toReturn = nullptr;
        return nullptr;
    }

    parameters.get();
    getline(parameters, toReturn->bookID, ',');
    return toReturn;
}