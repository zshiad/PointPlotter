#include "PointPlotter.h"
#include <QWidget>
#include <QTime>
#include <QString>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <cstdlib>
#include "Point.h"
#include "Brute.h"
#include "Fast.h"
#include <string>
#include <sstream>

using namespace std;
PointPlotter::PointPlotter() 
{    
     const char *FILE  = "input.txt";
     ifstream fin(FILE); 
     assert (fin.is_open ());
     int line=0;
     int temp_num;
     
     while (!fin.eof ()){   
       if(line==0){
      fin >>point_num; 
      temp_num=point_num;
	 line++;
      } 
      else{
        int x;
	int y;  
        if (fin.fail()) 
           break;      
        fin >>x; 
        if (fin.fail()) 
           break;      
        fin >>y;
	Point temp_point(x,y);
	it=std::find(points.begin(),points.end(),temp_point);
	if(it!=points.end()){
	  temp_num=temp_num-1;
	}
	else{
	points.push_back(temp_point);}
	line++;
	if(line>point_num){break;}
      }
    }
    point_num=temp_num;
    fin.close ();
    std::sort(points.begin(),points.end());
    arrptr=new int*[point_num];
     for(int i=0;i<point_num;i++){
      arrptr[i]=new int[point_num];
    }
    for(int x=0; x<point_num;x++){
      for(int y=0; y<point_num;y++){
      arrptr[x][y]=0;
    }  
    }
    
  
  
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    
    board = new QLabel;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(topFiller);
    layout->addWidget(board);
    widget->setLayout(layout);

    createActions();
    createMenus();
    
    setWindowTitle(tr("PointPlotter"));
    setMinimumSize(1, 1);
    resize(480, 480);
    
    Time.setWindowTitle(tr("Time"));
    About.setWindowTitle(tr("About"));
    About.setText("SHI Zhenmei");
    brute();
}

PointPlotter::~PointPlotter(){
  points.clear();
  for(int i=0;i<point_num;i++){
      delete [] arrptr[i];
    }
    delete []arrptr;
} 


void PointPlotter::createActions()
{
    bruteAct = new QAction(tr("Load brute algo"), this);
    QWidget::connect(bruteAct, SIGNAL(triggered()), this, SLOT(brute()));

    fastAct = new QAction(tr("Load fast algo"), this);
    QWidget::connect(fastAct, SIGNAL(triggered()), this, SLOT(fast()));
    
    exitAct = new QAction(tr("Exit"), this);
    QWidget::connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));
    
    aboutAct = new QAction(tr("about"), this);
    QWidget::connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    
}

void PointPlotter::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(bruteAct);
    fileMenu->addAction(fastAct);
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(aboutAct);

}
void PointPlotter::brute()
{
    for(int x=0; x<point_num;x++){
     for(int y=0; y<point_num;y++){
      arrptr[x][y]=0;
    }  
    }
    int time1=time.msecsTo(time.currentTime());
    Brute brute=Brute(points,point_num,arrptr);
    int time2=time.msecsTo(time.currentTime());
    brute.print();
    resize(this->width(),this->height()+1);
    resize(this->width(),this->height()-1);
    stringstream ss;
    ss<<time2-time1;
    std::string str=ss.str();
    str.append(" msec");
    const char* chr=str.c_str();
    QString qstr=QString(chr);
    Time.setText(qstr);
    Time.setVisible(0);
}

void PointPlotter::fast()
{
    for(int x=0; x<point_num;x++){
     for(int y=0; y<point_num;y++){
      arrptr[x][y]=0;
    }  
    }
    int time1=time.msecsTo(time.currentTime());
    Fast fast=Fast(points,point_num,arrptr);
    int time2=time.msecsTo(time.currentTime());
    fast.print();
    resize(this->width(),this->height()+1);
    resize(this->width(),this->height()-1);
    stringstream ss;
    ss<<time2-time1;
    std::string str=ss.str();
    str.append(" msec");
    const char* chr=str.c_str();
    QString qstr=QString(chr);
    Time.setText(qstr);
    Time.setVisible(1);
    
}

void PointPlotter::about()
{ 
   About.setVisible(1);
}

void PointPlotter::resizeEvent(QResizeEvent* event){
   int height=this->height();
   int width=this->width();
   QMainWindow::resizeEvent(event);
   qpixmap=new QPixmap(width,height-25);
   qpixmap->fill();
   QPainter qPainter(qpixmap);
   for(int i=0;i<point_num;i++){
     int x=points[i].get_x();
     int y=points[i].get_y();
     x=x*width/34000-2;
     y=height-27-y*height/34000;
     qPainter.drawEllipse(x,y,4,4);
  }
  for(int i=0;i<point_num;i++){
    for(int j=0;j<point_num;j++){
     if(arrptr[i][j]==1){
     int xi=points[i].get_x();
     int yi=points[i].get_y();
     xi=xi*width/34000;
     yi=height-25-yi*height/34000;
     int xj=points[j].get_x();
     int yj=points[j].get_y();
     xj=xj*width/34000;
     yj=height-25-yj*height/34000;
     qPainter.drawLine(xi,yi,xj,yj);
      }
    }
  }
   board->setPixmap(QPixmap::fromImage(*qpixmap));
   board->show();
   
    
}


