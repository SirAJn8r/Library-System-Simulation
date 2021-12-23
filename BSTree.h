/** 
 * @file BSTree.h
 * @author Alex Lambert
 * 
 * Description:
 *   - Is a binary search tree of BSTData type objects
 *   - Can be used to insert objects into itself
 *   - Can be cleared of all nodes and object
 *   - Can retrieve a pointer to a designated item in the structure
 * 
 * Assumptions/Implementation:
 *   - Each binary tree must store only one concrete type of item at a time
 * for comparison (e.g. exclusively fiction books, or exclusively patrons)
 *   - Uses linked BSTNodes to store the values in the tree
 */

#ifndef BSTree_H
#define BSTree_H

#include "BSTData.h"
#include "BSTNode.h"
#include <iostream>
#include <string>

using namespace std;

class BSTree {
public:
    //-----------------------------------------------------------------------
    /** BSTree()
     * Default Constructor
     * 
     * Creates an empty BSTree
     * @pre None.
     * @post BSTree object exists with no values contained
     */
    BSTree();

    //-----------------------------------------------------------------------
    /** ~BSTree()
     * Default Destructor
     * 
     * Destroys the BSTree
     * @pre None.
     * @post Deallocates all memory in the BSTree and its object references
     */
    virtual ~BSTree();

    //-----------------------------------------------------------------------
    /** insert()
     * BSTree Insert Function
     * 
     * Inserts given object into the current instance of BSTree, returning a
     * bool value indicating the success of the insert
     * @param data is the new item to be stored
     * @pre data isn't a nullptr.
     * @post data was inserted into the BSTree if the return value is true
     * @return returns true if data exists and no duplicate is found making a
     * successful insert, false otherwise
     */
    bool insert(BSTData* data);

    //-----------------------------------------------------------------------
    /** retrieve()
     * BSTree Retrieve Function
     * 
     * Retrieves and returns the BSTData that has the same values as dataCopy
     * @param dataCopy is an item that returns 0 when compared (getComp) to
     * the BSTData object to be searched for 
     * @pre dataCopy isn't a nullptr.
     * @post None.
     * @return Returns a pointer to the BSTData equivalent to dataCopy, or
     * nullptr if it doesn't exist.
     */
    BSTData* retrieve(const BSTData* dataCopy) const;

    //-----------------------------------------------------------------------
    /** clear()
     * BSTree Clear Function
     * 
     * Clears the current BSTree of all its nodes making it empty
     * @pre None.
     * @post the BSTree is empty, root is set to nullptr, all destroyed 
     * objects are deallocated and returned to memory.
     */
    void clear();

    //-----------------------------------------------------------------------
    /** displayAll()
     * BSTree Display All Function
     * 
     * Calls display() on all BSTData objects inside the BSTree in-order
     * @pre None.
     * @post None.
     */
    void displayAll() const;

private:
    //-----------------------------------------------------------------------
    /** insertHelper()
     * BSTree Insert Helper Function
     * 
     * Finds the location to place the new data item, then does so
     * @param curr is the current spot in the BSTree to find space for data
     * @param data is the item to be inserted
     * @pre curr is initialy root, data isn't a nullptr
     * @post If data isn't already in the BSTree, it will be inserted into
     * its spot in the BSTree
     * @return if the data was successfully inserted
     */
    bool insertHelper(BSTNode*& curr, BSTData* data);

    //-----------------------------------------------------------------------
    /** retrieveHelper()
     * BSTree Retrieve Helper Function
     * 
     * Searches the BSTree for where dataCopy should be placed, trying to 
     * find if there is a BSTData equivalent to it, then returning that.
     * @param curr is the current spot in the BSTree to look for BSTData
     * @param dataCopy is its own BSTData object that is equivalent to the 
     * BSTData object retrieve is searching for
     * @pre curr is initially root, dataCopy isn't a nullptr
     * @post None, no changes made.
     * @return the BSTData object equivalent to dataCopy, nullptr if it 
     * isn't found
     */
    BSTData* retrieveHelper(BSTNode* curr, const BSTData* dataCopy) const;

    //-----------------------------------------------------------------------
    /** displayAllHelper()
     * BSTree Display All Helper Function
     * 
     * Calls display() on all BSTData objects inside the BSTree in-order
     * @param curr is the current BSTNode in the recursive function
     * @pre curr is initially root
     * @post None.
     */
    void displayAllHelper(const BSTNode* curr) const;

    // root of the Binary Search Tree
    BSTNode* bstRoot;
};

#endif