/** 
 * @file patron.h
 * @author Alex Lambert
 *
 * Description:
 *   - Patrons have an ID, a name, and can have books checked out to them
 *   - Has few functions, primarily controlling their history
 *
 * Implementation/Assumptions:
 *   - Implements the BSTData interface
 *   - Compare to each other using ID, name is irrelevant
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
    //-----------------------------------------------------------------------
    /** Patron()
    * Default Constructor
    *
    * Creates a new patron object 
    * @pre None.
    * @post Patron object exists with the given ID and name
    */
    Patron(int ID, string name);

    //------------------------------------------------------------------------
    /** ~Patron()
    * Default Destructor
    *
    * Destroys the patron object 
    * @pre None.
    * @post Deallocates all memory in this patron
    */
    virtual ~Patron();

    //------------------------------------------------------------------------
    /** addBook()
    * Check Out Book
    *
    * Checks out a book to the patron
    * @param book is the book the Patron is checking out
    * @pre The book can and has been checked out to the Patron
    * @post History will include this checkout
    */
    virtual void addBook(Book* book);

    //------------------------------------------------------------------------
    /** returnBook()
    * Return Book 
    *
    * Returns the book from the patron 
    * @param book is the book the Patron is return
    * @pre The book can and has been returned by the Patron
    * @post History will include this return
    */
    virtual void returnBook(Book* book);

    //------------------------------------------------------------------------
    /** display()
    * Display Patron Information
    *
    * Display patron information / history in easy-to-read columns.
    * @pre None.
    * @post None. const function
    */
    virtual void display() const;

    //------------------------------------------------------------------------
    /** getName()
    * Get Name
    *
    * Return the name of the patron
    * @pre None.
    * @post None. const function
    * @return the name variable
    */
    virtual string getName() const;

protected:
    //-----------------------------------------------------------------------
    /** getComp()
     * Get Comparison
     * 
     * Returns the comparison value of this and rhs
     * @pre Both items are of the same type
     * @post None, no changes
     * @return -1 if this is smaller, 0 if equivalent, 1 is this is bigger
     */
    virtual int getComp(const BSTData& rhs) const;

    // pastActions have a string representing the action (CheckOut or Return)
    // and a book involved in the action
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