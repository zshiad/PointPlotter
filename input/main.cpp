#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
int main (int argc, char *argv[])
{
    const char *FILE = "input.txt";
    std::ofstream fout(FILE);                
    assert (fout.is_open ()); 
    for(int i=0;i<10000;i++){
     fout << rand()%32767<< ' ' << rand()%32767<<std::endl; 
    }
    fout.close ();
    return 0;
}
 