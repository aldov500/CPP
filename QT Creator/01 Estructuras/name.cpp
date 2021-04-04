#include "name.h"
using namespace std;

string Name::getLast()
{
    return last;

}

string Name::getFirst()
{
    return first;

}

void Name::setLast(const string& l)
{
    last = l;
}

void Name::setFirst(const string& f)
{
    first = f;
}
