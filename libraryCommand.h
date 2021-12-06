/** @file librarycommand.h
 * @author Josh Helzerman
 *
 * Description:
 *   - Class that encapsulates a variety of LibraryCommands that the library
 * manager can execute
 *
 * Implementation:
 *   - this is an abstract class and must be implemented in the child classes
 *   - this class is similar to an interface in Java
 *
 */

#ifndef LIBRARYCOMMAND_H
#define LIBRARYCOMMAND_H

#include "bookDatabase.h"
#include "patronDatabase.h"
#include <fstream>

class LibraryCommand {
public:
    //virtual ~LibraryCommand();

    // -------------------------------------------------------------------------
    /** execute()
    * Execute LibraryCommand
    *
    * Executes this LibraryCommand object. This is pure virtual and must be
    * implemented in derived classes
    * @pre TBD
    * @post TBD
    */
    virtual void execute() = 0;

    /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the appropriate type
    * this function is pure virtual
    * @pre None
    * @post a new library command exists
    */
    virtual LibraryCommand* create(ifstream& parameters) const = 0;

protected:
    // pointer to library object that this command exists in
    BookDatabase* bookDB;
    PatronDatabase* patronDB;
};

#endif