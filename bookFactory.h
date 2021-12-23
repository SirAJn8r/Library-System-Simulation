/** 
 * @file bookfactory.h
 * @author Alex Lambert
 *
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *  objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 * string data provided by the LibraryBuilder.
 *   - This is the only class that would need to be changed if new types of
 * books were to be added
 *
 *
 * Assumptions/Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one base instance used to create copies of that type of book
 *   - Classifies each type of book and creates the correct sub-class of
 * book for each string passed in.
 */

#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H

#include "book.h"
#include "children.h"
#include "fiction.h"
#include "formattingConsts.h"
#include "periodical.h"
#include <iomanip>
#include <sstream>
#include <string>

#define NUM_BOOK_TYPES 3

class BookFactory {
public:
    //-----------------------------------------------------------------------
    /** BookFactory()
     * Default Constructor
     * 
     * Creates a BookFactory
     * @pre None.
     * @post BookFactory object exists with the base instances
     */
    BookFactory();

    //-----------------------------------------------------------------------
    /** ~BookFactory()
     * Default Destructor
     * 
     * Destroys the BookFactory
     * @pre None.
     * @post Deallocates the BookFactory memory, destroys the base instances
     */
    virtual ~BookFactory();

    //-----------------------------------------------------------------------
    /** getID()
     * Get ID Function
     *
     * Retreives the ID of any provided Book object fromt the bookTypeID
     *   int array and returns the id as an int.
     * @param type is a capital letter representing the type of book
     * @pre None.
     * @post None.
     * @return the ID of the type, -1 if it isn't valid
     */
    int getID(char type) const;

    //-----------------------------------------------------------------------
    /** createBook()
     * Create Book Function
     *
     * Creates a book based on bookString
     * @param bookString stores the info about the book to be fetched
     * @param altString represents if the book string is formatted in the
     * normal or alternative format
     * @pre bookString is properly formatted as per the formatting type
     * @post None. No changes made.
     * @return Book pointer to the new book, nullptr if it failed
     */
    Book* createBook(string bookString, bool altString = false) const;

    // array of the titles of each type of book
    stringstream bookTypeHeader[NUM_BOOK_TYPES];

private:
    //-----------------------------------------------------------------------
    /** checkFormat()
     * Check if Valid Format
     *
     * Checks if the format is legal or not
     * @param format is a capital letter representing the format
     * @pre None.
     * @post None.
     * @return if the format is valid
     */
    bool checkFormat(char format) const;

    // Array of base instances of each type, used to create usable instances
    Book* bookTypes[NUM_BOOK_TYPES];

    // A 26 long int array that correlates letters of the alphabet to a book
    // type. [0] represents A, [1] B, [2] C = Children's Book, etc.
    const int bookTypeID[26] { -1, -1, 2, -1, -1, 0, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

    // A 26 long bool array correlating letters of the alphabet to a format
    // type. [0] represents A, [1] B. Only H is valid currently.
    // false represents invalid, true represent valid
    const bool validFormats[26] { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
};

#endif