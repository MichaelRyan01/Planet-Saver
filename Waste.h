#pragma once
#ifndef WASTE_H
#define WASTE_H

#include "TileManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Waste

{

public:
	Waste(float wasteX, float wasteY, bool isSpawned);
	Sprite getSprite();
	FloatRect getPosition();
	bool isSpawned();
	bool clean();

private:
	float wasteX = 0;
	float wasteY = 0;
	bool w_Spawned;

	Sprite w_Sprite;
	Texture w_Texture;
	Vector2f w_Position;
};
#endif