#include "displayLibrary.h"

using namespace std;

DisplayLibrary::DisplayLibrary(BookDatabase* bookDB)
{
    this->bookDB = bookDB;
}

DisplayLibrary::~DisplayLibrary()
{
    bookDB = nullptr;
}

void DisplayLibrary::execute()
{
    bookDB->displayAll();
}

LibraryCommand* DisplayLibrary::create(ifstream& parameters) const
{
    return new DisplayLibrary(bookDB);
}