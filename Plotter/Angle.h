#ifndef ANGLE
#define ANGLE
#include <cstdlib>
#include <iostream>
class Angle
{
private:
int divisor;
int dividend;
int pointindex;
int gcd(int dy,int dx){
  return dx==0 ? dy :gcd(dx,dy%dx);
}
public:
    Angle():divisor(0),dividend(0),pointindex(0){}
    Angle(int dy,int dx,int index){
    pointindex=index; 
    int d=gcd(dy,dx);
    if(d<0){d=-d;}
    if(d==0){
    dividend=0;
    divisor=0;  
    }
    else{
    dividend=dy/d;
    divisor=dx/d;
    }
  }
  int get_divisor()const{return divisor;}
  int get_dividend()const{return dividend;}
  bool  operator==(const Angle& angle)const{
    if((divisor==angle.get_divisor())&&(dividend==angle.get_dividend())){return 1;}
    else{return 0;}
  }
  bool  operator<(const Angle& angle)const{
    if((dividend*angle.get_divisor())<(divisor*angle.get_dividend())){return 1;}
    else if((dividend*angle.get_divisor())==(divisor*angle.get_dividend())&&
      (pointindex<angle.get_index())){return 1;}
    else {return 0;}
  }
  int get_index()const{return pointindex;}
  void set_index(int i){pointindex=i;}
};
#endif 