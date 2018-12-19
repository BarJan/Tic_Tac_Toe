#include "TicTacToe.h"

const Board& TicTacToe :: board()const{
    return game_board;
}
    bool TicTacToe :: check(){
        //check row:
        uint x = last.i, y=0;
        char c = this->game_board[last];
        bool check = (game_board[{x,y}]==c);
        while(y<(game_board.size()-1)&&check){
            y++;
            check = (game_board[{x,y}]==c);
        }
        if (y==(game_board.size()-1)&&check) return true;
        
        //check column:
         x = last.j; y=0;
         c = this->game_board[last];
         check = (game_board[{y,x}]==c);
        while(y<(game_board.size()-1)&&check){
            y++;
            check = (game_board[{y,x}]==c);
        }
        if (y==(game_board.size()-1)&&check) return true;
        
        //check slant:
         x=0;y=0;
         c = this->game_board[last];
         check = (game_board[{x,y}]==c);
        while(y<(game_board.size()-1)&&check){
            y++;
            x++;
            check = (game_board[{x,y}]==c);
        }
        if (y==(game_board.size()-1)&&check) return true;
        
        return false;
    }
    
    void TicTacToe :: play( Player& fir , Player& sec){
        bool EndOfGame = false;
        fir.setChar('X');
        sec.setChar('O');
        while(!EndOfGame){
            //
            
            //first player play - and then check.
            bool firTurn=true;
            while(firTurn){
                this-> last = fir.play(this->game_board);
                if(game_board[this->last]!='.'){
                    throw IllegalCoordinateException(this->last);
                    this -> Winner = &sec;
                    //this -> sign = 'X';
                    return;
                } 
                else {
                    game_board[this->last] = 'X';
               //     stepCount++;
                    if(check()){
                        EndOfGame = true;
                        this->Winner = &fir;
                    }
                    firTurn=false;
                    }
            }
            
            //second player play - and then check.
            bool secTurn=true;
            while(secTurn){
                this-> last = sec.play(this->game_board);
                if(game_board[this->last]!='.'){ // if player is trying to cheat, throw error. and other player wins.
                    throw IllegalCoordinateException(this->last);
                    this -> Winner = &fir;
                    //this -> sign = 'O';
                    return;
                }
                else {
                game_board[this->last] = 'O';
                if(check()){
                    EndOfGame = true;
                   this->Winner = &sec;
                }
                secTurn=false;
                }
            }
        
      } //end of while
      
      // not sure thats the place, but need to remove the obj.
        this -> game_board.rmv();
    }
