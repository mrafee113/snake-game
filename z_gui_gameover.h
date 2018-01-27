#ifndef Z_GUI_GAMEOVER_H
#define Z_GUI_GAMEOVER_H
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <iostream>

using namespace std ;

#include "z_player.h"
#include "z_board.h"
#include "z_game.h"

class z_GUI_gameover : public QWidget
{
    Q_OBJECT
    QLabel * label ;
    QVBoxLayout * layout ;
    QLineEdit * getname ;
    QPushButton * enter ;
    QString* tmp ;
    QPushButton * exitbutt ;
    z_GUI_Game * Game ;
public:
    z_GUI_gameover(z_GUI_Game * getGame);

    QString score (z_GUI_Game * getGame , Person user);
public slots :
    void GetUserNamePage();
    void settmp(QString s);
    void ScoreBoardPage();
    void ExitGame();
    void Re_play();
};

#endif // Z_GUI_GAMEOVER_H
