/** @file BSTree.h
 *  @author Joseph Collora
 * 
 *  Description:
 *  - A binary search tree that exists as a contains BSTData type objects
 *  - Can be used to insert objects into itself
 *  - Can be cleared of all nodes and object
 *  - Can retrieve a pointer to a designated item in the structure
 * 
 *  Assumptions/Implementation:
 *  - Each binary tree stores one concrete type of item at a time for
 *  comparison (e.g. exclusively fiction books, or exclusively patrons)
 *  - Uses a linked list binary search tree to store the values, containing a
 *  reference to the root node.
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
     * @pre data isn't a nullptr.
     * @post data was inserted into the BSTree if the return value is true
     * @return returns true if data exists and no duplicate is found making a
     * successful insert, false otherwise
     */
    bool insert(BSTData* data);

    // Temp function for testing, will be deleted
    bool insert();

    //-----------------------------------------------------------------------
    /** retrieve()
     * BSTree Retrieve Function
     * 
     * Retrieves and returns the BSTData that has the same values as dataCopy
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
     * Finds the location to place
     * @pre None.
     * @post None.
     */
    bool insertHelper(BSTNode*& curr, BSTData* data);

    //-----------------------------------------------------------------------
    /** retrieveHelper()
     * BSTree Retrieve Helper Function
     * 
     * Calls display() on all BSTData objects inside the BSTree in-order
     * @pre None.
     * @post None.
     */
    BSTData* retrieveHelper(BSTNode* curr, const BSTData* dataCopy) const;

    //-----------------------------------------------------------------------
    /** displayAllHelper()
     * BSTree Display All Helper Function
     * 
     * Calls display() on all BSTData objects inside the BSTree in-order
     * @pre None.
     * @post None.
     */
    void displayAllHelper(const BSTNode* curr) const;

    // root of the Binary Search Tree
    BSTNode* bstRoot;
};

#endif