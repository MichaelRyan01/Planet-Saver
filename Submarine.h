
#pragma once
#ifndef SUBMARINE_H
#define SUBMARINE_H
#include <iostream>
#include "Vehicle.h"

class Submarine
{
public:
	Submarine();
	void movement();
	void clean();
	void boost(int boost);



private:
	std::string vehicleID;
	int speed;
	int m_boost;
	float vehicle_x;
	float vehicle_y;
};

#endif