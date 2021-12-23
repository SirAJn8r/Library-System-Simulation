/** 
 * @file patronDatabase.h
 * @author Alex Lambert
 *
 * Description:
 *   - PatronDatabase holds all of the patrons for a library
 *   - It can retrieve patrons and insert patrons
 *   - There is no functionality for removing patrons from the database
 *
 * Assumptions/Implementation:
 *   - Creates patrons based on the string, which can only have 1 format
 *   - Uses a BSTree to store the patrons
 */

#ifndef PATRONDATABASE_H
#define PATRONDATABASE_H

#include "BSTree.h"
#include "patron.h"
#include <iostream>
#include <sstream>
#include <string>

class PatronDatabase {
public:
    //-----------------------------------------------------------------------
    /** PatronDatabase()
     * Default Constructor
     *
     * Constructs an empty PatronDatabase
     * @pre None
     * @post PatronDatabase is initialized with a BSTree for Patrons
     */
    PatronDatabase();

    //-----------------------------------------------------------------------
    /** ~PatronDatabase()
     * Default Destructor
     *
     * Destroys the PatronDatabase and every item inside it
     * @pre None
     * @post All memory used by the PatronDatabase and its parts is
     * deallocated
    */
    virtual ~PatronDatabase();

    //-----------------------------------------------------------------------
    /** insertPatron()
     * Insert Patron Function
     *
     * Inserts the given Patron into the BSTree
     * @param patronInfo is a string holding the new patron's ID and name
     * @pre patronInfo is properly formatted
     * @post the new patron is added, if the Patron is valid
     * @return if the patron was successfully inserted
     */
    bool insertPatron(string patronInfo);

    //-----------------------------------------------------------------------
    /** getPatron()
     * Get Patron Function
     * 
     * Return a Patron object based on the information that is passed in if 
     * it is in a BSTree
     * @param patronInfo is a string holding the patron's ID that you're 
     * searching for
     * @pre patronInfo is properly formatted
     * @post None. No changes made
     * @return Pointer to the Patron object that they are looking for, if it
     * wasn't found, returns nullptr.
     */
    Patron* getPatron(string patronInfo) const;

private:
    //-----------------------------------------------------------------------
    /** createPatron()
     * Create Patron Function
     * 
     * Creates a patron based on patronInfo
     * @param patronInfo is a string holding the patron's ID and name
     * @pre patronInfo is properly formatted
     * @post None
     * @return Pointer to the new Patron, or nullptr if it was invalid
     */
    Patron* createPatron(string patronInfo) const;

    // BSTree that holds all the patrons
    BSTree* patronBST;
};

#endif