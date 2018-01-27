#ifndef Z_COLLECTIBLE_H
#define Z_COLLECTIBLE_H
#include <QList>
class z_game ;
class z_GUI_Game ;
class z_snake ;
struct fpoint
{
    int i;
    int j;
    char k ;
};

class z_collectible
{
    fpoint p;
    QList<fpoint> coll;
public:
    //setter&getter
    fpoint&  getp();
    void setp(fpoint get);
    QList<fpoint>& getcoll();
    ///

    z_collectible();

    void collectiblegenerate(int n, z_game *game);
    virtual void collect( z_GUI_Game * game );
};

#endif // Z_COLLECTIBLE_H
