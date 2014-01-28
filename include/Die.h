#ifndef DIE_H
#define DIE_H

#include <cstdlib>


// Interface of a Die
//
// A die has a certain number of sides (n_sides).
//
// A die supports one operation: roll
//

class Die
{
    public:
        Die(int n_sides);
        virtual ~Die();

        virtual int roll() const { return rand() % n_sides; }

    protected:

    private:
        int n_sides;
};

#endif // DIE_H
