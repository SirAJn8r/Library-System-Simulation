#include "book.h"

bool Book::receiveBook(Patron* patron)
{
    if (count == maxCount)
        return false;

    // If the patron has the book checked out, check it back in
    // If the patron does not, they can't return the book
    for (int i = 0; i < maxCount + 1; i++) {
        if (i == maxCount)
            return false;
        if (checkouts[i] == patron) {
            checkouts[i] = nullptr;
            break;
        }
    }

    count++;
    return true;
}

bool Book::giveBook(Patron* patron)
{
    if (!checkAvailability(patron))
        return false;

    count--;
    return true;
}

bool Book::checkAvailability(Patron* patron) const
{
    // If there are no copies left, it is unavailable
    if (count == 0)
        return false;

    // If the patron is already checking out a copy, it's unavailable
    for (int i = 0; i < maxCount; i++) {
        if (patron == checkouts[i])
            return false;
    }

    return true;
}