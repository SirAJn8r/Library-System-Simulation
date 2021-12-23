/** 
 * @file bookDatabase.h
 * @author Alex Lambert
 *
 * Description:
 *   - BookDatabase holds all of the books for a library
 *   - It can retrieve books, insert books, and display its contents
 *   - There is no functionality for removing books from the BookDatabase
 *
 * Assumptions/Implementation:
 *   - Stores each book type in its own BSTree instance
 *   - Uses bookFactory to determine the type of a book and create them
 *   - Automatically scales if new book types were to be added
 */

#ifndef BOOKDATABASE_H
#define BOOKDATABASE_H

#include "BSTree.h"
#include "book.h"
#include "bookFactory.h"
#include <string>

using namespace std;

class BookDatabase {
public:
    //-----------------------------------------------------------------------
    /** BookDatabase()
     * Default Constructor
     *
     * Constructs an empty BookDatabase
     * @pre None
     * @post BookDatabase is initialized with 1 BSTree for each book type
     */
    BookDatabase();

    //-----------------------------------------------------------------------
    /** ~BookDatabase()
     * Default Destructor
     *
     * Destroys the BookDatabase and every item inside it
     * @pre None
     * @post All memory used by the BookDatabase and its parts is deallocated
     */
    virtual ~BookDatabase();

    //-----------------------------------------------------------------------
    /** insertNewBook()
     * Insert Book Function
     *
     * Inserts the given book into the correct BSTree
     * @param bookString is the book to be inserted into the appropriate 
     * BSTree, using the main parsing method (altString = false)
     * @pre bookString is properly formatted
     * @post newBook is added to the correct BSTree, if the book is valid
     * @return if newBook was successfully inserted
     */
    bool insertBook(string bookString);

    //-----------------------------------------------------------------------
    /** getBook()
     * Get Book Function
     * 
     * Return a book object based on the information that is passed in if it 
     * is in a BSTree
     * @param bookString stores the info about the book to be fetched
     * @param altString represents if the book string is formatted in the
     * normal or alternative format
     * @pre bookString is properly formatted as per the formatting type
     * @post None. No changes made.
     * @return Pointer to the Book object that they are looking for, if it
     * wasn't found, returns nullptr.
     */
    Book* getBook(string bookString, bool altString = false) const;

    //-----------------------------------------------------------------------
    /** displayAll()
     * Display All Books Function
     * 
     * Displays all of the books that have been inserted in the database, 
     * each type of book being sorted, each type being displayed in its own 
     * section
     * @pre None.
     * @post None, no changes.
     */
    void displayAll() const;

private:
    // An array containing a BSTree for each book type
    BSTree* bookBSTs[NUM_BOOK_TYPES];

    // Points to the bookFactory that creates books based on inputted strings
    BookFactory* bookFactory;
};

#endif