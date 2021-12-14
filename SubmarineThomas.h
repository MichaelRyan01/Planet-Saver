#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include "Vehicle.h" 



class Submarine : public Vehicle
{
public:
	// A constructor specific to Player
	Submarine();

	// The overriden input handler for Player
	bool virtual handleInput();
	void virtual update(float elapsedTime);
};




#endif 