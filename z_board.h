#ifndef Z_BOARD_H
#define Z_BOARD_H
#include "z_collectible.h"
#include "z_player.h"
#include "z_snake.h"

#include <map>
class z_board
{
    z_collectible collectible ;
    z_snake snake;
    z_player player;
    Person person;
public:
    //setter&getter
    z_collectible&  getcollectible();
    z_snake& getsnake();
    z_player& getplayer();
    Person&  getperson();
    ///

    z_board();
};

#endif // Z_BOARD_H
