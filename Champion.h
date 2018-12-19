#pragma once

#include "Player.h"


class Champion: public Player {
	bool First;
	bool vsXY = false;
	bool vsYX = false;
	
public:
	inline bool amIfirst() {return Player :: myChar == 'X';}
	const string name() const override { return "Champion Player"; }
	const Coordinate play(const Board& board) override;
	const Coordinate playFirst(const Board&);
	const Coordinate playSecond(const Board&);
};
