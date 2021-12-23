/** 
 * @file bookfactory.h
 * @author Alex Lambert
 *
 * Description:
 *   - A BookFactory object represents the factory class that creates Book
 *  objects in their different subtypes to be stored in the books database.
 *   - Can create a book and correctly classify it as the right type using
 * string data provided by the LibraryBuilder.
 *   - This is the only class that would need to be changed if new types of
 * books were to be added
 *
 *
 * Assumptions/Implementation:
 *   - This a factory class following the factory design pattern.
 *   - Contains one base instance used to create copies of that type of book
 *   - Classifies each type of book and creates the correct sub-class of
 * book for each string passed in.
 */

#include "bookFactory.h"

//---------------------------------------------------------------------------
/** BookFactory()
 * Default Constructor
 * 
 * Creates a BookFactory
 * @pre None.
 * @post BookFactory object exists with the base instances
 */
BookFactory::BookFactory()
{
    bookTypes[0] = new Fiction();
    bookTypes[1] = new Periodical();
    bookTypes[2] = new Children();

    bookTypeHeader[0] << "Fiction:\n"
                      << left
                      << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL"
                      << setw(AUTHOR_MAX_LENGTH + 2) << "AUTHOR"
                      << setw(TITLE_MAX_LENGTH + 2) << "TITLE"
                      << setw(YEAR_OUTPUT_WIDTH) << "YEAR";
    bookTypeHeader[1] << "Periodicals:\n"
                      << left
                      << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL"
                      << setw(YEAR_OUTPUT_WIDTH) << "YEAR"
                      << setw(MONTH_OUTPUT_WIDTH) << "MONTH"
                      << setw(TITLE_MAX_LENGTH + 2) << "TITLE";
    bookTypeHeader[2] << "Children's:\n"
                      << left
                      << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL"
                      << setw(TITLE_MAX_LENGTH + 2) << "TITLE"
                      << setw(AUTHOR_MAX_LENGTH + 2) << "AUTHOR"
                      << setw(YEAR_OUTPUT_WIDTH) << "YEAR";
}

//---------------------------------------------------------------------------
/** ~BookFactory()
 * Default Destructor
 * 
 * Destroys the BookFactory
 * @pre None.
 * @post Deallocates the BookFactory memory, destroys the base instances
 */
BookFactory::~BookFactory()
{
    for (int i = 0; i < NUM_BOOK_TYPES; i++) {
        delete bookTypes[i];
        bookTypes[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
/** getID()
 * Get ID Function
 *
 * Retreives the ID of any provided Book object fromt the bookTypeID
 *   int array and returns the id as an int.
 * @param type is a capital letter representing the type of book
 * @pre None.
 * @post None.
 * @return returns the ID of the type, -1 if it isn't valid
 */
int BookFactory::getID(char type) const
{
    int ID = int(type) - 65;
    if (ID < 0 || ID >= 26)
        return -1;
    return bookTypeID[ID];
}

//---------------------------------------------------------------------------
/** createBook()
 * Create Book Function
 *
 * Creates a book based on bookString
 * @param bookString stores the info about the book to be fetched
 * @param altString represents if the book string is formatted in the
 * normal or alternative format
 * @pre bookString is properly formatted as per the formatting type
 * @post None. No changes made.
 * @return Book pointer to the new book, nullptr if it failed
 */
Book* BookFactory::createBook(string bookString, bool altString) const
{
    int ID = getID(bookString[0]);
    if (ID == -1)
        return nullptr;

    stringstream bookStringReader(bookString);
    bookStringReader.get();
    bookStringReader.get();

    if (altString) {
        char format;
        bookStringReader >> format;
        bookStringReader.get();

        if (!checkFormat(format)) {
            cout << "ERROR: \'" << format
                 << "\' is not a valid format type for ";
            return nullptr;
        }
    }

    return bookTypes[ID]->create(bookStringReader, altString);
}

//-----------------------------------------------------------------------
/** checkFormat()
 * Check if Valid Format
 *
 * Checks if the format is legal or not
 * @param format is a capital letter representing the format
 * @pre None.
 * @post None.
 * @return if the format is valid
 */
bool BookFactory::checkFormat(char format) const
{
    int formatID = int(format) - 65;
    if (formatID < 0 || formatID >= 26)
        return -1;
    return validFormats[formatID];
}