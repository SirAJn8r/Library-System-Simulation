/** 
 * @file patron.h
 * @author Alex Lambert
 *
 * Description:
 *   - Patrons have an ID, a name, and can have books checked out to them
 *   - Has few functions, primarily controlling their history
 *
 * Implementation/Assumptions:
 *   - Implements the BSTData interface
 *   - Compare to each other using ID, name is irrelevant
 */

#include "patron.h"

using namespace std;

//---------------------------------------------------------------------------
/** Patron()
 * Default Constructor
 *
 * Creates a new patron object 
 * @pre None.
 * @post Patron object exists with the given ID and name
 */
Patron::Patron(int ID, string name)
{
    this->ID = ID;
    this->name = name;
    history = new list<pastAction>;
}

//---------------------------------------------------------------------------
/** ~Patron()
 * Default Destructor
 *
 * Destroys the patron object 
 * @pre None.
 * @post Deallocates all memory in this patron
 */
Patron::~Patron()
{
    delete history;
    history = nullptr;
}

//---------------------------------------------------------------------------
/** addBook()
 * Check Out Book
 *
 * Checks out a book to the patron
 * @param book is the book the Patron is checking out
 * @pre The book can and has been checked out to the Patron
 * @post History will include this checkout
 */
void Patron::addBook(Book* book)
{
    pastAction newAction;
    newAction.action = "CheckOut ";
    newAction.book = book;

    history->push_back(newAction);
}

//---------------------------------------------------------------------------
/** returnBook()
 * Return Book 
 *
 * Returns the book from the patron 
 * @param book is the book the Patron is return
 * @pre The book can and has been returned by the Patron
 * @post History will include this return
 */
void Patron::returnBook(Book* book)
{
    pastAction newAction;
    newAction.action = "Return   ";
    newAction.book = book;

    history->push_back(newAction);
}

//---------------------------------------------------------------------------
/** display()
 * Display Patron Information
 *
 * Display patron information / history in easy-to-read columns.
 * @pre None.
 * @post None. const function
 */
void Patron::display() const
{
    cout << endl;
    cout << ID << "  " << name << ":" << endl;

    for (list<pastAction>::iterator next = history->begin();
         next != history->end(); next++) {
        cout << (*next).action;
        (*next).book->displayForPatron();
    }
}

//---------------------------------------------------------------------------
/** getName()
 * Get Name
 *
 * Return the name of the patron
 * @pre None.
 * @post None. const function
 * @return the name variable
 */
string Patron::getName() const
{
    return name;
}

//---------------------------------------------------------------------------
/** getComp()
 * Get Comparison
 * 
 * Returns the comparison value of this and rhs
 * @pre Both items are of the same type
 * @post None, no changes
 * @return -1 if this is smaller, 0 if equivalent, 1 is this is bigger
 */
int Patron::getComp(const BSTData& rhs) const
{
    return ID - ((Patron*)&rhs)->ID;
}