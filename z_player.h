#ifndef Z_PLAYER_H
#define Z_PLAYER_H

#include "z_score.h"
#include "z_life.h"

#include <QString>
#include <set>

using namespace std;

class Person
{
    z_life life;
public:
    //setter&getter
    QString name;
    /*C:\Users\Mehdi\Desktop\shiiiit\test2-new\z_game.cpp:220: error: passing 'const Person' as 'this' argument of 'QString& Person::getname()' discards qualifiers [-fpermissive]
         if(itr->getname() == user.getname())^*/
    z_score score;
    /*C:\Users\Mehdi\Desktop\shiiiit\test2-new\z_player.h:24: error: passing 'const Person' as 'this' argument of 'z_score Person::getscoreop()' discards qualifiers [-fpermissive]
         if(this->getscoreop().getscoreop() < y.getscoreop().getscoreop())^*/
    QString& getname();
    z_score& getscore();
    z_life& getlife();
    ///

    void setname (QString get );
    bool operator < (Person const &y) const;
};

class z_player
{
    set<Person> qpset;
public:
    //setter&getter
    set<Person>& getqpset();
    ///

    z_player();
    ~z_player();

};


#endif // Z_PLAYER_H
