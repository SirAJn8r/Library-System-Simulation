/** 
 * @file returnBook.h
 * @author Alex Lambert
 *
 * Description:
 *   - Returns a copy of the book from the patron to the library
 *
 * Assumptions/Implementation:
 *   - Inherits from Command interface
 *   - Assumes the book string was stored in the alternative book format
 * (Books from the book data file are stored differently than in the command 
 * data file)
 */

#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "book.h"
#include "bookDatabase.h"
#include "libraryCommand.h"
#include "patron.h"
#include "patronDatabase.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ReturnBook : public LibraryCommand {
public:
    //-----------------------------------------------------------------------
    /** ReturnBook()
     * Default Constructor
     *
     * Constructs a base instance of the ReturnBook command. This 
     * instance must not be executed.
     * @param bookDB is the BookDatabase to be searched for the book
     * @param patronDB is PatronDatabase to be searched for the patron
     * @pre bookDB and patronDB should be for the same library
     * @post ReturnBook command object exists for bookDB/patronDB
     */
    ReturnBook(BookDatabase* bookDB, PatronDatabase* patronDB);

    //-----------------------------------------------------------------------
    /** ~ReturnBook()
     * Default Destructor
     *
     * Destroys this command
     * @pre None
     * @post Deallocates memory used by this command.
     */
    virtual ~ReturnBook();

    //-----------------------------------------------------------------------
    /** execute()
     * Execute ReturnBook Command
     *
     * Checks to see if the book and patron exist, and if the patron can
     * return the book. If so, the book has one copy returned to it and
     * the patron loses that copy.
     * @pre None
     * @post Book and Patron are updated accordingly, if everything was valid
     */
    virtual void execute();

    //-----------------------------------------------------------------------
    /** create()
     * Create ReturnBook Command (factory)
     *
     * Creates a ReturnBook command that can be executed
     * @param parameters is a reference to the ifstream, starting immediately 
     * after the command code
     * @pre None
     * @post No changes, just returns the new command. Parameters will read up 
     * until and including the end-of-line character
     * @return returns the new executable command, or nullptr if the
     * parameters were invalid
     */
    virtual LibraryCommand* create(stringstream& parameters) const;

protected:
    // ID of patron this command uses
    string patronID;

    // The identifying info of the book this command uses
    string bookID;
};

#endif