/**
 * @file commandFactory.h
 * @author Alex Lambert
 *
 * Description:
 *   - Uses an input stream to read text and create commands based off it
 *   - The factory is associated with a BookDatabase and a PatronDatabase
 * which the commands are made for
 *   - Returns a CommandQueue containing all the commands generated
 *
 * Assumptions/Implementation:
 *   - If the factory is destroyed, nothing else is deleted with it
 *   - Fetches the command to be made using CommandTypeHashmap
 *   - Delegates initializing a command to the command object.
 */

#include "commandFactory.h"

//---------------------------------------------------------------------------
/** CommandFactory()
 * Default Constructor
 *
 * Builds a CommandFactory for the inputted bookDB and patronDB
 * @param bookDB The BookDatabase to create commands for.
 * @param patronDB The PatronDatabase to create commands for.
 * @pre bookDB and patronDB must be for the same library.
 * @post Stores private pointer to the bookDB and patronDB
 */
CommandFactory::CommandFactory(BookDatabase* bookDB, PatronDatabase* patronDB)
{
    this->bookDB = bookDB;
    this->patronDB = patronDB;

    baseCommands[0] = new CheckoutBook(bookDB, patronDB);
    baseCommands[1] = new ReturnBook(bookDB, patronDB);
    baseCommands[2] = new DisplayPatronHistory(patronDB);
    baseCommands[3] = new DisplayLibrary(bookDB);
}

//---------------------------------------------------------------------------
/** ~CommandFactory()
 * Default Destructor
 *
 * Destroys the CommandFactory
 * @pre None
 * @post Returns CommandFactory to memory, nothing else
 */
CommandFactory::~CommandFactory()
{
    for (int i = 0; i < NUM_COMMAND_TYPES; i++) {
        delete baseCommands[i];
        baseCommands[i] = nullptr;
    }

    bookDB = nullptr;
    patronDB = nullptr;
}

//---------------------------------------------------------------------------
/** createCommands()
 * Create Commands
 *
 * Reads the file, creating LibraryCommands and storing them into a 
 * CommandQueue
 * @param commandfile is an input file containing a list of commands
 * @pre commandFile must be properly formatted
 * @post CommandQueue is initialized and filled. Library unchanged
 * @return A filled CommandQueue object
 */
CommandQueue* CommandFactory::createCommands(ifstream& commandFile)
{
    char type;
    LibraryCommand* commandMaker = nullptr;
    LibraryCommand* next = nullptr;
    CommandQueue* queue = new CommandQueue();

    while (!commandFile.eof()) {
        string currLine;
        getline(commandFile, currLine);

        if (currLine.length() == 0)
            break;

        stringstream currLineStream(currLine);
        type = '#';
        currLineStream >> type;
        commandMaker = getCommand(type);

        // If the command type is valid
        if (commandMaker) {
            next = commandMaker->create(currLineStream);
            commandMaker = nullptr;

            // If a command was successfully created
            if (next) {
                queue->enqueue(next);
                next = nullptr;
            }
        }
    }

    return queue;
}

//---------------------------------------------------------------------------
/** getCommand()
 * Get Base Command Object
 *
 * Returns the base command indicated by the type given
 * @param type A 1 capital character string indicating the type of command
 * @pre None
 * @post Returns the respective baseCommand, no changes
 * @return The library command if type was valid, or nullptr otherwise
 */
LibraryCommand* CommandFactory::getCommand(char type) const
{
    int ID = int(type) - 65;
    if (ID < 0 || ID >= 26 || commandIDs[ID] == -1) {
        cout << "ERROR: \'" << type << "\' is not a valid command type."
             << endl;
        return nullptr;
    }
    return baseCommands[commandIDs[ID]];
}