#include "z_collectible.h"
#include "z_game.h"

#include <time.h>

fpoint &z_collectible::getp(){return p;}

void z_collectible::setp(fpoint get) { p.i = get.i ; p.j = get.j ; p.k = get.k ; }

QList<fpoint> &z_collectible::getcoll(){return coll;}

z_collectible::z_collectible()
{
    p.i=50;
    p.j=50;
    p.k='o';
    coll.push_front(p);
}
void z_collectible::collectiblegenerate( int n ,z_game * game)
{
        p.i=(rand()%(n-65))+32.5;
        p.i/=10;
        p.i*=10;
        p.j=(rand()%(n-65))+32.5;
        p.j/=10;
        p.j*=10;
        for(int i=0 ; i<game->getboard().getsnake().getplist().size() ; i++)
        {
            if(p.i==game->getboard().getsnake().getplist().at(i).i && p.j==game->getboard().getsnake().getplist().at(i).j)
            {
                p.i+=10;
                p.j+=10;
                break;
            }
        }

    srand(time(0)) ;
    static int check ;
    int rando = rand()%16 ;
    if ( check == rando )
        rando += 1 ;

    switch ( rando )
    {
        case 0 :
        {
            p.k = 'U' ;
            check = 0 ;
            break ;
        }

        case 1 :
        {
            p.k ='L';
            check = 1 ;
            break ;
        }

        case 2 :
        {
            p.k ='*' ;
            check = 2 ;
            break ;
        }

        case 3 :
        {
            p.k ='+' ;
            check = 3 ;
            break ;
        }

        case 4 :
        {
            p.k = 'I' ;
            check = 4 ;
            break ;
        }

        case 5 :
        {
            p.k = 'D' ;
            check = 5 ;
            break ;
        }
        case 6 :
        {
            p.k = 'l' ;
            check = 6 ;
            break ;
        }

        default :
        {
            p.k='o';
        }
    }
    getcoll().push_back(p);
}

void z_collectible::collect(z_GUI_Game *game){}

