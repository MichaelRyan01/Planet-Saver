#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

class vehicle
{
public:
	vehicle();
	void movement();



private:
	std::string vehicleID;
	int speed;
	float vehicle_x;
	float vehicle_y;
};

#endif