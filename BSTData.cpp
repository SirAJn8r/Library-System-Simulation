#include "BSTData.h"

using namespace std;

BSTData::~BSTData() { }

bool BSTData::operator<(const BSTData& rhs) const
{

    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) < 0;
}

bool BSTData::operator<=(const BSTData& rhs) const
{

    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) <= 0;
}

bool BSTData::operator>(const BSTData& rhs) const
{

    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) > 0;
}

bool BSTData::operator>=(const BSTData& rhs) const
{

    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) >= 0;
}

bool BSTData::operator==(const BSTData& rhs) const
{
    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) == 0;
}

bool BSTData::operator!=(const BSTData& rhs) const
{

    cout << " " << endl;
    cout << "Ack" << endl;
    cout << " " << endl;
    return getComp(rhs) != 0;
}