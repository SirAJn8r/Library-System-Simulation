#include "checkoutBook.h"

CheckoutBook::CheckoutBook(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;
}

CheckoutBook::~CheckoutBook()
{
    bookDB = nullptr;
    patronDB = nullptr;
}

void CheckoutBook::execute()
{
    Book* book = bookDB->getBook(bookID);
    Patron* patron = patronDB->getPatron(patronID);

    if (!book || !patron) {
        cout << "Couldn't find Book or Patron for Checkout" << endl;
        return;
    }

    if (book->giveBook(patron))
        patron->addBook(book);
}

LibraryCommand* CheckoutBook::create(ifstream& parameters) const
{
    CheckoutBook* toReturn = new CheckoutBook(bookDB, patronDB);
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