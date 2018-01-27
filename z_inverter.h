#ifndef Z_INVERTER_H
#define Z_INVERTER_H
#include "z_collectible.h"

class z_inverter : public z_collectible
{
public:
    z_inverter();
    void collect (z_GUI_Game *game ) ;
};

#endif // Z_INVERTER_H
