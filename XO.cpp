#include "XO.h"

X_O :: X_O(){
            this -> curr='.';
        }
        
        
X_O :: X_O(char c){
    if (c != 'X' && c != 'O' && c != '.'){
       throw IllegalCharException(c);
    }
   this-> curr = c;
}

X_O :: X_O(X_O& other){
    this -> curr = other.curr;
}

X_O& X_O :: operator=(X_O& x){
    char c = x.getChar();
    
    if (c != 'X' && c != 'O' && c != '.'){
       throw IllegalCharException(c);
    }
    if(x.getChar()=='X') this->setX();
    if(x.getChar()=='O') this->setO();
    if(x.getChar()=='.') this->setDot();
   
    return *this;
}


void X_O ::operator=(char c){
    if (c != 'X' && c != 'O' && c != '.'){
       throw IllegalCharException(c);
    }
    if(c=='X') this->setX();
    if(c=='O') this->setO();
    if(c=='.') this->setDot();
   
}

bool X_O  ::  operator==(X_O x) const{ return this-> curr == x.getChar(); }
bool X_O  ::  operator!=(X_O x) const{ return this-> curr != x.getChar(); }
bool X_O  ::  operator==(const char& c) const{ return this-> curr == c; }
bool X_O  ::  operator!=(const char& c) const{ return this-> curr != c; }
