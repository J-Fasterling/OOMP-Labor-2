#pragma once

#include <string>
#include <iostream>
#include "Player.h"


class Board;
class Field
{
private:
	
	Field* next;
	Field* prev;
	std::string name;
	//Board* board;

public:
	//Field();
	Field(std::string _name, Field* _next = NULL, Field* _prev = NULL);
	~Field();
	virtual void enter(Player& player) = 0;
	void setNext(Field* fNext);
	void setPrev(Field* fPrev);

};

