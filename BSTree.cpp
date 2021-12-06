#include "BSTree.h"

using namespace std;

BSTree::BSTree()
{
    bstRoot = nullptr;
}

BSTree::~BSTree()
{
    clear();
}

bool BSTree::insert()
{
    cout << "vv" << endl;

    BSTNode* temp = nullptr;
    cout << " " << temp << endl;

    //bstRoot is a class variable BSTNode* (prints P7BSTNode before demangled)
    cout << " " << typeid(bstRoot).name() << endl;

    cout << "Address of bstRoot pointer " << &bstRoot << endl;
    cout << "Address of temp pointer " << &temp << endl;

    // segmentation fault happens if I try to read bstRoot, such as below
    if (bstRoot == nullptr)
        return true;

    // segmentation fault happens if I try to write bstRoot, such as below
    bstRoot = nullptr;

    // But no error happens when any of this is done inside the Constructor

    cout << "^^" << endl;

    return false;
}

bool BSTree::insert(BSTData* data)
{
    insert();

    cout << " " << endl;
    cout << "1" << endl;
    cout << " " << endl;

    if (data == nullptr)
        return false;

    cout << " " << endl;
    cout << "2" << endl;
    cout << " " << endl;

    if (bstRoot == nullptr) {

        cout << " " << endl;
        cout << "2.5" << endl;
        cout << " " << endl;
        bstRoot = new BSTNode(data);

        cout << " " << endl;
        cout << "2.7" << endl;
        cout << " " << endl;
        return true;
    }

    cout << " " << endl;
    cout << "3" << endl;
    cout << " " << endl;

    BSTNode* curr = bstRoot;
    return insertHelper(curr, data);
}

bool BSTree::insertHelper(BSTNode*& curr, BSTData* data)
{
    cout << " " << endl;
    cout << "4" << endl;
    cout << " " << endl;

    // If the desired slot is available, put the data in there
    if (curr = nullptr) {
        curr = new BSTNode(data);
        return true;
    }

    cout << " " << endl;
    cout << "5" << endl;
    cout << " " << endl;

    // If the data is already in the tree, fail
    if (*(curr->data) == *data) {

        cout << " " << endl;
        cout << "5.5" << endl;
        cout << " " << endl;

        return false;
    }

    cout << " " << endl;
    cout << "6" << endl;
    cout << " " << endl;

    // If data is smaller, go left. Otherwise go right
    if (*data < *curr->data)
        curr = curr->left;
    else
        curr = curr->right;

    cout << " " << endl;
    cout << "7" << endl;
    cout << " " << endl;

    return insertHelper(curr, data);
}

BSTData* BSTree::retrieve(const BSTData* dataCopy) const
{
    if (dataCopy == nullptr)
        return nullptr;

    return retrieveHelper(bstRoot, dataCopy);
}

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

void BSTree::clear()
{
    if (bstRoot)
        delete bstRoot;
    bstRoot = nullptr;
}

void BSTree::displayAll() const
{
    displayAllHelper(bstRoot);
}

void BSTree::displayAllHelper(const BSTNode* curr) const
{
    if (curr == nullptr)
        return;

    displayAllHelper(curr->left);
    curr->data->display();
    displayAllHelper(curr->right);
}