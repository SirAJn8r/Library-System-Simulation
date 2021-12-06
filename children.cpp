#include "children.h"

using namespace std;

Children::Children()
{
    maxCount = 5;
    count = 5;
    month = -1;
    checkouts = new Patron*[maxCount];
    format = 'H';
}

Children::~Children()
{
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
    delete checkouts;
    checkouts = nullptr;
}

void Children::display() const
{
    cout << "C " << author << ", " << title << ", " << year << endl;
}

Book* Children::create(stringstream& parameters) const
{
    Children* toReturn = new Children();
    string readIn;

    getline(parameters, toReturn->author, ',');
    parameters.get();

    getline(parameters, toReturn->title, ',');
    parameters.get();

    parameters >> readIn;
    toReturn->year = stoi(readIn);

    return toReturn;
}

int Children::getComp(const BSTData& rhs) const
{
    const Children* childrenRhs = (const Children*)&rhs;

    int comp = title.compare(childrenRhs->title);
    if (comp == 0)
        comp = author.compare(childrenRhs->author);

    return comp;
}
