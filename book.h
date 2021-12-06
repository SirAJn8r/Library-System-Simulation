/** @file book.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A book object represents a unique book and the number of copies 
 * available for that book at any given time
 *   - Can be queried to display its information
 *   - Can be queried to see if there are any available copies
 *   - Can be compared with other books
 *   - number of available books can be changed
 *
 *
 * Implementation:
 *   - This is an abstract class
 *   - Some functions are virtual and some are pure virtual
 *   - One book object can represent multiple copies of the same book using 
 * the count member variable
 *   - count can be decreased or increased
 */

#ifndef BOOK_H
#define BOOK_H

#include "BSTData.h"
#include <sstream>
#include <string>

using namespace std;

class Patron;

// needs inheritance to BST data. book factory should befriend book for
// instantiation
class Book : public BSTData {
public:
    // -----------------------------------------------------------------------
    /** recieveBook()
    * Add a copy of the book to the collection
    *
    * Adds 1 to the count of the book, representing a copy of the book
    * has been returned
    * @pre None.
    * @post count is incremented
    */
    bool receiveBook(Patron* patron);

    // -----------------------------------------------------------------------
    /** giveBook()
    * Remove a book from collection
    *
    * Subtracts 1 from count variable of book, a copy of the book has been
    * checked out.
    * @pre must have a copy of the book available. count > 0
    * @post count--
    * @return true if book was available, false otherwise
    */
    bool giveBook(Patron* patron);

    // -----------------------------------------------------------------------
    /** checkAvailability()
    * Check if book is avaiable
    *
    * Checks if a copy of the book is available for patron to checkout
    * @pre None.
    * @post None. Const Function
    * @return If the patron can check out the book
    */
    bool checkAvailability(Patron* patron) const;

    // -----------------------------------------------------------------------
    /** displayBook()
    * Display book information
    *
    * Display book information in easy-to-read columns.
    * Displayed in order: Title, author, type, month & year published
    * Virtual function, can be overridden
    * @pre None.
    * @post None. Const Function
    * @return None
    */
    virtual void display() const = 0;

    // -----------------------------------------------------------------------
    /** create()
    * Create book (for factory)
    *
    * Creates a book instance
    * @pre None
    * @post new book object exists
    * @return reference to new children's book
    *
    */
    virtual Book* create(stringstream& parameters) const = 0;

protected:
    // author of book
    string author;

    // title of book
    string title;

    // year book was published
    int year;

    // month book was published
    int month;

    // copies of book available
    int count;

    // Total number of books available
    int maxCount;

    // format of book
    char format;

    // current patrons checking out the book. max size is maxCount
    Patron** checkouts;
};

#endif