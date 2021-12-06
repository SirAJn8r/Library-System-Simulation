#include "library.h"

Library::Library(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;
}

Library::~Library()
{
    delete bookDB;
    bookDB = nullptr;

    delete patronDB;
    patronDB = nullptr;
}

void Library::processCommands(ifstream& commandFile)
{
    CommandFactory* commandFactory = new CommandFactory(bookDB, patronDB);
    CommandQueue* commandQueue = commandFactory->createCommands(commandFile);

    while (!commandQueue->isEmpty())
        commandQueue->executeNext();

    delete commandQueue;
    delete commandFactory;
    commandQueue = nullptr;
    commandFactory = nullptr;
}