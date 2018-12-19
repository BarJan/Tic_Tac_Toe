#pragma once
#include "XO.h"

using namespace std;
using pairs=Coordinate;

    class Board{
        
        private:
            
            X_O** board;
            pairs place;
        
        public:
            uint Size;
            inline uint size() const {return this -> Size;}
            inline pairs getPair() const {return this -> place;}
            inline void fill(char c, int i, int j){
                board[i][j].setCurr(c);
            }
           
            Board(int);
            Board(const Board&);
            Board();
            ~Board();
            
            void rmv();
            friend ostream& operator<<(ostream& ,const Board& );
            void reset();
            Board& operator=(const Board& );
            char operator=(char);
           
            X_O& operator[](const Coordinate)const;
          //  char& operator[](const Coordinate);
            

         
    };
    
inline ostream& operator<<(ostream& out,const Board& b)
{
   for(int i = 0; i < b.size(); i++){
			for(int j = 0; j < b.size(); j++ ){
				out << (b.board[i][j]).getChar();
			}
			out << endl;
		}
        return out;
}
