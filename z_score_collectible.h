#ifndef Z_SCORE_COLLECTIBLE_H
#define Z_SCORE_COLLECTIBLE_H
#include "z_collectible.h"

class z_score_collectible : public z_collectible
{
public:
    z_score_collectible();
    void collect (z_GUI_Game *game) ;
};

#endif // Z_SCORE_COLLECTIBLE_H
