#pragma once

#include "Champion.h"
#include "DummyPlayers.h"
#include "Board.h"


    class TicTacToe{
        
        private:
            Coordinate last;
            Board game_board;
            Player* Winner;
           
        public:
         
            TicTacToe(const int size):game_board(size),Winner() {} 
            void play(Player&,Player&);
            bool check();
            const Board& board()const;
            inline Player& winner()const{return *this->Winner;}
            inline string name()const{return Winner->name();}
            //inline char getChar(){return sign;}
           // inline Board board()const{return game_board;}
            
};
