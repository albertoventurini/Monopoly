#ifndef FIXEDDIE_H
#define FIXEDDIE_H

#include <Die.h>

// Interface of FixedDie
//
// A fixed die is a die that always returns the same value (initialized at constructor time)
//

class FixedDie : public Die
{
    public:
        FixedDie(int fixedResult);
        virtual ~FixedDie();

        int roll() const { return fixedResult; }

    protected:

    private:
        int fixedResult;
};

#endif // FIXEDDIE_H
