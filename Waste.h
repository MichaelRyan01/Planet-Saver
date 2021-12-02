#pragma once
#ifndef WASTE_H
#define WASTE_H

class Waste

{

public:
	Waste();
	void status();

private:
	int wasteLeft = 0;
	float wasteX = 0;
	float wasteY = 0;
};

#endif