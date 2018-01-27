#ifndef Z_GUI_BEGIN_H
#define Z_GUI_BEGIN_H
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



#include "z_gui_game.h"


class z_GUI_Begin : public QWidget
{
    Q_OBJECT
    QVBoxLayout * grid ;
    QPushButton * btn ;
    QLabel * label ;
    QLineEdit * getspd ;
    QLineEdit * getboard ;
    QHBoxLayout * layout ;
    z_GUI_Game * GUIgame ;
public :
    z_GUI_Begin();
public slots :
    void GameSettingPage();
    void setspd(QString i);
    void setboard(QString i);
    void StartGame();
};
#endif // Z_GUI_BEGIN_H
