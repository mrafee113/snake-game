#include "z_gui_begin.h"

z_GUI_Begin::z_GUI_Begin()
{
    GUIgame = new z_GUI_Game ;
    grid = new QVBoxLayout(this) ;
    label = new QLabel ;
    btn = new QPushButton ;
    getspd = new QLineEdit ;
    layout = new QHBoxLayout ;
    getboard = new QLineEdit ;


    this->resize(320,380);
    setWindowTitle("Snake - Game");


    label->setText("SNAKE\nTHE GAME");
    label->setAlignment(Qt::AlignCenter);
    QFont font("Courier",30,QFont::Bold);
    label->setFont(font);


    btn->setText("ok");
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(GameSettingPage()));


    grid->addWidget(label);
    grid->addWidget(btn);
    this->show();
}

void z_GUI_Begin::GameSettingPage()
{
    layout->removeWidget(label);
    layout->removeWidget(btn);
    label->hide();
    btn->hide();


    resize(320,190);


    getspd->setText(": 140 :");
    connect(getspd,SIGNAL(textChanged(QString)),this,SLOT(setspd(QString)));


    getboard->setText(": 300 :");
    connect(getboard,SIGNAL(textChanged(QString)),this,SLOT(setboard(QString)));


    btn->setText("Startgame");
    btn->show();
    disconnect(btn,SIGNAL(clicked(bool)),this,SLOT(GameSettingPage()));
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(StartGame()));


    label->setText("speed :\nregular :: 140\n\nboardsize :\nregualr :: 300\nmargin :: 20");
    QFont font ("Courier",9);
    label->setFont(font);
    label->show();


    layout->addWidget(getspd);
    layout->addWidget(getboard);
    layout->addWidget(btn);
    layout->setAlignment(Qt::AlignTop);


    grid->addLayout(layout);
    grid->addWidget(label);
}

void z_GUI_Begin::setspd(QString i)
{
    this->GUIgame->game->setspd(i.toInt());
}

void z_GUI_Begin::setboard(QString i)
{
    this->GUIgame->game->setboardsize( i.toInt());
    this->GUIgame->resize (GUIgame->game->getboardsize() + GUIgame->getmargin() , GUIgame->game->getboardsize() + 2.5 * GUIgame->getmargin() ) ;
}

void z_GUI_Begin::StartGame()
{
    grid->removeWidget(label);
    layout->removeWidget(btn);
    layout->removeWidget(getspd);
    layout->removeWidget(getboard);


    delete layout ;
    delete grid ;
    delete btn ;
    delete label ;
    delete getspd ;
    delete getboard ;


    this->hide();


    GUIgame->show();
    GUIgame->settimerId(GUIgame->startTimer(GUIgame->game->getspd())) ;
}
