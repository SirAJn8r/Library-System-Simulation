/** 
 * @file librarycommand.h
 * @author Alex Lambert
 *
 * Description:
 *   - Class that encapsulates a variety of LibraryCommands that the library
 * manager can execute
 *   - LibraryCommands can execute on the provided book and patron databases
 *
 * Assumptions/Implementation:
 *   - This is an pure virtual abstract class, methods must be implemented in 
 * the child classes
 *   - The constructor for the children classes makes a base instance that
 * must not be executed. Use the base instance to create real instances using
 * the create() command.
 */

#ifndef LIBRARYCOMMAND_H
#define LIBRARYCOMMAND_H

#include "bookDatabase.h"
#include "patronDatabase.h"
#include <sstream>

class LibraryCommand {
public:
    //-----------------------------------------------------------------------
    /** ~LibraryCommand()
    * Default Destructor
    *
    * Destroys this command
    * @pre None
    * @post Deallocates memory used by this command.
    */
    virtual ~LibraryCommand();

    //-----------------------------------------------------------------------
    /** execute()
    * Execute LibraryCommand
    *
    * Executes this LibraryCommand object. This is pure virtual and must be
    * implemented in derived classes
    * @pre This command must have been made using the create command.
    * @post TBD
    */
    virtual void execute() = 0;

    //-----------------------------------------------------------------------
    /** create()
    * Create Library Command (factory)
    *
    * Create a library command of the same type as the LibraryCommand 
    * implementing this function.
    * @pre This command was built using valid constructor inputs.
    * @post A new library command exists if parameters worked.
    * @return Returns the new library commmand if it succeeded, else nullptr
    */
    virtual LibraryCommand* create(stringstream& parameters) const = 0;

protected:
    // pointer to BookDatabase that this command exists in
    BookDatabase* bookDB;
    // pointer to PatronDatabase that this command exists in
    PatronDatabase* patronDB;
};

#endif