#include "z_life.h"

int &z_life::getlives(){return lives;}

void z_life::setlives(int get) { lives = get ; }

z_life::z_life()
{
    lives=3;

}
void z_life::updatelife ()
{
    setlives(getlives()-1);
}
