/** 
 * @file librarycommand.h
 * @author Alex Lambert
 *
 * Description:
 *   - Class that encapsulates a variety of LibraryCommands that the 
 * library manager can execute
 *   - LibraryCommands can execute on the provided book and patron databases
 *
 * Assumptions/Implementation:
 *   - This is an pure virtual abstract class, methods must be implemented 
 * in the child classes
 *   - The constructor for the children classes makes a base instance that
 * must not be executed. Use the base instance to create real instances 
 * using the create() command.
 */

#include "libraryCommand.h"

//---------------------------------------------------------------------------
/** ~LibraryCommand()
 * Default Destructor
 *
 * Destroys this command
 * @pre None
 * @post Deallocates memory used by this command.
 */
LibraryCommand::~LibraryCommand() { }