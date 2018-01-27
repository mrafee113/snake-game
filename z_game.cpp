#include "z_game.h"

z_board &z_game::getboard(){return board;}

z_snake &z_game::getsnake(){return snake;}

bool &z_game::getifpoisoneaten(){return ifpoisoneaten ;}

void z_game::setifpoisoneaten(bool get) { ifpoisoneaten = get ;}

bool &z_game::getifspeedupeaten(){return ifspeedupeaten ;}

void z_game::setifspeedupeaten(bool get) { ifspeedupeaten = get ;}

bool &z_game::getifspeeddowneaten(){return ifspeeddowneaten;}

void z_game::setifspeeddowneaten(bool get) { ifspeeddowneaten = get ;}

int &z_game::getspd(){return spd ;}

void z_game::setspd(int get) { spd = get ; }

z_game::z_game()
{
    setboardsize(300);
    spd = 140 ;
    ifpoisoneaten = 0 ;
    ifspeedupeaten = 0 ;
    ifspeeddowneaten = 0 ;
}
