#include "z_gui_game.h"
#include <unistd.h>

void z_GUI_Game::paintEvent(QPaintEvent *e)
{
    QPainter *qp = new QPainter(this) ;
    Q_UNUSED(e) ;
    if (ingame)
    {
        //Change Collectible image
        {
            switch (game->getboard().getcollectible().getcoll().last().k)
            {
            case 'I' :
            {
                Collectible->load("inverter.png") ;
                break ;
            }
            case '+' :
            {
                Collectible->load("score.png") ;
                break ;
            }
            case '*' :
            {
                Collectible->load("poison.png") ;
                break ;
            }
            case 'D' :
            {
                Collectible->load("speeddown.png") ;
                break ;
            }
            case 'L' :
            {
                Collectible->load("legnthreducer.png") ;
                break ;
            }
            case 'U' :
            {
                Collectible->load("speedup.png") ;
                break ;
            }
            case 'o' :
            {
                Collectible->load("apple.png");
                break ;
            }
            }
        }

        //Snake Paint(move) speed
        {
            if ( game->getifspeeddowneaten() ) sleep(Delay);
            else if ( !game->getifspeedupeaten() ) sleep(Delay);
            else sleep(Delay);
        }

        //Paint game wall
        for (int i=margin ; i<=game->getboardsize()-10;i++)
        {
            qp->drawImage(i,margin,*wall);
            qp->drawImage(i,game->getboardsize()-10,*wall);
            qp->drawImage(margin,i,*wall);
            qp->drawImage(game->getboardsize()-10,i,*wall);
        }
        //paint collectible
        qp->drawImage(this->game->getboard().getcollectible().getcoll().last().i,this->game->getboard().getcollectible().getcoll().last().j,*Collectible);
        //paint snake
        for ( auto itr = game->getboard().getsnake().getplist().begin() ; itr!= game->getboard().getsnake().getplist().end() ; ++itr )
        {
            if ( itr == game->getboard().getsnake().getplist().begin() ) qp->drawImage(itr->i,itr->j,*head);
            else qp->drawImage(itr->i,itr->j,*body);
        }
        //paint Score & life
        {
            QString score = "Score : " ;
            score += QString::number(game->getboard().getperson().getscore().score);
            QFont font("Courier", 13*game->getboardsize()/300);
            QFontMetrics fm(font);
            int textWidth = fm.width(score);
            qp->setFont(font);
            qp->translate(QPoint(margin+15,margin+15+game->getboardsize() ));
            qp->drawText(0, 0, score);
            QString life = "life : " ;
            life += QString::number(game->getboard().getperson().getlife().getlives());
            textWidth = fm.width(life);
            qp->setFont(font);
            qp->drawText(game->getboardsize()-margin-textWidth-20, 0, life);
        }
    }
}

void z_GUI_Game::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    static int SpeedChangeCounter = 1 ;

    //Snake move
    if(!game->getboard().getsnake().move(game->getboardsize(),this,margin))
        ingame = false ; //if move failure

    //gameover
    if(!ingame)
    {
        killTimer(timerId);
        this->hide();
        over = new z_GUI_gameover (this) ;
        over->show();
    }

    //apply speedup collectible
    if ( this->game->getifspeedupeaten() == 1 && SpeedChangeCounter<=10 )
    {
        SpeedChangeCounter++ ;
        Delay = 0 ;
    }
    //apply speeddown collectible
    if ( this->game->getifspeeddowneaten() == 1 && SpeedChangeCounter<=5 )
    {
        SpeedChangeCounter++ ;
        Delay = 150 ;
    }
    //apply regular speed
    else
    {
        SpeedChangeCounter = 1 ;
        Delay = 20 ;
        game->setifspeedupeaten(0) ;
        game->setifspeeddowneaten(0);
    }
    QWidget::update() ;//Calls PaintEvent
}

void z_GUI_Game::keyPressEvent(QKeyEvent *e)
{
    static int i = 1 ;
    int key = e->key();
    //Direction
    {
        //Reverse Direction set
        if ( this->game->getifpoisoneaten() == 1 && i<=10 )
        {
            if (key == Qt::Key_Up)
            {
                if(this->game->getboard().getsnake().dir!='d' && (this->game->getboard().getsnake().dir=='l' ||this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='r'))
                    this->game->getboard().getsnake().dir = 'd' ;
            }
            else if (key == Qt::Key_Right)
            {
                if(this->game->getboard().getsnake().dir!='l' && (this->game->getboard().getsnake().dir=='r' || this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='d'))
                    this->game->getboard().getsnake().dir = 'l';
            }
            else if (key == Qt::Key_Down)
            {
                if(this->game->getboard().getsnake().dir!='u' && (this->game->getboard().getsnake().dir=='l' || this->game->getboard().getsnake().dir=='r' ||this->game->getboard().getsnake().dir=='d'))
                    this->game->getboard().getsnake().dir = 'u';
            }
            else if (key == Qt::Key_Left)
            {
                if(this->game->getboard().getsnake().dir!='r' && (this->game->getboard().getsnake().dir=='l' || this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='d')  )
                    this->game->getboard().getsnake().dir = 'r';
            }
            i++ ;
        }
        //Direction set
        else
        {
            if (key == Qt::Key_Up)
            {
                if(this->game->getboard().getsnake().dir!='d' && (this->game->getboard().getsnake().dir=='l' ||this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='r'))
                    this->game->getboard().getsnake().dir = 'u' ;
            }
            else if (key == Qt::Key_Right)
            {
                if(this->game->getboard().getsnake().dir!='l' && (this->game->getboard().getsnake().dir=='r' || this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='d'))
                    this->game->getboard().getsnake().dir = 'r';
            }
            else if (key == Qt::Key_Down)
            {
                if(this->game->getboard().getsnake().dir!='u' && (this->game->getboard().getsnake().dir=='l' || this->game->getboard().getsnake().dir=='r' ||this->game->getboard().getsnake().dir=='d'))
                    this->game->getboard().getsnake().dir = 'd';
            }
            else if (key == Qt::Key_Left)
            {
                if(this->game->getboard().getsnake().dir!='r' && (this->game->getboard().getsnake().dir=='l' || this->game->getboard().getsnake().dir=='u' || this->game->getboard().getsnake().dir=='d')  )
                    this->game->getboard().getsnake().dir = 'l';
            }
        }
    }
    //poison collectible counter
    {
        if ( i>10 )
        {
            i = 1 ;
            game->setifpoisoneaten(0) ;
        }
    }
    QWidget::keyPressEvent(e);
}

z_GUI_Game::z_GUI_Game(QWidget *parent) : QWidget(parent)
{
    grid = new QGridLayout(this) ;
    game = new z_game ;
    Collectible = new QImage ;
    head = new QImage ;
    body = new QImage ;
    wall = new QImage ;


    setStyleSheet("background-color:#aacc99;");
    setWindowTitle("Snake - Game");
    margin = 20 ;
    resize (game->getboardsize()+margin,game->getboardsize()+2.5*margin) ;


    Collectible->load("apple.png");
    head->load("head.png");
    body->load("body.png");
    wall->load("wall.png");


    ingame = 1 ;
    Delay = 20 ;
}
