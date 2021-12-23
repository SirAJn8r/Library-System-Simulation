/** 
 * @file bookDatabase.h
 * @author Alex Lambert
 *
 * Description:
 *   - Library class contains books and patrons, the patrons can do things 
 * such as checking out or returning the books.
 *   - There are a few commands that happen to do this checking in and out
 * of books, and also displaying information about the library.
 * 
 * Assumptions/Implmentation:
 *   - The library should be created by LibraryBuilder so it is properly done.
 *   - Processes commands by using an ifstream, which should be properly 
 * formatted.
 *   - Can process multiple sets of commands if desired
 */

#include "library.h"

//---------------------------------------------------------------------------
/** Library()
 * Default Constructor
 *
 * Constructs a Library object containing bookDB and patronDB.
 * @param bookDB is a complete valid bookDatabase
 * @param patronDB is a complete valid patronDatabase
 * @pre None.
 * @post Library object exists and is initialized
 */
Library::Library(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;
}

//---------------------------------------------------------------------------
/** ~Library()
 * Default Destructor
 *
 * Destroys the library and everything in it
 * @pre None.
 * @post All memory used by everything in the library is deallocated.
 */
Library::~Library()
{
    delete bookDB;
    bookDB = nullptr;

    delete patronDB;
    patronDB = nullptr;
}

//---------------------------------------------------------------------------
/** processComands()
 * Process Commands
 * 
 * Runs all the commands in the commandFile that are legal.
 * @param commandFile is an input file of the commands to execute.
 * @pre commandFile is properly formatted.
 * @post valid legal commands are executed in the library.
 */
void Library::processCommands(ifstream& commandFile)
{
    CommandFactory* commandFactory = new CommandFactory(bookDB, patronDB);
    CommandQueue* commandQueue = commandFactory->createCommands(commandFile);

    delete commandFactory;
    commandFactory = nullptr;

    while (!commandQueue->isEmpty())
        commandQueue->executeNext();

    delete commandQueue;
    commandQueue = nullptr;
}