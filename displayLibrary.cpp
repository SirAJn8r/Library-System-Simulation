/** 
 * @file displayLibrary.h
 * @author Alex Lambert
 *
 * Description:
 *   - Displays all books in the library, sorted
 *
 * Assumptions/Implementation:
 *   - Inherits from Command interface
 *   - Doesn't need to use the patronDatabase
 */

#include "displayLibrary.h"

using namespace std;

//---------------------------------------------------------------------------
/** DisplayLibrary()
 * Default Constructor
 *
 * Constructs a base instance of the display library command. This 
 * instance must not be executed.
 * @param bookDB is the BookDatabase to be displayed
 * @pre None
 * @post DisplayLibrary command object exists for bookDB
 */
DisplayLibrary::DisplayLibrary(BookDatabase* bookDB)
{
    this->bookDB = bookDB;
}

//---------------------------------------------------------------------------
/** ~DisplayLibrary()
 * Default Destructor
 *
 * Destroys this command
 * @pre None
 * @post Deallocates memory used by this command.
 */
DisplayLibrary::~DisplayLibrary()
{
    bookDB = nullptr;
}

//---------------------------------------------------------------------------
/** execute()
 * Execute DisplayLibrary Command
 *
 * Prints all books in library in sorted order
 * @pre None
 * @post None. Library is unchanged
 */
void DisplayLibrary::execute()
{
    cout.setf(ios::left, ios::adjustfield);
    bookDB->displayAll();
}

//---------------------------------------------------------------------------
/** create()
 * Create DisplayLibrary Command (factory)
 *
 * Creates a DisplayLibrary command that can be executed
 * @param parameters is a reference to the ifstream, starting immediately 
 * after the command code
 * @pre None
 * @post No changes, just returns the new command. Parameters will read up 
 * until and including the end-of-line character
 * @return returns the new executable command, or nullptr if the
 * parameters were invalid
 */
LibraryCommand* DisplayLibrary::create(stringstream& parameters) const
{
    parameters.get();
    return new DisplayLibrary(bookDB);
}