#ifndef FAST
#define FAST
#include <cstdlib>
#include <iostream>
#include "Point.h"
#include "Angle.h"
#include <vector>


class Fast 
{

public:
    Fast(std::vector<Point> & ,int,int**);
    ~Fast();
    void print();
    
private:
void sort(std::vector<Point> & ,int,int**);
std::vector<Point> line; 
std::vector<int> pointsize; 
int linesize;
};


#endif 