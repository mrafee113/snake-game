#ifndef Z_POISON_H
#define Z_POISON_H
#include "z_collectible.h"

class z_poison : public z_collectible
{
    bool ifpoisoneaten;
public:
    bool getifpoisoneaten();
    z_poison();
    void collect(z_game* game) ;
};

#endif // Z_POISON_H
