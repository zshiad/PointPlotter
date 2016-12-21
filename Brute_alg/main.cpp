#include <QWidget>
#include <QApplication>
#include "PointPlotter.h"

int main(int argv, char *args[])
{
    QApplication app(argv, args);
    PointPlotter pointplotter;
    return app.exec();
}
 