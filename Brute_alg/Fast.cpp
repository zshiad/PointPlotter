#include "Fast.h"
#include <iostream>
#include <cstdlib>
#include "Point.h"
#include <vector>
#include "Angle.h"
#include <algorithm>
using namespace std;
Fast::Fast(vector<Point> &points, int point_num,int**arrptr){
  linesize=0;
  sort(points, point_num,arrptr);
}
 
  
Fast::~Fast(){
  line.clear();
  pointsize.clear();
}
  
    
void Fast::print(){
  int index=0;
  for(int i=0;i<linesize;i++){
    cout<<pointsize[i]<<": ";
    for(int j=0;j<pointsize[i];j++){
      cout<<line[index];
      index++;
      if(j==pointsize[i]-1){
	cout<<endl;
      }
      else{
	cout<<"->";
      }
  }
}
}

void Fast::sort(vector<Point> &points, int point_num,int**arrptr){
if(point_num>=4){
  if(points[0].angle.size()==0){
  for(int i=0;i<point_num-3;i++){
    for(int j=i+1;j<point_num;j++){
      Angle a=Angle(points[j].get_y()-points[i].get_y(),points[j].get_x()-points[i].get_x(),j);
           points[i].angle.push_back(a);
	   points[i].anglenum++;
    }
    std::sort(points[i].angle.begin(),points[i].angle.end()); 
  }
  }
  for(int i=0;i<point_num-3;i++){
  int begin=0;
  int end=1;
  while(1){
   if (points[i].angle[begin]==points[i].angle[end]){
     end++;  
     if(end==points[i].anglenum){
       if(end-begin>2){
	 if(arrptr[i][points[i].angle[begin].get_index()]==0){
	  line.push_back(points[i]);
	  arrptr[i][points[i].angle[begin].get_index()]=1;
	  for(int num=0;num<end-begin;num++)
	  {
	    int index=points[i].angle[begin+num].get_index();
	    line.push_back(points[index]);
	    if(num>0){
	       arrptr[points[i].angle[begin+num-1].get_index()][points[i].angle[begin+num].get_index()]=1;
	    }
	  }
	  pointsize.push_back(end-begin+1);
	  linesize++;
       }
      }
      break; 
    }
  } 
  else if(end-begin>2){
    if(arrptr[i][points[i].angle[begin].get_index()]==0){
	  line.push_back(points[i]);
	  arrptr[i][points[i].angle[begin].get_index()]=1;
	  for(int num=0;num<end-begin;num++)
	  { 
	    int index=points[i].angle[begin+num].get_index();
	    line.push_back(points[index]);
	    if(num>0){
	       arrptr[points[i].angle[begin+num-1].get_index()][points[i].angle[begin+num].get_index()]=1;
	    }
	  }
	  pointsize.push_back(end-begin+1);
	  linesize++;
    }
	  begin=end;
	  end=end+1;
	  if(end==points[i].anglenum){
	    break;
	  }
    }

    else{
      begin=end;
      end=end+1;
      if(end==points[i].anglenum){
	break;
      }
    }
  }
  }  
}
}
  