#ifndef Z_SCORE_H
#define Z_SCORE_H

class z_life;

class z_score
{
public:
    //setter&getter
    int& getscore();
    void setscore(int get);
    ///

    z_score();

    int score;
    /*
C:\Users\Mehdi\Desktop\shiiiit\test2-new\z_player.h:24: error: passing 'const Person' as 'this' argument of 'z_score Person::getscoreop()' discards qualifiers [-fpermissive]
         if(this->getscoreop().getscoreop() < y.getscoreop().getscoreop())^ */

    void update_score(z_life *);
};

#endif // Z_SCORE_H
