/** 
 * @file displayLibrary.h
 * @author Alex Lambert
 *
 * Description:
 *   - Displays all books in the library, sorted
 *
 * Assumptions/Implementation:
 *   - Inherits from Command interface
 *   - Doesn't need to use the patronDatabase
 */

#ifndef DISPLAYLIBRARY_H
#define DISPLAYLIBRARY_H

#include "bookDatabase.h"
#include "libraryCommand.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DisplayLibrary : public LibraryCommand {
public:
    //-----------------------------------------------------------------------
    /** DisplayLibrary()
     * Default Constructor
     *
     * Constructs a base instance of the display library command. This 
     * instance must not be executed.
     * @param bookDB is the BookDatabase to be displayed
     * @pre None
     * @post DisplayLibrary command object exists for bookDB
     */
    DisplayLibrary(BookDatabase* bookDB);

    //-----------------------------------------------------------------------
    /** ~DisplayLibrary()
     * Default Destructor
     *
     * Destroys this command
     * @pre None
     * @post Deallocates memory used by this command.
     */
    virtual ~DisplayLibrary();

    //-----------------------------------------------------------------------
    /** execute()
     * Execute DisplayLibrary Command
     *
     * Prints all books in library in sorted order
     * @pre None
     * @post None. Library is unchanged
     */
    virtual void execute();

    //-----------------------------------------------------------------------
    /** create()
     * Create DisplayLibrary Command (factory)
     *
     * Creates a DisplayLibrary command that can be executed
     * @param parameters is a reference to the ifstream, starting immediately 
     * after the command code
     * @pre None
     * @post No changes, just returns the new command. Parameters will read up 
     * until and including the end-of-line character
     * @return returns the new executable command, or nullptr if the
     * parameters were invalid
     */
    virtual LibraryCommand* create(stringstream& parameters) const;
};

#endif