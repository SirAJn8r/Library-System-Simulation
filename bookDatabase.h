/** @file bookDatabase.h
 *  @author Mogul Solutions
 *
 * Description:
 *   BookDatabase holds all of the children, periodical, and fiction books that
 *   are inserted from the book factory. As well as it is able to display them 
 *   and retrieve a book
 *
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
    // -------------------------------------------------------------------------
    /** BookDatabase()
    * Default Constructor
    *
    * Constructs a BookDatabase object with default values
    * 
    * @pre None.
    * @post BookDatabase object exists
    */
    BookDatabase();

    // -------------------------------------------------------------------------
    /** BookDatabase()
    * Default Constructor
    *
    * Constructs a BookDatabase object with default values
    * 
    * @pre None.
    * @post BookDatabase object exists
    */
    virtual ~BookDatabase();

    //--------------------------------------------------------------------------
    /** insertNewBook()
    * Insert Method
    *
    * Inserts the given book into the correct BST
    * @param newBook a book to be inserted into the appropriate BST
    * @pre None
    * @post newBook is added to the right BST, if successful
    * @return true if newBook was successfully inserted
    */
    bool insertBook(string bookString);

    //--------------------------------------------------------------------------
    /** getBook(String bookId)
    * 
    * Return a book object based on the information that is passed in if it is in a BST
    * 
    * @pre None.
    * @post None. const function
    * @return Book* representing the Book object that they are looking for if found
    */
    Book* getBook(string bookString) const;

    //--------------------------------------------------------------------------
    /** displayAll() const
    * 
    * Displays all of the books that have been inserted in the database.
    * 
    * The books are printed based on their class memeber variables
    * 
    * @pre None.
    * @post None. const function
    */
    void displayAll() const;

private:
    BSTree** bookBSTs;

    BookFactory* bookFactory;
};

#endif