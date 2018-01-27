#include "z_score.h"
#include "z_life.h"

int &z_score::getscore(){return score;}

void z_score::setscore(int get){score = get ;}

z_score::z_score()
{
    score=0;
}

void z_score::update_score(z_life * life)
{
    score +=10;

	if(double(score%100)==0)
	{
        life->setlives(life->getlives()+1);
	}

}

