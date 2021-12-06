/**
 * @file commandFactory.h
 * @author Mogul Solutions
 *
 * Description:
 *   -Uses an input stream to read text and create commands based off it
 *   -The factory is associated with a library which commands are made for
 *
 * Assumptions/Implementation:
 *   -If the factory is destroyed, nothing else is deleted with it
 *   -Fetches the command to be made using CommandTypeHashmap
 *   -Delegates initializing a command to the command object.
 */

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#define NUM_COMMAND_TYPES 4

#include "bookDatabase.h"
#include "checkoutBook.h"
#include "commandQueue.h"
#include "displayLibrary.h"
#include "displayPatronHistory.h"
#include "libraryCommand.h"
#include "patronDatabase.h"
#include "returnBook.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class CommandFactory {

public:
    /** CommandFactory
    * Command Factory Constructor
    *
    * Builds a CommandFactory for the inputted library
    * @param library The library to create commands for
    * @pre None
    * @post Stores private pointer to library
    */
    CommandFactory(BookDatabase* bookDB, PatronDatabase* patronDB);

    /** ~CommandFactory
    * Command Factory Destructor
    *
    * Destroys the CommandFactory
    * @pre None
    * @post Returns CommandFactory to memory, nothing else
    */
    virtual ~CommandFactory();

    /** createCommands
    * Create Commands
    *
    * Reads the file, creating LibraryCommands and storing them
    * into a CommandQueue
    * @param file Pointer to an input file containing text form of commands
    * @pre file must be properly formatted
    * @post CommandQueue is initialized and filled. Library unchanged.
    * @return A filled CommandQueue object
    */
    CommandQueue* createCommands(ifstream& commandFile);

private:
    /** getCommand
    * Create Command Object
    *
    * Returns the type of command indicated by the type given
    * @param type A 1 capital character string indicating the type of command
    * @pre None
    * @post Creates the object and returns it, nothing else
    * @return The library command if type was valid, or nullptr otherwise
    */
    LibraryCommand* getCommand(char type);

    BookDatabase* bookDB;
    PatronDatabase* patronDB;
    LibraryCommand** commands;

    static const int* commandIDs;
};

#endif