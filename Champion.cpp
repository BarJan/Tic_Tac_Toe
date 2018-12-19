#include "Champion.h"



const Coordinate Champion::play(const Board& board) {
		
			if(amIfirst()){
				return this ->playFirst(board);
			}
			else{
				 return this-> playSecond(board);
			}
	  
}

const Coordinate Champion :: playFirst(const Board& board){	// this func is playing if we are playing as X which is the first player.
	Coordinate cc{0,0};

	if(board[cc]=='.'){
		return cc;
	}
	
	else{
		//first we are checking (it will happen every time though) if we are against XY or YX.
		//
		//******* If we are first theres no need for that algorithm. ************
		//we just put a row on board[0][y] S.T 0<= y <= size-1.
		//need to fix.
		
		if((board[{0,1}]!='.')&&(board[{0,1}]!=myChar)) vsXY=true;
		else vsYX=true;
		
		if(vsXY){	// if vs XY
    		uint x = 0;
    		while(board[{x+1,0}]!='.')
    			x++;
    		Coordinate c{x+1,0};
    		return c;
    	}								// if vs XY
    	else if(vsYX){
    		uint y=0;
    		while(board[{0,y+1}]!='.')
    			y++;
    		Coordinate c{0,y+1};
    		return c;
    	}

	}
	return cc;
}

const Coordinate Champion :: playSecond(const Board& board){
	
	Coordinate cc{0,0};
	
	if((board[{0,1}]=='.')&&(board[{1,0}]=='.')){
		Coordinate c{0,1};
		return c;
	}
	
	if(board[{0,2}]!='.') vsXY=true;
	else vsYX=true;
	
	
	if(vsXY){	// if vs XY
		uint x=0;
		while(board[{x+1,1}]!='.'){
			x++;
		}
		Coordinate c{x+1,1};
		return c;
	}								// if vs YX
	else if(vsYX){
		if(board[{2,0}]=='.'){
			Coordinate c{2,0};
			return c;
		}
		else{
			uint y=0;
    		while(board[{2,y+1}]!='.'){
    			y++;
    		}
			Coordinate c{2,y+1};
			return c;
		}	
	}
/*	else {							// if vs the others
		Coordinate c{x,y};
		if(board[c]=='.') return c;
	}*/
	return cc;
}
