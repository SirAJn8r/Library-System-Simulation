/** 
 * @file book.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A book object represents a unique book and the number of copies 
 * available for that book at any given time
 *   - Can be queried to display its information
 *   - Can be queried to see if there are any available copies
 *   - Can be compared with other books
 *   - Number of available books can be changed
 *
 *
 * Assumptions/Implementation:
 *   - This is an abstract class
 *   - Some functions are virtual and some are pure virtual
 *   - One book object can represent multiple copies of the same book using 
 * the count member variable
 *   - Count can be decreased or increased
 */

#ifndef BOOK_H
#define BOOK_H

#include "BSTData.h"
#include <sstream>
#include <string>

using namespace std;

class Patron;

class Book : public BSTData {
public:
    //-----------------------------------------------------------------------
    /** recieveBook()
     * Add Copy of Book
     *
     * Adds 1 to the count of the book if the patron is eligible to return a 
     * copy
     * @param patron is the patron returning the book
     * @pre Patron isn't a nullptr
     * @post count is incremented if the patron doesn't currently has a copy
     * @return if the book was successfully returned
     */
    bool receiveBook(Patron* patron);

    //-----------------------------------------------------------------------
    /** giveBook()
     * Subtract Copy of Book
     *
     * Subtracts 1 from count of the book if it is available for the patron
     * to check out
     * @param patron is the patron checking out the book
     * @pre must have a copy of the book available. count > 0
     * @post count is decremented if the patron can check out a copy
     * @return true if book was available, false otherwise
     */
    bool giveBook(Patron* patron);

    //-----------------------------------------------------------------------
    /** checkAvailability()
     * Check if Book is Avaiable
     *
     * Checks if a copy of the book is available for patron to checkout
     * @param patron is the patron checking out the book
     * @pre patron isn't a nullptr
     * @post None. Const Function
     * @return If the patron can check out the book
     */
    bool checkAvailability(Patron* patron) const;

    //-----------------------------------------------------------------------
    /** displayBook()
     * Display book information
     *
     * Display book information in easy-to-read columns.
     * Pure virtual, each book type must implement
     * @pre None.
     * @post None. Const Function
     */
    virtual void display() const = 0;

    //-----------------------------------------------------------------------
    /** displayForPatron()
     * Display book information
     *
     * Display book information in easy-to-read columns for patron history
     * Virtual function, can be overridden
     * @pre None.
     * @post None. const function
     */
    virtual void displayForPatron() const = 0;

    //-----------------------------------------------------------------------
    /** getTitle()
     * Get Ttile
     *
     * Returns the title of the book
     * @pre Book type uses the title
     * @post None. const function
     * @return the title, or some other signifier if the book type 
     * doesn't use titles
     */
    virtual string getTitle() const;

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
        const = 0;

protected:
    // Deriving classes do not need to use author, title, year, and month

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

    // Total number of copies in this library
    int maxCount;

    // array of current patrons checking out the book. max size is maxCount
    Patron** checkouts;
};

#endif