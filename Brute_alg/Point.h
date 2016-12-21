#ifndef POINT
#define POINT
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Angle.h"
using namespace std;
class Point 
{
public:
    int anglenum;
    vector<Angle> angle;
    Point(int x, int y):anglenum(0),x(x),y(y){}
    ~Point(){angle.clear();}
    int get_x ()const{return x;}
    int get_y ()const{return y;}
    void set(int a,int b){
      x=a;
      y=b;}
    bool  operator==(const Point &point)const{
    if(x==point.get_x()&&y==point.get_y()){return 1;}
    else{return 0;}
    }
    bool  operator!=(const Point &point)const{
    if(x!=point.get_x()||y!=point.get_y()){return 1;}
    else{return 0;}
    }

    bool  operator<(const Point &point)const{
    if(x<point.get_x()){return 1;}
    else if((x==point.get_x())&&(y<point.get_y())){return 1;}
    else{return 0;}
    }
    Point&  operator=(const Point &point){
    int x=point.get_x();
    int y=point.get_y();
    this->set(x,y);
    this->angle.clear();
    for(int i=0;point.angle.size();i++){
      this->angle.push_back(point.angle[i]);
    }
    return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, Point& p){
      os<<"("<<p.get_x()<<","<<p.get_y()<<")";
      return os;
    }  
private:
    int x;
    int y;
};



#endif 