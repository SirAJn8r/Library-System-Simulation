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

#ifndef DISPLAYPATRONHISTORY_H
#define DISPLAYPATRONHISTORY_H

#include "libraryCommand.h"
#include "patron.h"
#include "patronDatabase.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DisplayPatronHistory : public LibraryCommand {
public:
    //-----------------------------------------------------------------------
    /** DisplayPatronHistory()
     * Default Constructor
     *
     * Constructs a base instance of the DisplayPatronHistory command. This 
     * instance must not be executed.
     * @param patronDB is PatronDatabase to be searched for the patron.
     * @pre None
     * @post DisplayPatronHistory command object exists for patronDB
     */
    DisplayPatronHistory(PatronDatabase* patronDB);

    //-----------------------------------------------------------------------
    /** ~DisplayPatronHistory()
     * Default Destructor
     *
     * Destroys this command
     * @pre None
     * @post Deallocates memory used by this command.
     */
    virtual ~DisplayPatronHistory();

    //-----------------------------------------------------------------------
    /** execute()
     * Execute DisplayPatronHistory Command
     *
     * Prints all action history by the given patron, if it exists
     * @pre None
     * @post None. Patron is unchanged
     */
    virtual void execute();

    //-----------------------------------------------------------------------
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
    virtual LibraryCommand* create(stringstream& parameters) const;

protected:
    // ID of patron this command uses
    string patronID;
};

#endif