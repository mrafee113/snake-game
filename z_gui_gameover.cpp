#include "z_gui_gameover.h"
#include "z_gui_game.h"

z_GUI_gameover::z_GUI_gameover(z_GUI_Game * getGame)  : Game(getGame)
{
    layout = new QVBoxLayout(this) ;
    tmp = new QString ;
    getname = new QLineEdit ;
    exitbutt = new QPushButton ;
    label = new QLabel ;
    enter = new QPushButton ;


    label->setText("GAME-OVER\n:-|");
    label->setAlignment(Qt::AlignCenter);
    QFont font("Courier",30,QFont::Bold);
    label->setFont(font);


    enter->setText("continue :(");
    connect(enter,SIGNAL(clicked(bool)),this,SLOT(GetUserNamePage()));


    layout->addWidget(label);
    layout->addWidget(enter);
}

QString z_GUI_gameover::score(z_GUI_Game * getGame, Person user)
{
    //sums up the string for scoreboardpage
    QString name ;
    bool exist = false ;
    for(auto itr=getGame->game->getboard().getplayer().getqpset().begin() ; itr !=getGame->game->getboard().getplayer().getqpset().end(); itr++ )
    {
        if(itr->name == user.name)
        {
            exist=true;
            if(itr->score.score < getGame->game->getboard().getperson().getscore().getscore())
            {
                name += "\n__________________________\n\n\tNEW HIGH SCORE\nLast HIGH SCORE :" ;
                name += QString::number(itr->score.score) ;

                getGame->game->getboard().getplayer().getqpset().erase(itr);
                user.score.score=getGame->game->getboard().getperson().getscore().getscore();
                getGame->game->getboard().getplayer().getqpset().insert(user);
            }
            else
            {
                name += "\n\n_____________________\n\nYOUR NEW SCORE : " ;
                name += QString::number(getGame->game->getboard().getperson().getscore().getscore()) ;
                name += '\n' ;
            }
            break;
        }
    }
    if (!exist)
    {
        user.score.score=getGame->game->getboard().getperson().getscore().getscore();
        getGame->game->getboard().getplayer().getqpset().insert(user);
    }
    name += "\n_____________________\n\nSCORE BOARD : \n\n" ;
    int n =1 ;
    for (auto itr=getGame->game->getboard().getplayer().getqpset().begin() ; itr!=getGame->game->getboard().getplayer().getqpset().end() ; itr++ )
    {
        if(n<=10)
        {
            name += QString::number(n) ;
            name += ") " ;
            name += itr->name ;
            name += ":  " ;
            name += QString::number(itr->score.score) ;
            name += '\n' ;
        }
        n++;
    }
    return name ;
}

void z_GUI_gameover::GetUserNamePage()
{
    disconnect(enter,SIGNAL(clicked(bool)),this,SLOT(GetUserNamePage()));
    layout->removeWidget(label);
    layout->removeWidget(enter);
    label->hide();
    enter->hide();


    getname->setText("Please Enter your name");
    connect(getname,SIGNAL(textChanged(QString)),this,SLOT(settmp(QString)));


    enter->setText("ok");
    connect(enter,SIGNAL(clicked(bool)),this,SLOT(ScoreBoardPage()));
    enter->show();


    layout->addWidget(getname);
    layout->addWidget(enter);
}

void z_GUI_gameover::ExitGame()
{
    exit (EXIT_SUCCESS);
}

void z_GUI_gameover::settmp(QString s){*tmp = s ;}

void z_GUI_gameover::ScoreBoardPage()
{
    disconnect(enter,SIGNAL(clicked(bool)),this,SLOT(ScoreBoardPage()));
    layout->removeWidget(enter);
    layout->removeWidget(getname);
    enter->hide();
    getname->hide();


    exitbutt->setText("Exit");
    connect(exitbutt,SIGNAL(clicked(bool)),this,SLOT(ExitGame()));


    enter->setText("Replay");
    enter->show();
    connect(enter,SIGNAL(clicked(bool)),this,SLOT(Re_play()));


    Person user ;
    user.setname(*tmp);
    QString name = score(Game,user);
    label->setText(name);
    label->setAlignment(Qt::AlignLeft);
    QFont font ("Courier",9);
    label->setFont(font);


    layout->addWidget(exitbutt);
    layout->addWidget(enter);
    layout->addWidget(label);
    label->show();
}

void z_GUI_gameover::Re_play()
{
    delete getname ;
    delete enter ;
    delete exitbutt ;
    delete label ;
    delete layout ;
    delete Game->game ;


    Game->game = new z_game ;


    Game->show();
    Game->setingame(true) ;
    Game->settimerId(Game->startTimer(Game->game->getspd())) ;


    delete this ;
}
