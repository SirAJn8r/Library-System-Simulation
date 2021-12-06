/** @file displayPatronHistory.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Command for library manager. displays patron's book history
 *
 * Implementation
 *   - inherits from Command interface.
 *   - displays patron book history
 */

#ifndef DISPLAYPATRONHISTORY_H
#define DISPLAYPATRONHISTORY_H

#include "libraryCommand.h"
#include "patron.h"
#include "patronDatabase.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class DisplayPatronHistory : public LibraryCommand {
public:
    // -------------------------------------------------------------------------
    /** DisplayPatronHistory()
    * Default Constructor
    *
    * Constructs a display patron book history command object with default
    * values
    * @pre None.
    * @post DisplayPatronHistory command object exists
    */
    DisplayPatronHistory(PatronDatabase* patronDB);

    virtual ~DisplayPatronHistory();

    // -------------------------------------------------------------------------
    /** execute()
    * Execute display patron history command
    *
    * Prints patron history
    * @pre The patron should exist in the system
    * @post None. patron is unchanged
    */
    virtual void execute();

    /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
    virtual LibraryCommand* create(ifstream& parameters) const;

protected:
    // ID of patron this command uses
    string patronID;
};

#endif