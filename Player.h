#pragma once
#include <string>
#include <iostream>
#include "Board.h"
//using namespace std;

class Player {
    //protected:
        
    public:
        char myChar;    
        Player(): myChar('.') {}
        Player(char sign): myChar(sign) {}
        
        char getChar() const;
        const void setChar(char c) {myChar=c;}
        virtual const string name() const=0;
        virtual const Coordinate play(const Board&)=0;
        
    
};
