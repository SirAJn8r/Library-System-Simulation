/** 
 * @file periodical.h
 * @author Josh Helzerman
 *
 * Description:
 *   - A Periodical book type
 *
 * Assumptions/Implementation:
 *   - Implements the pure virtual comparison functions from Book and BSTData
 */

#include "periodical.h"

using namespace std;

//---------------------------------------------------------------------------
/** Periodical()
 * Default constructor
 *
 * Creates an unusable base instance of a periodical book
 * @pre None
 * @post Periodical book object exists with no values
 */
Periodical::Periodical()
{
    maxCount = 1;
    count = 1;
    author = "";
    checkouts = new Patron*[maxCount];
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
}

//---------------------------------------------------------------------------
/** ~Periodical()
 * Default destructor
 *
 * Destroys the periodical book
 * @pre None.
 * @post All memory for the periodical book is deallocated
 */
Periodical::~Periodical()
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
 * Displayed in order: count, year, month, title 
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 * @return String representing book data
 */
void Periodical::display() const
{
    cout << setw(AVAIL_OUTPUT_WIDTH) << count
         << setw(YEAR_OUTPUT_WIDTH) << year
         << setw(MONTH_OUTPUT_WIDTH) << month
         << setw(TITLE_MAX_LENGTH + 2)
         << title.substr(0, TITLE_MAX_LENGTH) << endl;
}

//---------------------------------------------------------------------------
/** displayForPatron()
 * Display book information
 *
 * Display book information in easy-to-read columns for patron history
 * Displayed in order: year, month, title 
 * Virtual function, can be overridden
 * @pre None.
 * @post None. const function
 */
void Periodical::displayForPatron() const
{
    cout << setw(YEAR_OUTPUT_WIDTH) << year
         << setw(MONTH_OUTPUT_WIDTH) << month
         << setw(ALT_TITLE_MAX_LENGTH + 2)
         << title.substr(0, ALT_TITLE_MAX_LENGTH) << endl;
}

//---------------------------------------------------------------------------
/** create()
 * Create Periodical Book
 *
 * Creates a book based on bookString
 * @param bookString stores the info about the book to be fetched
 * @param altString represents if the book string is formatted in the
 * normal or alternative format
 * @pre bookString is properly formatted as per the formatting type
 * @post None. No changes made.
 * @return Book pointer to the new book, nullptr if it failed
*/
Book* Periodical::create(stringstream& parameters,
    bool altString) const
{
    Periodical* toReturn = new Periodical();

    if (!altString) {
        getline(parameters, toReturn->title, ',');

        parameters.get();
        parameters >> toReturn->month;

        parameters.get();
        parameters >> toReturn->year;

    } else {
        parameters >> toReturn->year;

        parameters.get();
        parameters >> toReturn->month;

        parameters.get();
        getline(parameters, toReturn->title, ',');
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
int Periodical::getComp(const BSTData& rhs) const
{
    const Periodical* periodicalRhs = (const Periodical*)&rhs;

    int comp = year - periodicalRhs->year;
    if (comp == 0)
        comp = month - periodicalRhs->month;
    if (comp == 0)
        comp = title.compare(periodicalRhs->title);

    return comp;
}