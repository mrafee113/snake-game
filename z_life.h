#ifndef Z_LIFE_H
#define Z_LIFE_H


class z_life
{
    int lives;
public:
    //setter&getter
    int& getlives();
    void setlives(int get );
    ///

    z_life();

    void updatelife ();
};

#endif // Z_LIFE_H
