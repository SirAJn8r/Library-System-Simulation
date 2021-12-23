/** 
 * @file fiction.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A Fiction book type
 *
 * Assumptions/Implementation:
 *   - Implements the pure virtual comparison functions from Book and BSTData
 */

#ifndef FICTION_H
#define FICTION_H

#include "book.h"
#include "formattingConsts.h"
#include <iomanip>
#include <iostream>
#include <sstream>

class Fiction : public Book {
public:
    //-----------------------------------------------------------------------
    /** Fiction()
     * Default constructor
     *
     * Creates an unusable base instance of a fiction book
     * @pre None
     * @post Fiction book object exists with no values
     */
    Fiction();

    //-----------------------------------------------------------------------
    /** ~Fiction()
     * Default destructor
     *
     * Destroys the fiction book
     * @pre None.
     * @post All memory for the fiction book is deallocated
     */
    virtual ~Fiction();

    //-----------------------------------------------------------------------
    /** display()
     * Display book information
     * 
     * Display book information in easy-to-read columns.
     * Displayed in order: count, author, title, year
     * Virtual function, can be overridden
     * @pre None.
     * @post None. const function
     * @return String representing book data
     */
    virtual void display() const;

    //-----------------------------------------------------------------------
    /** displayForPatron()
     * Display book information
     *
     * Display book information in easy-to-read columns for patron history
     * Displayed in order: author, title, year
     * Virtual function, can be overridden
     * @pre None.
     * @post None. const function
     */
    virtual void displayForPatron() const;

    //-----------------------------------------------------------------------
    /** create()
     * Create Book
     *
     * Creates a book based on bookString
     * @param bookString stores the info about the book to be fetched
     * @param altString represents if the book string is formatted in the
     * normal or alternative format
     * @pre bookString is properly formatted as per the formatting type
     * @post None. No changes made.
     * @return Book pointer to the new book, nullptr if it failed
     */
    virtual Book* create(stringstream& parameters, bool altString = false)
        const;

private:
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
};

#endif