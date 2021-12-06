#include "patron.h"

using namespace std;

Patron::Patron(int ID, string name)
{
    this->ID = ID;
    this->name = name;
    history = new list<pastAction>;
}

Patron::~Patron()
{
    delete history;
    history = nullptr;
}

void Patron::addBook(Book* book)
{
    pastAction newAction;
    newAction.action = "CheckOut ";
    newAction.book = book;

    history->push_back(newAction);
}

void Patron::returnBook(Book* book)
{
    pastAction newAction;
    newAction.action = "Return   ";
    newAction.book = book;

    history->push_back(newAction);
}

void Patron::display() const
{
    cout << ID << "  " << name << ":" << endl;

    for (list<pastAction>::iterator next = history->begin();
         next != history->end(); next++) {
        cout << (*next).action;
        (*next).book->display();
    }
}

int Patron::getComp(const BSTData& rhs) const
{
    return ID - ((Patron*)&rhs)->ID;
}