/** 
 * @file BSTNode.h
 * @author Alex Lambert
 * 
 * Description:
 *   - BSTNode keeps a left and right branch, and holds a BSTData item
 *   - Meant to be used inside a Binary Search Tree
 *   - Includes no funcitons
 * 
 * Assumptions/Implementation:
 *   - Left BSTNode and right BSTNode default to 
 *   - When deleting, it deletes its left/right branches first
 */

#ifndef BSTNODE_H
#define BSTNODE_H

#include "BSTData.h"

using namespace std;

class BSTNode {
public:
    //-----------------------------------------------------------------------
    /** BSTNode()
     * Default Constructor
     *
     * Constructs an BSTNode containing data
     * @pre None
     * @post BSTNode is initialized with no left/right subtree
     */
    BSTNode(BSTData* data);

    //-----------------------------------------------------------------------
    /** ~BSTNode()
     * Default Destructor
     *
     * Destroys the BSTNode, its left/right subtrees, and its data item
     * @pre None
     * @post All memory used by the BSTNode and its parts is deallocated
     */
    virtual ~BSTNode();

    // Pointer to left branch
    BSTNode* left;

    // Pointer to right branch
    BSTNode* right;

    // Pointer to the data object
    BSTData* data;
};

#endif