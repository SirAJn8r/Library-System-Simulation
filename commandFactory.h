/**
 * @file commandFactory.h
 * @author Alex Lambert
 *
 * Description:
 *   - Uses an input stream to read text and create commands based off it
 *   - The factory is associated with a BookDatabase and a PatronDatabase
 * which the commands are made for
 *   - Returns a CommandQueue containing all the commands generated
 *
 * Assumptions/Implementation:
 *   - If the factory is destroyed, nothing else is deleted with it
 *   - Fetches the command to be made using CommandTypeHashmap
 *   - Delegates initializing a command to the command object.
 */

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

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
#include <sstream>
#include <string>

#define NUM_COMMAND_TYPES 4

using namespace std;

class CommandFactory {

public:
    //-----------------------------------------------------------------------
    /** CommandFactory()
     * Default Constructor
     *
     * Builds a CommandFactory for the inputted bookDB and patronDB
     * @param bookDB The BookDatabase to create commands for.
     * @param patronDB The PatronDatabase to create commands for.
     * @pre bookDB and patronDB must be for the same library.
     * @post Stores private pointer to the bookDB and patronDB
     */
    CommandFactory(BookDatabase* bookDB, PatronDatabase* patronDB);

    //-----------------------------------------------------------------------
    /** ~CommandFactory()
     * Default Destructor
     *
     * Destroys the CommandFactory
     * @pre None
     * @post Returns CommandFactory to memory, nothing else
     */
    virtual ~CommandFactory();

    //-----------------------------------------------------------------------
    /** createCommands()
     * Create Commands
     *
     * Reads the file, creating LibraryCommands and storing them into a 
     * CommandQueue
     * @param commandfile is an input file containing a list of commands
     * @pre commandFile must be properly formatted
     * @post CommandQueue is initialized and filled. Library unchanged
     * @return A filled CommandQueue object
     */
    CommandQueue* createCommands(ifstream& commandFile);

private:
    //-----------------------------------------------------------------------
    /** getCommand()
     * Get Base Command Object
     *
     * Returns the base command indicated by the type given
     * @param type A 1 capital character string indicating the type of command
     * @pre None
     * @post Returns the respective baseCommand, no changes
     * @return The library command if type was valid, or nullptr otherwise
     */
    LibraryCommand* getCommand(char type) const;

    // A pointer to the BookDatabase the commands will run in
    BookDatabase* bookDB;
    // A pointer to the PatronDatabase the commands will run in
    PatronDatabase* patronDB;

    // An array containing 1 of each command type to make usable commands
    // of that type
    LibraryCommand* baseCommands[NUM_COMMAND_TYPES];

    // A 26 long int array that correlates letters of the alphabet to a
    // command type. [0] represents A, [1] B, [3] D = Display Library, etc.
    const int commandIDs[26] { -1, -1, 0, 3, -1, -1, -1, 2, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1 };
};

#endif