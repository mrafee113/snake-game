#include "z_board.h"
#include <stdio.h>
//#include <conio.h>
//#include <windows.h>

z_collectible &z_board::getcollectible(){ return collectible ; }

z_snake &z_board::getsnake() { return snake;}

z_player &z_board::getplayer() {return player;}

Person &z_board::getperson() { return person; }

z_board::z_board()
{

}
