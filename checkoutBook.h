/** 
 * @file checkoutBook.h
 * @author Alex Lambert
 *
 * Description:
 *   - Checks out a copy of the book to the patron
 *
 * Assumptions/Implementation:
 *   - Inherits from Command interface
 *   - Assumes the book string was stored in the alternative book format
 * (Books from the book data file are stored differently than in the command 
 * data file)
 */

#ifndef CHECKOUTBOOK_H
#define CHECKOUTBOOK_H

#include "book.h"
#include "bookDatabase.h"
#include "libraryCommand.h"
#include "patron.h"
#include "patronDatabase.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class CheckoutBook : public LibraryCommand {
public:
    //-----------------------------------------------------------------------
    /** CheckoutBook()
     * Default Constructor
     *
     * Constructs a base instance of the CheckoutBook command. This 
     * instance must not be executed.
     * @param bookDB is the BookDatabase to be searched for the book
     * @param patronDB is PatronDatabase to be searched for the patron
     * @pre bookDB and patronDB should be for the same library
     * @post CheckoutBook command object exists for bookDB/patronDB
     */
    CheckoutBook(BookDatabase* bookDB, PatronDatabase* patronDB);

    //-----------------------------------------------------------------------
    /** ~CheckoutBook()
     * Default Destructor
     *
     * Destroys this command
     * @pre None
     * @post Deallocates memory used by this command.
     */
    virtual ~CheckoutBook();

    //-----------------------------------------------------------------------
    /** execute()
     * Execute CheckoutBook Command
     *
     * Checks to see if the book and patron exist, and if the patron can
     * checkout the book. If so, the book has one copy checked out and
     * the patron recieves that copy.
     * @pre None
     * @post Book and Patron are updated accordingly, if everything was valid
     */
    virtual void execute();

    //-----------------------------------------------------------------------
    /** create()
     * Create CheckoutBook Command (factory)
     *
     * Creates a CheckoutBook command that can be executed
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