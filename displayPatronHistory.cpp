/** 
 * @file displayPatronHistory.h
 * @author Alex Lambert
 *
 * Description:
 *   - Displays a patron's action history
 *
 * Assumption/Implementation:
 *   - Inherits from Command interface.
 *   - Doesn't need to use the bookDatabase
 */

#include "displayPatronHistory.h"

using namespace std;

//---------------------------------------------------------------------------
/** DisplayPatronHistory()
 * Default Constructor
 *
 * Constructs a base instance of the DisplayPatronHistory command. This 
 * instance must not be executed.
 * @param patronDB is PatronDatabase to be searched for the patron.
 * @pre None
 * @post DisplayPatronHistory command object exists for patronDB
 */
DisplayPatronHistory::DisplayPatronHistory(PatronDatabase* patronDB)
{
    this->patronDB = patronDB;
}

//---------------------------------------------------------------------------
/** ~DisplayPatronHistory()
 * Default Destructor
 *
 * Destroys this command
 * @pre None
 * @post Deallocates memory used by this command.
 */
DisplayPatronHistory::~DisplayPatronHistory()
{
    patronDB = nullptr;
}

//---------------------------------------------------------------------------
/** execute()
 * Execute DisplayPatronHistory Command
 *
 * Prints all action history by the given patron, if it exists
 * @pre None
 * @post None. Patron is unchanged
 */
void DisplayPatronHistory::execute()
{
    Patron* dispPatron = patronDB->getPatron(patronID);

    if (dispPatron) {
        cout.setf(ios::left, ios::adjustfield);
        dispPatron->display();
        dispPatron = nullptr;
    } else {
        cout << "Couldn't find a patron with ID "
             << patronID << "." << endl;
    }
}

//---------------------------------------------------------------------------
/** create()
 * Create DisplayPatronHistory Command (factory)
 *
 * Creates a DisplayPatronHistory command that can be executed
 * @param parameters is a reference to the ifstream, starting immediately 
 * after the command code
 * @pre None
 * @post No changes, just returns the new command. Parameters will read up 
 * until and including the end-of-line character
 * @return returns the new executable command, or nullptr if the
 * parameters were invalid
 */
LibraryCommand* DisplayPatronHistory::create(stringstream& parameters) const
{
    DisplayPatronHistory* toReturn = new DisplayPatronHistory(patronDB);
    parameters >> toReturn->patronID;
    parameters.get();

    if (toReturn->patronID.compare("9999") != 0)
        return toReturn;

    delete toReturn;
    return nullptr;
}