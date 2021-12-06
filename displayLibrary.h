/** @file displayLibrary.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. displays all books in library, sorted
 *
 * Implementation
 *   - inherits from Command interface.
 *   - displays all books in library in sorted order
 */

#ifndef DISPLAYLIBRARY_H
#define DISPLAYLIBRARY_H

#include "bookDatabase.h"
#include "libraryCommand.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class DisplayLibrary : public LibraryCommand {
public:
    // -------------------------------------------------------------------------
    /** DisplayLibrary()
    * Default Constructor
    *
    * Constructs a display library command object with default values
    * @pre None.
    * @post DisplayLibrary command object exists
    */
    DisplayLibrary(BookDatabase* bookDB);

    virtual ~DisplayLibrary();

    // -------------------------------------------------------------------------
    /** execute()
    * Execute display library command
    *
    * Prints all books in library in sorted order
    * @pre The library object should have books inputed
    * @post None. library is unchanged
    */
    virtual void execute();

    /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
    virtual LibraryCommand* create(ifstream& parameters) const;
};

#endif