#ifndef Z_SPEEDUP_H
#define Z_SPEEDUP_H
#include "z_collectible.h"

class z_speedup : public z_collectible
{
public:
    z_speedup();
    void collect(z_GUI_Game *game);
};

#endif // Z_SPEEDUP_H
