#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <exception>
#include <initializer_list>
using namespace std;


struct Coordinate{
   
        uint i,j;
        
        inline void operator=(const Coordinate& c){this->i = c.i;this->j=c.j;}
    /*Coordinate (initializer_list<int> crds){
   
    initializer_list<int>::iterator it = crds.begin();
    this -> i = *it;
    it++;
    this -> j = *it;
  
    }*/
};
/*
struct pairs
{
  int i, j;
};
*/

class IllegalCoordinateException : public exception {
    
    string msg;
//  Coordinate pair;
    Coordinate c;
public:
/*
    IllegalCoordinateException(Coordinate couple) {
      this -> pair = couple;
  }
*/ 
   IllegalCoordinateException(Coordinate couple) {
      this -> c = couple;
  }
  
  
  string theCoordinate() const {
      
     ostringstream msg;
     msg << this -> c.i << "," << this -> c.j << endl;
      return  msg.str();
  }
  
 };
 
 
 class IllegalCharException : public exception {
    char c;
public:

    IllegalCharException(const char theChar) {
      this -> c = theChar;
    }
  
    char theChar() const {
    return this -> c;
  }
  
 };

