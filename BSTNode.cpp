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
#include "BSTNode.h"

//---------------------------------------------------------------------------
/** BSTNode()
 * Default Constructor
 *
 * Constructs an BSTNode containing data
 * @pre None
 * @post BSTNode is initialized with no left/right subtree
 */
BSTNode::BSTNode(BSTData* data)
{
    left = nullptr;
    right = nullptr;
    this->data = data;
}

//---------------------------------------------------------------------------
/** ~BSTNode()
 * Default Destructor
 *
 * Destroys the BSTNode, its left/right subtrees, and its data item
 * @pre None
 * @post All memory used by the BSTNode and its parts is deallocated
 */
BSTNode::~BSTNode()
{
    if (left)
        delete left;
    left = nullptr;

    if (right)
        delete right;
    right = nullptr;

    if (data)
        delete data;
    data = nullptr;
}