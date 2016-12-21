#include "Brute.h"
#include <iostream>
#include <cstdlib>
#include "Point.h"
Brute::Brute(vector<Point> &points, int point_num,int** arrptr){
  linesize=0;
  if(point_num>=4){
  for(int l1=0;l1<point_num-3;l1++){
    for(int l2=0;l2<point_num-3-l1;l2++){
      for(int l3=0;l3<point_num-3-l1-l2;l3++){
	for(int p1=0;p1<point_num-3-l1-l2-l3;p1++){
	  int p2=p1+1+l1;
	  int p3=p2+1+l2;
	  int p4=p3+1+l3;
	  Angle a2=Angle(points[p2].get_y()-points[p1].get_y(),points[p2].get_x()-points[p1].get_x(),0);
	  Angle a3=Angle(points[p3].get_y()-points[p1].get_y(),points[p3].get_x()-points[p1].get_x(),0);
	  Angle a4=Angle(points[p4].get_y()-points[p1].get_y(),points[p4].get_x()-points[p1].get_x(),0);
	  if(a2==a3&&a2==a4){
	    line.push_back(points[p1]);
	    line.push_back(points[p2]);
	    line.push_back(points[p3]);
	    line.push_back(points[p4]);
	    linesize++;
	    arrptr[p1][p2]=1;
	    arrptr[p2][p3]=1;
	    arrptr[p3][p4]=1;
	  }
	}
      }  
    }
  }
  }
}
  
Brute::~Brute(){
  line.clear();
}
  
    
void Brute::print(){
  for(int i=0;i<linesize;i++){
    cout<<"4: "<<line[4*i]<<"->"<<line[4*i+1]<<"->"<<line[4*i+2]<<"->"<<line[4*i+3]<<endl;
  }
}
  