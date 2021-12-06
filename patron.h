/** @file patron.h
 * @author Alex Lambert
 *
 * Description:
 *   - 
 *
 *
 * Implementation/Assumptions:
 *   - 
 */

#ifndef PATRON_H
#define PATRON_H

#include "BSTData.h"
#include "book.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Patron : public BSTData {
public:
    // -------------------------------------------------------------------------
    /** Patron()
    * Default Constructor
    *
    * Creates a new blank patron object 
    * @pre None.
    * @post Book object exists with default member variables
    */
    Patron(int ID, string name);

    // -------------------------------------------------------------------------
    /** ~Patron()
    * Default Destructor
    *
    * Destroys the patron object 
    * @pre None.
    * @post Deallocates all memory in this patron
    */
    ~Patron();

    // -------------------------------------------------------------------------
    /** addBook()
    * Check out Book
    *
    * Checks out the book to the patron if it can, and adds it to its history
    * @pre A patron can't check out a book it already has
    * @post currentBooks and bookHistory will both include the book
    * @return if the book was successfully checked out
    */
    virtual void addBook(Book* book);

    // -------------------------------------------------------------------------
    /** returnBook()
    * Return Book 
    *
    * Removes the book from the patron's current books, if it can
    * @pre A patron can't return a book they don't have
    * @post The patron will not be currently checking out the book
    * @return true if book was available, false otherwise
    */
    virtual void returnBook(Book* book);

    // -------------------------------------------------------------------------
    /** display()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month published, year published
    * Virtual function, can be overridden
    * @pre None.
    * @post None. const function
    * @return String representing book data
    */
    virtual void display() const;

protected:
    virtual int getComp(const BSTData& rhs) const;

    struct pastAction {
        string action;
        Book* book;
    };

    // patron identifier, 4 digit number
    int ID;

    // patron full name
    string name;

    // list of past book checkouts and returns
    list<pastAction>* history;
};

#endif