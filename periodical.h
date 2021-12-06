/** @file periodical.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A Periodical book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTData
 */

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

class Periodical : public Book {
public:
    // -----------------------------------------------------------------------
    /** Periodical()
    * Default constructor
    *
    * Creates a Periodical book object
    * @pre None.
    * @post Periodical book object exists
    */
    Periodical();

    // -----------------------------------------------------------------------
    /** ~Periodical()
    * Default destructor
    *
    * Destroys the periodical book
    * @pre None.
    * @post All memory for the periodical book is deallocated
    */
    virtual ~Periodical();

    // -----------------------------------------------------------------------
    /** displayBook()
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

    // -----------------------------------------------------------------------
    /** create()
    * Create Periodical book
    *
    * Creates a Periodical book instance
    * @pre None
    * @post new Periodical book object exists
    * @return reference to new children's book
    *
    */
    virtual Book* create(stringstream& parameters) const;

private:
    virtual int getComp(const BSTData& rhs) const;
};

#endif