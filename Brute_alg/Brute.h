#ifndef BRUTE
#define BRUTE
#include <cstdlib>
#include <iostream>
#include "Point.h"
#include "Angle.h"
#include <vector>


class Brute 
{

public:
    Brute(std::vector<Point> & ,int,int**);
    ~Brute();
    void print();
private:
std::vector<Point> line;  
int linesize;
};


#endif 