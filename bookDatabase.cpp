#include "bookDatabase.h"

using namespace std;

BookDatabase::BookDatabase()
{
    bookBSTs = new BSTree* [NUM_BOOK_TYPES] { new BSTree() };
    bookFactory = new BookFactory();
}

BookDatabase::~BookDatabase()
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++)
        delete bookBSTs[i];
    delete bookBSTs;
    bookBSTs = nullptr;

    delete bookFactory;
    bookFactory = nullptr;
}

bool BookDatabase::insertBook(string bookString)
{
    int ID = bookFactory->getID(bookString[0]);
    if (ID == -1)
        return false;

    Book* newBook = bookFactory->createBook(bookString);
    if (newBook) {

        cout << "ID = " << ID << endl;
        cout << " " << endl;

        return bookBSTs[ID]->insert(newBook);
    }

    return false;
}

Book* BookDatabase::getBook(string bookString) const
{
    int ID = bookFactory->getID(bookString[0]);
    if (ID == -1)
        return nullptr;

    Book* newBook = bookFactory->createBook(bookString);
    if (newBook)
        return (Book*)bookBSTs[ID]->retrieve(newBook);

    return nullptr;
}

void BookDatabase::displayAll() const
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++)
        bookBSTs[i]->displayAll();
}