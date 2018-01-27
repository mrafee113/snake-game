#include "z_player.h"

#include <fstream>
#include <iostream>
#include <QStringList>
using namespace std;

set<Person> &z_player::getqpset(){return qpset;}

z_player::z_player()
{
    ifstream player_info ("player_info.txt");
    if (!player_info.is_open())
        return ;
    while (!player_info.eof())
    {
        Person person ;
        char str [ 10000 ] ;
        player_info.getline(str,10000) ;
        QStringList sl = QString(str).split(',');
        if (sl.size()!=2)
            continue;
        person.name = sl.at(0) ;
        person.score.score = sl.at(1).toInt() ;
		qpset.insert(person);
    }
    player_info.close();
}

z_player::~z_player()
{
    ofstream player_info ("player_info.txt");
    if (!player_info.is_open())
        return ;
	for (auto itr=qpset.begin() ; itr!=qpset.end() ; itr++ )
		player_info << itr->name.toStdString()  << "," << itr->score.score << endl ;
    player_info.close();
}


QString &Person::getname(){return name;}

void Person::setname(QString get) { name = get ; }

z_score &Person::getscore(){return score;}

z_life &Person::getlife(){return life;}

bool Person::operator <(const Person &y) const
{
    if(this->score.score < y.score.score)
        return false;
    return true;
}
