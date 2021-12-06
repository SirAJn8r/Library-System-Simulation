/** @file returnBook.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. returns book from patron to library
 *
 * Implementation
 *   - inherits from Command interface.
 *   - adds a copy of an existing book to the library
 */

#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "book.h"
#include "bookDatabase.h"
#include "libraryCommand.h"
#include "patron.h"
#include "patronDatabase.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class ReturnBook : public LibraryCommand {
public:
    // -------------------------------------------------------------------------
    /** ReturnBook()
    * Default Constructor
    *
    * Constructs a return book command object with default values
    * @pre None.
    * @post ReturnBook command object exists
    */
    ReturnBook(BookDatabase* bookDB, PatronDatabase* patronDB);

    ~ReturnBook();

    // -------------------------------------------------------------------------
    /** execute()
    * Execute return book command
    *
    * updates the patron's current books and increments the book's count
    * @pre The patron and book should exist in the system
    * @post patron and book are updated accordingly
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

protected:
    // ID of patron this command uses
    string patronID;

    // ID of book this command uses
    string bookID;
};

#endif