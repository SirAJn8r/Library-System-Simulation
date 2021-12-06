/** @file children.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A children book type
 *
 * Implementation:
 *   - implements the pure virtual comparison functions from Book and BSTData
 */

#ifndef CHILDREN_H
#define CHILDREN_H

#include "book.h"
#include <iostream>
#include <sstream>

using namespace std;

class Children : public Book {
public:
    // -----------------------------------------------------------------------
    /** children()
    * Default constructor
    *
    * Creates a children book object
    * @pre None.
    * @post children book object exists
    */
    Children();

    // -----------------------------------------------------------------------
    /** ~Children()
    * Default destructor
    *
    * Destroys the children book
    * @pre None.
    * @post All memory for the children book is deallocated
    */
    virtual ~Children();

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
    * Create childrens book
    *
    * Creates a childrens book instance
    * @pre None
    * @post new childrens book object exists
    * @return reference to new children's book
    *
    */
    virtual Book* create(stringstream& parameters) const;

private:
    virtual int getComp(const BSTData& rhs) const;
};

#endif