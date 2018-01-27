#include <QApplication>
#include "z_gui_begin.h"

int main(int argc , char *argv[])
{
    QApplication app(argc,argv) ;
    z_GUI_Begin Begin ;
    return app.exec();
}
