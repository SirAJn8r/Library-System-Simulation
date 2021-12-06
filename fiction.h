/** @file fiction.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A Fiction book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTData
 */

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include <iostream>
#include <sstream>

class Fiction : public Book {
public:
    // -----------------------------------------------------------------------
    /** Fiction()
    * Default constructor
    *
    * Creates a fiction book object
    * @pre None.
    * @post Fiction book object exists
    */
    Fiction();

    // -----------------------------------------------------------------------
    /** ~Fiction()
    * Default destructor
    *
    * Destroys the fiction book
    * @pre None.
    * @post All memory for the fiction book is deallocated
    */
    virtual ~Fiction();

    // -----------------------------------------------------------------------
    /** displayBook()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month & year published
    * Virtual function, can be overridden
    * @pre None.
    * @post None. const function
    * @return String representing book data
    */
    virtual void display() const;

    // -----------------------------------------------------------------------
    /** create()
    * Create Fiction book
    *
    * Creates a Fiction book instance
    * @pre None
    * @post new Fiction book object exists
    * @return reference to new children's book
    *
    */
    virtual Book* create(stringstream& parameters) const;

private:
    virtual int getComp(const BSTData& rhs) const;
};

#endif