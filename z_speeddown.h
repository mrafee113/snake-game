#ifndef Z_SPEEDDOWN_H
#define Z_SPEEDDOWN_H
#include "z_collectible.h"

class z_speeddown : public z_collectible
{
public:
    z_speeddown();
    void collect(z_GUI_Game *game);
};

#endif // Z_SPEEDUP_H
