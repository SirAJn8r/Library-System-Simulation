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

#include "BSTree.h"

using namespace std;

//---------------------------------------------------------------------------
/** BSTree()
 * Default Constructor
 * 
 * Creates an empty BSTree
 * @pre None.
 * @post BSTree object exists with no values contained
 */
BSTree::BSTree()
{
    bstRoot = nullptr;
}

//---------------------------------------------------------------------------
/** ~BSTree()
 * Default Destructor
 * 
 * Destroys the BSTree
 * @pre None.
 * @post Deallocates all memory in the BSTree and its object references
 */
BSTree::~BSTree()
{
    clear();
}

//---------------------------------------------------------------------------
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
bool BSTree::insert(BSTData* data)
{
    if (data == nullptr)
        return false;

    if (bstRoot == nullptr) {
        bstRoot = new BSTNode(data);
        return true;
    }

    BSTNode* curr = bstRoot;
    return insertHelper(curr, data);
}

//---------------------------------------------------------------------------
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
bool BSTree::insertHelper(BSTNode*& curr, BSTData* data)
{
    // If the desired slot is available, put the data in there
    if (curr == nullptr) {
        curr = new BSTNode(data);
        return true;
    }

    // If the data is already in the tree, fail
    if (*(curr->data) == *data)
        return false;

    // If data is smaller, go left. Otherwise go right
    if (*data < *curr->data)
        return insertHelper(curr->left, data);
    else
        return insertHelper(curr->right, data);
}

//---------------------------------------------------------------------------
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
BSTData* BSTree::retrieve(const BSTData* dataCopy) const
{
    if (dataCopy == nullptr)
        return nullptr;

    return retrieveHelper(bstRoot, dataCopy);
}

//---------------------------------------------------------------------------
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
BSTData* BSTree::retrieveHelper(BSTNode* curr, const BSTData* dataCopy) const
{
    // If in a dead end, the data isn't in the tree
    if (curr == nullptr)
        return nullptr;

    // If the data is found, return it
    if (*curr->data == *dataCopy)
        return curr->data;

    // If dataCopy is smaller, go left. Otherwise go right
    if (*dataCopy < *curr->data)
        return retrieveHelper(curr->left, dataCopy);
    else
        return retrieveHelper(curr->right, dataCopy);
}

//---------------------------------------------------------------------------
/** clear()
 * BSTree Clear Function
 * 
 * Clears the current BSTree of all its nodes making it empty
 * @pre None.
 * @post the BSTree is empty, root is set to nullptr, all destroyed 
 * objects are deallocated and returned to memory.
 */
void BSTree::clear()
{
    if (bstRoot)
        delete bstRoot;
    bstRoot = nullptr;
}

//---------------------------------------------------------------------------
/** displayAll()
 * BSTree Display All Function
 * 
 * Calls display() on all BSTData objects inside the BSTree in-order
 * @pre None.
 * @post None.
 */
void BSTree::displayAll() const
{
    cout << endl;
    displayAllHelper(bstRoot);
}

//---------------------------------------------------------------------------
/** displayAllHelper()
 * BSTree Display All Helper Function
 * 
 * Calls display() on all BSTData objects inside the BSTree in-order
 * @param curr is the current BSTNode in the recursive function
 * @pre curr is initially root
 * @post None.
 */
void BSTree::displayAllHelper(const BSTNode* curr) const
{
    if (curr == nullptr)
        return;

    displayAllHelper(curr->left);
    curr->data->display();
    displayAllHelper(curr->right);
}