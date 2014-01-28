#include "FixedDie.h"

FixedDie::FixedDie(int fixedResult) : Die(0)
{
    this->fixedResult = fixedResult;
}

FixedDie::~FixedDie()
{
    //dtor
}
