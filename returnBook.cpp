/** 
 * @file returnBook.cpp
 * @author Alex Lambert
 *
 * Description:
 *   - Returns a copy of the book from the patron to the library
 *
 * Assumptions/Implementation:
 *   - Inherits from Command interface
 *   - Assumes the book string was stored in the alternative book format
 * (Books from the book data file are stored differently than in the command
 * data file)
 */

#include "returnBook.h"

using namespace std;

//---------------------------------------------------------------------------
/** ReturnBook()
 * Default Constructor
 *
 * Constructs a base instance of the ReturnBook command. This 
 * instance must not be executed.
 * @param bookDB is the BookDatabase to be searched for the book
 * @param patronDB is PatronDatabase to be searched for the patron
 * @pre bookDB and patronDB should be for the same library
 * @post ReturnBook command object exists for bookDB/patronDB
 */
ReturnBook::ReturnBook(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;
}

//---------------------------------------------------------------------------
/** ~ReturnBook()
 * Default Destructor
 *
 * Destroys this command
 * @pre None
 * @post Deallocates memory used by this command.
 */
ReturnBook::~ReturnBook()
{
    bookDB = nullptr;
    patronDB = nullptr;
}

//---------------------------------------------------------------------------
/** execute()
 * Execute ReturnBook Command
 *
 * Checks to see if the book and patron exist, and if the patron can
 * return the book. If so, the book has one copy returned to it and
 * the patron loses that copy.
 * @pre None
 * @post Book and Patron are updated accordingly, if everything was valid
 */
void ReturnBook::execute()
{
    Patron* patron = patronDB->getPatron(patronID);
    if (!patron) {
        cout << "ERROR: Couldn't find a patron with ID "
             << patronID << "." << endl;
        return;
    }

    Book* book = bookDB->getBook(bookID, true);
    if (!book) {
        cout << patron->getName() << " to return." << endl;
        return;
    }

    if (book->receiveBook(patron))
        patron->returnBook(book);
    else
        cout << "ERROR: " << patron->getName() << " cannot return \'"
             << book->getTitle() << "\'." << endl;
}

//---------------------------------------------------------------------------
/** create()
 * Create ReturnBook Command (factory)
 *
 * Creates a ReturnBook command that can be executed
 * @param parameters is a reference to the ifstream, starting immediately 
 * after the command code
 * @pre None
 * @post No changes, just returns the new command. Parameters will read up 
 * until and including the end-of-line character
 * @return returns the new executable command, or nullptr if the
 * parameters were invalid
 */
LibraryCommand* ReturnBook::create(stringstream& parameters) const
{
    ReturnBook* toReturn = new ReturnBook(bookDB, patronDB);
    parameters >> toReturn->patronID;
    parameters.get();
    getline(parameters, toReturn->bookID);

    if (toReturn->patronID.compare("9999") == 0) {
        delete toReturn;
        toReturn = nullptr;
        return nullptr;
    }

    return toReturn;
}