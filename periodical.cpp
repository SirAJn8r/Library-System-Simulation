#include "periodical.h"

using namespace std;

Periodical::Periodical()
{
    maxCount = 1;
    count = 1;
    author = "";
    checkouts = new Patron*[maxCount];
    format = 'H';
}

Periodical::~Periodical()
{
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
    delete checkouts;
    checkouts = nullptr;
}

void Periodical::display() const
{
    cout << "P " << title << ", " << month << " " << year << endl;
}

Book* Periodical::create(stringstream& parameters) const
{
    Periodical* toReturn = new Periodical();
    string readIn;

    getline(parameters, toReturn->title, ',');
    parameters.get();
    parameters >> readIn;
    toReturn->month = stoi(readIn);
    parameters.get();
    parameters >> readIn;
    toReturn->year = stoi(readIn);

    return toReturn;
}

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