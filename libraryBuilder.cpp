/**
 * @file libraryBuilder.h
 * @author Alex Lambert
 *
 * Description:
 *   - A LibraryBuilder object represents the builder class that creates
 * and fills up a Library object with books and patrons.
 *   - Can handle new books or book types added to the library in the future
 *
 * Assumptions/Implementation:
 *   - This is a builder class following the builder design pattern
 *   - It contains one function that initializes all library data into
 * the book database and patron database using ifstream as inputs from files
 *   - The 2 ifstreams must be properly formatted of course
 * 
 * Note:
 *   - The builder design pattern is used to create complex objects, 
 * especially when done so from a file. This allows flexibility if later 
 * there is another way to represent the data, or if more databases or 
 * added, or other modifications to the libraty.
 */

#include "libraryBuilder.h"

using namespace std;

//---------------------------------------------------------------------------
/** LibraryBuilder()
 * Default Constructor
 *
 * Creates a library builder instance
 * @pre None.
 * @post None.
 */
LibraryBuilder::LibraryBuilder() { }

//---------------------------------------------------------------------------
/** ~LibraryBuilder()
 * Default Destructor
 *
 * Destroys the library builder instance
 * @pre None.
 * @post Deallocates the memory in the library builder
 */
LibraryBuilder::~LibraryBuilder() { }

//---------------------------------------------------------------------------
/** createLibrary()
 * Builder Function
 *
 * Creates a Library object by initializing one and returning it. It
 * requires file input formatted in a specific format to parse and read
 * data from the file. Initializes the Library object through filling up
 * the BookDatabase and PatronDatabase associated with the Library.
 * @param books is an input file stream of the books to be in the library
 * @param patrons is an input file stream of the patrons to be in the
 * library
 * @pre books and patrons must be properly formatted
 * @post Creates and initializes a library, then returns it
 * @return Returns the initialed filled library
 */
Library* LibraryBuilder::createLibrary(ifstream& books, ifstream& patrons)
{
    BookDatabase* bookDB = new BookDatabase();
    PatronDatabase* patronDB = new PatronDatabase();
    string readString;

    while (!books.eof()) {
        getline(books, readString);
        if (readString.length() == 0)
            break;

        bookDB->insertBook(readString);
    }

    while (!patrons.eof()) {
        getline(patrons, readString);
        if (readString.length() == 0)
            break;

        patronDB->insertPatron(readString);
    }

    return new Library(bookDB, patronDB);
}