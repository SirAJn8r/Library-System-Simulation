#include "commandFactory.h"

const int* CommandFactory::commandIDs = new int[26] { -1, -1, 0, 3, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1 };

CommandFactory::CommandFactory(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;

    commands = new LibraryCommand*[NUM_COMMAND_TYPES];
    commands[0] = new CheckoutBook(bookDB, patronDB);
    commands[1] = new ReturnBook(bookDB, patronDB);
    commands[2] = new DisplayPatronHistory(patronDB);
    commands[3] = new DisplayLibrary(bookDB);
}

CommandFactory::~CommandFactory()
{
    for (int i = 0; i < NUM_COMMAND_TYPES; i++) {
        delete commands[i];
        commands[i] = nullptr;
    }
    delete commands;
    commands = nullptr;

    bookDB = nullptr;
    patronDB = nullptr;
}

CommandQueue* CommandFactory::createCommands(ifstream& commandFile)
{
    char type;
    string trashLine;
    LibraryCommand* commandMaker;
    LibraryCommand* next;
    CommandQueue* queue = new CommandQueue();

    while (!commandFile.eof()) {

        commandFile >> type;
        commandMaker = getCommand(type);

        // If the command type is valid
        if (commandMaker) {
            next = commandMaker->create(commandFile);

            // If a command was successfully created
            if (next) {
                queue->enqueue(next);
                next = nullptr;

                // get rid of the end of line char
                commandFile.get();
            }
            // If creating the command failed, get rid of the rest of the line
            else
                getline(commandFile, trashLine);
        }
        // If the command type doesn't exist, get rid of the rest of the line
        else
            getline(commandFile, trashLine);
    }

    return queue;
}

LibraryCommand* CommandFactory::getCommand(char type)
{
    int ID = int(type) - 65;
    if (ID < 0 || ID >= 26)
        return nullptr;
    if (commandIDs[ID] == -1)
        return nullptr;
    return commands[commandIDs[ID]];
}