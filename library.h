/** @file bookDatabase.h
 *  @author Mogul Solutions
 *
 * Description:
 *      Library class is an object that includes pointers to both the patron and
 *      the book database. The class processes all of the commands that are come
 *      from an input data stream
 *   
 *
 */

#include "bookDatabase.h"
#include "commandFactory.h"
#include "commandQueue.h"
#include "patronDatabase.h"
#include <fstream>

class Library {

public:
    // -------------------------------------------------------------------------
    /** Library()
    * Default Constructor
    *
    * Constructs a Library object with default values for the patron database
    * 
    * 
    * @pre None.
    * @post Library object exists
    */
    Library(BookDatabase* bookDB, PatronDatabase* patronDB);

    virtual ~Library();

    // -------------------------------------------------------------------------
    /** processComands()
    *
    * This method is responsible for processing all of the library commands that
    * are provided by the ifstream
    * 
    * @pre None.
    * @param ifstream an input file stream
    *                 a stream of data used for reading input from a file
    * @post commands are executed based on the parameter
    */
    void processCommands(ifstream& commandFile);

private:
    //this member class is the d-base that holds all of the books for library
    BookDatabase* bookDB;
    //this memebr class is the d-base that holds all of the patrons for library
    PatronDatabase* patronDB;
};