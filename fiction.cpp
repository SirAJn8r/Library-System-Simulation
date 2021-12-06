#include "fiction.h"

using namespace std;

Fiction::Fiction()
{
    maxCount = 5;
    count = 5;
    month = -1;
    checkouts = new Patron*[maxCount];
    format = 'H';
}

Fiction::~Fiction()
{
    for (int i = 0; i < maxCount; i++)
        checkouts[i] = nullptr;
    delete checkouts;
    checkouts = nullptr;
}

void Fiction::display() const
{
    cout << "F " << author << ", " << title << ", " << year << endl;
}

Book* Fiction::create(stringstream& parameters) const
{
    Fiction* toReturn = new Fiction();
    string readIn;

    getline(parameters, toReturn->author, ',');
    parameters.get();
    getline(parameters, toReturn->title, ',');
    parameters.get();
    parameters >> readIn;
    toReturn->year = stoi(readIn);

    return toReturn;
}

int Fiction::getComp(const BSTData& rhs) const
{
    const Fiction* fictionRhs = (const Fiction*)&rhs;

    int comp = author.compare(fictionRhs->author);
    if (comp == 0)
        comp = title.compare(fictionRhs->title);

    return comp;
}