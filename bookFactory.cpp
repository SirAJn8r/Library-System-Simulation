#include "bookFactory.h"

const int* BookFactory::bookTypeID = new int[26] { -1, -1, 2, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

BookFactory::BookFactory()
{
    bookTypes = new Book*[NUM_BOOK_TYPES];
    bookTypes[0] = new Fiction();
    bookTypes[1] = new Periodical();
    bookTypes[2] = new Children();
}

BookFactory::~BookFactory()
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++) {
        delete bookTypes[i];
        bookTypes[i] = nullptr;
    }

    delete bookTypes;
    bookTypes = nullptr;
}

int BookFactory::getID(char type) const
{
    int ID = int(type) - 65;
    if (ID < 0 || ID >= 26)
        return -1;
    return bookTypeID[ID];
}

Book* BookFactory::createBook(string bookString) const
{
    int ID = getID(bookString[0]);
    if (ID == -1)
        return nullptr;

    stringstream bookStringReader(bookString);
    bookStringReader.get();
    bookStringReader.get();

    return bookTypes[ID]->create(bookStringReader);
}