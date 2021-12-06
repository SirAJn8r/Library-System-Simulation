#include "displayPatronHistory.h"

using namespace std;

DisplayPatronHistory::DisplayPatronHistory(PatronDatabase* patronDB)
{
    this->patronDB = patronDB;
}

DisplayPatronHistory::~DisplayPatronHistory()
{
    patronDB = nullptr;
}

void DisplayPatronHistory::execute()
{
    Patron* dispPatron = patronDB->getPatron(this->patronID);

    if (dispPatron) {
        dispPatron->display();
        dispPatron = nullptr;
    } else {
        cout << "Couldn't find Patron " << patronID << endl;
    }
}

LibraryCommand* DisplayPatronHistory::create(ifstream& parameters) const
{
    DisplayPatronHistory* toReturn = new DisplayPatronHistory(patronDB);
    parameters >> toReturn->patronID;

    if (toReturn->patronID.compare("9999") == 0)
        return toReturn;

    delete toReturn;
    return nullptr;
}