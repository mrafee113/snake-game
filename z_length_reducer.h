#ifndef Z_LENGTH_REDUCER_H
#define Z_LENGTH_REDUCER_H
#include <QList>

#include "z_collectible.h"
#include "z_game.h"


class z_length_reducer : public z_collectible
{
public:
    void collect(z_GUI_Game *game );
};

#endif // Z_LENGTH_REDUCER_H
