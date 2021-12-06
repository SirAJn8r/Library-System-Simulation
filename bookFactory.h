/** @file bookfactory.h
 * @author Omar Ahmed
 *
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *  objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 * string data provided by the LibraryBuilder.
 *   - Holds three types of books: Fiction, Periodicals, and Children.
 *
 *
 * Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one function used to create and classify a book using
 * string data.
 *   - Classifies each type of book and creates the correct sub-class of
 * book for each string passed in.
 */

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

#define NUM_BOOK_TYPES 3

#include "book.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
#include <sstream>

class BookFactory {
public:
    BookFactory();

    virtual ~BookFactory();

    // -------------------------------------------------------------------------
    /** getID()
    * Accessor Function
    *
    * Retreives the ID of any provided Book object fromt the bookTypeID
    *   int array and returns the id as an int.
    * Returns -1 if not found.
    * @pre Book book.
    * @post int.
    */
    int getID(char type) const;

    // -------------------------------------------------------------------------
    /** createBook()
    * Builder Function
    *
    * Creates a Book using the data provided as string input and creates it
    * using the correct book subclass. Inserts in to the bookTypes array and
    * returns a pointer to the Book just inserted.
    * @pre string bookString.
    * @post Book pointer.
    */
    Book* createBook(string bookString) const;

private:
    // Array of subclasses of Book object to classify each book as its correct
    //  type.
    Book** bookTypes;

    // int array of bookIDs that can be searched to retrieve any id for a book
    //  the exists in it.
    static const int* bookTypeID;
};

#endif