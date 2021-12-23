/** 
 * @file children.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A children book type
 *
 * Assumptions/Implementation:
 *   - Implements the pure virtual comparison functions from Book and BSTData
 */

#include "children.h"

using namespace std;

//---------------------------------------------------------------------------
/** Children()
 * Default constructor
 *
 * Creates an unusable base instance of a children's book
 * @pre None
 * @post Children book object exists with no values
 */
Children::Children()
{
    maxCount = 5;
    count = 5;
    month = -1;
    checkouts = new Patron*[maxCount];
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
}

//---------------------------------------------------------------------------
/** ~Children()
 * Default destructor
 *
 * Destroys the children book
 * @pre None.
 * @post All memory for the children book is deallocated
 */
Children::~Children()
{
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;

    delete[] checkouts;
    checkouts = nullptr;
}

//---------------------------------------------------------------------------
/** display()
 * Display book information
 *
 * Display book information in easy-to-read columns.
 * Displayed in order: count, title, author, year
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 */
void Children::display() const
{
    cout << setw(AVAIL_OUTPUT_WIDTH) << count
         << setw(TITLE_MAX_LENGTH + 2)
         << title.substr(0, TITLE_MAX_LENGTH)
         << setw(AUTHOR_MAX_LENGTH + 2)
         << author.substr(0, AUTHOR_MAX_LENGTH)
         << setw(YEAR_OUTPUT_WIDTH) << year << endl;
}

//---------------------------------------------------------------------------
/** displayForPatron()
 * Display book information
 *
 * Display book information in easy-to-read columns for patron history
 * Displayed in order: title, author, year
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 */
void Children::displayForPatron() const
{
    cout << setw(ALT_TITLE_MAX_LENGTH + 2)
         << title.substr(0, ALT_TITLE_MAX_LENGTH)
         << setw(ALT_AUTHOR_MAX_LENGTH + 2)
         << author.substr(0, ALT_AUTHOR_MAX_LENGTH)
         << setw(YEAR_OUTPUT_WIDTH) << year << endl;
}

//---------------------------------------------------------------------------
/** create()
 * Create Children's Book
 *
 * Creates a book based on bookString
 * @param bookString stores the info about the book to be fetched
 * @param altString represents if the book string is formatted in the
 * normal or alternative format
 * @pre bookString is properly formatted as per the formatting type
 * @post None. No changes made.
 * @return Book pointer to the new book, nullptr if it failed
 */
Book* Children::create(stringstream& parameters, bool altString) const
{
    Children* toReturn = new Children();

    if (!altString) {
        getline(parameters, toReturn->author, ',');

        parameters.get();
        getline(parameters, toReturn->title, ',');

        parameters.get();
        parameters >> toReturn->year;

    } else {
        getline(parameters, toReturn->title, ',');

        parameters.get();
        getline(parameters, toReturn->author, ',');

        toReturn->year = -1;
    }

    return toReturn;
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
int Children::getComp(const BSTData& rhs) const
{
    const Children* childrenRhs = (const Children*)&rhs;

    int comp = title.compare(childrenRhs->title);
    if (comp == 0)
        comp = author.compare(childrenRhs->author);

    return comp;
}