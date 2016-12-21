#include <qapplication.h>
#include <QWidget>
#include <QtGui>
#include <QTime>
#include <QMainWindow>
#include <cstdlib>
#include "Point.h"
#include "Angle.h"
#include <vector>

#ifndef POINTPLOTTER
#define POINTPLOTTER
using namespace std;
class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class PointPlotter:public QMainWindow{
  Q_OBJECT
public:
  PointPlotter();
  ~PointPlotter();
  std::vector<Point> points;
  std::vector<Point>::iterator it;
  int** arrptr;
private slots:
    void brute();
    void fast();
    void about();
private:
    void createActions();
    void createMenus();
    void resizeEvent(QResizeEvent*);
    QMenu *fileMenu;
    QMenu *helpMenu;
    QLabel *board;
    QPixmap *qpixmap;
    QAction *bruteAct;
    QAction *fastAct;
    QAction *exitAct;
    QAction *aboutAct;
    int point_num;  
    QMessageBox About;
    QMessageBox Time;
    QTime time;
};
  

#endif