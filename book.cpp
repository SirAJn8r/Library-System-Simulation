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

#include "book.h"

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
bool Book::receiveBook(Patron* patron)
{
    if (patron == nullptr)
        return false;
    if (count == maxCount)
        return false;

    // If the patron has the book checked out, check it back in
    // If the patron does not, they can't return the book
    for (int i = 0; i < maxCount + 1; i++) {
        if (i == maxCount)
            return false;
        if (checkouts[i] == patron) {
            checkouts[i] = nullptr;
            break;
        }
    }

    count++;
    return true;
}

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
bool Book::giveBook(Patron* patron)
{
    if (patron == nullptr)
        return false;
    if (!checkAvailability(patron))
        return false;

    for (int i = 0; i < maxCount; i++) {
        if (checkouts[i] == nullptr) {
            checkouts[i] = patron;
            break;
        }
    }

    count--;
    return true;
}

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
bool Book::checkAvailability(Patron* patron) const
{
    // If there are no copies left, it is unavailable
    if (count == 0)
        return false;
    if (patron == nullptr)
        return false;

    // If the patron is already checking out a copy, it's unavailable
    for (int i = 0; i < maxCount; i++) {
        if (patron == checkouts[i])
            return false;
    }

    return true;
}

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
string Book::getTitle() const
{
    return title;
}