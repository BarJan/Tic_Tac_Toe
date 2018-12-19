#pragma once
#include "exceptions.h"
//using namespace std;

class X_O{
    char curr;
    
    public:
        
        X_O();
        X_O(char);
        X_O(X_O&);
        
        bool operator==(X_O x) const;
        bool operator!=(X_O x) const;
        bool operator==(const char& c) const;
        bool operator!=(const char& c) const;
        
        inline void setCurr(char c) {this -> curr = c;}
        inline void setO() {curr ='O';}
        inline void setX() {curr ='X';}
        inline void setDot() {curr ='.';}
        inline char getChar() {return this-> curr;}
        inline operator char() const{
                return curr;
            }
        X_O& operator=(X_O&);
        void operator=(char);
        
        friend ostream& operator<<(ostream&, X_O&);
};
    
inline ostream& operator<<(ostream& out, X_O& x){
	    out << x.getChar() << endl;
        return out;
    }
inline bool operator==(const char& c,X_O x){ return c == x.getChar(); }
inline bool operator!=(const char& c,X_O x){ return c != x.getChar();}    
    

//X_O_H
