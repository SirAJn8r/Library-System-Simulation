/** 
 * @file fiction.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A Fiction book type
 *
 * Assumptions/Implementation:
 *   - Implements the pure virtual comparison functions from Book and BSTData
 */

#include "fiction.h"

using namespace std;

//---------------------------------------------------------------------------
/** Fiction()
 * Default constructor
 *
 * Creates an unusable base instance of a fiction book
 * @pre None
 * @post Fiction book object exists with no values
 */
Fiction::Fiction()
{
    maxCount = 5;
    count = 5;
    month = -1;
    checkouts = new Patron*[maxCount];
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
}

//---------------------------------------------------------------------------
/** ~Fiction()
 * Default destructor
 *
 * Destroys the fiction book
 * @pre None.
 * @post All memory for the fiction book is deallocated
 */
Fiction::~Fiction()
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
 * Displayed in order: count, author, title, year
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 * @return String representing book data
 */
void Fiction::display() const
{
    cout << setw(AVAIL_OUTPUT_WIDTH) << count
         << setw(AUTHOR_MAX_LENGTH + 2)
         << author.substr(0, AUTHOR_MAX_LENGTH)
         << setw(TITLE_MAX_LENGTH + 2)
         << title.substr(0, TITLE_MAX_LENGTH)
         << setw(YEAR_OUTPUT_WIDTH) << year << endl;
}

//---------------------------------------------------------------------------
/** displayForPatron()
 * Display book information
 *
 * Display book information in easy-to-read columns for patron history
 * Displayed in order: author, title, year
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 */
void Fiction::displayForPatron() const
{
    cout << setw(ALT_AUTHOR_MAX_LENGTH + 2)
         << author.substr(0, ALT_AUTHOR_MAX_LENGTH)
         << setw(ALT_TITLE_MAX_LENGTH + 2)
         << title.substr(0, ALT_TITLE_MAX_LENGTH)
         << setw(YEAR_OUTPUT_WIDTH) << year << endl;
}

//---------------------------------------------------------------------------
/** create()
 * Create Fiction Book
 *
 * Creates a book based on bookString
 * @param bookString stores the info about the book to be fetched
 * @param altString represents if the book string is formatted in the
 * normal or alternative format
 * @pre bookString is properly formatted as per the formatting type
 * @post None. No changes made.
 * @return Book pointer to the new book, nullptr if it failed
 */
Book* Fiction::create(stringstream& parameters, bool altString) const
{
    Fiction* toReturn = new Fiction();

    if (!altString) {
        getline(parameters, toReturn->author, ',');

        parameters.get();
        getline(parameters, toReturn->title, ',');

        parameters.get();
        parameters >> toReturn->year;

    } else {
        getline(parameters, toReturn->author, ',');

        parameters.get();
        getline(parameters, toReturn->title, ',');

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
int Fiction::getComp(const BSTData& rhs) const
{
    const Fiction* fictionRhs = (const Fiction*)&rhs;

    int comp = author.compare(fictionRhs->author);
    if (comp == 0)
        comp = title.compare(fictionRhs->title);

    return comp;
}