#include "patronDatabase.h"
#include <iostream>

using namespace std;

PatronDatabase::PatronDatabase()
{
    patronBST = new BSTree();
}

PatronDatabase::~PatronDatabase()
{
    delete patronBST;
}

bool PatronDatabase::insertPatron(string patronID)
{
    Patron* newPatron = createPatron(patronID);
    if (!newPatron)
        return false;

    return patronBST->insert(newPatron);
}

Patron* PatronDatabase::getPatron(string patronID) const
{
    Patron* newPatron = createPatron(patronID);
    if (!newPatron)
        return nullptr;

    return (Patron*)patronBST->retrieve(newPatron);
}

Patron* PatronDatabase::createPatron(string patronID) const
{
    string stringID = patronID.substr(0, 4);
    int id = stoi(stringID);
    if (id == 9999)
        return nullptr;

    string name = patronID.substr(5, patronID.length() - 5);

    return new Patron(id, name);
}