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

#include "bookDatabase.h"

using namespace std;

//---------------------------------------------------------------------------
/** BookDatabase()
 * Default Constructor
 *
 * Constructs an empty BookDatabase
 * @pre None
 * @post BookDatabase is initialized with 1 BSTree for each book type
 */
BookDatabase::BookDatabase()
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++)
        bookBSTs[i] = new BSTree();

    bookFactory = new BookFactory();
}

//---------------------------------------------------------------------------
/** ~BookDatabase()
 * Default Destructor
 *
 * Destroys the BookDatabase and every item inside it
 * @pre None
 * @post All memory used by the BookDatabase and its parts is deallocated
 */
BookDatabase::~BookDatabase()
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++) {
        delete bookBSTs[i];
        bookBSTs[i] = nullptr;
    }

    delete bookFactory;
    bookFactory = nullptr;
}

//---------------------------------------------------------------------------
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
bool BookDatabase::insertBook(string bookString)
{
    int ID = bookFactory->getID(bookString[0]);
    if (ID == -1)
        return false;

    Book* newBook = bookFactory->createBook(bookString);
    if (newBook)
        return bookBSTs[ID]->insert(newBook);

    return false;
}

//---------------------------------------------------------------------------
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
Book* BookDatabase::getBook(string bookString, bool altString) const
{
    int ID = bookFactory->getID(bookString[0]);
    if (ID == -1) {
        cout << "ERROR: \'" << bookString[0]
             << "\' is not a valid book type for ";
        return nullptr;
    }

    Book* newBook = bookFactory->createBook(bookString, altString);
    if (newBook) {
        Book* toReturn = (Book*)bookBSTs[ID]->retrieve(newBook);
        if (!toReturn) {
            cout << "ERROR: Could not find \'" << newBook->getTitle() << "\' in the catalog for ";
        }
        delete newBook;
        newBook = nullptr;
        return toReturn;
    }

    return nullptr;
}

//---------------------------------------------------------------------------
/** displayAll()
 * Display All Books Function
 * 
 * Displays all of the books that have been inserted in the database, 
 * each type of book being sorted, each type being displayed in its own 
 * section
 * @pre None.
 * @post None, no changes.
 */
void BookDatabase::displayAll() const
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++) {
        cout << endl;
        cout << bookFactory->bookTypeHeader[i].str();
        bookBSTs[i]->displayAll();
    }
}